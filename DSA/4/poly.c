#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "poly.h"

static void append_term(poly_t *poly, double coeff, int exp) {
    if (fabs(coeff) < 1e-9) return;
    term_t *new_node = create_term(coeff, exp);
    if (!poly->head) {
        poly->head = new_node;
    } else {
        term_t *curr = poly->head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

poly_t create_poly(void) {
    poly_t poly;
    poly.head = NULL;
    int n;
    printf("Number of terms: ");
    if (scanf("%d", &n) != 1) return poly;

    for (int i = 0; i < n; ++i) {
        double coeff;
        int exp;
        printf("Coefficient Exponent: ");
        if (scanf("%lf %d", &coeff, &exp) == 2) {
            append_term(&poly, coeff, exp);
        }
    }
    return poly;
}

void display_poly(poly_t poly) {
    if (!poly.head) {
        printf("0\n");
        return;
    }
    term_t *curr = poly.head;
    int is_first = 1;
    while (curr) {
        print_term(curr, is_first);
        is_first = 0;
        curr = curr->next;
    }
    printf("\n");
}

void add_poly(poly_t poly1, poly_t poly2, poly_t *sum) {
    sum->head = NULL;
    term_t *p1 = poly1.head;
    term_t *p2 = poly2.head;

    while (p1 && p2) {
        if (p1->exp == p2->exp) {
            double combined_coeff = p1->coeff + p2->coeff;
            if (fabs(combined_coeff) > 1e-9) {
                append_term(sum, combined_coeff, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            append_term(sum, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            append_term(sum, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1) {
        append_term(sum, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2) {
        append_term(sum, p2->coeff, p2->exp);
        p2 = p2->next;
    }
}

poly_t integrate_poly(poly_t poly) {
    poly_t integrated;
    integrated.head = NULL;

    term_t *curr = poly.head;
    term_t temp;
    while (curr) {
        integrate_term(curr, &temp);
        append_term(&integrated, temp.coeff, temp.exp);
        curr = curr->next;
    }
    return integrated;
}

double eval_poly(poly_t poly, double x) {
    double sum = 0.0;
    term_t *curr = poly.head;
    while (curr) {
        sum += curr->coeff * pow(x, curr->exp);
        curr = curr->next;
    }
    return sum;
}

void destroy_poly(poly_t *poly) {
    if (!poly) return;
    term_t *curr = poly->head;
    while (curr) {
        term_t *temp = curr;
        curr = curr->next;
        free(temp);
    }
    poly->head = NULL;
}