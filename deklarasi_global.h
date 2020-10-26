// PROGRAM DOUBLE-CIRCULAR-LIST (DCL)
// Created by rakaputrawidyasf on 15/10/20.
// Declaraation Header

#ifndef INC_045_DOUBLYCIRCULARLIST_DEKLARASI_GLOBAL_H
#define INC_045_DOUBLYCIRCULARLIST_DEKLARASI_GLOBAL_H

// Global Libraries
#include <iostream>

// Namespaces
using namespace std;

// Local Libraries

// Global Definitions

// Global Declarations
struct Node{
    int value;
    struct Node* prev;
    struct Node* next;
};
typedef struct Node* DoubleCirclist;

// Procedure Declarations
void createNewList(DoubleCirclist *DCL);
void deleteList(DoubleCirclist *DCL);
void insertFirst(DoubleCirclist *DCL, int DAT);
void insertBefore(DoubleCirclist *DCL, int Search, int DAT);
void insertAfter(DoubleCirclist *DCL, int Search, int DAT);
void insertLast(DoubleCirclist *DCL, int DAT);
void removeFirst(DoubleCirclist *DCL, int *DAT);
void removeSelected(DoubleCirclist *DCL, int Search, int *DAT);
void removeLast(DoubleCirclist *DCL, int *DAT);
void printList(DoubleCirclist DCL);
void reversePrintList(DoubleCirclist DCL);
void operationMenu(DoubleCirclist *DCL);

// Function Declarations

#endif //INC_045_DOUBLYCIRCULARLIST_DEKLARASI_GLOBAL_H
