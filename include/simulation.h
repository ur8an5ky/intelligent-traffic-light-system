#pragma once

#include "intersection.h"

typedef struct {
    Intersection* intersection;
    double currentTime;
    double timeStep;
    Queue* leftVehicles;
    int leftVehiclesCount;
} Simulation;

Simulation* simulation_create();
void simulation_destroy(Simulation* simulation);
char* simulation_run(Simulation* simulation, const char* line);
char* simulation_generateStepStatusJSON(Simulation* simulation);
void simulation_displayState(const Simulation* simulation);
void simulation_stepNorthSouth(Simulation* simulation);
void simulation_stepEastWest(Simulation* simulation);
void simulation_clearConsole();