#pragma once

#include "vehicle.h"

#include <stdbool.h>

typedef struct Node Node;

typedef struct {
    Node* front;
    Node* back;
    int size;
} Queue;

struct Node{
    Vehicle* data;
    char destination[6]; // enum?
    Node* next;
    // Node* previous;
};

Queue* createQueue();
void destroyQueue(Queue* q);
void initialize_queue(Queue* q);
bool isEmpty(Queue* q);
// bool is_full(Queue* q);
void enqueue(Queue* q, Vehicle* v);
Vehicle* dequeue(Queue* q);
void displayQueue(Queue* q);