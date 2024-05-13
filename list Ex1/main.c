#include <stdio.h>
#include "list.h"

int main() {
    int frequency, i;
    struct list list;
    create(&list);

    insert(&list, 2);

    for (i = 0; i < 10; i++) {
        insert(&list, i);
    }
    insert(&list, 2);
    insert(&list, 2);
    insert(&list, 10);
    insert(&list, 12);

    display(&list);
    frequency = count(&list, 2);
    delete_duplicate(&list, 2);
    printf("\n\n\n");
    display(&list);

    return 0;
}
