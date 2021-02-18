#include "../include/Serendipity.h"

// Function: bookInfo - sets up a prompt to allow the user to add a record to the database
// pre-condigion: navigated to from invmenu, all appropriate parallel arrays declared and passed from main.
// post-condition: records added to data base.
void editBook(const int recordCount, BookData books[]) {
    char choice;
    bool exitmenu = false;
    int editIndex;

    editIndex = lookupBook(recordCount, books);
    if (editIndex == -1)  {
        cout << "Couldn't find that item. Try again." << endl;
        pause();
        return;
    }

    do {
        system("clear");
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "|                         Serendipity Booksellers                         |" << endl;
        cout << "|                                Edit Book                                |" << endl;
        cout << "|                                                                         |" << endl;
        cout << "|                Database Size: " << DBSIZE << "  Current Record Count: " << setw(16) << left << recordCount << "|" << endl;
        cout << "|                                                                         |" << endl;
        cout << "| [1] Edit Book Title              ->  " << setw(35) << left << books[editIndex].bookTitle.substr(0, 35) << "|" << endl;
        cout << "| [2] Edit ISBN                    ->  " << setw(35) << left << books[editIndex].isbn.substr(0, 35) << "|" << endl;
        cout << "| [3] Edit Author                  ->  " << setw(35) << left << books[editIndex].author.substr(0, 35) << "|" << endl;
        cout << "| [4] Edit Publisher               ->  " << setw(35) << left << books[editIndex].publisher.substr(0, 35) << "|" << endl;
        cout << "| [5] Edit Date Added (mm/dd/yyyy) ->  " << setw(35) << left << books[editIndex].dateAdded << "|" << endl;
        cout << "| [6] Edit Quantity On Hand        ->  " << setw(35) << left << books[editIndex].qtyOnHand << "|" << endl;
        cout << "| [7] Edit WholeSale Cost          ->  " << '$' << setw(34) << left << fixed << setprecision(2)  << books[editIndex].wholesale << "|" << endl;
        cout << "| [8] Edit Retail Price            ->  " << '$' << setw(34) << left  << books[editIndex].retail << "|" << endl;
        cout << "| [9] Return to Inventory Menu          " << setw(34) << left << ' ' << "|" << endl;
        cout << "|                                                                         |" << endl;
        cout << "---------------------------------------------------------------------------" << endl << endl;
        cout << "                                Choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Book Title: ";
                cin.ignore();
                getline(cin, books[editIndex].bookTitle);
                break;
            case '2':
                cout << "ISBN: ";
                cin.ignore();
                getline(cin, books[editIndex].isbn);
                break;
            case '3':
                cout << "Author: ";
                cin.ignore();
                getline(cin, books[editIndex].author);
                break;
            case '4':
                cout << "Publisher: ";
                cin.ignore();
                getline(cin, books[editIndex].publisher);
                break;
            case '5':
                cout << "Date: ";
                cin.ignore();
                getline(cin, books[editIndex].dateAdded);
                break;
            case '6':
                cout << "Quantity On Hand: ";
                cin.ignore();
                cin >> books[editIndex].qtyOnHand;
                break;
            case '7':
                cout << "Wholesale Cost: ";
                cin.ignore();
                cin >> books[editIndex].wholesale;
                break;
            case '8':
                cout << "Retail Price: ";
                cin.ignore();
                cin >> books[editIndex].retail;
                break;
            case '9':
                exitmenu = true;
                break;
            default:
                cout << "\nPlease enter a number in the range 1-9." << endl;
                pause();
        }

    } while (!exitmenu);
}