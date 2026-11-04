#include <stdlib.h>

#include "cstructs/queue.h"

typedef struct element {
    int value;
    struct element* next;
} element;

typedef struct queue {
    size_t size;
    element* first;
    element* last;
} Queue;

void enqueue(Queue* q, int value) {
    element* new = malloc(sizeof(element));
    new->value = value;
    new->next = NULL;

    if (q->size == 0) {
        q->first = new;
    }
    else if (q->size == 1) {
        q->last = new;
        q->first->next = new;
    }
    else {
        element* temp = q->last;
        q->last = new;
        temp->next = new;
    }
   
    q->size++;
}

int dequeue(Queue* q) {
    element* temp = q->first;
    int value = temp->value;

    q->first = temp->next;

    free(temp);

    q->size--;

    if (q->size == 1)
        q->last = NULL;

    return value;
}

Queue* create_queue() {
    Queue* new = malloc(sizeof(Queue));
    new->first = NULL;
    new->last = NULL;
    new->size = 0;

    return new;
}

void destroy_queue(Queue* q) {
    free(q);
}

int size_queue(Queue* q) {
    return q->size;
}