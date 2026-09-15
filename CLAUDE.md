# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

A tree-sitter grammar for Refal-5. Its main user is the Zed extension https://github.com/butvinm/zed-refal5, which pins a commit of this repo in its `extension.toml` and builds the grammar to WebAssembly. The `bindings/` directories are the standard tree-sitter language bindings.

## Commands

- `tree-sitter generate`: regenerate `src/parser.c`, `src/grammar.json`, `src/node-types.json` and `src/tree_sitter/*.h` from `grammar.js`. Commit them together with the grammar change and never edit them by hand. A newer tree-sitter CLI also changes these files without any grammar change, so put such a regeneration in its own commit.
- `tree-sitter test`: run the corpus tests in `test/corpus/*.txt`. `tree-sitter test --include 'regex'` runs the tests whose name matches.
- `tree-sitter parse file.ref`: print the tree. Parse problems show up as ERROR and MISSING nodes.
- `tree-sitter build --wasm --output /tmp/refal5.wasm`: check that the grammar compiles to WebAssembly, which is how Zed builds it.

`tree-sitter test --update` rewrites every corpus file, including whitespace changes to tests that did not fail. Restore the unrelated files before committing, or write new expected trees by hand.

## Grammar structure

`src/scanner.c` handles the tokens that plain rules cannot express, and its `TokenType` enum must stay in the same order as `externals` in `grammar.js`:

- `special_comment` (`*$...`) and `line_comment` (`*`) only at column 0.
- `type`, the `s`, `t` or `e` of a variable, only when directly followed by `.`. Otherwise these letters are identifiers, as in `(e 'u_')`.

Refal-5 token rules follow the lexer of the Refal-05 compiler, `R5FW-Parser.ref` in refal-5-framework. For example, an escape sequence outside quotes such as `\n` or `\x42` is a single character, parsed as `escape`.

## Unfinished code

The grammar deliberately accepts some code that is still being typed, so it parses without ERROR nodes: a sentence without `=` or a call block, and a condition without `:`. Zed does not re-indent a line that has just ended up inside an ERROR node, so without this, lines typed after a pattern keep the pattern's indentation. The cost is that tree-sitter tools no longer flag these as syntax errors; the compiler still does. When adding a construct that is typed across several lines, check what it parses to while unfinished, and add a test to `test/corpus/unfinished.txt`.

## Releasing to the extension

Merge PRs here with a merge commit, not a squash: the extension pins the commit hash. Then update `commit` in zed-refal5's `extension.toml`. That repo's `make test` checks that its queries compile against the pinned grammar and replays Zed's auto-indent over its fixtures.
