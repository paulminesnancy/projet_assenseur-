#include "elevator.h"
#include "person.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons){
    Elevator* e = malloc(sizeof(Elevator));
    e -> capacity = capacity;
    e -> currentFloor = currentFloor;
    e -> persons = persons;
    return e;
};

Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists){
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
    e -> persons = rest;
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

void stepElevator(Building *b);

int main(){
    Person* pers1 = createPerson(0, 3);
    Person* pers2 = createPerson(1, 0);
    PersonList* l = NULL;
    l = insert(pers1, l);
    l = insert(pers2, l);
    Elevator* elev = create_elevator(2, 3, l);
    printf("les personnes dans l'ascensseur de base : ");
    affiche_perlist(elev -> persons);
    printf("ceux qui restent :");
    PersonList* out = exitElevator(elev); 
    affiche_perlist(elev -> persons);
    printf("ceux qui sortent");
    affiche_perlist(out);

    PersonList* waiting = NULL;
    Person* pers3 = createPerson(3, 1);
    Person* pers4 = createPerson(3, 2);
    waiting = insert(pers3, waiting);
    waiting = insert(pers4, waiting);
    printf("ceux qui attendent :");
    affiche_perlist(waiting);
    waiting = enterElevator(elev, waiting);
    printf("ceux qui attendent apres le passage de l'ascenseur :");
    affiche_perlist(waiting);
    printf("ceux qui sont dedans apres passage :");
    affiche_perlist(elev -> persons);

    return 0;
};