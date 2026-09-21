#include <stdio.h>
#include <stdlib.h>
#include "headers/queue.h"

void push(Patient **head, Patient *newPatient)
{
    if (*head == NULL || newPatient->priority < (*head)->priority) // if list is empty or the priority of new patient is superior, push directly
    {
        newPatient->next = *head;
        *head = newPatient;
    }
    else
    {
        Patient *temp = *head;

        while (temp->next != NULL && temp->next->priority <= newPatient->priority) // finds the perfect priority to push the new patient
        {
            temp = temp->next;
        }
        newPatient->next = temp->next;
        temp->next = newPatient; // inserts the new patient node
    }
}

int pop(Patient **head)
{

    if (*head == NULL) // checks if linkedlist is empty
    {
        return -1;
    }

    Patient *temp = *head;
    printf("Treated Patient Details : \n");
    printf("ID : %d\n", (temp)->id);
    printf("Name : %s\n", (temp)->name);
    printf("Condition : %s\n", (temp)->condition);

    *head = (*head)->next;

    free(temp); // removes the treated patient data from memory space

    return 0;
}

Patient *search(Patient *head, int id)
{
    while (head != NULL)
    { // loops till the end of list
        if (head->id == id)
        { // if found return the node
            return head;
        }
        head = head->next;
    }
    return NULL; // else return null
}

void display(Patient *head)
{
    Patient *curr = head;

    if (curr == NULL) // checks for empty linkedlist
    {
        printf("---NO PATIENT---");
        return;
    }

    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Condition", "Priority");
    printf("----------------------------------------------------------------\n");
    while (curr != NULL) // loops till the end of linkedlist
    {
        char *priorityStr;

    if (curr->priority == 1)
    {
        priorityStr = "Critical";
    }
    else if (curr->priority == 2)
    {
        priorityStr = "Serious";
    }
    else if (curr->priority == 3)
    {
        priorityStr = "Normal";
    }
    else
    {
        priorityStr = "Unknown";
    }
        printf("%-10d %-20s %-20s %-10s\n", curr->id, curr->name, curr->condition, priorityStr);

        curr = curr->next; // moves pointer to the next node
    }
}