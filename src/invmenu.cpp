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

// Function: lookupBook - allow the user to search through the database according to publisher, author, or title
// pre-condition: navigated to from invmenu, at least 1 record added, all parallel arrays are stored correctly and passed
// post-condition: bookinfo called on the search results.
int lookupBook(bookType* books[]) {
    string searchTerm;
    int i;
    if (bookType::getBookCount() == 0)
        return -1;

    system("clear");
    cout << "---------------------------------------------" << endl;
    cout << "|           Serendipity Booksellers         |" << endl;
    cout << "|                Look Up Book               |" << endl;
    cout << "|                                           |" << endl;
    cout << "| There are " << setw(2)  << left << bookType::getBookCount() << " records available to search. |" << endl;
    cout << "---------------------------------------------" << endl << endl;
    cout << "Search: ";
    cin.ignore();
    getline(cin, searchTerm);
    // perform the search:
    for (i = 0; i < bookType::getBookCount(); i++) {
        if (
            searchInsensitive(books[i]->getTitle(), searchTerm) || 
            searchInsensitive(books[i]->getAuthor(), searchTerm) || 
            searchInsensitive(books[i]->getPublisher(), searchTerm)
        ) { // if the title contains the substring searchTerm (case insensitive)
            char choice;            
            system("clear");
            books[i]->print();
            cout << "\nSelect this item? (y/n): ";
            cin >> choice;
            if (tolower(choice) == 'y')
                return i; // exit out of lookupbook if the user found what they were looking for and dont continue the loop.
        }
    }
    return -1;
}

void deleteBook(bookType* books[]) {
    int deleteIndex = lookupBook(books);
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
    if (tolower(choice) == 'y') { // if confirmed
        delete books[deleteIndex]; // set the book pointer to zero, and free memory
        books[deleteIndex] = books[bookType::getBookCount()-1]; // switch the last book that was added with what we are deleting, and make that spot inaccessable
        bookType::decBookCount();
    }
}

// Function: invmenu - allow the user to use submomdules related to inventory
// pre-condition: navigated to from mainmenu.
// post-condition: navigation to a submenu.
void invmenu(bookType* books[]) {
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
                if (bookType::getBookCount() > 0) {
                    recordIndex = lookupBook(books);
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
                if (bookType::getBookCount() < DBSIZE) 
                    addBook(books);
                else {
                    system("clear");
                    cout << "Database is full, cannot add any more books." << endl;
                    pause();
                }
                break;
            case '3':
                if (bookType::getBookCount() > 0)
                    editBook(books);
                else {
                    system("clear");
                    cout << "Database is empty, cannot edit any records." << endl;
                    pause();
                }
                break;
             case '4':
                if (bookType::getBookCount() > 0)
                    deleteBook(books);
                else {
                    system("clear");
                    cout << "Database is empty, cannot delete any records." << endl;
                    pause();
                }
                break;
             case '5':
                exitmenu = true;
                break;
            default:
                cout << "\nPlease enter a number in the range of 1-5." << endl;
                pause();
        }
    } while (!exitmenu);
}