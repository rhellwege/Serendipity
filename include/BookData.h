#ifndef BOOKDATA_H 
#define BOOKDATA_H
#include <string>
using namespace std;
struct BookData {
    string bookTitle;
    string isbn;
    string author;  
    string publisher;
    string dateAdded;
    int    qtyOnHand;
    float  wholesale;
    float  retail;  
};

void setTitle(BookData &book, string title);
void setISBN(BookData &book, string isbn);
void setAuthor(BookData &book, string author);
void setPub(BookData &book, string publisher);
void setDateAdded(BookData &book, string date);
void setQty(BookData &book, int qty);
void setWholesale(BookData &book, float wholesale);
void setRetail(BookData &book, float retail);
#endif