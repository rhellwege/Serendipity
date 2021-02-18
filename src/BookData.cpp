#include "../include/BookData.h"

void setTitle(BookData &book, string title)  {
    book.bookTitle = title;
}
void setISBN(BookData &book, string isbn) {
    book.isbn = isbn;
}
void setAuthor(BookData &book, string author) {
    book.author = author;
}
void setPub(BookData &book, string publisher) {
    book.publisher = publisher;
}
void setDateAdded(BookData &book, string date) {
    book.dateAdded = date;
}
void setQty(BookData &book, int qty) {
    book.qtyOnHand = qty;
}
void setWholesale(BookData &book, float wholesale) {
    book.wholesale = wholesale;
}
void setRetail(BookData &book, float retail) {
    book.retail = retail;
}