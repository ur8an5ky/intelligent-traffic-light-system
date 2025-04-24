#include "simulation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <jansson.h>

Simulation* simulation_create()
{
    Simulation* newSimulation = (Simulation*)malloc(sizeof(Simulation));
    if(newSimulation == NULL)
    {
        return NULL;
    }

    newSimulation->intersection = intersection_create();
    newSimulation->currentTime = 0.0;
    newSimulation->timeStep = 1.0;
    newSimulation->leftVehiclesCount = 0;
    newSimulation->leftVehicles = queue_create();

    return newSimulation;
}

void simulation_destroy(Simulation* simulation)
{
    if(simulation == NULL)
    {
        return;
    }

    queue_destroy(simulation->leftVehicles);
    intersection_destroy(simulation->intersection);
    free(simulation);
}

char* simulation_run(Simulation* simulation, const char* line)
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
        simulation_stepNorthSouth(simulation);
        char *stepStatus = simulation_generateStepStatusJSON(simulation);
        free(stepStatus);
        simulation->currentTime += simulation->timeStep;

        simulation_stepEastWest(simulation);
        stepStatus = simulation_generateStepStatusJSON(simulation);
        json_array_append_new(stepStatuses, json_loads(stepStatus, 0, NULL));
        free(stepStatus);
        simulation->currentTime += simulation->timeStep;

        while(!queue_isEmpty(simulation->leftVehicles))
        {
            Vehicle* vehicle = queue_pop(simulation->leftVehicles);
            vehicle_destroy(vehicle);
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
            Vehicle* vehicle = vehicle_create(vehicleId, endRoad);
            intersection_addVehicle(simulation->intersection, vehicle, startRoad, endRoad);
        }
    }

    return NULL;
}

char* simulation_generateStepStatusJSON(Simulation* simulation) {
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

void simulation_displayState(const Simulation* simulation)
{
    printf("Simulation Time: %.2f seconds\n", simulation->currentTime);
    intersection_displayInfo(simulation->intersection);
}

void simulation_stepNorthSouth(Simulation* simulation)
{
    if(!queue_isEmpty(simulation->intersection->northRoadway->straightLane))
    {
        Vehicle* vehicle = queue_pop(simulation->intersection->northRoadway->straightLane);
        if(vehicle)
        {
            queue_push(simulation->leftVehicles, vehicle, "left");
            // printf("Vehicle %s left the intersection from north\n", vehicle->id);
        }
    }

    if(!queue_isEmpty(simulation->intersection->southRoadway->straightLane))
    {
        Vehicle* vehicle = queue_pop(simulation->intersection->southRoadway->straightLane);
        if(vehicle)
        {
            queue_push(simulation->leftVehicles, vehicle, "left");
            // printf("Vehicle %s left the intersection from south\n", vehicle->id);
        }
    }
}

void simulation_stepEastWest(Simulation* simulation)
{
    if(!queue_isEmpty(simulation->intersection->eastRoadway->straightLane))
    {
        Vehicle* vehicle = queue_pop(simulation->intersection->eastRoadway->straightLane);
        if(vehicle)
        {
            queue_push(simulation->leftVehicles, vehicle, "left");
            // printf("Vehicle %s left the intersection from east\n", vehicle->id);
        }
    }

    if (!queue_isEmpty(simulation->intersection->westRoadway->straightLane))
    {
        Vehicle* vehicle = queue_pop(simulation->intersection->westRoadway->straightLane);
        if (vehicle)
        {
            queue_push(simulation->leftVehicles, vehicle, "left");
            // printf("Vehicle %s left the intersection from west\n", vehicle->id);
        }
    }
}

void simulation_clearConsole()
{
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // Linux
    #endif
}