#pragma once

#include <stdbool.h>

extern const char* colorNames[];
enum TrafficLightColor {GREEN, YELLOW, RED};

typedef struct {
    enum TrafficLightColor color;
    int duration;
    bool isActive;
} TrafficLight;

extern TrafficLight greenLight;
extern TrafficLight yellowLight;
extern TrafficLight redLight;
// static TrafficLight greenArrow;

void initializeTrafficLights();
void updateTrafficLightState(TrafficLight* light);
void displayTrafficLightInfo(const TrafficLight* light);