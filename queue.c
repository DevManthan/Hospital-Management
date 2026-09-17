#include <stdio.h>
#include <stdlib.h>
#include "headers/queue.h"

void push(Patient** head, Patient* newPatient){
    if(*head == NULL ||newPatient -> priority < (*head) -> priority){
        newPatient -> next = *head;
        *head = newPatient;  
    }
    else{
        Patient* temp = *head;

        while(temp->next != NULL && temp->next->priority <= newPatient->priority){
           temp = temp -> next;
        }
        newPatient -> next = temp -> next;
        temp -> next = newPatient;
    }
}

void pop(){
    printf("Popped\n");
}

void search(){
    printf("Patient Searched\n");
}

void display(){
    printf("Displayed\n");
}