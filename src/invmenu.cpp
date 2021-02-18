// =================================================
// Name: Ryan Hellwege
// Date: 27 Jan, 2021
// Professor: Jeff Barnett
// Assignment A(0.5)
// Program Name: invenu.cpp
// ------------------------------------------------
// Algorithim:
// Step 1: output options
// Step 2: allow the user to input a number
// =================================================

#include "../include/Serendipity.h"

void listall(const int recordCount, const BookData books[]) {
    int i;
    for (i = 0; i < recordCount; i++) {
        cout << i << endl;
        bookInfo(books[i]);
        cout << endl;
    }
    cin.ignore();
    cin.get();
}

// Function: lookupBook - allow the user to search through the database according to publisher, author, or title
// pre-condition: navigated to from invmenu, at least 1 record added, all parallel arrays are stored correctly and passed
// post-condition: bookinfo called on the search results.
int lookupBook(const int recordCount, const BookData books[]) {
    string searchTerm;
    int i;
    if (recordCount == 0)
        return -1;

    system("clear");
    cout << "---------------------------------------------" << endl;
    cout << "|           Serendipity Booksellers         |" << endl;
    cout << "|                Look Up Book               |" << endl;
    cout << "|                                           |" << endl;
    cout << "| There are " << setw(2)  << left << recordCount << " records available to search. |" << endl;
    cout << "---------------------------------------------" << endl << endl;
    cout << "Search: ";
    cin.ignore();
    getline(cin, searchTerm);
    // perform the search:
    for (i = 0; i < recordCount; i++) {
        if (searchInsensitive(books[i].bookTitle, searchTerm) || searchInsensitive(books[i].author, searchTerm) || searchInsensitive(books[i].publisher, searchTerm)) { // if the title contains the substring searchTerm (case insensitive)
            char choice;            
            system("clear");
            bookInfo(books[i]);
            cout << "\nSelect this item? (y/n): ";
            cin >> choice;
            if (tolower(choice) == 'y')
                return i; // exit out of lookupbook if the user found what they were looking for and dont continue the loop.
        }
    }
    return -1;
}

void deleteBook(int &recordCount, BookData books[]) {
    int deleteIndex = lookupBook(recordCount, books);
    char choice;
    if (deleteIndex == -1)  {
        cout << "Couldn't find that item. Try again." << endl;
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
        return;
    }
    // swap with last element
    cout << "WARNING: You are about to delete a record, are you sure you want to do that? (y/n): ";
    cin >> choice;
    if (tolower(choice) == 'y') {
        books[deleteIndex] = books[recordCount-1];
        recordCount--;
    }
}

// Function: invmenu - allow the user to use submomdules related to inventory
// pre-condition: navigated to from mainmenu.
// post-condition: navigation to a submenu.
void invmenu(int &recordCount, BookData books[]) {
    char choice;
    bool exitmenu = false;
    int recordIndex;
    
    do {
        system("clear");
        cout << "-------------------------------------------" << endl;
        cout << "|          Serendipity Booksellers        |" << endl;
        cout << "|            Inventory Database           |" << endl;
        cout << "|                                         |" << endl;
        cout << "|      1. Look Up a Book                  |" << endl;
        cout << "|      2. Add a Book                      |" << endl;
        cout << "|      3. Edit a Book's Record            |" << endl;
        cout << "|      4. Delete a Book                   |" << endl;
        cout << "|      5. Return to the Main Menu         |" << endl;
        cout << "-------------------------------------------" << endl << endl;
        cout << "           Enter Your Choice: ";
        cin >> choice;
        switch (choice) {
            case '1':
                if (recordCount > 0) {
                    recordIndex = lookupBook(recordCount, books);
                    if (recordIndex == -1) {
                        system("clear");
                        cout << "Record not found." << endl;
                        pause();
                    }
                }
                else {
                    system("clear");
                    cout << "Database is empty, cannot search for records." << endl;
                    pause();
                }
                break;
            case '2':
                if (recordCount < DBSIZE) 
                    addBook(recordCount, books);
                else {
                    system("clear");
                    cout << "Database is full, cannot add any more books." << endl;
                    pause();
                }
                break;
            case '3':
                if (recordCount > 0)
                    editBook(recordCount, books);
                else {
                    system("clear");
                    cout << "Database is empty, cannot edit any records." << endl;
                    pause();
                }
                break;
             case '4':
                if (recordCount > 0)
                    deleteBook(recordCount, books);
                else {
                    system("clear");
                    cout << "Database is empty, cannot delete any records." << endl;
                    pause();
                }
                break;
             case '5':
                exitmenu = true;
                break;
            case '6':
                listall(recordCount, books);
                break;
            default:
                cout << "\nPlease enter a number in the range of 1-5." << endl;
                pause();
        }
    } while (!exitmenu);
}