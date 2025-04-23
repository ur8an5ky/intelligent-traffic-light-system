#pragma once

#include "vehicle.h"

#include <stdbool.h>

enum Destination {NORTH, EAST, SOUTH, WEST};
typedef struct Node Node;

typedef struct {
    Node* front;
    Node* back;
    int size;
} Queue;

struct Node{
    Vehicle* data;
    enum Destination endRoad;
    Node* next;
};

Queue* createQueue();
void destroyQueue(Queue* q);
void initialize_queue(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, Vehicle* v, const char* destination);
Vehicle* dequeue(Queue* q);
void displayQueue(Queue* q);