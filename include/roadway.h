#pragma once

#include "traffic_lights.h"
#include "queue.h"

typedef struct {
    Queue* straightLane;
    TrafficLights* straightLights;

    // Queue* leftLane;
    // TrafficLights* leftLights;
} Roadway;

Roadway* roadway_create();
void roadway_destroy(Roadway* roadway);
void roadway_initialize(Roadway* roadway);
void roadway_displayInfo(const Roadway* roadway);