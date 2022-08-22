#include "person.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


Person* createPerson(int src, int dest){
    //initialize a type Person with attributes src and dest
    Person *p;
    p = (Person*)malloc(sizeof(Person));
    (*p).src = src;
    (*p).dest = dest;
    return p;
};

PersonList* insert(Person *p, PersonList *list){
    //add a type Person to a PersonList
    PersonList *pl;
    pl = (PersonList*)malloc(sizeof(PersonList));
    (*pl).person = p;
    (*pl).next = list;
    return pl;
};

void affiche_perlist(PersonList* pl){
    PersonList* actuel = pl;
    while (actuel != NULL) {
        printf("(src : %d, dest : %d) -> ", actuel -> person -> src, actuel -> person -> dest);
        actuel = actuel -> next;
    }
    printf("null\n");
};

int len_perlist(PersonList* pl){
    /*function that returns the length of a PersonList*/
    PersonList* actuel = pl;
    int len = 0;
    while (actuel != NULL) {
        len += 1;
        actuel = actuel -> next;
    }
    return len;
}

/* int main(){
    Person* pers1 = createPerson(0, 3);
    Person* pers2 = createPerson(1, 0);
    PersonList* l = NULL;
    l = insert(pers1, l);
    l = insert(pers2, l);
    affiche_perlist(l);
    printf("longueure : %d\n", len_perlist(l));
    return 0;
}; */