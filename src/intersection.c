#include "intersection.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Intersection* intersection_create()
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

    intersection_initialize(newIntersection);

    return newIntersection;
}

void intersection_destroy(Intersection* intersection)
{
    if(intersection == NULL)
    {
        return;
    }

    roadway_destroy(intersection->northRoadway);
    roadway_destroy(intersection->eastRoadway);
    roadway_destroy(intersection->southRoadway);
    roadway_destroy(intersection->westRoadway);
    free(intersection);
}

void intersection_initialize(Intersection* intersection)
{
    if(intersection == NULL)
    {
        return;
    }

    intersection->northRoadway = roadway_create();
    intersection->eastRoadway = roadway_create();
    intersection->southRoadway = roadway_create();
    intersection->westRoadway = roadway_create();
}

void intersection_displayInfo(const Intersection* intersection)
{
    if(intersection == NULL)
    {
        return;
    }

    printf("###############################################################\n");

    printf("North Roadway Straight Lane [size=%d]:\n", intersection->northRoadway->straightLane->size);
    queue_display(intersection->northRoadway->straightLane);
    printf("\nNorth Roadway Left Lane:\n");
    queue_display(intersection->northRoadway->leftLane);
    
    printf("\nEast Roadway Straight Lane:\n");
    queue_display(intersection->eastRoadway->straightLane);
    printf("\nEast Roadway Left Lane:\n");
    queue_display(intersection->eastRoadway->leftLane);

    printf("\nSouth Roadway Straight Lane:\n");
    queue_display(intersection->southRoadway->straightLane);
    printf("\nSouth Roadway Left Lane:\n");
    queue_display(intersection->southRoadway->leftLane);

    printf("\nWest Roadway Straight Lane:\n");
    queue_display(intersection->westRoadway->straightLane);
    printf("\nWest Roadway Left Lane:\n");
    queue_display(intersection->westRoadway->leftLane);

    printf("###############################################################\n");
}

void intersection_addVehicle(Intersection* intersection, Vehicle* vehicle, const char* startRoad, const char* direction)
{
    if(strcmp(direction, "left") == 0)
    {
        if(strcmp(startRoad, "north") == 0)
        {
            queue_push(intersection->northRoadway->leftLane, vehicle, direction);
        }
        else if(strcmp(startRoad, "east") == 0)
        {
            queue_push(intersection->eastRoadway->leftLane, vehicle, direction);
        }
        else if(strcmp(startRoad, "south") == 0)
        {
            queue_push(intersection->southRoadway->leftLane, vehicle, direction);
        }
        else if(strcmp(startRoad, "west") == 0)
        {
            queue_push(intersection->westRoadway->leftLane, vehicle, direction);
        }
    }
    else
    {
        if(strcmp(startRoad, "north") == 0)
        {
            queue_push(intersection->northRoadway->straightLane, vehicle, direction);
        }
        else if(strcmp(startRoad, "east") == 0)
        {
            queue_push(intersection->eastRoadway->straightLane, vehicle, direction);
        }
        else if(strcmp(startRoad, "south") == 0)
        {
            queue_push(intersection->southRoadway->straightLane, vehicle, direction);
        }
        else if(strcmp(startRoad, "west") == 0)
        {
            queue_push(intersection->westRoadway->straightLane, vehicle, direction);
        }
    }
}