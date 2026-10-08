#include "eventlist.h"

int read_all(FILE *fp, event_t e[], int n) {
    int count = 0;
    while (count < n) {
        /* Peek ahead to check for EOF without consuming actual data */
        int c = fgetc(fp);
        if (c == EOF) break;
        ungetc(c, fp);

        read_event(fp, &e[count]);
        count++;
    }
    return count;
}

void disp_all(event_t e[], int n) {
    for (int i = 0; i < n; i++) {
        print_event(e[i]);
    }
}

event_t find_latest(event_t e[], int n) {
    event_t latest = e[0];
    for (int i = 1; i < n; i++) {
        if (compare_event(e[i], latest) > 0) {
            latest = e[i];
        }
    }
    return latest;
}

int count_in_month(event_t e[], int n, int month) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (get_event_month(e[i]) == month) {
            count++;
        }
    }
    return count;
}

int remove_on_date(event_t e[], int *n, date_t d) {
    int removed = 0;
    int i = 0;
    
    while (i < *n) {
        if (compare_date(get_event_date(e[i]), d) == 0) {
            removed++;
            /* Shift remaining elements left */
            for (int j = i; j < (*n) - 1; j++) {
                e[j] = e[j + 1];
            }
            (*n)--;
        } else {
            i++;
        }
    }
    return removed;
}