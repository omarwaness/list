//
// Created by o9s9w on 4/26/2024.
//

#ifndef LIST_EX_2_LIST_H
#define LIST_EX_2_LIST_H

#endif //LIST_EX_2_LIST_H

struct student {
    int ID;
    int grade;
};
struct element {
    struct student student;
    struct element *next;
};
struct list {
    struct element *first;
    struct element *last;
};

void create(struct list *);
int empty(struct list );
void insert(struct list *, struct student);
void add_after(struct element *, struct student);
void add_before(struct element *, struct student);
void before_first(struct list *, struct student);
void after_last(struct list *, struct student);
struct element *search(struct list *, int);
void display(struct list*);
void sorted_insert(struct list *);
int count(struct list *);
void add_sorted(struct list *);
float average(struct list *);
