//
// Created by o9s9w on 4/25/2024.
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
struct element *search_address(struct list *l, struct element *value) {
    struct element *p;
    p = l->first;
    while (p && p != value) {
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
int count(struct list *l, int value) {
    struct element *p;
    int count = 0;
    p = l->first;
    while (p) {
        if (p->key == value) {
            count++;
        }
        p = p->next;
    }
    return count;
}
void delete_duplicate(struct list *l, int value) {
    int frequency = 0, c;
    struct element *p, *prv;
    c = count(l, value);
    p = l->first;
    while (p && frequency < c-1) {
        if (p->key == value && p == l->first) {
            l->first = l->first->next;
            frequency++;
        } else if (p->key == value) {
            prv->next = p->next;
            frequency++;
        }
        prv = p;
        p = p->next;
    }
}
