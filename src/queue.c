#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue* queue_create()
{
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    if(newQueue == NULL)
    {
        return NULL;
    }
    
    queue_initialize(newQueue);
    return newQueue;
}

void queue_destroy(Queue* queue)
{
    if(queue == NULL)
    {
        return;
    }

    while(!queue_isEmpty(queue))
    {
        Vehicle* vehicle = queue_pop(queue);
        vehicle_destroy(vehicle);
    }

    free(queue);
}

void queue_initialize(Queue* queue)
{
    queue->front = NULL;
    queue->back = NULL;
    queue->size = 0;
}

bool queue_isEmpty(Queue* queue)
{
    return queue->size == 0;
}

void queue_push(Queue* queue, Vehicle* v, const char* destination)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = NULL;

    if(strcmp(destination, "north") == 0)
    {
        newNode->endRoad = NORTH;
    }
    else if(strcmp(destination, "east") == 0)
    {
        newNode->endRoad = EAST;
    }
    else if(strcmp(destination, "south") == 0)
    {
        newNode->endRoad = SOUTH;
    }
    else if(strcmp(destination, "west") == 0)
    {
        newNode->endRoad = WEST;
    }
    else if(strcmp(destination, "left") == 0)
    {
        newNode->endRoad = LEFT;
    }
    else
    {
        return;
    }

    if(queue->front == NULL)
    {
        queue->front = queue->back = newNode;
    }
    else
    {
        queue->back->next = newNode;
        queue->back = newNode;
    }

    queue->size++;
}

Vehicle* queue_pop(Queue* queue)
{
    if(queue_isEmpty(queue))
    {
        return NULL;
    }

    Node* tempNode = queue->front;
    Vehicle* tempVehicle = tempNode->data;
    queue->front = queue->front->next;

    if(queue->front == NULL)
    {
        queue->back = NULL;
    }

    free(tempNode);

    queue->size--;

    return tempVehicle;
}

void queue_display(Queue* queue)
{
    Node* tempNode = queue->front;
    printf("{  ");
    while(tempNode)
    {
        vehicle_displayInfo(tempNode->data);
        tempNode=tempNode->next;
    }
    printf("  }");
}