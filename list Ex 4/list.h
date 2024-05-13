//
// Created by o9s9w on 5/2/2024.
//

#ifndef LIST_EX_4_LIST_H
#define LIST_EX_4_LIST_H

#endif //LIST_EX_4_LIST_H

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
void display(struct list*);
void add_after_all(struct list *, int);
void sorted_insert(struct list *, int);
void delete(struct list *, int);
void delete_after(struct list *);
void delete_max(struct list *);


