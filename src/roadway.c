#include "roadway.h"
#include <stdio.h>
#include <stdlib.h>

Roadway* roadway_create()
{
    Roadway* newRoadway = (Roadway*)malloc(sizeof(Roadway));

    if(newRoadway == NULL)
    {
        return NULL;
    }

    newRoadway->straightLane = NULL;
    newRoadway->straightLights = NULL;

    roadway_initialize(newRoadway);

    return newRoadway;
}

void roadway_destroy(Roadway* roadway)
{
    if(roadway == NULL)
    {
        return;
    }

    queue_destroy(roadway->straightLane);
    trafficLights_destroy(roadway->straightLights);

    queue_destroy(roadway->leftLane);
    trafficLights_destroy(roadway->leftLights);
    free(roadway);
}

void roadway_initialize(Roadway* roadway)
{
    if(roadway == NULL)
    {
        return;
    }

    roadway->straightLane = queue_create();
    roadway->straightLights = trafficLights_create();

    roadway->leftLane = queue_create();
    roadway->leftLights = trafficLights_create();
}

void roadway_displayInfo(const Roadway* roadway)
{
    if(roadway == NULL)
    {
        return;
    }

    queue_display(roadway->straightLane);
    printf("\tSize: %d\n", roadway->straightLane->size);
    queue_display(roadway->leftLane);
    printf("\tSize: %d\n", roadway->leftLane->size);
}