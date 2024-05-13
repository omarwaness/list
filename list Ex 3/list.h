//
// Created by o9s9w on 5/2/2024.
//

#ifndef LIST_EX_3_LIST_H
#define LIST_EX_3_LIST_H

#endif //LIST_EX_3_LIST_H


struct book {
    char title[20];
    int number;
};
struct element {
    struct book book;
    struct element *next;
};
struct list {
    struct element *first;
    struct element *last;
};

void create(struct list *);
int empty(struct list );
void insert(struct list *, struct book);
void add_after(struct element *, struct book);
void add_before(struct element *, struct book);
void before_first(struct list *, struct book);
void after_last(struct list *, struct book);
struct element *search(struct list *, char );
void display(struct list*);
void add_book(struct list *, struct book);
void delete(struct list *);
void delete_empty(struct list *);
int count_empty(struct list *);
