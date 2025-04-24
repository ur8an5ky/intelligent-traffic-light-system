#pragma once

/**
 * @brief Structure representing a vehicle.
 *
 * This structure holds the vehicle's identifier and its destination road.
 */
typedef struct {
    char id[12];            /**< Vehicle identifier (max. 11 characters + 1 for '\0'). */
    char endRoad[6];        /**< Destination road (max. 5 characters + 1 for '\0'). */
    // char registrationPlate[9];
} Vehicle;

/**
 * @brief Creates a new vehicle.
 *
 * This function allocates memory for a new vehicle and initializes its fields.
 *
 * @param id     The vehicle's identifier.
 * @param destination  The destination road for the vehicle.
 * @return Pointer to the newly created vehicle or NULL if memory allocation fails.
 */
Vehicle* vehicle_create(const char* id, /*const char* registrationPlate,*/ const char* destination);

/**
 * @brief Frees the memory occupied by the vehicle.
 *
 * This function releases the memory allocated to the vehicle structure.
 *
 * @param vehicle Pointer to the to-be-destroyed vehicle.
 */
void vehicle_destroy(Vehicle* vehicle);

/**
 * @brief Displays information about the vehicle.
 *
 * This function prints the vehicle's informations.
 *
 * @param vehicle Pointer to the to-be-displayed vehicle.
 */
void vehicle_displayInfo(Vehicle* vehicle);