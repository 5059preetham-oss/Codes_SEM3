#ifndef EVENT_H
#define EVENT_H

#include "date.h"
#include <stdio.h>

typedef struct {
    date_t d;
    char detail[50];
} event_t;

void read_event(FILE *fp, event_t *e);
void print_event(event_t e);
int compare_event(event_t e1, event_t e2); /* compares by date */

/* Added to maintain strict encapsulation in eventlist.c */
int get_event_month(event_t e);
date_t get_event_date(event_t e);

#endif