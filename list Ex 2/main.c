#include <stdio.h>
#include "list.h"

int main() {
    int i, c;
    float avg;
    struct student std;
    struct list list;

    create(&list);

//    This function asks for the number of students in the list then adds them to the list while keeping the sorted
    sorted_insert(&list);
    printf("\nThe number of students in the list is %d\n", count(&list));
    printf("The list of students\n");
    display(&list);

//    here we are adding a new student to the list and the list stays sorted
    printf("\nAdd the new student to the list:");
    add_sorted(&list);
    printf("\nThe number of students in the list is %d\n", count(&list));
    printf("The list of students after updating it\n");
    display(&list);

    avg = average(&list);
    printf("The average is: %f\n", avg);

    return 0;
}
