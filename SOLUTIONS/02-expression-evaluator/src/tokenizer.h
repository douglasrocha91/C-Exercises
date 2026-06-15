#ifndef TOKENIZER_H
#define TOKENIZER_H

typedef enum {
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,
    TOKEN_SLASH,
    TOKEN_PERCENT,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_EOF,
    TOKEN_ERROR
} TokenType;

typedef struct {
    TokenType type;
    double value;
} Token;

void tokenizer_init(const char *input);
Token tokenizer_next(void);

#endif
