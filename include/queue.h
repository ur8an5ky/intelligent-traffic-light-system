#ifndef QUEUE_H
#define QUEUE_H

#include <vehicle.h>
#define MAX_SIZE 25 // testing value

typedef struct {
    Node* front;
    Node* rear;
} Queue;

typedef struct {
    Vehicle data;
    Node* next;
} Node;

void initialize_queue(Queue* q);
bool is_empty(Queue* q);
bool is_full(Queue* q);
void enqueue(Queue* q, Vehicle* value);
Vehicle* dequeue(Queue* q);
Vehicle* display(Queue* q);
void print_queue(Queue* q);  

#endif // QUEUE_H