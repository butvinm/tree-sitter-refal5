#include "tree_sitter/parser.h"
#include <string.h>
#include <wctype.h>

// Tree-Sitter cannot handle "begging of the line" rules
enum TokenType {
    SPECIAL_COMMENT, // Line staring with "*$"
    LINE_COMMENT, // Line starting with "*"
};

void* tree_sitter_refal5_external_scanner_create() { return NULL; }
void tree_sitter_refal5_external_scanner_destroy(void* p) { }
void tree_sitter_refal5_external_scanner_reset(void* p) { }
unsigned tree_sitter_refal5_external_scanner_serialize(void* p, char* buffer) { return 0; }
void tree_sitter_refal5_external_scanner_deserialize(void* p, const char* b, unsigned n) { }

bool tree_sitter_refal5_external_scanner_scan(void* payload, TSLexer* lexer, const bool* valid_symbols) {
    while (iswspace(lexer->lookahead)) {
        lexer->advance(lexer, true);
    }

    bool at_effective_line_start = lexer->get_column(lexer) == 0;

    if (
        (valid_symbols[SPECIAL_COMMENT] || valid_symbols[LINE_COMMENT]) 
        && lexer->lookahead == '*' 
        && at_effective_line_start
    ) {
        lexer->advance(lexer, false); // Consume '*'

        if (valid_symbols[SPECIAL_COMMENT] && lexer->lookahead == '$') {
            while (lexer->lookahead != '\n' && lexer->lookahead != '\0') {
                lexer->advance(lexer, false);
            }

            lexer->result_symbol = SPECIAL_COMMENT;
            lexer->mark_end(lexer);
            return true;
        }

        if (valid_symbols[LINE_COMMENT] && lexer->lookahead != '/') { // verify it is not end of the block comment (*/)
            while (lexer->lookahead != '\n' && lexer->lookahead != '\0') {
                lexer->advance(lexer, false);
            }

            lexer->result_symbol = LINE_COMMENT;
            lexer->mark_end(lexer);
            return true;
        }
    }

    return false;
}
