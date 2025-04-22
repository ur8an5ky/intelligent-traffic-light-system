#pragma once

#include "roadway.h"

typedef struct {
    Roadway* northRoadway;

    Roadway* eastRoadway;
    
    Roadway* southRoadway;
    
    Roadway* westRoadway;
} Intersection;

Intersection* createIntersection();
void initializeIntersection(Intersection* intersection);
// void updateIntersectionState(Intersection* intersection);
void displayIntersectionInfo(const Intersection* intersection);
void destroyIntersection(Intersection* intersection);