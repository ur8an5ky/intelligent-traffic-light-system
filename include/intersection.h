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
// void updateIntersectionState(Intersection* intersection);
void displayIntersection(const Intersection* intersection);