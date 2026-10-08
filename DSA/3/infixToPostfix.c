#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

// Precedence table logic
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

// Associativity check
bool isLeftAssociative(char op) {
    if (op == '^') return false; // ^ is right-associative
    return true; // +, -, *, / are left-associative
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void infixToPostfix(const char *infix, char *postfix) {
    Stack s;
    initStack(&s);
    int i = 0, k = 0;

    while (infix[i] != '\0') {
        // Skip whitespace
        if (isspace(infix[i])) {
            i++;
            continue;
        }

        // Multi-character operand handling (Step 3)
        if (isalnum(infix[i]) || infix[i] == '_') {
            while (isalnum(infix[i]) || infix[i] == '_') {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' '; // Separate operands with space
            continue;
        }

        // Parentheses handling
        if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
                postfix[k++] = ' ';
            }
            if (!isEmpty(&s) && peek(&s) == '(') {
                pop(&s); // Discard '('
            } else {
                printf("Error: Unmatched parentheses\n");
                return;
            }
        } 
        // Operator handling
        else if (isOperator(infix[i])) {
            char op1 = infix[i];
            while (!isEmpty(&s) && peek(&s) != '(') {
                char op2 = peek(&s);
                if ((precedence(op2) > precedence(op1)) || 
                    (precedence(op2) == precedence(op1) && isLeftAssociative(op1))) {
                    postfix[k++] = pop(&s);
                    postfix[k++] = ' ';
                } else {
                    break;
                }
            }
            push(&s, op1);
        } else {
            printf("Error: Invalid character '%c'\n", infix[i]);
            return;
        }
        i++;
    }

    // Pop remaining operators
    while (!isEmpty(&s)) {
        if (peek(&s) == '(') {
            printf("Error: Unmatched parentheses\n");
            return;
        }
        postfix[k++] = pop(&s);
        postfix[k++] = ' ';
    }
    postfix[k] = '\0';
}

int main() {
    char infix[256];
    char postfix[256];

    printf("Enter infix expression: ");
    if (fgets(infix, sizeof(infix), stdin) != NULL) {
        infixToPostfix(infix, postfix);
        printf("Postfix expression: %s\n", postfix);
    }
    return 0;
}