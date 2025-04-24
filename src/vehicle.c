#include "vehicle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vehicle* vehicle_create(const char* id, /*const char* registrationPlate,*/ const char* destination)
{
    Vehicle* newVehicle = (Vehicle*)malloc(sizeof(Vehicle));
    if(newVehicle == NULL)
    {
        return NULL;
    }

    strncpy(newVehicle->id, id, sizeof(newVehicle->id) - 1);
    newVehicle->id[sizeof(newVehicle->id) - 1] = '\0';

    strncpy(newVehicle->endRoad, destination, sizeof(newVehicle->endRoad) - 1);
    newVehicle->endRoad[sizeof(newVehicle->endRoad) - 1] = '\0';

    return newVehicle;
}

void vehicle_destroy(Vehicle* vehicle)
{
    if(vehicle == NULL)
    {
        return;
    }
    // printf("Destroyed vehicle: %s\n", vehicle->id);

    free(vehicle);
}

void vehicle_displayInfo(Vehicle* vehicle)
{
    printf("[id=%s and destination road:%s]; ", vehicle->id, vehicle->endRoad);
    // printf("[id=%s and registration number:%s]; ", vehicle->id, vehicle->registrationPlate);
}