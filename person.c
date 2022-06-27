#include "person.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Person* createPerson(int src, int dest){
    Person* p = malloc(sizeof(Person));
    (*p).src = src;
    (*p).dest = dest;
    return p;
};

PersonList* insert(Person *p, PersonList *list){
    PersonList* pl = malloc(sizeof(PersonList));
    (*pl).person = p;
    (*pl).next = list;
    return pl;
};

/*int main(){
    Person* pers1 = createPerson(0, 3);
    Person* pers2 = createPerson(1, 0);
    PersonList* l = NULL;
    l = insert(pers1, l);
    l = insert(pers2, l);
    printf("1ere pers : dest = %d et src = %d\n2eme pers : dest = %d et src = %d\n", l->person->dest, l->person->src, l->next->person->dest, l->next->person->src);

    return 0;
};*/