#ifndef QUEUE_H
#define QUEUE_H


typedef struct queue Queue;

void enqueue(Queue* q, int value);
int dequeue(Queue* q);
Queue* create_queue();
void destroy_queue(Queue* q);
int size_queue(Queue* q);


#endif