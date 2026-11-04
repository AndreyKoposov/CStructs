#ifndef QUEUE_H
#define QUEUE_H


typedef struct queue Queue;

void enqueue(Queue* q, int value);
int dequeue(Queue* q);
Queue* queue_create();
void queue_destroy(Queue* q);
int queue_size(Queue* q);


#endif