#include "intersection.h"
#include <stdio.h>
#include <stdlib.h>

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

// void updateIntersectionState(Intersection* intersection)

void displayIntersection(const Intersection* intersection)
{
    if(intersection == NULL)
    {
        return;
    }

    printf("Intersection Information:\n");
    printf("#####################\n");

    printf("North Roadway:\n");
    displayRoadway(intersection->northRoadway);
    printf("*********************\n");

    printf("East Roadway:\n");
    displayRoadway(intersection->eastRoadway);
    printf("*********************\n");

    printf("South Roadway:\n");
    displayRoadway(intersection->southRoadway);
    printf("*********************\n");

    printf("West Roadway:\n");
    displayRoadway(intersection->westRoadway);
    printf("*********************\n");

    printf("#####################\n");
}