#include "../include/Serendipity.h"
#include <iomanip>

const int RESULTS_PER_PAGE = 10;

// formatting widths
const int wTitle = 28, wIsbn = 14, wAuthor = 15, wPublisher = 15, wDate = 11, wQty = 8, wWhole = 15, wRetail = 13;
const int repTitle = 40;
const int repSpacing = 12;

// helper function to make code smaller, changes the page number, or can exit the menu
void navigation(int maxPages, int& page, bool& exitmenu) {
    int toPage;
    int c;
    bool valid = true;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "|  Navigation:  PgDown = Next Page  |  PgUp = Previus Page  |  F5 = Jump to Page  |  Esc = Quit  |" << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    c = kbhit();
    if (c > 0)
        c = tolower(c); // for processing non escape sequences
    do {
        if (c == 'q')
            exitmenu = true;
        else if (c == 'd' || c == K_PGDOWN || c == K_DOWN || c == K_RIGHT || c == 'j')
            page++;
        else if (c == 'u' || c == K_PGUP || c == K_UP || c == K_LEFT || c == 'k')
            page--;
        else if (c == K_F5 || c == 'f') {
            system("clear");
            cout << "Jump to page (1-" << maxPages << "): ";
            cin >> toPage;
            if (toPage < 1 || toPage > maxPages) {
                valid = false;
                break;
            }
            page = toPage;
        }
    } while(!valid);
    if (page > maxPages)
            page = 1;
        if (page <= 0)
            page = maxPages;
}

// summary of every listing, displaying every parameter of each book.
void repListing(bookType* books[]) {
    int page = 1;
    int maxPages = bookType::getBookCount() / RESULTS_PER_PAGE;
    int i;
    bool exitmenu = false;
    do {
        system("clear");
        cout << "***************************************************************************************************************************" << endl;
        cout << "*                                               SERENDIPITY BOOKSELLERS                                                   *" << endl;
        cout << "*                                                    REPORT LISTING                                                       *" << endl;
        cout << "*                                                                                                                         *" << endl;
        cout << "*    DATE: " << get_date() << "          PAGE: " << page << " of " << maxPages << "           DATABASE SIZE: " << DBSIZE << "            CURRENT BOOK COUNT: " << bookType::getBookCount() << "        *" << endl;
        cout << "*                                                                                                                         *" << endl;
        cout << left << fixed << setprecision(2);
        // table heading
        cout << "* " 
             << setw(wTitle) << "TITLE" 
             << setw(wIsbn) << "ISBN" 
             << setw(wAuthor) << "AUTHOR" 
             << setw(wPublisher) << "PUBLISHER" 
             << setw(wDate) << "DATE ADDED" 
             << setw(wQty) << "QTY O/H" 
             << setw(wWhole) << "WHOLESALE COST" 
             << setw(wRetail) << "RETAIL PRICE" 
             << " *" << endl;
        // lines
        cout << setfill('-');
        cout << '*' 
             << setw(wTitle) << ' ' 
             << setw(wIsbn) << ' ' 
             << setw(wAuthor) << ' ' 
             << setw(wPublisher) << ' ' 
             << setw(wDate) << ' ' 
             << setw(wQty) << ' ' 
             << setw(wWhole) << ' ' 
             << setw(wRetail) << ' ' 
             << "  *" << endl;
        cout << setfill(' ');
        // table body
        for (i = 0; i < RESULTS_PER_PAGE; i++) {
            if (i >= bookType::getBookCount())
                break;
            int index = i + (page-1)*RESULTS_PER_PAGE;
            cout << "* " << left
                 << setw(wTitle) << books[index]->getTitle().substr(0, wTitle-1)
                 << setw(wIsbn) << books[index]->getIsbn()
                 << setw(wAuthor) << books[index]->getAuthor().substr(0, wAuthor-1)
                 << setw(wPublisher) << books[index]->getPublisher().substr(0, wPublisher-1)
                 << setw(wDate) << books[index]->getDateAdded()
                 << right
                 << setw(wQty-1) << books[index]->getQty()
                 << left  << " $"
                 << setfill('.') << right
                 << setw(wWhole-2) << books[index]->getWholesale()
                 << setfill(' ')
                 << left  << " $"
                 << setfill('.') << right
                 << setw(wRetail-2) << books[index]->getRetail()
                 << setfill(' ')
                 << "  *" << endl;
            cout << "*                                                                                                                         *" << endl;
        }
        cout << "***************************************************************************************************************************" << endl;
        // handle navigation:
        navigation(maxPages, page, exitmenu);
    } while (!exitmenu);
}

