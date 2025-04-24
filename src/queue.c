#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue* createQueue()
{
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    if(newQueue == NULL)
    {
        return NULL;
    }
    
    initialize_queue(newQueue);
    return newQueue;
}

void destroyQueue(Queue* q)
{
    if(q == NULL)
    {
        return;
    }

    while(!isEmpty(q))
    {
        Vehicle* vehicle = dequeue(q);
        destroyVehicle(vehicle);
    }

    free(q);
}

void initialize_queue(Queue* q)
{
    q->front = NULL;
    q->back = NULL;
    q->size = 0;
}

bool isEmpty(Queue* q)
{
    return q->size == 0;
}

void enqueue(Queue* q, Vehicle* v, const char* destination)
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

    if(q->front == NULL)
    {
        q->front = q->back = newNode;
    }
    else
    {
        q->back->next = newNode;
        q->back = newNode;
    }

    q->size++;
}

Vehicle* dequeue(Queue* q)
{
    if(isEmpty(q))
    {
        return NULL;
    }

    Node* tempNode = q->front;
    Vehicle* tempVehicle = tempNode->data;
    q->front = q->front->next;

    if(q->front == NULL)
    {
        q->back = NULL;
    }

    free(tempNode);

    q->size--;

    return tempVehicle;
}

void displayQueue(Queue* q)
{
    Node* tempNode = q->front;
    printf("{  ");
    while(tempNode)
    {
        displayInfo(tempNode->data);
        tempNode=tempNode->next;
    }
    printf("  }");
}