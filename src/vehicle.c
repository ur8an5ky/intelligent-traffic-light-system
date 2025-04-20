#include "vehicle.h"
#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h> // strcpy

Vehicle* createVehicle(const char* id, const char* registrationPlate)
{
    Vehicle* newVehicle = malloc(sizeof(Vehicle));

    strcpy(newVehicle->id, id);
    strcpy(newVehicle->registrationPlate, registrationPlate); //strncpy?

    return newVehicle;
}

void destroyVehicle(Vehicle* vehicle)
{
    free(vehicle);
}

void displayInfo(Vehicle* vehicle)
{
    printf("Vehicle of id=%s has the following registration number:%s\n", vehicle->id, vehicle->registrationPlate);
}