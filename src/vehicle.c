#include "vehicle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vehicle* createVehicle(const char* id, const char* registrationPlate, const char* destination)
{
    Vehicle* newVehicle = malloc(sizeof(Vehicle));
    if(newVehicle == NULL)
    {
        return NULL;
    }

    strncpy(newVehicle->id, id, sizeof(newVehicle->id) - 1);
    strncpy(newVehicle->registrationPlate, registrationPlate, sizeof(newVehicle->registrationPlate) - 1);
    strncpy(newVehicle->endRoad, destination, sizeof(newVehicle->endRoad) - 1);
    
    newVehicle->id[sizeof(newVehicle->id) - 1] = '\0';
    newVehicle->registrationPlate[sizeof(newVehicle->registrationPlate) - 1] = '\0';
    newVehicle->endRoad[sizeof(newVehicle->endRoad) - 1] = '\0';

    return newVehicle;
}

void destroyVehicle(Vehicle* vehicle)
{
    if(vehicle == NULL)
    {
        return;
    }

    free(vehicle);
}

void displayInfo(Vehicle* vehicle)
{
    printf("[id=%s and registration number:%s]; ", vehicle->id, vehicle->registrationPlate);
}