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

// void updateRoadwayState(Roadway* roadway)

void displayRoadway(const Roadway* roadway)
{
    if(roadway == NULL)
    {
        printf("Roadway is emoty\n");
        return;
    }

    printf("Roadway Information:\n");
    printf("--------------------\n");

    printf("Straight Lane:\n");
    printf("\tQueue size: %d\n", roadway->straightLane->size);
    displayQueue(roadway->straightLane);

    printf("\nTraffic Lights:\n");
    displayTrafficLightsInfo(roadway->straightLights);

    printf("--------------------\n");
}