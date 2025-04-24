#include "intersection.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Intersection* createIntersection()
{
    Intersection* newIntersection = (Intersection*)malloc(sizeof(Intersection));

    if(newIntersection == NULL)
    {
        return NULL;
    }

    newIntersection->northRoadway = NULL;
    newIntersection->eastRoadway = NULL;
    newIntersection->southRoadway = NULL;
    newIntersection->westRoadway = NULL;

    initializeIntersection(newIntersection);

    return newIntersection;
}

void destroyIntersection(Intersection* intersection)
{
    if(intersection == NULL)
    {
        return;
    }

    destroyRoadway(intersection->northRoadway);
    destroyRoadway(intersection->eastRoadway);
    destroyRoadway(intersection->southRoadway);
    destroyRoadway(intersection->westRoadway);
    free(intersection);
}

void initializeIntersection(Intersection* intersection)
{
    if(intersection == NULL)
    {
        return;
    }

    intersection->northRoadway = createRoadway();
    intersection->eastRoadway = createRoadway();
    intersection->southRoadway = createRoadway();
    intersection->westRoadway = createRoadway();
}

void displayIntersection(const Intersection* intersection)
{
    if(intersection == NULL)
    {
        return;
    }

    // printf("Intersection Information:\n");
    printf("###############################################################\n");

    printf("North Roadway:  ");
    displayRoadway(intersection->northRoadway);

    printf("East Roadway:  ");
    displayRoadway(intersection->eastRoadway);

    printf("South Roadway:  ");
    displayRoadway(intersection->southRoadway);

    printf("West Roadway:  ");
    displayRoadway(intersection->westRoadway);

    printf("###############################################################\n");
}

void addVehicleToIntersection(Intersection* intersection, Vehicle* vehicle, const char* startRoad, const char* direction)
{
    if(strcmp(startRoad, "north") == 0)
    {
        enqueue(intersection->northRoadway->straightLane, vehicle, direction);
    }
    else if(strcmp(startRoad, "east") == 0)
    {
        enqueue(intersection->eastRoadway->straightLane, vehicle, direction);
    }
    else if(strcmp(startRoad, "south") == 0)
    {
        enqueue(intersection->southRoadway->straightLane, vehicle, direction);
    }
    else if(strcmp(startRoad, "west") == 0)
    {
        enqueue(intersection->westRoadway->straightLane, vehicle, direction);
    }
}