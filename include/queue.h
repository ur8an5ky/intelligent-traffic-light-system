#pragma once

#include "vehicle.h"

#include <stdbool.h>

enum Destination {NORTH, EAST, SOUTH, WEST, LEFT};
typedef struct Node Node;

typedef struct {
    Node* front;
    Node* back;
    int size;
} Queue;

struct Node {
    Vehicle* data;
    enum Destination endRoad;
    Node* next;
};

Queue* queue_create();
void queue_destroy(Queue* queue);
void queue_initialize(Queue* queue);
bool queue_isEmpty(Queue* queue);
void queue_push(Queue* queue, Vehicle* v, const char* destination);
Vehicle* queue_pop(Queue* queue);
void queue_display(Queue* queue);