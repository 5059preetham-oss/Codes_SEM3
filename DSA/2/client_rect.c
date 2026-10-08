#include <stdio.h>
#include "rect.h"

int main(void)
{
	rect_t rectangle;
	int length;
	int breadth;

	printf("Enter length and breadth: ");
	if(scanf("%d %d", &length, &breadth) != 2 || length < 0 || breadth < 0)
	{
		printf("Invalid dimensions.\n");
		return 1;
	}

	set_rect(&rectangle, length, breadth);
	display_rect(&rectangle);
	return 0;
}