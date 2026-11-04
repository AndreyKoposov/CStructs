#ifndef QUEUE_H
#define QUEUE_H


typedef struct stack Stack;

void push(Stack* q, long long value);
long long pop(Stack* q);
Stack* stack_create();
void stack_destroy(Stack* q);
size_t stack_size(Stack* q);


#endif