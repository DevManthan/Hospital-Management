#ifndef QUEUE_H
#define QUEUE_H
#include "patient.h"

void push(Patient **head, Patient *newPatient);

int pop(Patient **head);

Patient* search(Patient *head, int id);

void display(Patient *head);

#endif