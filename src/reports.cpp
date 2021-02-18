// =================================================
// Name: Ryan Hellwege
// Date: 27 Jan, 2021
// Professor: Jeff Barnett
// Assignment A(.5)
// Program Name: reportsmenu.cpp
// ------------------------------------------------
// Algorithim:
// Step 1: output options
// Step 2: allow the user to input a number
// =================================================

#include "../include/Serendipity.h"

// stub functions:
void repListing() {
    cout << "You chose Inventory Listing."<< endl;
    pause();
}
void repWholesale() {
    cout << "You chose Wholesale value."<< endl;
    pause();
}
void repRetail() {
    cout << "You chose retail."<< endl;
    pause();
}
void repCost() {
    cout << "You chose cost."<< endl;
    pause();
} 
void repQty() {
    cout << "You chose quantity."<< endl;
    pause();
}
void repAge() {
    cout << "You chose age."<< endl;
    pause();
}

// Function: reports - allows the user to choose a function to display reports
// pre-condition: navigated to from mainmenu.
// post-condition: navigation.
void reports() 
{
    char choice;
    bool exitmenu = false;

    do {
        system("clear");
        cout << "-------------------------------------------" << endl;
        cout << "|          Serendipity Booksellers        |" << endl;
        cout << "|                  Reports                |" << endl;
        cout << "|                                         |" << endl;
        cout << "|      1. Inventory Listing               |" << endl;
        cout << "|      2. Inventory Wholesale Value       |" << endl;
        cout << "|      3. Inventory Retail Value          |" << endl;
        cout << "|      4. Inventory Quantity              |" << endl;
        cout << "|      5. Listing by Cost                 |" << endl;
        cout << "|      6. Listing by Age                  |" << endl;
        cout << "|      7. Return to the Main Menu         |" << endl;
        cout << "-------------------------------------------" << endl << endl;
        cout << "            Enter Your Choice: ";

        cin >> choice;
        switch (choice) {
            case '1':
                repListing();
                break;
            case '2':
                repWholesale();
                break;
            case '3':
                repRetail();
                break;
            case '4':
                repQty();
                break;
            case '5':
                repCost();
                break;
            case '6':
                repAge();
                break;
            case '7':
                exitmenu = true;
                break;
            default:
                cout << "\nPlease enter a number in the range 1-7." << endl;
                pause();
        }
    } while (!exitmenu);
}