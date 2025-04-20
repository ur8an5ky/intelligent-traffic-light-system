#pragma once

typedef struct {
    char id[12];
    char registrationPlate[9];
} Vehicle;

Vehicle* createVehicle(const char* id, const char* registrationPlate);
void destroyVehicle(Vehicle* vehicle);
void displayInfo(Vehicle* vehicle);