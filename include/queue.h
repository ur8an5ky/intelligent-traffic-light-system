#pragma once

#include "vehicle.h"

#include <stdbool.h>

/**
 * @brief Enum representing possible destinations.
 *
 * This enum defines the various directions a vehicle can head towards.
 */
enum Destination {NORTH, EAST, SOUTH, WEST, LEFT};

/**
 * @brief Forward declaration of the Node structure.
 */
typedef struct Node Node;

/**
 * @brief Structure representing a queue.
 *
 * This structure holds pointers to the front and back of the queue, as well as the current size.
 */
typedef struct {
    Node* front;    /**< Pointer to the front node of the queue. */
    Node* back;     /**< Pointer to the back node of the queue. */
    int size;       /**< Current size of the queue. */
} Queue;

/**
 * @brief Structure representing a node in the queue.
 *
 * Each node contains vehicle data, the destination road, and a pointer to the next node.
 */
 struct Node {
    Vehicle* data;          /**< Pointer to the vehicle data. */
    enum Destination endRoad; /**< Destination the vehicle is heading to. */
    Node* next;            /**< Pointer to the next node in the queue. */
};

/**
 * @brief Creates a new queue.
 *
 * This function allocates memory for a new queue and initializes it.
 *
 * @return Pointer to the newly created queue or NULL if memory allocation fails.
 */
Queue* queue_create();

/**
 * @brief Destroys the queue.
 *
 * This function frees the memory occupied by the queue and its nodes.
 *
 * @param queue Pointer to the queue to be destroyed.
 */
void queue_destroy(Queue* queue);

/**
 * @brief Initializes the queue.
 *
 * This function sets the front and back pointers to NULL and size to 0.
 *
 * @param queue Pointer to the queue to be initialized.
 */
void queue_initialize(Queue* queue);

/**
 * @brief Checks if the queue is empty.
 *
 * This function checks whether the queue contains any elements.
 *
 * @param queue Pointer to the queue to be checked.
 * @return true if the queue is empty, false otherwise.
 */
bool queue_isEmpty(Queue* queue);

/**
 * @brief Pushes a vehicle onto the queue.
 *
 * This function adds a vehicle to the back of the queue with the specified destination.
 *
 * @param queue Pointer to the queue where the vehicle will be added.
 * @param v Pointer to the vehicle to be added.
 * @param destination The destination road for the vehicle (e.g. "north", "east").
 */
void queue_push(Queue* queue, Vehicle* v, const char* destination);

/**
 * @brief Pops a vehicle from the queue.
 *
 * This function removes and returns the vehicle from the front of the queue.
 *
 * @param queue Pointer to the queue to pop from.
 * @return Pointer to the vehicle that was removed from the queue or NULL if the queue is empty.
 */
Vehicle* queue_pop(Queue* queue);

/**
 * @brief Displays the contents of the queue.
 *
 * This function prints the information of each vehicle in the queue to the standard output.
 *
 * @param queue Pointer to the queue to be displayed.
 */
void queue_display(Queue* queue);