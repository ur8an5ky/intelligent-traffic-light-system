#include <stdio.h>
#include "vehicle.h"

int main() {
    Vehicle* vehicle1 = create_vehicle(123, "ABC1234S");
    display_info(vehicle1);

    Vehicle* vehicle2 = create_vehicle(456, "XYZ56U78");
    display_info(vehicle2);

    display_info(vehicle1);
    display_info(vehicle2);

    destory_vehicle(vehicle1);
    destory_vehicle(vehicle2);

    return 0;
}