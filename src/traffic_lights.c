#include "traffic_lights.h"

#include <stdio.h>

TrafficLight greenLight;
TrafficLight yellowLight;
TrafficLight redLight;
const char* colorNames[] = {"green", "yellow", "red"/*, "greenArrow"*/};

void initializeTrafficLights()
{
    greenLight.color = GREEN;
    greenLight.isActive = 0;

    yellowLight.color = YELLOW;
    yellowLight.isActive = 0;

    redLight.color = RED;
    redLight.isActive = 0;
}

void updateTrafficLightState(TrafficLight* light)
{
    light->isActive = !light->isActive;
}

void displayTrafficLightInfo(const TrafficLight* light)
{
    printf("That traffic light's color is %s and it's %sactive\n", colorNames[light->color], light->isActive ? "" : "not");
}