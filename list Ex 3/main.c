#include <stdio.h>
#include "list.h"

int main() {
    int i, empty;
    struct book book, Y = {"yellow", 0}, G = {"green", 1}, P = {"pink", 5};
    struct list list;

    create(&list);
    for (i=0; i < 3; i++) {
        printf("Title of the book:");
        scanf("%s", book.title);
        printf("Quantity of books:");
        scanf("%d", &book.number);
        insert(&list, book);
    }
    add_book(&list, Y);
    add_book(&list,G);
    add_book(&list, P);
    delete_empty(&list);

    display(&list);

    //empty = count_empty(&list);
    //printf("Number of empty books: %d\n", empty);

    return 0;
}