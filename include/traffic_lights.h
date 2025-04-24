#pragma once

#include <stdbool.h>

/**
 * @brief Array of traffic light color names.
 *
 * This array holds the string representations of the traffic light colors.
 */
extern const char* colorNames[];

/**
 * @brief Enum representing the traffic light colors.
 *
 * This enum defines the possible colors of a traffic light.
 */
enum TrafficLightColor {GREEN, YELLOW, RED};

/**
 * @brief Structure representing a traffic light.
 *
 * This structure holds the color, duration, and active state of a traffic light.
 */
typedef struct {
    enum TrafficLightColor color; /**< The current color of the traffic light. */
    int duration;                 /**< The duration for which the color is active (not used in the current implementation). */
    bool isActive;               /**< Indicates whether the traffic light is currently active. */
} TrafficLight;

/**
 * @brief Structure representing the traffic lights system.
 *
 * This structure holds pointers to the green, yellow, and red traffic lights.
 */
 typedef struct {
    TrafficLight* greenLight;   /**< Pointer to the green traffic light. */
    TrafficLight* yellowLight;  /**< Pointer to the yellow traffic light. */
    TrafficLight* redLight;     /**< Pointer to the red traffic light. */
} TrafficLights;

/**
 * @brief Creates a new traffic lights system.
 *
 * This function allocates memory for a new traffic lights system and initializes its lights.
 *
 * @return Pointer to the newly created TrafficLights object or NULL if memory allocation fails.
 */
TrafficLights* trafficLights_create();

/**
 * @brief Destroys the traffic lights system.
 *
 * This function frees the memory occupied by the traffic lights and its lights.
 *
 * @param lights Pointer to the TrafficLights object to be destroyed.
 */
void trafficLights_destroy(TrafficLights* lights);

/**
 * @brief Initializes the traffic lights.
 *
 * This function sets the initial state of the traffic lights (color and active state).
 *
 * @param lights Pointer to the TrafficLights object to be initialized.
 */
void trafficLights_initialize(TrafficLights* lights);

/**
 * @brief Toggles the active state of the specified traffic light.
 *
 * This function changes the active state of a traffic light to its opposite state.
 *
 * @param light Pointer to the TrafficLight to be updated.
 */
void trafficLights_update(TrafficLight* light);

/**
 * @brief Displays information about the traffic lights system.
 *
 * This function prints the current state and colors of the traffic lights to standard output.
 *
 * @param lights Pointer to the TrafficLights object whose information will be displayed.
 */
void trafficLights_displayInfo(const TrafficLights* lights);