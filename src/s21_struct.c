#include "s21_struct.h"

struct knot *init_knot(int operation, double value) {
    struct knot *tmp = malloc(sizeof(struct knot));
    if (tmp != NULL) {
        tmp -> operation = operation;
        tmp -> value = value;
        tmp -> next = NULL;
    }
    return tmp;
}

// очередь
struct queue *init_queue() {
    struct queue *tmp = malloc(sizeof(struct queue));
    if (tmp != NULL) {
        tmp -> first = NULL;
    }
    return tmp;
}

void push_queue(struct queue *head, int operation, double value) {
    struct knot *n = init_knot(operation, value);
    if (head -> first == NULL) {
        head -> first = n;
    } else {
        struct knot *last_knot = head -> first;
        while (last_knot -> next != NULL) {
            last_knot = last_knot -> next;
        }
        last_knot -> next = n;
    }
}

int pop_queue(struct queue *head, int *operation, double *value) {
    int ret_v = 0;
    if (head->first != NULL) {
        *operation = head -> first->operation;
        *value = head -> first -> value;
        struct knot *next = head -> first -> next;
        free(head -> first);
        head -> first = next;
    } else {
        ret_v = 1;
    }
    return ret_v;
}

void destroy_queue(struct queue *head) {
    struct knot *next = head -> first;
    while (next != NULL) {
        struct knot *t = next -> next;
        free(next);
        next = t;
    }
    free(head);
}

struct queue *clone_queue(struct queue *from) {
    struct queue *tmp = init_queue();
    if (tmp != NULL) {
        struct knot *knot = from->first;
        while (knot != NULL) {
            push_queue(tmp, knot -> operation, knot -> value);
            knot = knot -> next;
        }
    }
    return tmp;
}

// стек
struct stack *init_stack() {
    struct stack *ret = malloc(sizeof(struct stack));
    if (ret != NULL) {
        ret -> back = NULL;
    }
    return ret;
}

void push_stack(struct stack *head, int operation, double value) {
    struct knot *new_knot = init_knot(operation, value);
    if (new_knot != NULL) {
        new_knot -> next = head -> back;
        head -> back = new_knot;
    }
}

int pop_stack(struct stack *head, int *operation, double *value) {
    int ret_v = 0;
    if (head -> back != NULL) {
        *operation = head -> back -> operation;
        *value = head -> back -> value;
        struct knot *tmp = head -> back -> next;
        free(head -> back);
        head -> back = tmp;
    } else {
        ret_v = 1;
    }
    return ret_v;
}

void destroy_stack(struct stack *head) {
    struct knot *cur = head -> back;
    while (cur != NULL) {
        struct knot *tmp = cur -> next;
        free(cur);
        cur = tmp;
    }
    free(head);
}

