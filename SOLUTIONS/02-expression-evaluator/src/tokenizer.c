#include "tokenizer.h"
#include <ctype.h>
#include <stdlib.h>

static const char *current_input;

void tokenizer_init(const char *input) {
    current_input = input;
}

Token tokenizer_next(void) {
    Token token;
    token.value = 0;

    while (isspace((unsigned char)*current_input)) {
        current_input++;
    }

    if (*current_input == '\0') {
        token.type = TOKEN_EOF;
        return token;
    }

    if (isdigit((unsigned char)*current_input) || *current_input == '.') {
        char *endptr;
        token.value = strtod(current_input, &endptr);
        current_input = endptr;
        token.type = TOKEN_NUMBER;
        return token;
    }

    switch (*current_input) {
        case '+': token.type = TOKEN_PLUS; break;
        case '-': token.type = TOKEN_MINUS; break;
        case '*': token.type = TOKEN_STAR; break;
        case '/': token.type = TOKEN_SLASH; break;
        case '%': token.type = TOKEN_PERCENT; break;
        case '(': token.type = TOKEN_LPAREN; break;
        case ')': token.type = TOKEN_RPAREN; break;
        default: token.type = TOKEN_ERROR; break;
    }
    current_input++;
    return token;
}
