#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "parser.h"
#include "evaluator.h"

int main(void) {
    char line[256];

    printf("Expression Evaluator\n");
    printf("Enter an expression (or 'quit'/'exit' to stop):\n");

    while (1) {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin)) break;

        // Remove trailing newline
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') line[len-1] = '\0';

        if (strcmp(line, "quit") == 0 || strcmp(line, "exit") == 0) {
            break;
        }

        if (strlen(line) == 0) continue;

        tokenizer_init(line);
        ASTNode *ast = parse_expression();

        if (ast) {
            double result;
            if (evaluate_ast(ast, &result)) {
                printf("= %g\n", result);
            }
            free_ast(ast);
        }
    }

    return 0;
}
