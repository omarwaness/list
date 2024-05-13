//
// Created by o9s9w on 4/25/2024.
//

#ifndef LIST_EX1_LIST_H
#define LIST_EX1_LIST_H

#endif //LIST_EX1_LIST_H


struct element {
    int key;
    struct element *next;
};
struct list {
    struct element *first;
    struct element *last;
};

void create(struct list *);
int empty(struct list );
void insert(struct list *, int);
void add_after(struct element *, int);
void add_before(struct element *, int);
void before_first(struct list *, int);
void after_last(struct list *, int);
struct element *search(struct list *, int);
struct element *search_address(struct list *, struct element *);
void display(struct list*);
int count(struct list*, int);
void delete_duplicate(struct list*, int);
