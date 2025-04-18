#include "vehicle.h"
#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h> // strcpy

Vehicle* create_vehicle(int id, const char* registration_plate)
{
    Vehicle* new_vehicle = malloc(sizeof(Vehicle));

    new_vehicle->id = id;
    strcpy(new_vehicle->registration_plate, registration_plate); //strncpy if registration number can be larger
    new_vehicle->registration_plate[8]='\0';

    return new_vehicle;
}

void destory_vehicle(Vehicle* vehicle)
{
    free(vehicle);
}

void display_info(Vehicle* vehicle)
{
    printf("Vehicle of id=%d has the following registration number:%s\n", vehicle->id, vehicle->registration_plate);
}