#include <stdio.h>
#include <stdlib.h>
#include "headers/patient.h"
#include "headers/queue.h"

void admit(){

    push();
    printf("Admit Function\n");
}

void treat(){
    pop();
    printf("Treat Function\n");
}

void searchByID(){
    search();
    printf("Got patient\n");
}