#include "queue.h"
#include <stdio.h>
#include <stdlib.h> // malloc, free

void initialize_queue(Queue* q)
{
    q->front = NULL;
    q->back = NULL;
    q->size = 0;
}

bool isEmpty(Queue* q)
{
    return q->size>0 ? 0 : 1;
}

void enqueue(Queue* q, Vehicle* v)
{
    Node* newNode = (Node *)malloc(sizeof(Node));
    // obsługa błedu alokacji?
    newNode->data = v;
    newNode->next = NULL;

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
    Vehicle* tempVehicle = (Vehicle *)malloc(sizeof(Vehicle));

    tempVehicle = tempNode->data;
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
    printf("The following vehicles are in a queue:\n");
    while(tempNode)
    {
        printf("\t");
        displayInfo(tempNode->data);
        tempNode=tempNode->next;
    }
    free(tempNode);
}