// shows summary of each book's title, isbn, qty, and wholesale value
void repWholesale(bookType* books[]) {
    int page = 1;
    int maxPages = bookType::getBookCount() / RESULTS_PER_PAGE;
    int i;
    bool exitmenu = false;
    cout << left << fixed << setprecision(2);
    do {
        system("clear");
        cout << "************************************************************************************************************************" << endl;
        cout << "*                                               SERENDIPITY BOOKSELLERS                                                *" << endl;
        cout << "*                                               REPORT WHOLESALE LISTING                                               *" << endl;
        cout << "*                                                                                                                      *" << endl;
        cout << "*    DATE: " << get_date() << "          PAGE: " << page << " of " << maxPages << "           DATABASE SIZE: " << DBSIZE << "            CURRENT BOOK COUNT: " << bookType::getBookCount() << "     *" << endl;
        cout << "*                                                                                                                      *" << endl;
        // table heading
        cout << "* " << left
             << setw(repTitle) << "TITLE" << setw(repSpacing) << ' '
             << setw(wIsbn) << "ISBN" << setw(repSpacing) << ' '
             << setw(wQty) << "QTY O/H" << setw(repSpacing) << ' '
             << setw(wWhole) << "WHOLESALE COST" 
             << "    *" << endl;
        // lines
        cout << setfill('-');
        cout << "*" 
             << setw(repTitle) << ' ' << setfill(' ') << setw(repSpacing) << ' ' << setfill('-')
             << setw(wIsbn) << ' ' << setfill(' ') << setw(repSpacing) << ' ' << setfill('-')
             << setw(wQty) << ' ' << setfill(' ') << setw(repSpacing) << ' ' << setfill('-')
             << setw(wWhole) << ' ' 
             << "     *" << endl;
        cout << setfill(' ');
        // table body
        for (i = 0; i < RESULTS_PER_PAGE; i++) {
            if (i >= bookType::getBookCount())
                break;
            int index = i + (page-1)*RESULTS_PER_PAGE;
            cout << "* " << left
                 << setw(repTitle) << books[index]->getTitle().substr(0, repTitle-1)<< setw(repSpacing) << ' '
                 << setw(wIsbn) << books[index]->getIsbn()<< setw(repSpacing) << ' '
                 << right
                 << setw(wQty-1) << books[index]->getQty()<< setw(repSpacing+1) << ' '
                 << left << "$" << setfill('.') << right
                 << setw(wWhole-2) << books[index]->getWholesale()
                 << setfill(' ')
                 << "     *" << endl;
            cout << "*                                                                                                                      *" << endl;
        }
        // display total:
        float total = 0;
        for (int i = 0; i < bookType::getBookCount(); i++) {
            total += books[i]->getWholesale() * books[i]->getQty();
        }
        //cout << "*                                                                                               Total: " << total << " *" << endl;
        //cout << "* " << setw((repSpacing*3)+wTitle+wIsbn+wQty-1) << right  << "Total:" << setw(wWhole+repSpacing) << total << "        *" << endl;
        cout << "* " << setw((repSpacing*3)+wTitle+wIsbn+wQty-1) << right << "Total:" << left
             << setw(repSpacing+1) << ' ' << "$" << setfill('.') << right << setw(wWhole-2) << total << "     *" << setfill(' ') << endl;
        cout << "*                                                                                                                      *" << endl;
        cout << "************************************************************************************************************************" << endl;
        // handle navigation:
        navigation(maxPages, page, exitmenu);
    } while(!exitmenu);
}

