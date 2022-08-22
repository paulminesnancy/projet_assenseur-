#ifndef PERSON_H
#define PERSON_H

typedef struct _Person {
    //a type person is defined by it's attributes src (where it comes from) and dest (where it goes) 
    int src;
    int dest;
} Person;

typedef struct _PersonList {
    // a type representing a list of person using a linked list structure
    Person *person;
    struct _PersonList *next;
} PersonList;

Person* createPerson(int src, int dest);
PersonList* insert(Person *p, PersonList *list);
void affiche_perlist(PersonList *pl);
int len_perlist(PersonList* pl);

#endif
