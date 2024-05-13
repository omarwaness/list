#include <stdio.h>
#include "list.h"

int main() {
    int i, c;
    float avg;
    struct student std;
    struct list list;

    create(&list);
    sorted_insert(&list);
    add_sorted(&list);
    display(&list);
    avg = average(&list);
    printf("The average is: %f\n", avg);

    return 0;
}
