#include "../include/Serendipity.h"

// Function: bookInfo - sets up a prompt to allow the user to add a record to the database
// pre-condigion: navigated to from invmenu, all appropriate parallel arrays declared and passed from main.
// post-condition: records added to data base.
void editBook(orderedLinkedList<bookType*> &masterList) {
    char choice;
    bool exitmenu = false;
    linkedListIterator<bookType*> editBook;
    string buffer; // temporary memory to store input, then to set members

    editBook = lookupBook(masterList);
    if (editBook == nullptr)  {
        cout << "Couldn't find that item. Try again." << endl;
        wait();
        return;
    }

    do {
        system("clear");
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "|                         Serendipity Booksellers                         |" << endl;
        cout << "|                                Edit Book                                |" << endl;
        cout << "|                                                                         |" << endl;
        cout << "|                         Current Record Count: " << setw(16) << left << bookType::getBookCount() << "          |" << endl;
        cout << "|                                                                         |" << endl;
        cout << "| [1] Edit Book Title              ->  " << setw(35) << left << (*editBook)->getTitle().substr(0, 35) << "|" << endl;
        cout << "| [2] Edit ISBN                    ->  " << setw(35) << left << (*editBook)->getIsbn().substr(0, 35) << "|" << endl;
        cout << "| [3] Edit Author                  ->  " << setw(35) << left << (*editBook)->getAuthor().substr(0, 35) << "|" << endl;
        cout << "| [4] Edit Publisher               ->  " << setw(35) << left << (*editBook)->getPublisher().substr(0, 35) << "|" << endl;
        cout << "| [5] Edit Date Added (mm/dd/yyyy) ->  " << setw(35) << left << (*editBook)->getDateAdded() << "|" << endl;
        cout << "| [6] Edit Quantity On Hand        ->  " << setw(35) << left << (*editBook)->getQty() << "|" << endl;
        cout << "| [7] Edit WholeSale Cost          ->  " << '$' << setw(34) << left << fixed << setprecision(2)  << (*editBook)->getWholesale() << "|" << endl;
        cout << "| [8] Edit Retail Price            ->  " << '$' << setw(34) << left  << (*editBook)->getRetail() << "|" << endl;
        cout << "| [9] Return to Inventory Menu          " << setw(34) << left << ' ' << "|" << endl;
        cout << "|                                                                         |" << endl;
        cout << "---------------------------------------------------------------------------" << endl << endl;
        cout << "                                Choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Book Title: ";
                cin.ignore();
                getline(cin, buffer);
                (*editBook)->setTitle(buffer);
                break;
            case '2':
                cout << "ISBN: ";
                cin.ignore();
                getline(cin, buffer);
                (*editBook)->setISBN(buffer);
                break;
            case '3':
                cout << "Author: ";
                cin.ignore();
                getline(cin, buffer);
                (*editBook)->setAuthor(buffer);
                break;
            case '4':
                cout << "Publisher: ";
                cin.ignore();
                getline(cin, buffer);
                (*editBook)->setPublisher(buffer);
                break;
            case '5':
                cout << "Date: ";
                cin.ignore();
                getline(cin, buffer);
                (*editBook)->setDate(buffer);
                break;
            case '6':
                cout << "Quantity On Hand: ";
                cin.ignore();
                getline(cin, buffer);
                (*editBook)->setQty(atoi(buffer.c_str()));
                break;
            case '7':
                cout << "Wholesale Cost: ";
                cin.ignore();
                getline(cin, buffer);
                (*editBook)->setWholesale(atof(buffer.c_str()));
                break;
            case '8':
                cout << "Retail Price: ";
                cin.ignore();
                getline(cin, buffer);
                (*editBook)->setRetail(atoi(buffer.c_str()));
                break;
            case '9':
                exitmenu = true;
                break;
            default:
                cout << "\nPlease enter a number in the range 1-9." << endl;
                wait();
        }

    } while (!exitmenu);
}