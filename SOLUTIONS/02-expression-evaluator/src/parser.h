#ifndef PARSER_H
#define PARSER_H

typedef enum {
    AST_NUMBER,
    AST_ADD,
    AST_SUB,
    AST_MUL,
    AST_DIV,
    AST_MOD,
    AST_NEGATE
} ASTNodeType;

typedef struct ASTNode {
    ASTNodeType type;
    double value;
    struct ASTNode *left;
    struct ASTNode *right;
} ASTNode;

ASTNode *parse_expression(void);
void free_ast(ASTNode *node);

#endif