// shows summary of each book's title, isbn, qty, and retail value
void repRetail(bookType* books[]) {
    int page = 1;
    int maxPages = bookType::getBookCount() / RESULTS_PER_PAGE;
    int i;
    bool exitmenu = false;
    cout << left << fixed << setprecision(2);
    do {
        system("clear");
        cout << "************************************************************************************************************************" << endl;
        cout << "*                                               SERENDIPITY BOOKSELLERS                                                *" << endl;
        cout << "*                                                REPORT RETAIL LISTING                                                 *" << endl;
        cout << "*                                                                                                                      *" << endl;
        cout << "*    DATE: " << get_date() << "          PAGE: " << page << " of " << maxPages << "           DATABASE SIZE: " << DBSIZE << "            CURRENT BOOK COUNT: " << bookType::getBookCount() << "     *" << endl;
        cout << "*                                                                                                                      *" << endl;
        // table heading
        cout << "* " << left
             << setw(repTitle) << "TITLE" << setw(repSpacing) << ' '
             << setw(wIsbn) << "ISBN" << setw(repSpacing) << ' '
             << setw(wQty) << "QTY O/H" << setw(repSpacing) << ' '
             << setw(wRetail) << "RETAIL PRICE" 
             << "      *" << endl;
        // lines
        cout << setfill('-');
        cout << "*" 
             << setw(repTitle) << ' ' << setfill(' ') << setw(repSpacing) << ' ' << setfill('-')
             << setw(wIsbn) << ' ' << setfill(' ') << setw(repSpacing) << ' ' << setfill('-')
             << setw(wQty) << ' ' << setfill(' ') << setw(repSpacing) << ' ' << setfill('-')
             << setw(wRetail) << ' ' 
             << "       *" << endl;
        cout << setfill(' ');
        // table body
        for (i = 0; i < RESULTS_PER_PAGE; i++) {
            if (i >= bookType::getBookCount())
                break;
            int index = i + (page-1)*RESULTS_PER_PAGE;
            cout << "* " << left
                 << setw(repTitle) << books[index]->getTitle().substr(0, repTitle-1)<< setw(repSpacing) << ' '
                 << setw(wIsbn) << books[index]->getIsbn()<< setw(repSpacing) << ' '
                 << right
                 << setw(wQty-1) << books[index]->getQty()<< setw(repSpacing+1) << ' '
                 << left << "$" << setfill('.') << right
                 << setw(wRetail-2) << books[index]->getRetail()
                 << setfill(' ')
                 << "       *" << endl;
            cout << "*                                                                                                                      *" << endl;
        }
        // display total:
        float total = 0;
        for (int i = 0; i < bookType::getBookCount(); i++) {
            total += books[i]->getRetail() * books[i]->getQty();
        }
        //cout << "*                                    Total: " << total << "                                                                  *" << endl;
        cout << "* " << setw((repSpacing*3)+wTitle+wIsbn+wQty-1) << right << "Total:" << left
             << setw(repSpacing+1) << ' ' << "$" << setfill('.') << right << setw(wRetail-2) << total << "       *" << setfill(' ') << endl;
        cout << "*                                                                                                                      *" << endl;
        cout << "************************************************************************************************************************" << endl;
        // handle navigation:
        navigation(maxPages, page, exitmenu);
    } while(!exitmenu);
}

void repCost(bookType* books[]) {
    cout << "You chose cost."<< endl;
    wait();
}

