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
linkedListIterator<bookType*> lookupBook(orderedLinkedList<bookType*> &masterList) {
    string searchTerm;
    linkedListIterator<bookType*> iter;
    if (bookType::getBookCount() == 0)
        return nullptr;

    system("clear");
    cout << "----------------------------------------------" << endl;
    cout << "|           Serendipity Booksellers          |" << endl;
    cout << "|                Look Up Book                |" << endl;
    cout << "|                                            |" << endl;
    cout << "| There are " << setw(3)  << left << bookType::getBookCount() << " records available to search. |" << endl;
    cout << "----------------------------------------------" << endl << endl;
    cout << "Search: ";
    cin.ignore();
    getline(cin, searchTerm);
    // perform the search:
    for (iter = masterList.begin(); iter != masterList.end(); ++iter) {
        if (
            searchInsensitive((*iter)->getTitle(), searchTerm) || 
            searchInsensitive((*iter)->getAuthor(), searchTerm) || 
            searchInsensitive((*iter)->getPublisher(), searchTerm)
        ) { // if the title contains the substring searchTerm (case insensitive)
            char choice;            
            system("clear");
            //books[i]->print();
            cout << **iter; // output stream overloaded.
            cout << "\nSelect this item? (y/n): ";
            cin >> choice;
            if (tolower(choice) == 'y')
                return iter; // exit out of lookupbook if the user found what they were looking for and dont continue the loop.
        }
    }
    return nullptr;
}

void deleteBook(orderedLinkedList<bookType*> &masterList) {
    linkedListIterator<bookType*> deleteBook = lookupBook(masterList);
    char choice;
    if (deleteBook == nullptr) {
        cout << "Couldn't find that item. Try again." << endl;
        wait();
        return;
    }
    cout << "WARNING: You are about to delete a record, are you sure you want to do that? (y/n): ";
    cin >> choice;
    if (tolower(choice) == 'y') { // if confirmed
        masterList.deleteNode(*deleteBook); // call delete node method with found item.
    }
}

// Function: invmenu - allow the user to use submomdules related to inventory
// pre-condition: navigated to from mainmenu.
// post-condition: navigation to a submenu.
void invmenu(orderedLinkedList<bookType*> &masterList) {
    char choice;
    bool exitmenu = false;
    linkedListIterator<bookType*> record;
    
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
                    record = lookupBook(masterList);
                    if (record == nullptr) {
                        system("clear");
                        cout << "Record not found." << endl;
                        wait();
                    }
                }
                else {
                    system("clear");
                    cout << "Database is empty, cannot search for records." << endl;
                    wait();
                }
                break;
            case '2':
                //if (bookType::getBookCount() < DBSIZE) 
                    addBook(masterList);
                //else {
                //    system("clear");
                //    cout << "Database is full, cannot add any more books." << endl;
                //    wait();
                //}
                break;
            case '3':
                if (bookType::getBookCount() > 0)
                    editBook(masterList);
                else {
                    system("clear");
                    cout << "Database is empty, cannot edit any records." << endl;
                    wait();
                }
                break;
             case '4':
                if (bookType::getBookCount() > 0)
                    deleteBook(masterList);
                else {
                    system("clear");
                    cout << "Database is empty, cannot delete any records." << endl;
                    wait();
                }
                break;
             case '5':
                exitmenu = true;
                break;
            default:
                cout << "\nPlease enter a number in the range of 1-5." << endl;
                wait();
        }
    } while (!exitmenu);
}