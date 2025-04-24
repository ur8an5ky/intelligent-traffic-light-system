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

TrafficLights* trafficLights_create();
void trafficLights_destroy(TrafficLights* lights);
void trafficLights_initialize(TrafficLights* lights);
void trafficLights_update(TrafficLight* light);
void trafficLights_displayInfo(const TrafficLights* lights);