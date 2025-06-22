/**
 * @file Refal5 grammar for tree-sitter
 * @author Mikhail Butvin <butvin.mihail@yandex.ru>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const sep1 = (rule, separator) => seq(rule, repeat(seq(separator, rule)));

module.exports = grammar({
  name: "refal",

  externals: ($) => [$.special_comment, $.line_comment],

  extras: ($) => [/\s/, $.block_comment, $.line_comment],

  word: ($) => $.identifier,

  conflicts: ($) => [[$.conditions]],

  rules: {
    program: ($) => repeat($._unit),

    _unit: ($) =>
      choice(seq($.function, optional(";")), seq($.extern), $.special_comment),

    extern: ($) => seq($.extern_directive, sep1($.identifier, ","), ";"),

    function: ($) =>
      seq(
        field("scope", optional($.entry_directive)),
        field("name", $.identifier),
        "{",
        field("sentences", optional($.sentences)),
        "}",
      ),

    sentences: ($) => seq(sep1($.sentence, ";"), optional(";")),

    sentence: ($) =>
      seq(
        field("pattern", optional($.pattern)),
        field("conditions", optional($.conditions)),
        choice(
          seq("=", field("return", optional($.result))),
          seq(",", field("call_block", $.call_block)),
        ),
      ),

    conditions: ($) => repeat1($.condition),

    condition: ($) =>
      seq(
        ",",
        field("result", optional($.result)),
        ":",
        field("pattern", optional($.pattern)),
      ),

    call_block: ($) =>
      seq(
        field("result", optional($.result)),
        ":",
        "{",
        field("sentences", optional($.sentences)),
        "}",
      ),

    result: ($) => repeat1(choice($.symbol, $.variable, $.brackets, $.call)),
    pattern: ($) => repeat1(choice($.symbol, $.variable, $.brackets)),

    brackets: ($) => seq("(", optional($.result), ")"),
    call: ($) => seq("<", field("callee", $.callee), optional($.result), ">"),

    callee: ($) => choice(/[%*+\-/?]/, $.identifier),

    symbol: ($) => choice($.identifier, $.macrodigit, $.chars, $.compound),
    variable: ($) =>
      seq(field("type", $.type), token.immediate("."), field("index", $.index)),

    type: ($) => token(prec(1, choice("s", "t", "e"))),
    index: ($) => token.immediate(/([a-zA-Z_][a-zA-Z0-9_-]*)|([0-9]+)/), // identifier or macrodigit

    identifier: ($) => /[a-zA-Z_][a-zA-Z0-9_-]*/,
    compound: ($) => /"([^"\\]|\\.)*"/,
    macrodigit: ($) => /[0-9]+/,
    chars: ($) => /'([^'\\]|\\.)*'/,

    block_comment: ($) => /\/\*[^\*]*\*\//,

    // TODO: make a token for all directives,
    // including directives inside special comments, so we can highlight them in the unified way
    extern_directive: ($) => choice("$EXTERNAL", "$EXTERN", "$EXTRN"),

    entry_directive: ($) => "$ENTRY",
  },
});
