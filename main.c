#include "roadway.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Roadway* myRoadway = createRoadway();
    if(myRoadway == NULL)
    {
        printf("Failed to create Roadway\n");
        return 1;
    }

    printf("Empty Roadway:\n");
    displayRoadway(myRoadway);

    Vehicle* vehicle1 = createVehicle("vehicle1", "ABC123");
    Vehicle* vehicle2 = createVehicle("vehicle2", "XYZ789");
    Vehicle* vehicle3 = createVehicle("vehicle3", "DEF456");

    enqueue(myRoadway->straightLane, vehicle1);
    enqueue(myRoadway->straightLane, vehicle2);
    enqueue(myRoadway->straightLane, vehicle3);

    printf("\nRoadway after adding vehicles:\n");
    displayRoadway(myRoadway);

    destroyRoadway(myRoadway);

    return 0;
}