#include "../include/Serendipity.h"

// Function: bookInfo - sets up a prompt to allow the user to add a record to the database
// pre-condigion: navigated to from invmenu, all appropriate parallel arrays declared and passed from main.
// post-condition: records added to data base.
void addBook(bookType* books[]) {
    char choice;
    bool exitmenu = false;
    bool savedWork = true;

    string tmpIsbn      = "*EMPTY*";
    string tmpTitle     = "*EMPTY*";
    string tmpAuthor    = "*EMPTY*";
    string tmpPublisher = "*EMPTY*";
    string tmpDate      = "*EMPTY*";
    int    tmpQty       = 0;
    float  tmpWholesale = 0.0f;
    float  tmpRetail    = 0.0f;

    do {
        if (bookType::getBookCount() >= DBSIZE)
            return;
        system("clear");
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "|                         Serendipity Booksellers                         |" << endl;
        cout << "|                                 Add Book                                |" << endl;
        cout << "|                                                                         |" << endl;
        cout << "|                Database Size: " << DBSIZE << "  Current Record Count: " << setw(16) << left << bookType::getBookCount() << "|" << endl;
        cout << "|                                                                         |" << endl;
        cout << "| [1] Enter Book Title              ->  " << setw(34) << left << tmpTitle.substr(0, 34) << "|" << endl;
        cout << "| [2] Enter ISBN                    ->  " << setw(34) << left << tmpIsbn.substr(0, 34) << "|" << endl;
        cout << "| [3] Enter Author                  ->  " << setw(34) << left << tmpAuthor.substr(0, 34) << "|" << endl;
        cout << "| [4] Enter Publisher               ->  " << setw(34) << left << tmpPublisher.substr(0, 34) << "|" << endl;
        cout << "| [5] Enter Date Added (mm/dd/yyyy) ->  " << setw(34) << left << tmpDate << "|" << endl;
        cout << "| [6] Enter Quantity On Hand        ->  " << setw(34) << left << tmpQty << "|" << endl;
        cout << "| [7] Enter WholeSale Cost          ->  " << '$' << setw(33) << left << fixed << setprecision(2)  << tmpWholesale << "|" << endl;
        cout << "| [8] Enter Retail Price            ->  " << '$' << setw(33) << left  << tmpRetail << "|" << endl;
        cout << "| [9] Save Book to Database             " << setw(34) << left << ' ' << "|" << endl;
        cout << "| [0] Return to Inventory Menu          " << setw(34) << left << ' ' << "|" << endl;
        cout << "|                                                                         |" << endl;
        cout << "---------------------------------------------------------------------------" << endl << endl;
        cout << "                                Choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                savedWork = false;
                cout << "Book Title: ";
                cin.ignore();
                getline(cin, tmpTitle);
                break;
            case '2':
                savedWork = false;
                cout << "ISBN: ";
                cin.ignore();
                getline(cin, tmpIsbn);
                break;
            case '3':
                savedWork = false;
                cout << "Author: ";
                cin.ignore();
                getline(cin, tmpAuthor);
                break;
            case '4':
                savedWork = false;
                cout << "Publisher: ";
                cin.ignore();
                getline(cin, tmpPublisher);
                break;
            case '5':
                savedWork = false;
                cout << "Date: ";
                cin.ignore();
                getline(cin, tmpDate);
                break;
            case '6':
                savedWork = false;
                cout << "Quantity On Hand: ";
                cin.ignore();
                cin >> tmpQty;
                break;
            case '7':
                savedWork = false;
                cout << "Wholesale Cost: ";
                cin.ignore();
                cin >> tmpWholesale;
                break;
            case '8':
                savedWork = false;
                cout << "Retail Price: ";
                cin.ignore();
                cin >> tmpRetail;
                break;
            case '9': // save to database
                if (bookType::getBookCount() == DBSIZE) {
                    cout << "Database is full, you must delete a record if you would like to add a record." << endl;
                    pause();
                    break;
                }
    
                books[bookType::getBookCount()] = new bookType( // initiate the class with a default constructor
                    tmpTitle, tmpIsbn, tmpAuthor, 
                    tmpPublisher, tmpDate, tmpQty, 
                    tmpWholesale, tmpRetail
                ); 

                bookType::incBookCount();
                savedWork = true;
                
                tmpIsbn      = "*EMPTY*";
                tmpTitle     = "*EMPTY*";
                tmpAuthor    = "*EMPTY*";
                tmpPublisher = "*EMPTY*";
                tmpDate      = "*EMPTY*";
                tmpQty       = 0;
                tmpWholesale = 0.0f;
                tmpRetail    = 0.0f;
                break;
            case '0':
                if (!savedWork) {
                    char exitChoice;
                    cout << "You have unsaved work. Are you sure you want to exit? (y/n): ";
                    cin >> exitChoice;
                    if (tolower(exitChoice) == 'y')
                        exitmenu = true;
                } else 
                    exitmenu = true;
                break;
            default:
                cout << "\nPlease enter a number in the range 0-9." << endl;
                pause();
        }

    } while (!exitmenu);
}