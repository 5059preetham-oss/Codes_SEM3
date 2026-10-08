#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "term.h"

term_t *create_term(double coeff, int exp) {
    term_t *node = (term_t *)malloc(sizeof(term_t));
    if (!node) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;
    return node;
}

void print_term(term_t *ptr_term, int is_first) {
    if (!ptr_term || fabs(ptr_term->coeff) < 1e-9) return;

    double c = ptr_term->coeff;
    int e = ptr_term->exp;

    if (is_first) {
        if (c < 0) {
            printf("-");
            c = -c;
        }
    } else {
        if (c < 0) {
            printf(" - ");
            c = -c;
        } else {
            printf(" + ");
        }
    }

    if (e == 0) {
        if (fabs(c - (long)c) < 1e-6) printf("%ld", (long)c);
        else printf("%.2lf", c);
    } else {
        if (fabs(c - 1.0) > 1e-9) {
            if (fabs(c - (long)c) < 1e-6) printf("%ld", (long)c);
            else printf("%.2lf", c);
        }
        printf("x");
        if (e != 1) printf("^%d", e);
    }
}

/*
 * Assumption for exponent = -1:
 * Power rule (x^(n+1))/(n+1) causes division by zero when n = -1.
 * Standard polynomials only support whole-number/non-negative exponents.
 * If exp == -1 is encountered, an error is printed and program exits.
 */
void integrate_term(term_t *ptr_term, term_t *ptr_integrated_term) {
    if (!ptr_term || !ptr_integrated_term) return;

    if (ptr_term->exp == -1) {
        fprintf(stderr, "Error: Integral of x^-1 is logarithmic; cannot form polynomial term.\n");
        exit(EXIT_FAILURE);
    }

    ptr_integrated_term->coeff = ptr_term->coeff / (ptr_term->exp + 1);
    ptr_integrated_term->exp = ptr_term->exp + 1;
    ptr_integrated_term->next = NULL;
}