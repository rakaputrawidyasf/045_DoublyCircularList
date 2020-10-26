// PROGRAM DOUBLE-CIRCULAR-LIST (DCL)
// Created by rakaputrawidyasf on 15/10/20.
// Local Procedures & Functions

// Global Libraries
#include <iostream>

// Namespaces
using namespace std;

// Local Libraries
#include "deklarasi_global.h"

// Procedures
void createNewList(DoubleCirclist *DCL) {
    // DEKLARASI LOKAL

    // ALGORITMA
    *DCL = (DoubleCirclist) new Node();
    *DCL = NULL;
}
void deleteList(DoubleCirclist *DCL) {
    // DEKLARASI GLOBAL
    DoubleCirclist Temp;

    // ALGORITMA
    if(*DCL == NULL) {
        return;
    } else {
        Temp = (*DCL);
        while((*DCL)->next != Temp) {
            *DCL = (*DCL)->next;
        }
        delete Temp;
    }
}
void insertFirst(DoubleCirclist *DCL, int DAT) {
    // DEKLARASI GLOBAL
    DoubleCirclist New, Last;

    // ALGORITMA
    New = new Node();
    New->value = DAT;
    if(*DCL == NULL) {
        New->prev = New;
        New->next = New->prev;
    } else {
        Last = (*DCL)->prev;
        New->prev = Last;
        New->next = (*DCL);
        (*DCL)->prev = New;
        Last->next = (*DCL)->prev;
    }
    *DCL = New;
}
void insertBefore(DoubleCirclist *DCL, int Search, int DAT) {
    // DEKLARASI GLOBAL
    DoubleCirclist New, NextNode;

    // ALGORITMA
    New = new Node();
    New->value = DAT;
    if(*DCL == NULL) {
        return;
    } else {
        NextNode = (*DCL);
        while(NextNode->prev != (*DCL) && NextNode->value != Search) {
            NextNode = NextNode->prev;
        }
        if(NextNode->value == Search) {
            New->prev = NextNode->prev;
            NextNode->prev = New;
            New->next = NextNode;
            New->prev->next = New;
        } else {
            return;
        }
    }
}
void insertAfter(DoubleCirclist *DCL, int Search, int DAT) {
    // DEKLARASI GLOBAL
    DoubleCirclist New, PrevNode;
    
    // ALGORITMA
    New = new Node();
    New->value = DAT;
    if(*DCL == NULL) {
        return;
    } else {
        PrevNode = (*DCL);
        while(PrevNode->next != (*DCL) && PrevNode->value != Search) {
            PrevNode = PrevNode->next;
        }
        if(PrevNode->value == Search) {
            New->next = PrevNode->next;
            PrevNode->next = New;
            New->prev = PrevNode;
            New->next->prev = New;
        } else {
            return;
        }
    }
}
void insertLast(DoubleCirclist *DCL, int DAT) {
    // DEKLARASI GLOBAL
    DoubleCirclist New, Last;

    // ALGORITMA
    New = new Node();
    New->value = DAT;
    if(*DCL == NULL) {
        New->prev = New;
        New->next = New->prev;
        *DCL = New;
    } else {
        Last = (*DCL)->prev;
        New->prev = Last;
        New->next = (*DCL);
        (*DCL)->prev = New;
        Last->next = (*DCL)->prev;
    }
}
void removeFirst(DoubleCirclist *DCL, int *DAT) {
    // DEKLARASI GLOBAL
    DoubleCirclist First;

    // ALGORITMA
    if(*DCL == NULL) {
        return;
    } else {
        if((*DCL)->next == (*DCL)) {
            *DAT = (*DCL)->value;
            delete (*DCL);
            *DCL = NULL;
        } else {
            First = (*DCL);
            *DCL = (*DCL)->next;
            (*DCL)->prev = First->prev;
            First->prev->next = (*DCL);
            *DAT = First->value;
            delete First;
        }
    }
}
void removeSelected(DoubleCirclist *DCL, int Search, int *DAT) {
    // DEKLARASI GLOBAL
    DoubleCirclist Selected, PrevNode;

    // ALGORITMA
    if(*DCL == NULL) {
        return;
    } else {
        if((*DCL)->value == Search) {
            removeFirst(&(*DCL), &(*DAT));
        } else {
            Selected = (*DCL);
            while(Selected->next != (*DCL) && Selected->value != Search) {
                PrevNode = Selected;
                Selected = Selected->next;
            }
            if(Selected->value == Search) {
                PrevNode->next = Selected->next;
                PrevNode->next->prev = PrevNode;
                *DAT = Selected->value;
                delete Selected;
            } else {
                return;
            }
        }
    }
}
void removeLast(DoubleCirclist *DCL, int *DAT) {
    // DEKLARASI GLOBAL
    DoubleCirclist Last;

    // ALGORITMA
    if(*DCL == NULL) {
        return;
    } else {
        if((*DCL)->next == (*DCL)) {
            *DAT = (*DCL)->value;
            delete (*DCL);
            *DCL = NULL;
        } else {
            Last = (*DCL)->prev;
            (*DCL)->prev = Last->prev;
            Last->prev->next = (*DCL);
            *DAT = Last->value;
            delete Last;
        }
    }
}
void printList(DoubleCirclist DCL) {
    // DEKLARASI GLOBAL
    DoubleCirclist Traversal;

    // ALGORITMA
    if(DCL == NULL) {
        return;
    } else {
        Traversal = DCL;
        do {
            cout << Traversal->value << "->";
            Traversal = Traversal->next;
        } while(Traversal != DCL);
        cout << endl;
    }
}
void reversePrintList(DoubleCirclist DCL) {
    // DEKLARASI GLOBAL
    DoubleCirclist Traversal;

    // ALGORITMA
    if(DCL == NULL) {
        return;
    } else {
        Traversal = DCL->prev;
        do {
            cout << Traversal->value << "->";
            Traversal = Traversal->prev;
        } while(Traversal != DCL->prev);
        cout << endl;
    }
}
void operationMenu(DoubleCirclist *DCL) {
    // DEKLARASI GLOBAL
    int DAT, Search;
    int options;

    // ALGORITMA
    do {
        cout << "--------------------------------------------------" << endl;
        cout << "Menu:" << endl;
        cout << "1) Insert di posisi pertama" << endl;
        cout << "2) Insert sebelum data terpilih" << endl;
        cout << "3) Insert setelah data terpilih" << endl;
        cout << "4) Insert di posisi terakhir" << endl;
        cout << "5) Remove data pertama" << endl;
        cout << "6) Remove data terpilih" << endl;
        cout << "7) Remove data terakhir" << endl;
        cout << "8) Tampilkan List" << endl;
        cout << "9) Tampilkan List (reversed)" << endl;
        cout << "10) Hapus list dan kembali ke menu utama" << endl;
        cout << "Pilih menu (1-10): "; cin >> options;
        switch(options) {
            case 1:
                cout << "--------------------------------------------------" << endl;
                cout << "Masukkan data: "; cin >> DAT;
                insertFirst(&(*DCL), DAT);
                break;
            case 2:
                cout << "--------------------------------------------------" << endl;
                cout << "Masukkan data yang sudah ada pada list: "; cin >> Search;
                cout << "Masukkan data baru: "; cin >> DAT;
                insertBefore(&(*DCL), Search, DAT);
                break;
            case 3:
                cout << "--------------------------------------------------" << endl;
                cout << "Masukkan data yang sudah ada pada list: "; cin >> Search;
                cout << "Masukkan data baru: "; cin >> DAT;
                insertAfter(&(*DCL), Search, DAT);
                break;
            case 4:
                cout << "--------------------------------------------------" << endl;
                cout << "Masukkan data: "; cin >> DAT;
                insertLast(&(*DCL), DAT);
                break;
            case 5:
                removeFirst(&(*DCL), &DAT);
                cout << "--------------------------------------------------" << endl;
                cout << "Data yang disingkirkan: " << DAT << endl;
                break;
            case 6:
                cout << "Masukkan data yang dipilih: "; cin >> Search;
                removeSelected(&(*DCL), Search, &DAT);
                cout << "--------------------------------------------------" << endl;
                cout << "Data yang disingkirkan: " << DAT << endl;
                break;
            case 7:
                removeLast(&(*DCL), &DAT);
                cout << "--------------------------------------------------" << endl;
                cout << "Data yang disingkirkan: " << DAT << endl;
                break;
            case 8:
                cout << "--------------------------------------------------" << endl;
                cout << "List dibuat:" << endl;
                printList(*DCL);
                break;
            case 9:
                cout << "--------------------------------------------------" << endl;
                cout << "List dibuat (reverse):" << endl;
                reversePrintList(*DCL);
                break;
            default:
                deleteList(&(*DCL));
                cout << "--------------------------------------------------" << endl;
                cout << "List didealokasi/dihapus!" << endl;
                cout << "--------------------------------------------------" << endl;
                break;
        }
    } while(options >= 1 && options < 10);
}

// Functions
