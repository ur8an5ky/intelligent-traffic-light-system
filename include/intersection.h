#pragma once

#include "roadway.h"

/**
 * @brief Structure representing an intersection.
 *
 * This structure holds pointers to the roadways coming from the four directions:
 * north, east, south, and west.
 */
typedef struct {
    Roadway* northRoadway;  /**< Pointer to the roadway coming from the north. */
    Roadway* eastRoadway;   /**< Pointer to the roadway coming from the east. */
    Roadway* southRoadway;  /**< Pointer to the roadway coming from the south. */
    Roadway* westRoadway;   /**< Pointer to the roadway coming from the west. */
} Intersection;

/**
 * @brief Creates a new intersection.
 *
 * This function allocates memory for a new intersection and initializes its roadways.
 *
 * @return Pointer to the newly created Intersection object or NULL if memory allocation fails.
 */
Intersection* intersection_create();

/**
 * @brief Destroys the intersection.
 *
 * This function frees the memory occupied by the intersection and its roadways.
 *
 * @param intersection Pointer to the Intersection object to be destroyed.
 */
void intersection_destroy(Intersection* intersection);

/**
 * @brief Initializes the intersection.
 *
 * This function sets up the roadways for each direction (north, east, south, west).
 *
 * @param intersection Pointer to the Intersection object to be initialized.
 */
void intersection_initialize(Intersection* intersection);

/**
 * @brief Displays information about the intersection.
 *
 * This function prints the state of each roadway within the intersection to standard output.
 *
 * @param intersection Pointer to the Intersection object whose information will be displayed.
 */
void intersection_displayInfo(const Intersection* intersection);

/**
 * @brief Adds a vehicle to the specified roadway of the intersection.
 *
 * This function places a vehicle into the appropriate roadway based on the start road and direction.
 *
 * @param intersection Pointer to the Intersection object to which the vehicle is added.
 * @param vehicle Pointer to the Vehicle object to be added.
 * @param startRoad The direction from which the vehicle is coming (e.g., "north", "east").
 * @param direction The intended direction for the vehicle (e.g., "north", "east").
 */
void intersection_addVehicle(Intersection* intersection, Vehicle* vehicle, const char* startRoad, const char* direction);