#include <stdio.h>
#include <stdlib.h>
#include "headers/queue.h"

void push(Patient **head, Patient *newPatient)
{
    if (*head == NULL || newPatient->priority < (*head)->priority)
    {
        newPatient->next = *head;
        *head = newPatient;
    }
    else
    {
        Patient *temp = *head;

        while (temp->next != NULL && temp->next->priority <= newPatient->priority)
        {
            temp = temp->next;
        }
        newPatient->next = temp->next;
        temp->next = newPatient;
    }
}

int pop(Patient **head)
{

    if (*head == NULL)
    {
        return -1;
    }

    Patient *temp = *head;
    printf("Treated Patient Details : \n");
    printf("ID : %d\n", (temp)->id);
    printf("Name : %s\n", (temp)->name);
    printf("Condition : %s\n", (temp)->condition);

    *head = (*head)->next;

    free(temp);

    return 0;
}

void search()
{
    printf("Patient Searched\n");
}

void display(Patient *head)
{
    Patient *curr = head;

    if (curr == NULL)
    {
        printf("---NO PATIENT---");
        return;
    }

    char *priorityStr;

    if (curr->priority == 1)
    {
        priorityStr = "Critical🥵";
    }
    else if (curr->priority == 2)
    {
        priorityStr = "Serious😰";
    }
    else if (curr->priority == 3)
    {
        priorityStr = "Normal😷";
    }
    else
    {
        priorityStr = "Unknown";
    }
    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Condition", "Priority");
    printf("----------------------------------------------------------------\n");
    while (curr != NULL)
    {
        printf("%-10d %-20s %-20s %-10s\n", curr->id, curr->name, curr->condition, priorityStr);

        curr = curr->next;
    }
}