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
void insert(struct list *l, int value) {
    struct element *p = (struct element *) malloc(sizeof(struct element));
    p->key = value;
    p->next = NULL;
    if (l->first == NULL) {
        l->first = p;
        l->last = p;
    } else {
        l->last->next = p;
        l->last = p;
    }
}
void add_after(struct element *l, int value) {
    struct element *p;
    p = (struct element*) malloc(sizeof(struct element));
    p->key = value;
    p->next = l->next;
    l->next = p;
}
void add_before(struct element *l, int value) {
    struct element *p;
    p = (struct element*) malloc(sizeof(struct element));
    p->key = l->key;
    l->key = value;
    p->next = l->next;
    l->next = p;
}
void before_first(struct list *l, int value) {
    struct element *p;
    p = (struct element*) malloc(sizeof(struct element));
    p->key = value;
    p->next = l->first;
    l->first = p;
}
void after_last(struct list *l, int value) {
    struct element *p;
    p = (struct element*) malloc(sizeof(struct element));
    p->key = value;
    p->next = NULL;
    l->last->next = p;
    l->last = p;
}
struct element *search(struct list *l, int value) {
    struct element *p;
    p = l->first;
    while (p && p->key != value) {
        p = p->next;
    }
    return p;
}
void display(struct list *l) {
    struct element *p;
    p = l->first;
    while (p) {
        printf("%d\n", p->key);
        p = p->next;
    }
}
void add_after_all(struct list *l, int value) {
    struct element *e;
    e = l->first;
    while (e) {
        add_after(e, value);
        e = e->next;
        e = e->next;
    }
}
void sorted_insert(struct list *l, int value) {
    struct element *e;
    e = l->first;
    if (value < e->key) {
        before_first(l, value);
    } else if (value > l->last->key) {
        after_last(l, value);
    } else {
        while (value > e->key) {
            e = e->next;
        }
        add_before(e, value);
    }
}
void delete(struct list *l, int value) {
    struct element *e, *prev;
    e = l->first;
    while (e && value != e->key) {
        prev = e;
        e = e->next;
    }
    prev->next = e->next;
}
void delete_after(struct list *l) {
    struct element *e;
    e = l->first;
    while (e) {
        e = e->next;
        delete(l, e->key);
        e = e->next;
    }
}
void delete_max(struct list *l) {
    struct element *e, *max;
    e = l->first;
    max = e;
    while (e) {
        if (e->key > max->key) {
            max = e;
        }
        e = e->next;
    }
    delete(l, max->key);
}

