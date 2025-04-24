#include "traffic_lights.h"

#include <stdio.h>
#include <stdlib.h>

const char* colorNames[] = {"green", "yellow", "red"/*, "greenArrow"*/};

TrafficLights* trafficLights_create()
{
    TrafficLights* newLights = (TrafficLights*)malloc(sizeof(TrafficLights));
    if(newLights == NULL)
    {
        return NULL;
    }

    newLights->greenLight = (TrafficLight*)malloc(sizeof(TrafficLight));
    newLights->yellowLight = (TrafficLight*)malloc(sizeof(TrafficLight));
    newLights->redLight = (TrafficLight*)malloc(sizeof(TrafficLight));

    if(newLights->greenLight == NULL || newLights->yellowLight == NULL || newLights->redLight == NULL)
    {
        free(newLights->greenLight);
        free(newLights->yellowLight);
        free(newLights->redLight);
        free(newLights);
        return NULL;
    }

    trafficLights_initialize(newLights);
    return newLights;
}

void trafficLights_initialize(TrafficLights* lights)
{
    lights->greenLight->color = GREEN;
    lights->greenLight->isActive = 0;

    lights->yellowLight->color = YELLOW;
    lights->yellowLight->isActive = 0;

    lights->redLight->color = RED;
    lights->redLight->isActive = 0;
}

void trafficLights_update(TrafficLight* light)
{
    light->isActive = !light->isActive;
}

void trafficLights_displayInfo(const TrafficLights* lights)
{
    printf("That traffic light's color is %s and it's %sactive\n", colorNames[lights->greenLight->color], lights->greenLight->isActive ? "" : "not");
    printf("That traffic light's color is %s and it's %sactive\n", colorNames[lights->yellowLight->color], lights->yellowLight->isActive ? "" : "not");
    printf("That traffic light's color is %s and it's %sactive\n", colorNames[lights->redLight->color], lights->redLight->isActive ? "" : "not");
}

void trafficLights_destroy(TrafficLights* lights)
{
    if(lights == NULL)
    {
        return;
    }

    free(lights->greenLight);
    free(lights->yellowLight);
    free(lights->redLight);

    free(lights);
}