#pragma once

#include <stdbool.h>

extern const char* colorNames[];
enum TrafficLightColor {GREEN, YELLOW, RED};

typedef struct {
    enum TrafficLightColor color;
    int duration;
    bool isActive;
} TrafficLight;

// extern TrafficLight greenLight;
// extern TrafficLight yellowLight;
// extern TrafficLight redLight;
static TrafficLight greenArrow;

typedef struct {
    TrafficLight* greenLight;
    TrafficLight* yellowLight;
    TrafficLight* redLight;
} TrafficLights;

void initializeTrafficLights(TrafficLights* lights);
void updateTrafficLightState(TrafficLight* light);
void displayTrafficLightsInfo(const TrafficLights* lights);
void destroyTrafficLights(TrafficLights* lights);