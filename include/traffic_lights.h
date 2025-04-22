#pragma once

#include <stdbool.h>

extern const char* colorNames[];
enum TrafficLightColor {GREEN, YELLOW, RED};

typedef struct {
    enum TrafficLightColor color;
    int duration;
    bool isActive;
} TrafficLight;

typedef struct {
    TrafficLight* greenLight;
    TrafficLight* yellowLight;
    TrafficLight* redLight;
} TrafficLights;

TrafficLights* createTrafficLights();
void destroyTrafficLights(TrafficLights* lights);
void initializeTrafficLights(TrafficLights* lights);
void updateTrafficLightState(TrafficLight* light);
void displayTrafficLightsInfo(const TrafficLights* lights);