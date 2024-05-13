//
// Created by o9s9w on 5/2/2024.
//

#include "list.h"
#include <stdio.h>
#include <stdlib.h>


void create(struct list *l) {
    l->first = NULL;
    l->last = NULL;
}
int empty(struct list l) {
    return (l.first == NULL && l.last == NULL);
}
void insert(struct list *l, struct book b) {
    struct element *p = (struct element *) malloc(sizeof(struct element));
    p->book = b;
    p->next = NULL;
    if (l->first == NULL) {
        l->first = p;
        l->last = p;
    } else {
        l->last->next = p;
        l->last = p;
    }
}
void add_after(struct element *l, struct book b) {
    struct element *p;
    p = (struct element*) malloc(sizeof(struct element));
    p->book = b;
    p->next = l->next;
    l->next = p;
}
void add_before(struct element *l, struct book b) {
    struct element *p;
    p = (struct element*) malloc(sizeof(struct element));
    p->book = l->book;
    l->book = b;
    p->next = l->next;
    l->next = p;
}
void before_first(struct list *l, struct book b) {
    struct element *p;
    p = (struct element*) malloc(sizeof(struct element));
    p->book = b;
    p->next = l->first;
    l->first = p;
}
void after_last(struct list *l, struct book b) {
    struct element *p;
    p = (struct element*) malloc(sizeof(struct element));
    p->book = b;
    p->next = NULL;
    l->last->next = p;
    l->last = p;
}
struct element *search(struct list *l, char name) {
    struct element *p;
    p = l->first;
    while (p && p->book.title != name) {
        p = p->next;
    }
    return p;
}
void display(struct list *l) {
    struct element *p;
    p = l->first;
    while (p) {
        printf("%s  %d\n", p->book.title, p->book.number);
        p = p->next;
    }
}
void add_book(struct list *l, struct book b) {
    if (b.number <= 1) {
        before_first(l, b);
    } else {
        after_last(l, b);
    }
}
void delete(struct list *l) {
    struct element *prev, *e;
    e = l->first;
    if (l->first->book.number == 0) {
        l->first = l->first->next;
    } else {
        while (e && e->book.number != 0) {
            prev = e;
            e = e->next;
        }
        prev->next = e->next;
    }
}
void delete_empty(struct list *l) {
    int empty, i;
    struct element *e;
    e = l->first;
    empty = count_empty(l);
    for (i = 0; i < empty; i++) {
        delete(l);
    }
}
int count_empty(struct list *l) {
    struct element *e;
    int count = 0;
    e = l->first;
    while (e) {
        if (e->book.number == 0) {
            count++;
        }
        e = e->next;
    }
    return count;
}



