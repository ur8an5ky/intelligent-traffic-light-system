#include "simulation.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Simulation* simulation = createSimulation();

    Vehicle* vehicle1 = createVehicle("vehicle1", "ABC123QW", "south");
    Vehicle* vehicle2 = createVehicle("vehicle2", "XYZ789AE", "north");
    Vehicle* vehicle3 = createVehicle("vehicle3", "LMN456GG", "west");
    Vehicle* vehicle4 = createVehicle("vehicle4", "QRS678FF", "east");
    Vehicle* vehicle5 = createVehicle("vehicle5", "ABC0P123", "south");
    Vehicle* vehicle6 = createVehicle("vehicle6", "XYZWE789", "north");
    Vehicle* vehicle7 = createVehicle("vehicle7", "LMNKR456", "west");
    Vehicle* vehicle8 = createVehicle("vehicle8", "QRSLL678", "east");
    Vehicle* vehicle9 = createVehicle("vehicle9", "ABCW123W", "south");
    Vehicle* vehicle10 = createVehicle("vehicle10", "XYZT7T89", "north");
    Vehicle* vehicle11 = createVehicle("vehicle11", "LMN4Y5Y6", "west");
    Vehicle* vehicle12 = createVehicle("vehicle12", "QRS67UI8", "east");

    addVehicleToIntersection(simulation->intersection, vehicle1, "north", "south");
    addVehicleToIntersection(simulation->intersection, vehicle2, "south", "north");
    addVehicleToIntersection(simulation->intersection, vehicle3, "east", "west");
    addVehicleToIntersection(simulation->intersection, vehicle4, "west", "east");
    addVehicleToIntersection(simulation->intersection, vehicle5, "north", "east");
    addVehicleToIntersection(simulation->intersection, vehicle6, "south", "west");
    addVehicleToIntersection(simulation->intersection, vehicle7, "east", "south");    
    addVehicleToIntersection(simulation->intersection, vehicle8, "west", "north");
    addVehicleToIntersection(simulation->intersection, vehicle9, "north", "west");
    addVehicleToIntersection(simulation->intersection, vehicle10, "south", "east");
    addVehicleToIntersection(simulation->intersection, vehicle11, "east", "north");    
    addVehicleToIntersection(simulation->intersection, vehicle12, "west", "south");

    runSimulation(simulation, 30.0);

    destroySimulation(simulation);
    return 0;
}