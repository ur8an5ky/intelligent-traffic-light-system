#pragma once

typedef struct {
    char id[12];
    // char registrationPlate[9];
    char endRoad[6];
} Vehicle;

Vehicle* vehicle_create(const char* id, /*const char* registrationPlate,*/ const char* destination);
void vehicle_destroy(Vehicle* vehicle);
void vehicle_displayInfo(Vehicle* vehicle);