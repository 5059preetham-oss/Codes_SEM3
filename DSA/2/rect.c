#include <stdio.h>
#include "rect.h"

static void print_area_value(long long value)
{
	if(value >= 10)
	{
		print_area_value(value / 10);
	}
	putchar((int)('0' + value % 10));
}

void set_rect(rect_t* rectangle, int length, int breadth)
{
	rectangle->length = length;
	rectangle->breadth = breadth;
}

void display_rect(const rect_t* rectangle)
{
	printf("Length: %d, Breadth: %d, Area: ", rectangle->length, rectangle->breadth);
	print_area_value(area_rect(rectangle));
	putchar('\n');
}

long long area_rect(const rect_t* rectangle)
{
	return (long long)rectangle->length * rectangle->breadth;
}

int compare_rect(const rect_t* first, const rect_t* second)
{
	return area_rect(first) < area_rect(second);
}