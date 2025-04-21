#include <stdio.h>
// #include <stdlib.h>
#include "traffic_lights.h"

int main()
{
    TrafficLights lights;

    initializeTrafficLights(&lights);

    printf("Initial states:\n");
    displayTrafficLightsInfo(&lights);

    updateTrafficLightState(lights.greenLight);
    // updateTrafficLightState(lights.yellowLight);
    // updateTrafficLightState(lights.redLight);

    printf("\nAfter updating the states:\n");
    displayTrafficLightsInfo(&lights);

    destroyTrafficLights(&lights);

    return 0;
}