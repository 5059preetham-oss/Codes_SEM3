#include <stdio.h>
#include "term.h"

void set_term(term_t *ptr_term, int coeff, int expo)
{
	ptr_term->coeff_ = coeff;
	ptr_term->expo_ = expo;
}

void disp_term(term_t *ptr_term)
{
	int coeff = ptr_term->coeff_;
	int absolute_coeff = coeff < 0 ? -coeff : coeff;

	if (coeff < 0)
		printf("- ");
	if (ptr_term->expo_ == 0)
		printf("%d", absolute_coeff);
	else if (ptr_term->expo_ == 1)
	{
		if (absolute_coeff != 1)
			printf("%d", absolute_coeff);
		printf("x");
	}
	else
	{
		if (absolute_coeff != 1)
			printf("%d", absolute_coeff);
		printf("x^%d", ptr_term->expo_);
	}
}

int compare_exponents(term_t *left, term_t *right)
{
	return left->expo_ - right->expo_;
}