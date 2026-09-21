#include <stdio.h>
#include <stdlib.h>
#include "headers/queue.h"
#include "headers/patient.h"

static Patient* head = NULL;

void admit()
{
    Patient *newPatient = (Patient *)malloc(sizeof(Patient));//assigns memory to new node of linked list containng the patient structure
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

    newPatient->next = NULL;//next = null because its the only node (currently), so there is no next node after this

    push(&head, newPatient);

    printf("Patient admitted successfully!\n");
}

void treat()
{
    int result = pop(&head);//returns -1 if list is empty gives 0 if popped sucessfully
    if(result == -1){
        printf("NO PATIENT ADMITTED");
    }
    else{
        printf("Patient treated and discharged successfully.\n");
    }
}

void getPatient(int id)
{
    Patient *p = search(head, id);//give patient details if found , else gives null

    if (p == NULL)
    {
        printf("\n---PATIENT WITH ID %d NOT FOUND---\n", id);
        return;
    }

    char *priorityStr = (p->priority == 1) ? "Critical" :
                        (p->priority == 2) ? "Serious"  :
                        (p->priority == 3) ? "Normal"   : "Unknown";//converts priority numbers(1,2,3) to critical etc.. for better looks

    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Condition", "Priority");
    printf("----------------------------------------------------------------\n");
    printf("%-10d %-20s %-20s %-10s\n", p->id, p->name, p->condition, priorityStr);
}

void viewQueue() {
    display(head);//displays all patients
}