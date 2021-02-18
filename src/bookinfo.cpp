#include "../include/Serendipity.h"

// Function: bookInfo - display information on a book.
// pre-condigion: book is declared
// post-condition: book is printed
void bookInfo(const BookData &book) {
     cout << "-------------------------------------------" << endl;
     cout << "|          Serendipity Booksellers        |" << endl;
     cout << "|             Book Information            |" << endl;
     cout << "|                                         |" << endl;
     cout << "-------------------------------------------" << endl;
     cout << endl;
     cout << setw(20) << "ISBN"              << ">>  " << book.isbn << endl;
     cout << setw(20) << "Title"             << ">>  " << book.bookTitle.substr(0,25) << endl;
     cout << setw(20) << "Author"            << ">>  " << book.author.substr(0,25)    << endl;
     cout << setw(20) << "Publisher"         << ">>  " << book.publisher.substr(0,25) << endl;
     cout << setw(20) << "Date Added"        << ">>  " << book.dateAdded << endl;
     cout << setw(20) << "Quantity on Hand"  << ">>  " << book.qtyOnHand << endl;
     cout << setw(20) << "Wholesale Cost"    << ">>  " << fixed << setprecision(2) << book.wholesale << endl;
     cout << setw(20) << "Retail Price"      << ">>  " << fixed << setprecision(2) << book.retail    << endl;
}