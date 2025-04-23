#pragma once

#include "intersection.h"

typedef struct {
    Intersection* intersection;
    double currentTime;
    double timeStep;
    // char** leftVehicles;
    // int leftVehiclesCount;
} Simulation;

Simulation* createSimulation();
void destroySimulation(Simulation* simulation);
void runSimulation(Simulation* simulation, double duration);
void displaySimulationState(const Simulation* simulation);
void stepNorthSouth(Simulation* simulation);
void stepEastWest(Simulation* simulation);
char* generateStepStatusJSON(Simulation* simulation);
void clearConsole();