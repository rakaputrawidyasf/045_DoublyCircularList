// PROGRAM DOUBLE-CIRCULAR-LIST (DCL)
// Created by rakaputrawidyasf on 15/10/20.
// Main Program/Driver

// Global Libraries
#include <iostream>

// Namespaces
using namespace std;

// Local Libraries
#include "deklarasi_global.h"

int main(int argc, const char * argv[]) {
    // DEKLARASI LOKAL
    DoubleCirclist DCL;
    int options;

    // ALGORITMA
    cout << "==========PROGRAM DOUBLE-CIRCULAR-LIST==========" << endl;
    do {
        cout << "Menu:" << endl;
        cout << "1) Buat List baru" << endl;
        cout << "2) Keluar" << endl;
        cout << "Pilih menu (1/2): "; cin >> options;
        if(options == 1) {
            createNewList(&DCL);
            operationMenu(&DCL);
        } else {
            cout << "--------------------------------------------------" << endl;
            cout << "Keluar dari program!" << endl;
        }
    } while(options == 1);
    return 0;
}
