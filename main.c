#include <stdio.h>
#include <stdlib.h>
#include "intersection.h"
#include "roadway.h"

// main do testowania Intersection
int main() {
    // Tworzymy skrzyżowanie
    Intersection* myIntersection = createIntersection();
    
    if (myIntersection == NULL) {
        fprintf(stderr, "Failed to create Intersection\n");
        return 1;
    }

    // Wyświetlamy początkowy stan skrzyżowania
    printf("Initial empty Intersection:\n");
    displayIntersection(myIntersection);

    // Tworzymy kilka pojazdów
    Vehicle* vehicle1 = createVehicle("vehicle1", "ABC123");
    Vehicle* vehicle2 = createVehicle("vehicle2", "XYZ789");
    Vehicle* vehicle3 = createVehicle("vehicle3", "DEF456");
    Vehicle* vehicle4 = createVehicle("vehicle4", "GHI012");
    Vehicle* vehicle5 = createVehicle("vehicle5", "ABC123");
    Vehicle* vehicle6 = createVehicle("vehicle6", "XYZ789");
    Vehicle* vehicle7 = createVehicle("vehicle7", "DEF456");
    Vehicle* vehicle8 = createVehicle("vehicle8", "GHI012");

    // Dodajemy pojazdy do różnych dróg w ramach skrzyżowania
    enqueue(myIntersection->northRoadway->straightLane, vehicle1);
    enqueue(myIntersection->northRoadway->straightLane, vehicle2);
    enqueue(myIntersection->northRoadway->straightLane, vehicle3);
    enqueue(myIntersection->eastRoadway->straightLane, vehicle4);
    enqueue(myIntersection->southRoadway->straightLane, vehicle5);
    enqueue(myIntersection->southRoadway->straightLane, vehicle6);
    enqueue(myIntersection->westRoadway->straightLane, vehicle7);
    enqueue(myIntersection->westRoadway->straightLane, vehicle8);

    // Wyświetlamy stan skrzyżowania po dodaniu pojazdów
    printf("\nIntersection after adding vehicles:\n");
    displayIntersection(myIntersection);

    // Niszczymy skrzyżowanie, zwalniając zasoby
    destroyIntersection(myIntersection);

    return 0;
}