void repQty(bookType* books[]) {
    int page = 1;
    int maxPages = bookType::getBookCount() / RESULTS_PER_PAGE;
    int i;
    bool exitmenu = false;
    cout << left << fixed << setprecision(2);
    sortArray(books, bookType::getBookCount());
    do {
        system("clear");
        cout << "************************************************************************************************************************" << endl;
        cout << "*                                               SERENDIPITY BOOKSELLERS                                                *" << endl;
        cout << "*                                                REPORT RETAIL LISTING                                                 *" << endl;
        cout << "*                                                                                                                      *" << endl;
        cout << "*    DATE: " << get_date() << "          PAGE: " << page << " of " << maxPages << "           DATABASE SIZE: " << DBSIZE << "            CURRENT BOOK COUNT: " << bookType::getBookCount() << "     *" << endl;
        cout << "*                                                                                                                      *" << endl;
        cout << "* " << left
             << setw(repTitle) << "TITLE" << setw(repSpacing) << ' '
             << setw(wIsbn) << "ISBN" << setw(repSpacing) << ' '
             << setw(wQty) << "QTY O/H" << setw(repSpacing) << ' '
             << "                   *" << endl;
        // lines
        cout << setfill('-');
        cout << "*" 
             << setw(repTitle) << ' ' << setfill(' ') << setw(repSpacing) << ' ' << setfill('-')
             << setw(wIsbn) << ' ' << setfill(' ') << setw(repSpacing) << ' ' << setfill('-')
             << setw(wQty) << ' ' << setfill(' ') << setw(repSpacing) << ' ' << setfill('-')
             << "                    *" << endl;
        cout << setfill(' ');
        // table body
        for (i = 0; i < RESULTS_PER_PAGE; i++) {
            if (i >= bookType::getBookCount())
                break;
            int index = i + (page-1)*RESULTS_PER_PAGE;
            cout << "* " << left
                 << setw(repTitle) << books[index]->getTitle().substr(0, repTitle-1)<< setw(repSpacing) << ' '
                 << setw(wIsbn) << books[index]->getIsbn()<< setw(repSpacing) << ' '
                 << right
                 << setw(wQty-1) << books[index]->getQty()<< setw(repSpacing+1) << ' '
                 << setfill(' ')
                 << "                   *" << endl;
            cout << "*                                                                                                                      *" << endl;
        }
        cout << "************************************************************************************************************************" << endl;
        navigation(maxPages, page, exitmenu);
    } while(!exitmenu);
}

void repAge(bookType* books[]) {
    cout << "You chose age."<< endl;
    wait();
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
                if (bookType::getBookCount() > 0)
                    repListing(books);
                else {
                    system("clear");
                    cout << "Database is empty, try again after adding records." << endl;
                    wait();
                }
                break;
            case '2':
                if (bookType::getBookCount() > 0)
                    repWholesale(books);
                else {
                    system("clear");
                    cout << "Database is empty, try again after adding records." << endl;
                    wait();
                }
                break;
            case '3':
                if (bookType::getBookCount() > 0)
                    repRetail(books);
                else {
                    system("clear");
                    cout << "Database is empty, try again after adding records." << endl;
                    wait();
                }
                break;
            case '4':
                if (bookType::getBookCount() > 0)
                    repQty(books);
                else {
                    system("clear");
                    cout << "Database is empty, try again after adding records." << endl;
                    wait();
                }
                break;
            case '5':
                if (bookType::getBookCount() > 0)
                    repCost(books);
                else {
                    system("clear");
                    cout << "Database is empty, try again after adding records." << endl;
                    wait();
                }
                break;
            case '6':
                if (bookType::getBookCount() > 0)
                    repAge(books);
                else {
                    system("clear");
                    cout << "Database is empty, try again after adding records." << endl;
                    wait();
                }
                break;
            case '7':
                exitmenu = true;
                break;
            default:
                cout << "\nPlease enter a number in the range 1-7." << endl;
                wait();
        }
    } while (!exitmenu);
}