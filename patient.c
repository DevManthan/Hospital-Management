#include <stdio.h>
#include <stdlib.h>
#include "headers/queue.h"
#include "headers/patient.h"

static Patient* head = NULL;

void admit()
{
    Patient *newPatient = (Patient *)malloc(sizeof(Patient));
    if (newPatient == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter Patient ID: ");
    scanf("%d", &newPatient->id);

    printf("Enter Patient Name: ");
    scanf(" %49[^\n]", newPatient->name);

    printf("Enter Condition: ");
    scanf(" %49[^\n]", newPatient->condition);

    printf("Enter Priority (1-Critical, 2-Serious, 3-Normal): ");
    scanf("%d", &newPatient->priority);

    newPatient->next = NULL;

    push(&head, newPatient);

    printf("Patient admitted successfully!\n");
}

void treat()
{
    pop(&head);
    printf("Treat Function\n");
}
