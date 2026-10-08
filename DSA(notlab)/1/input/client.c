#include <stdio.h>
#include "list.h"

int main(void)
{
	list_t polynomial;
	term_t term;
	int count;
	int coeff;
	int expo;

	init_list(&polynomial);
	printf("Enter number of terms: ");
	if (scanf("%d", &count) != 1 || count < 0)
	{
		deinit_list(&polynomial);
		return 1;
	}
	for (int index = 0; index < count; ++index)
	{
		printf("Enter coefficient and exponent: ");
		if (scanf("%d%d", &coeff, &expo) != 2)
		{
			deinit_list(&polynomial);
			return 1;
		}
		set_term(&term, coeff, expo);
		insert(&polynomial, term);
	}

	printf("Polynomial: ");
	disp(&polynomial);
	deinit_list(&polynomial);
	return 0;
}