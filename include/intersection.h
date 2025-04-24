#pragma once

#include "roadway.h"

typedef struct {
    Roadway* northRoadway;

    Roadway* eastRoadway;
    
    Roadway* southRoadway;
    
    Roadway* westRoadway;
} Intersection;

Intersection* intersection_create();
void intersection_destroy(Intersection* intersection);
void intersection_initialize(Intersection* intersection);
void intersection_displayInfo(const Intersection* intersection);
void intersection_addVehicle(Intersection* intersection, Vehicle* vehicle, const char* startRoad, const char* direction);