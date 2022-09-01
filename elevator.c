#include "elevator.h"
#include "person.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons){
    /*function generating an Elevator* with the input atribute*/
    Elevator* e = malloc(sizeof(Elevator));
    e -> capacity = capacity;
    e -> currentFloor = currentFloor;
    e -> persons = persons;
    return e;
};

Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists){
    /*ficntion that create a Building* with the input atribute*/""
    Building* b = malloc(sizeof(Building));
    b -> nbFloor = nbFloor; 
    b -> elevator = elevator;
    b -> waitingLists = waitingLists;
};

PersonList* exitElevator(Elevator *e){
    /*function that returns a PersonList pointer of people descending the elevator, others stay on it (in e -> persons)*/
    PersonList* actuel = e -> persons;
    PersonList* result = NULL;
    PersonList* rest = NULL;
    while (actuel != NULL) {
        if (actuel -> person -> dest == e-> currentFloor){
            result = insert(actuel -> person, result);
        }
        else {
            rest = insert(actuel -> person, rest);
        }
        actuel = actuel -> next;
    }
    //actuel PersonList is now used to invert rest PersonList
    while (rest != NULL) {
        actuel = insert(rest -> person, actuel);
        rest = rest -> next;
    }
    e -> persons = actuel;
    return result;
};

PersonList* enterElevator(Elevator *e, PersonList *list){
    /*function that returns a PersonList pointer of people remaining on the waiting list for the elevator, the PersonList of people in the elevator is so modified*/
    int place = e -> capacity - len_perlist(e -> persons);
    while ((place != 0) && (list != NULL)){
        e -> persons = insert(list -> person, e -> persons);
        place -= 1;
        list = list -> next;
    }
    return list; 
};

void stepElevator(Building *b){
    /*Person* pers_nul = createPerson(-1, -1);*/
    PersonList* out = NULL;
    /*out = insert(persnul, out);*/
    if (b -> elevator -> currentFloor == b -> elevator -> targetFloor){
        out = exitElevator(b -> elevator);
        (b -> waitingLists)[b -> elevator -> currentFloor] = enterElevator(b -> elevator, (b -> waitingLists)[b -> elevator -> currentFloor]);
        /*b -> elevator -> targetFloor = b -> elevator -> persons -> person -> dest;*/
    }
    else{
        if (b -> elevator -> currentFloor > b -> elevator -> targetFloor){
            b -> elevator -> currentFloor -= 1;
        }
        else {
            b -> elevator -> currentFloor += 1;
        }
    }
};