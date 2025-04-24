#pragma once

#include "intersection.h"

/**
 * @brief Structure representing a simulation.
 *
 * This structure holds the intersection, current simulation time, timestep,
 * a queue for left vehicles, and the count of left vehicles.
 */
typedef struct {
    Intersection* intersection;    /**< Pointer to the intersection being simulated. */
    double currentTime;            /**< Current time in the simulation. */
    double timeStep;               /**< The time step to be used for each simulation step. */
    Queue* leftVehicles;           /**< Pointer to the queue of vehicles that have left the intersection. */
    int leftVehiclesCount;         /**< Count of vehicles that have left the intersection. */
} Simulation;

/**
 * @brief Creates a new simulation.
 *
 * This function allocates memory for a new simulation and initializes its components.
 *
 * @return Pointer to the newly created Simulation object or NULL if memory allocation fails.
 */
Simulation* simulation_create();

/**
 * @brief Destroys the intersection.
 *
 * This function frees the memory occupied by the intersection and its roadways.
 *
 * @param intersection Pointer to the Intersection object to be destroyed.
 */
void simulation_destroy(Simulation* simulation);

/**
 * @brief Runs the simulation.
 *
 * This function processes the provided line of input for the simulation, either running a step or adding a vehicle.
 *
 * @param simulation Pointer to the Simulation object to run.
 * @param line The line of input which may include a command or vehicle details.
 * @return Pointer to the JSON string representing the status of the simulation step or NULL if added a vehicle.
 */
char* simulation_run(Simulation* simulation, const char* line);

/**
 * @brief Generates a JSON string representing the step status of the simulation.
 *
 * @param simulation Pointer to the Simulation object.
 * @return Pointer to a dynamically allocated JSON string representing the state of left vehicles.
 */
char* simulation_generateStepStatusJSON(Simulation* simulation);

/**
 * @brief Displays the current state of the simulation.
 *
 * This function prints the current time and the state of the intersection to the standard output.
 *
 * @param simulation Pointer to the Simulation object to display its state.
 */
void simulation_displayState(const Simulation* simulation);

/**
 * @brief Processes the North-South direction step in the simulation.
 *
 * This function manages the vehicles leaving the intersection from the North and South lanes.
 *
 * @param simulation Pointer to the Simulation object to process the step for North-South.
 */
void simulation_stepNorthSouth(Simulation* simulation);

/**
 * @brief Processes the East-West direction step in the simulation.
 *
 * This function manages the vehicles leaving the intersection from the East and West lanes.
 *
 * @param simulation Pointer to the Simulation object to process the step for East-West.
 */
void simulation_stepEastWest(Simulation* simulation);

/**
 * @brief Clears the console display.
 *
 * This function clears the terminal console based on the operating system.
 */
void simulation_clearConsole();