#include <stdio.h>
#include <stdlib.h>
#include "headers/patient.h"
#include "headers/queue.h"
#include "headers/report.h"

int main()
{
    char ch;

    while (1)
    {

        system("cls");

        printf("\n================================================\n");
        printf("  HOSPITAL EMERGENY PRIORLTY MANAGEMENT SYSTEM\n");
        printf("================================================\n");
        printf("Enter your Choice : \n");
        printf("1. Admit New Patient \n");
        printf("2. Treat New Patient \n");
        printf("3. View Current Queue\n");
        printf("4. Search Patient by ID\n");
        printf("5. Hospital Daily Analytics\n");
        printf("6. Exit\n");
        printf("------------------------------------\n");
        printf("Choice : ");

        if (scanf("%d", &ch) != 1)
        {
            while (getchar() != '\n');    
            ch = -1; 
        }
        printf("------------------------------------\n");

        switch (ch)
        {
        case 1:    
            admit();
            break;
        case 2:
            treat();
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        case 5:
            analysis();
            break;
        case 6:
            printf("\n----------------EXIT----------------\n");
        exit(0);
            break;
        default:
            printf("\n-----------INVALID INPUT------------\n");
            break;
        }
        printf("\n");
        system("pause");
    }
    return 0;
}
