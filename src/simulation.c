#include "simulation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

Simulation* createSimulation()
{
    Simulation* newSimulation = (Simulation*)malloc(sizeof(Simulation));
    if(newSimulation == NULL)
    {
        return NULL;
    }

    newSimulation->intersection = createIntersection();
    newSimulation->currentTime = 0.0;
    newSimulation->timeStep = 1.0;

    return newSimulation;
}

void destroySimulation(Simulation* simulation)
{
    if(simulation == NULL)
    {
        return;
    }

    destroyIntersection(simulation->intersection);
    free(simulation);
}

void runSimulation(Simulation* simulation, double duration)
{
    double endTime = simulation->currentTime + duration;

    displaySimulationState(simulation);
    sleep(5);

    clearConsole();
    printf("North and South roads have green light.\n");
    stepNorthSouth(simulation);
    sleep(5);

    clearConsole();
    printf("East and West roads have green light.\n");
    stepEastWest(simulation);
    sleep(5);

    while(simulation->currentTime < endTime)
    {
        clearConsole();
        displaySimulationState(simulation);
        sleep(5);

        clearConsole();
        printf("North and South roads have green light.\n");
        stepNorthSouth(simulation);
        sleep(5);

        clearConsole();
        printf("East and West roads have green light.\n");
        stepEastWest(simulation);
        sleep(5);

        simulation->currentTime += 20.0;
    }

    clearConsole();
    displaySimulationState(simulation);
    sleep(5);
}

void displaySimulationState(const Simulation* simulation)
{
    printf("Simulation Time: %.2f seconds\n", simulation->currentTime);
    displayIntersection(simulation->intersection);
}

void stepNorthSouth(Simulation* simulation)
{
    if(!isEmpty(simulation->intersection->northRoadway->straightLane))
    {
        Vehicle* vehicle = dequeue(simulation->intersection->northRoadway->straightLane);
        printf("Vehicle %s left the intersection from north\n", vehicle->id);
        destroyVehicle(vehicle);
    }

    if(!isEmpty(simulation->intersection->southRoadway->straightLane))
    {
        Vehicle* vehicle = dequeue(simulation->intersection->southRoadway->straightLane);
        printf("Vehicle %s left the intersection from south\n", vehicle->id);
        destroyVehicle(vehicle);
    }
}

void stepEastWest(Simulation* simulation)
{
    if(!isEmpty(simulation->intersection->eastRoadway->straightLane))
    {
        Vehicle* vehicle = dequeue(simulation->intersection->eastRoadway->straightLane);
        printf("Vehicle %s left the intersection from east\n", vehicle->id);
        destroyVehicle(vehicle);
    }

    if(!isEmpty(simulation->intersection->westRoadway->straightLane))
    {
        Vehicle* vehicle = dequeue(simulation->intersection->westRoadway->straightLane);
        printf("Vehicle %s left the intersection from west\n", vehicle->id);
        destroyVehicle(vehicle);
    }
}

void clearConsole()
{
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // Linux
    #endif
}