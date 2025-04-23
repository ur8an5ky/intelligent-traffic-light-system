#pragma once

typedef struct {
    char id[12];
    char registrationPlate[9];
    char endRoad[6];
} Vehicle;

Vehicle* createVehicle(const char* id, const char* registrationPlate, const char* destination);
void destroyVehicle(Vehicle* vehicle);
void displayInfo(Vehicle* vehicle);