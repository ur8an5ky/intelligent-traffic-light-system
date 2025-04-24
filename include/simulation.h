#pragma once

#include "intersection.h"

typedef struct {
    Intersection* intersection;
    double currentTime;
    double timeStep;
    Queue* leftVehicles;
    int leftVehiclesCount;
} Simulation;

Simulation* createSimulation();
void destroySimulation(Simulation* simulation);
char* runSimulation(Simulation* simulation, const char* line);
char* generateStepStatusJSON(Simulation* simulation);
void displaySimulationState(const Simulation* simulation);
void stepNorthSouth(Simulation* simulation);
void stepEastWest(Simulation* simulation);
void clearConsole();