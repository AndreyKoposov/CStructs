#ifndef QUEUE_H
#define QUEUE_H


typedef struct queue Queue;

void enqueue(Queue* q, long long value);
long long dequeue(Queue* q);
Queue* queue_create();
void queue_destroy(Queue* q);
size_t queue_size(Queue* q);


#endif