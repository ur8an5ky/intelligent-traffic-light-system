#pragma once

#include "roadway.h"

typedef struct {
    Roadway* northRoadway;

    Roadway* eastRoadway;
    
    Roadway* southRoadway;
    
    Roadway* westRoadway;
} Intersection;

Intersection* createIntersection();
void destroyIntersection(Intersection* intersection);
void initializeIntersection(Intersection* intersection);
void displayIntersection(const Intersection* intersection);
void addVehicleToIntersection(Intersection* intersection, Vehicle* vehicle, const char* startRoad, const char* direction);