#include "evaluator.h"
#include <stdio.h>
#include <math.h>

int evaluate_ast(ASTNode *node, double *result) {
    if (!node) return 0;

    double left_val, right_val;

    if (node->type == AST_NUMBER) {
        *result = node->value;
        return 1;
    }

    if (node->type == AST_NEGATE) {
        if (!evaluate_ast(node->left, &left_val)) return 0;
        *result = -left_val;
        return 1;
    }

    if (!evaluate_ast(node->left, &left_val) || !evaluate_ast(node->right, &right_val)) {
        return 0;
    }

    switch (node->type) {
        case AST_ADD: *result = left_val + right_val; break;
        case AST_SUB: *result = left_val - right_val; break;
        case AST_MUL: *result = left_val * right_val; break;
        case AST_DIV:
            if (right_val == 0.0) {
                fprintf(stderr, "Error: Division by zero\n");
                return 0;
            }
            *result = left_val / right_val;
            break;
        case AST_MOD:
            if (right_val == 0.0) {
                fprintf(stderr, "Error: Modulo by zero\n");
                return 0;
            }
            *result = fmod(left_val, right_val);
            break;
        default: return 0;
    }

    return 1;
}
