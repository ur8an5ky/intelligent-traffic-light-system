#ifndef VEHICLE_H
#define VEHICLE_H

typedef struct {
    int id;
    char registration_plate[8];
} Vehicle;

Vehicle* create_vehicle(int wiek, float waga, const char* imie);
void destory_vehicle(Vehicle* vehicle);

#endif // VEHICLE_H