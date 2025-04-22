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
void initializeRoadway(Roadway* roadway);
// void updateRoadwayState(Roadway* roadway);
void displayRoadway(const Roadway* roadway);
void destroyRoadway(Roadway* roadway);