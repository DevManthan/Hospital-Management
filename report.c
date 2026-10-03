#include <stdio.h>
#include <stdlib.h>
#include "headers/report.h"

void analysis(Patient *head)
{

    Patient *curr = head;
    int critical = 0, serious = 0, normal = 0;

    if (curr == NULL) // checks for empty linkedlist
    {
        printf("---NO PATIENT---");
        return;
    }

    while (curr != NULL)
    {

        if (curr->priority == 1)
        {
            critical++;
        }
        else if (curr->priority == 2)
        {
            serious++;
        }
        else
        {
            normal++;
        }
        curr = curr->next;
    }

    printf("\n================================================================\n");
    printf("                    DAILY HOSPITAL REPORT                       \n");
    printf("================================================================\n");
    printf(" Total Active Patients in Queue : %d\n", (critical + serious + normal));
    printf("----------------------------------------------------------------\n");
    printf(" [TRIAGE BREAKDOWN]\n");
    printf("  - Critical (Priority 1)       : %d\n", critical);
    printf("  - Serious  (Priority 2)       : %d\n", serious);
    printf("  - Normal   (Priority 3)       : %d\n", normal);
    printf("----------------------------------------------------------------\n");

    if (head != NULL)
    {
        printf(" Next Patient to Attend        : [ID: %d] %s\n", head->id, head->name);
    }
    else
    {
        printf(" Status                         : Queue is currently empty\n");
    }

    printf("================================================================\n\n");
}