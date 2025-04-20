#include <stdio.h>
#include <stdlib.h>
#include "vehicle.h"
#include "queue.h"

int main() {
    Queue* queue = (Queue *)malloc(sizeof(Queue));
    initialize_queue(queue);

    enqueue(queue, createVehicle("vehicle1", "ABC123"));
    enqueue(queue, createVehicle("vehicle2", "DEF456"));
    enqueue(queue, createVehicle("vehicle3", "GHI789"));

    printf("After adding vehicles (now there are %d of them):\n", queue->size);
    displayQueue(queue);

    Vehicle* dequeued = dequeue(queue);
    if (dequeued)
    {
        printf("\nVehicle removed: %s\n", dequeued->registrationPlate);
        free(dequeued);
    }

    printf("\nAfter removing first vehicle (now there are %d of them):\n", queue->size);
    displayQueue(queue);

    enqueue(queue, createVehicle("vehicle4", "JKL012"));

    printf("\nAfter adding another vehicle (now there are %d of them):\n", queue->size);
    displayQueue(queue);

    while (!isEmpty(queue))
    {
        Vehicle* vehicle = dequeue(queue);
        destroyVehicle(vehicle);
    }

    free(queue);

    return 0;
}