#include <stdio.h>
#include "date.h"
#include "event.h"
#include "eventlist.h"

int main(void) {
    event_t events[MAX_EVENTS];
    int count;

    FILE *fp = fopen("events.txt", "r");
    if (fp == NULL) {
        printf("Could not open events.txt\n");
        return 1;
    }

    count = read_all(fp, events, MAX_EVENTS);
    fclose(fp);

    printf("Read %d events:\n", count);
    disp_all(events, count);

    if (count > 0) {
        event_t latest = find_latest(events, count);
        printf("\nLatest event: ");
        print_event(latest);
    }

    int month = 8; /* August */
    int n = count_in_month(events, count, month);
    printf("\n%d event(s) found in month %d\n", n, month);

    /* Optional: Demonstrate remove_on_date */
    printf("\n--- Demonstrating Deletion ---\n");
    date_t target_date = make_date(15, 8, 1947); 
    printf("Removing events on ");
    print_date(target_date);
    printf("...\n");
    
    int removed = remove_on_date(events, &count, target_date);
    printf("Removed %d event(s).\n", removed);
    printf("Remaining events (%d):\n", count);
    disp_all(events, count);

    return 0;
}