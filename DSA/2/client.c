#include <stdio.h>
#include "list.h"

int main(void)
{
	list_t list;
	int count;
	init_list(&list);

	printf("Enter number of sites: ");
	if(scanf("%d", &count) != 1 || count < 0)
	{
		printf("Invalid number of sites.\n");
		return 1;
	}

	for(int index = 0; index < count; ++index)
	{
		int length;
		int breadth;
		printf("Enter length and breadth for site %d: ", index + 1);
		if(scanf("%d %d", &length, &breadth) != 2 || length < 0 || breadth < 0)
		{
			printf("Invalid dimensions.\n");
			free_list(&list);
			return 1;
		}
		if(!insert_list(&list, length, breadth))
		{
			printf("Memory allocation failed.\n");
			free_list(&list);
			return 1;
		}
	}

	printf("\nSites ordered by area:\n");
	display_list(&list);

	if(list.head != NULL)
	{
		double unit_area_value;
		const rect_t* longest = highest_length(&list);
		const rect_t* narrowest = least_breadth(&list);

		printf("\nEnter value of one unit area: ");
		if(scanf("%lf", &unit_area_value) != 1)
		{
			printf("Invalid unit area value.\n");
			free_list(&list);
			return 1;
		}
		printf("Total layout value: %.2f\n", total_value(&list, unit_area_value));
		printf("Site with highest length: ");
		display_rect(longest);
		printf("Site with least breadth: ");
		display_rect(narrowest);
	}

	free_list(&list);
	return 0;
}