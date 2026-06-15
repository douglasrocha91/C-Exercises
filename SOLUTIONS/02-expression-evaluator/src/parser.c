#include "parser.h"
#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>

static Token current_token;

static void advance(void) {
    current_token = tokenizer_next();
}

static ASTNode *create_node(ASTNodeType type, double value, ASTNode *left, ASTNode *right) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = type;
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

static ASTNode *parse_expr(void);

static ASTNode *parse_primary(void) {
    if (current_token.type == TOKEN_NUMBER) {
        ASTNode *node = create_node(AST_NUMBER, current_token.value, NULL, NULL);
        advance();
        return node;
    } else if (current_token.type == TOKEN_LPAREN) {
        advance();
        ASTNode *node = parse_expr();
        if (current_token.type == TOKEN_RPAREN) {
            advance();
        } else {
            fprintf(stderr, "Error: Expected ')'\n");
            free_ast(node);
            return NULL;
        }
        return node;
    }
    fprintf(stderr, "Error: Unexpected token\n");
    return NULL;
}

static ASTNode *parse_unary(void) {
    if (current_token.type == TOKEN_MINUS) {
        advance();
        ASTNode *node = parse_unary();
        if (node == NULL) return NULL;
        return create_node(AST_NEGATE, 0, node, NULL);
    } else if (current_token.type == TOKEN_PLUS) {
        advance();
        return parse_unary();
    }
    return parse_primary();
}

static ASTNode *parse_term(void) {
    ASTNode *node = parse_unary();
    if (node == NULL) return NULL;

    while (current_token.type == TOKEN_STAR || current_token.type == TOKEN_SLASH || current_token.type == TOKEN_PERCENT) {
        TokenType op = current_token.type;
        advance();
        ASTNode *right = parse_unary();
        if (right == NULL) {
            free_ast(node);
            return NULL;
        }
        ASTNodeType type = (op == TOKEN_STAR) ? AST_MUL : (op == TOKEN_SLASH) ? AST_DIV : AST_MOD;
        node = create_node(type, 0, node, right);
    }
    return node;
}

static ASTNode *parse_expr(void) {
    ASTNode *node = parse_term();
    if (node == NULL) return NULL;

    while (current_token.type == TOKEN_PLUS || current_token.type == TOKEN_MINUS) {
        TokenType op = current_token.type;
        advance();
        ASTNode *right = parse_term();
        if (right == NULL) {
            free_ast(node);
            return NULL;
        }
        ASTNodeType type = (op == TOKEN_PLUS) ? AST_ADD : AST_SUB;
        node = create_node(type, 0, node, right);
    }
    return node;
}

ASTNode *parse_expression(void) {
    advance();
    if (current_token.type == TOKEN_EOF) return NULL;
    ASTNode *ast = parse_expr();
    if (ast != NULL && current_token.type != TOKEN_EOF) {
        fprintf(stderr, "Error: Unexpected trailing characters\n");
        free_ast(ast);
        return NULL;
    }
    return ast;
}

void free_ast(ASTNode *node) {
    if (node) {
        free_ast(node->left);
        free_ast(node->right);
        free(node);
    }
}
