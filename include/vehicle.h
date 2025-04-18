#ifndef VEHICLE_H
#define VEHICLE_H

typedef struct {
    int id;
    char registration_plate[9];
} Vehicle;

Vehicle* create_vehicle(int id, const char* registration_plate);
void destory_vehicle(Vehicle* vehicle);
void display_info(Vehicle* vehicle);

#endif // VEHICLE_H