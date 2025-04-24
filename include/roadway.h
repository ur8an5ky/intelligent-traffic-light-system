#pragma once

#include "traffic_lights.h"
#include "queue.h"

typedef struct {
    Queue* straightLane;
    TrafficLights* straightLights;

    // Queue* leftLane;
    // TrafficLights* leftLights;
} Roadway;

Roadway* createRoadway();
void destroyRoadway(Roadway* roadway);
void initializeRoadway(Roadway* roadway);
void displayRoadway(const Roadway* roadway);