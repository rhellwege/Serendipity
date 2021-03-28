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

const int RESULTS_PER_PAGE = 10;

// stub functions:
void repListing(bookType* books[]) {
    int i = 0;
    while (i < 20000) {
        cout << i << endl;
        i++;
        if (key_is_pressed(XK_Q)) {
            exit(0);
        }
    }
}
void repWholesale(bookType* books[]) {
    cout << "You chose Wholesale value."<< endl;
    pause();
}
void repRetail(bookType* books[]) {
    cout << "You chose retail."<< endl;
    pause();
}
void repCost(bookType* books[]) {
    cout << "You chose cost."<< endl;
    pause();
} 
void repQty(bookType* books[]) {
    cout << "You chose quantity."<< endl;
    pause();
}
void repAge(bookType* books[]) {
    cout << "You chose age."<< endl;
    pause();
}

// Function: reports - allows the user to choose a function to display reports
// pre-condition: navigated to from mainmenu.
// post-condition: navigation.
void reports(bookType* books[]) 
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
                repListing(books);
                break;
            case '2':
                repWholesale(books);
                break;
            case '3':
                repRetail(books);
                break;
            case '4':
                repQty(books);
                break;
            case '5':
                repCost(books);
                break;
            case '6':
                repAge(books);
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