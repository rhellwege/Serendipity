// =================================================
// Name: Ryan Hellwege
// Date: 27 Jan, 2021
// Professor: Jeff Barnett
// Assignment A(0.5)
// Program Name: mainmenu.cpp
// ------------------------------------------------
// Algorithim:
// Step 1: output options
// Step 2: allow the user to input a number
// =================================================

#include "../include/Serendipity.h"

#include <iostream>
#include <string>

int main() {
    orderedLinkedList<bookType*> masterList;
    char choice;
    bool exitmenu = false;
    do {
        system("clear");
        cout << "-------------------------------------------" << endl;
        cout << "|          Serendipity Booksellers        |" << endl;
        cout << "|                 Main Menu               |" << endl;
        cout << "|                                         |" << endl;
        cout << "|      1. Cashier Module                  |" << endl;
        cout << "|      2. Inventory Database Module       |" << endl;
        cout << "|      3. Reports Module                  |" << endl;
        cout << "|      4. Exit                            |" << endl;
        cout << "-------------------------------------------" << endl << endl;
        cout << "           Enter Your Choice: ";
        
        cin >> choice;
        switch (choice) {
            case '1':
                cashier(masterList);
                break;
            case '2':
                invmenu(masterList);
                break;
            case '3':
                reports(masterList);
                break;
            case '4':
                exit(0);
                break;
            default:
                cout << "\nPlease enter a number in the range 1-4." << endl;
                wait();
        }
    } while (!exitmenu);
    return 0;
}