#ifndef PATIENT_H
#define PATIENT_H

typedef struct Patient{
    int id;
    char name[100];
    char condition[50];
    int priority;
    struct Patient* next;
} Patient;

void admit();
void treat();

#endif