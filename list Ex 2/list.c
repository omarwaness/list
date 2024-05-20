//
// Created by o9s9w on 4/26/2024.
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
void insert(struct list *l, struct student std) {
    struct element *p = (struct element *) malloc(sizeof(struct element));
    p->student = std;
    p->next = NULL;
    if (l->first == NULL) {
        l->first = p;
        l->last = p;
    } else {
        l->last->next = p;
        l->last = p;
    }
}
void add_after(struct element *l, struct student std) {
    struct element *p;
    p = (struct element*) malloc(sizeof(struct element));
    p->student = std;
    p->next = l->next;
    l->next = p;
}
void add_before(struct element *l, struct student std) {
    struct element *p;
    p = (struct element*) malloc(sizeof(struct element));
    p->student = l->student;
    l->student = std;
    p->next = l->next;
    l->next = p;
}
void before_first(struct list *l, struct student std) {
    struct element *p;
    p = (struct element*) malloc(sizeof(struct element));
    p->student = std;
    p->next = l->first;
    l->first = p;
}
void after_last(struct list *l, struct student std) {
    struct element *p;
    p = (struct element*) malloc(sizeof(struct element));
    p->student = std;
    p->next = NULL;
    l->last->next = p;
    l->last = p;
}
struct element *search(struct list *l, int value) {
    struct element *p;
    p = l->first;
    while (p && p->student.ID != value) {
        p = p->next;
    }
    return p;
}
void display(struct list *l) {
    struct element *p;
    p = l->first;
    while (p) {
        printf("student: %d grade: %d\n", p->student.ID, p->student.grade);
        p = p->next;
    }
}
void sorted_insert(struct list *l) {
    int number, i, prev = 0;
    struct student std;
    printf("Enter the number of students:");
    scanf("%d", &number);
    for (i = 0; i < number; i++) {
        printf("Enter the student ID:");
        scanf("%d", &std.ID);
        do {
            printf("Enter the student grade:");
            scanf("%d", &std.grade);
        } while (std.grade < prev);
        prev = std.grade;
        insert(l, std);
    }
}
int count(struct list *l) {
    int count = 1;
    struct element *e;
    e = l->first;
    while (e->next) {
        count++;
        e = e->next;
    }
    return count;
}
void add_sorted(struct list *l) {
    struct element *e = l->first;
    struct student std;
    printf("Enter the student ID:");
    scanf("%d", &std.ID);
    printf("Enter the student grade:");
    scanf("%d", &std.grade);
    if (e == l->first && e->next->student.grade > std.grade) {
        before_first(l, std);
        return;
    } else {
        while (e->next && e->next->student.grade < std.grade) {
            e = e->next;
        }
        add_after(e, std);
    }
}
float average(struct list *l) {
    struct element *e = l->first;
    float sum = 0;
    while (e) {
        sum += e->student.grade;
        e = e->next;
    }
    return sum / count(l);
}


