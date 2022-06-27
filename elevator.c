#include "elevator.h"

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons);
Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists);

PersonList* exitElevator(Elevator *e);
PersonList* enterElevator(Elevator *e, PersonList *list);
void stepElevator(Building *b);