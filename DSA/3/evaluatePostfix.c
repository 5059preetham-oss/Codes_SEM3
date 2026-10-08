#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "stack.h" // Ensure typedef double Element; is set in stack.h

void evaluatePostfixREPL() {
    char input[256];
    Stack s;

    while (1) {
        printf("postfix> ");
        if (fgets(input, sizeof(input), stdin) == NULL) break;

        // Strip trailing newline
        input[strcspn(input, "\r\n")] = 0;

        // Sentinel command handling
        if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0) {
            break;
        }

        clearStack(&s);
        char *token = strtok(input, " ");
        bool error = false;

        while (token != NULL) {
            // If token is a number
            char *end;
            double value = strtod(token, &end);
            if (*token != '\0' && *end == '\0') {
                push(&s, value);
            } 
            // If token is an operator
            else if (strlen(token) == 1 && strchr("+-*/^", token[0]) != NULL) {
                if (isEmpty(&s)) { printf("Error: Stack underflow\n"); error = true; break; }
                double rightOperand = pop(&s);
                
                if (isEmpty(&s)) { printf("Error: Stack underflow\n"); error = true; break; }
                double leftOperand = pop(&s);
                
                double result = 0.0;
                switch (token[0]) {
                    case '+': result = leftOperand + rightOperand; break;
                    case '-': result = leftOperand - rightOperand; break;
                    case '*': result = leftOperand * rightOperand; break;
                    case '/': 
                        if (rightOperand == 0) {
                            printf("Error: Division by zero\n");
                            error = true;
                        } else {
                            result = leftOperand / rightOperand;
                        }
                        break;
                    case '^': result = pow(leftOperand, rightOperand); break;
                }
                if (error) break;
                push(&s, result);
            } else {
                printf("Error: Invalid token '%s'\n", token);
                error = true;
                break;
            }
            token = strtok(NULL, " ");
        }

        if (!error) {
            double finalResult = pop(&s);
            if (!isEmpty(&s)) {
                printf("Error: Leftover operands\n");
            } else {
                printf("Result = %g\n", finalResult);
            }
        }
    }
}

int main() {
    printf("Postfix Evaluator REPL. Type 'exit' to quit.\n");
    evaluatePostfixREPL();
    return 0;
}