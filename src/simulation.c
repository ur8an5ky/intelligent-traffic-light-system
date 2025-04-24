#include "simulation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <jansson.h>

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
    newSimulation->leftVehicles = createQueue();

    return newSimulation;
}

void destroySimulation(Simulation* simulation)
{
    if(simulation == NULL)
    {
        return;
    }

    destroyQueue(simulation->leftVehicles);
    destroyIntersection(simulation->intersection);
    free(simulation);
}

char* runSimulation(Simulation* simulation, const char* line)
{
    static json_t *stepStatuses = NULL;

    if(stepStatuses == NULL)
    {
        stepStatuses = json_array();
    }

    if(line == NULL)
    {
        json_t *root = json_object();
        json_object_set_new(root, "stepStatuses", stepStatuses);

        char *final_json = json_dumps(root, JSON_INDENT(2));
        json_decref(root);
        stepStatuses = NULL;

        return final_json;
    }

    if(strcmp(line, "Step") == 0)
    {
        stepNorthSouth(simulation);
        char *stepStatus = generateStepStatusJSON(simulation);
        free(stepStatus);
        simulation->currentTime += simulation->timeStep;

        stepEastWest(simulation);
        stepStatus = generateStepStatusJSON(simulation);
        json_array_append_new(stepStatuses, json_loads(stepStatus, 0, NULL));
        free(stepStatus);
        simulation->currentTime += simulation->timeStep;

        while(!isEmpty(simulation->leftVehicles))
        {
            Vehicle* vehicle = dequeue(simulation->leftVehicles);
            destroyVehicle(vehicle);
        }
    }
    else
    {
        char *vehicleId = strtok((char*)line, ",");
        char *startRoad = strtok(NULL, ",");
        char *endRoad = strtok(NULL, ",");

        if
        (vehicleId && startRoad && endRoad)
        {
            Vehicle* vehicle = createVehicle(vehicleId, endRoad);
            addVehicleToIntersection(simulation->intersection, vehicle, startRoad, endRoad);
        }
    }

    return NULL;
}

char* generateStepStatusJSON(Simulation* simulation) {
    json_t *root = json_object();
    json_t *leftVehicles = json_array();

    Node* tempNode = simulation->leftVehicles->front;
    while (tempNode) {
        json_array_append_new(leftVehicles, json_string(tempNode->data->id));
        tempNode = tempNode->next;
    }

    json_object_set_new(root, "leftVehicles", leftVehicles);

    char *json_string = json_dumps(root, JSON_INDENT(2));
    json_decref(root);

    return json_string;
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
        if(vehicle)
        {
            enqueue(simulation->leftVehicles, vehicle, "left");
            // printf("Vehicle %s left the intersection from north\n", vehicle->id);
        }
    }

    if(!isEmpty(simulation->intersection->southRoadway->straightLane))
    {
        Vehicle* vehicle = dequeue(simulation->intersection->southRoadway->straightLane);
        if(vehicle)
        {
            enqueue(simulation->leftVehicles, vehicle, "left");
            // printf("Vehicle %s left the intersection from south\n", vehicle->id);
        }
    }
}

void stepEastWest(Simulation* simulation)
{
    if(!isEmpty(simulation->intersection->eastRoadway->straightLane))
    {
        Vehicle* vehicle = dequeue(simulation->intersection->eastRoadway->straightLane);
        if(vehicle)
        {
            enqueue(simulation->leftVehicles, vehicle, "left");
            // printf("Vehicle %s left the intersection from east\n", vehicle->id);
        }
    }

    if (!isEmpty(simulation->intersection->westRoadway->straightLane))
    {
        Vehicle* vehicle = dequeue(simulation->intersection->westRoadway->straightLane);
        if (vehicle)
        {
            enqueue(simulation->leftVehicles, vehicle, "left");
            // printf("Vehicle %s left the intersection from west\n", vehicle->id);
        }
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