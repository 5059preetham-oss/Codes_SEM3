#ifndef RECT_H
#define RECT_H

struct rect
{
	int length;
	int breadth;
};
typedef struct rect rect_t;

void set_rect(rect_t*, int length, int breadth);
void display_rect(const rect_t*);
long long area_rect(const rect_t*);
int compare_rect(const rect_t*, const rect_t*);

#endif