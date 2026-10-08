#ifndef TERM_H
#define TERM_H

typedef struct term
{
	int coeff_;
	int expo_;
} term_t;

void set_term(term_t *ptr_term, int coeff, int expo);
void disp_term(term_t *ptr_term);
int compare_exponents(term_t *left, term_t *right);

#endif