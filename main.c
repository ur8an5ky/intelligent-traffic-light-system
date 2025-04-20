#include <stdio.h>
#include "traffic_lights.h"

int main() {
    initializeTrafficLights();

    printf("Initial state:\n");
    displayTrafficLightInfo(&greenLight);
    displayTrafficLightInfo(&yellowLight);
    displayTrafficLightInfo(&redLight);

    printf("\nUpdating green light:\n");
    updateTrafficLightState(&greenLight);
    displayTrafficLightInfo(&greenLight);

    printf("\nUpdating red light:\n");
    updateTrafficLightState(&redLight);
    displayTrafficLightInfo(&redLight);

    return 0;
}