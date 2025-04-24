#pragma once

#include "traffic_lights.h"
#include "queue.h"

/**
 * @brief Structure representing a roadway.
 *
 * This structure holds a queue for vehicles in a straight lane and the associated traffic lights.
 */
typedef struct {
    Queue* straightLane;      /**< Pointer to the queue of vehicles in the straight lane. */
    TrafficLights* straightLights; /**< Pointer to the traffic lights for the straight lane. */

    // Queue* leftLane;       /**< Pointer to the queue for the left lane (currently unused). */
    // TrafficLights* leftLights;  /**< Pointer to the traffic lights for the left lane (currently unused). */
} Roadway;

/**
 * @brief Creates a new roadway.
 *
 * This function allocates memory for a new roadway and initializes its components.
 *
 * @return Pointer to the newly created Roadway object or NULL if memory allocation fails.
 */
Roadway* roadway_create();

/**
 * @brief Destroys the roadway.
 *
 * This function frees the memory occupied by the roadway, its queue of vehicles, and its traffic lights.
 *
 * @param roadway Pointer to the Roadway object to be destroyed.
 */
void roadway_destroy(Roadway* roadway);

/**
 * @brief Initializes the roadway.
 *
 * This function sets up the queue for the straight lane and initializes the traffic lights.
 *
 * @param roadway Pointer to the Roadway object to be initialized.
 */
void roadway_initialize(Roadway* roadway);

/**
 * @brief Displays information about the roadway.
 *
 * This function prints information about the vehicles in the straight lane and their count to standard output.
 *
 * @param roadway Pointer to the Roadway object whose information will be displayed.
 */
void roadway_displayInfo(const Roadway* roadway);