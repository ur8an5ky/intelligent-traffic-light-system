#include "roadway.h"
#include <stdio.h>
#include <stdlib.h>

Roadway* createRoadway()
{
    Roadway* newRoadway = (Roadway*)malloc(sizeof(Roadway));

    if(newRoadway == NULL)
    {
        return NULL;
    }

    newRoadway->straightLane = NULL;
    newRoadway->straightLights = NULL;

    initializeRoadway(newRoadway);

    return newRoadway;
}

void destroyRoadway(Roadway* roadway)
{
    if(roadway == NULL)
    {
        return;
    }

    destroyQueue(roadway->straightLane);
    destroyTrafficLights(roadway->straightLights);
    free(roadway);
}

void initializeRoadway(Roadway* roadway)
{
    if(roadway == NULL)
    {
        return;
    }

    roadway->straightLane = createQueue();
    roadway->straightLights = createTrafficLights();
}

void displayRoadway(const Roadway* roadway)
{
    if(roadway == NULL)
    {
        return;
    }

    // printf("Roadway Information:\n");
    // printf("--------------------\n");

    // printf("Straight Lane:\n");
    displayQueue(roadway->straightLane);
    printf("\tSize: %d\n", roadway->straightLane->size);

    // printf("\nTraffic Lights:\n");
    // displayTrafficLightsInfo(roadway->straightLights);

    // printf("--------------------\n");
}