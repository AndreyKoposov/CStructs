#include <stdlib.h>

#include "cstructs/stack.h"

typedef struct element {
    long long value;
    struct element* next;
} element;

typedef struct stack {
    size_t size;
    element* top;
} Stack;

void push(Stack* s, long long value) {
    element* new = malloc(sizeof(element));
    new->value = value;
    new->next = s->top;

    s->size++;
    
    s->top = new;
}

long long pop(Stack* s) {
    element* poped = s->top;

    s->top = poped->next;
    long long value = poped->value;
    free(poped);

    s->size--;

    return value;
}

Stack* stack_create() {
    Stack* s = malloc(sizeof(Stack));
    s->size = 0;
    s->top = NULL;

    return s;
}

void stack_destroy(Stack* s) {
    while (s->top != NULL) {
        element* next = s->top->next;
        free(s->top);
        s->top = next;
    }
    free(s);
}

size_t stack_size(Stack* s) {
    return s->size;
}