#include <stdio.h>
#include "list.h"

int main() {
    int i;
    struct list list;
    struct element *a;
    create(&list);

    for (i = 2; i < 6; i++) {
        insert(&list, i);
    }
    add_after_all(&list, 1);
    //sorted_insert(&list, 4);
    //delete(&list, 5);
    //delete_after(&list);
    //delete_max(&list);
    display(&list);


    return 0;
}
