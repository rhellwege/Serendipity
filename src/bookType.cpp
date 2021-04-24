#include "../include/bookType.h"

int bookType::bookCount = 0; // initialize the static variable

//constructors:
bookType::bookType() {
    setTitle("*EMPTY*");
    setISBN("*EMPTY*");
    setAuthor("*EMPTY*");
    setPublisher("*EMPTY*");
    setDate("*EMPTY*");
    setQty(0);
    setWholesale(0.0f);
    setRetail(0.0f);
}

bookType::bookType(
    const string& title, const string& isbn, const string& author, 
    const string& publisher, const string& date, int qty, float wholesale, 
    float retail
) {
    setTitle(title);
    setISBN(isbn);
    setAuthor(author);
    setPublisher(publisher);
    setDate(date);
    setQty(qty);
    setWholesale(wholesale);
    setRetail(retail);
}

//getters:
int bookType::getBookCount() {
    return bookCount;
} //  methods cannot have const
string bookType::getTitle() const {
    return bookTitle;
}
string bookType::getIsbn() const {
    return isbn;
}
string bookType::getAuthor() const {
    return author;
}
string bookType::getPublisher() const {
    return publisher;
}
string bookType::getDateAdded() const {
    return dateAdded;
}
int bookType::getQty() const {
    return qtyOnHand;
}
float bookType::getWholesale() const {
    return wholesale;
}
float bookType::getRetail() const {
    return retail;
}
//setters:
void bookType::incBookCount() {
    bookCount += 1;
}
void bookType::decBookCount() {
    bookCount -= 1;
}
void bookType::setTitle(const string& _title) {
    bookTitle = _title;
}
void bookType::setISBN(const string& _isbn) {
    isbn = _isbn;
}
void bookType::setAuthor(const string& _author) {
    author = _author;
}
void bookType::setPublisher(const string& _publisher) {
    publisher = _publisher;
}
void bookType::setDate(const string& _date) {
    dateAdded = _date;
}
void bookType::setQty(int _qty) {
    if (_qty >= 0)
        qtyOnHand = _qty;
}
void bookType::setWholesale(float _wholesale) {
    if (_wholesale >= 0)
        wholesale = _wholesale;
}
void bookType::setRetail(float _retail) {
    if (_retail >= 0)
        retail = _retail;
}
// additional functionality:
void bookType::print() const {
    cout << "-------------------------------------------" << endl;
    cout << "|          Serendipity Booksellers        |" << endl;
    cout << "|             Book Information            |" << endl;
    cout << "|                                         |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << endl;
    cout << setw(20) << "ISBN"              << ">>  " << getIsbn() << endl;
    cout << setw(20) << "Title"             << ">>  " << getTitle().substr(0,25) << endl;
    cout << setw(20) << "Author"            << ">>  " << getAuthor().substr(0,25)    << endl;
    cout << setw(20) << "Publisher"         << ">>  " << getPublisher().substr(0,25) << endl;
    cout << setw(20) << "Date Added"        << ">>  " << getDateAdded() << endl;
    cout << setw(20) << "Quantity on Hand"  << ">>  " << getQty() << endl;
    cout << setw(20) << "Wholesale Cost"    << ">>  " << fixed << setprecision(2) << getWholesale() << endl;
    cout << setw(20) << "Retail Price"      << ">>  " << fixed << setprecision(2) << getRetail()    << endl;
}

bool bookType::equals(const bookType& other) const {
    bool result = false;
    if (getTitle().compare(other.getTitle()) == 0)
        if (getIsbn().compare(other.getIsbn()) == 0)
            if (getAuthor().compare(other.getAuthor()) == 0)
                if (getPublisher().compare(other.getPublisher()) == 0)
                    if (getDateAdded().compare(other.getDateAdded()) == 0)
                        if (getQty() == other.getQty())
                            if (getWholesale() == other.getWholesale())
                                if (getRetail() == other.getRetail())
                                    result = true;
    
    return result;
}

ostream& operator<<(ostream& os, const bookType& book) {
    os << "-------------------------------------------" << endl;
    os << "|          Serendipity Booksellers        |" << endl;
    os << "|             Book Information            |" << endl;
    os << "|                                         |" << endl;
    os << "-------------------------------------------" << endl;
    os << endl;
    os << setw(20) << "ISBN"              << ">>  " << book.getIsbn() << endl;
    os << setw(20) << "Title"             << ">>  " << book.getTitle().substr(0,25) << endl;
    os << setw(20) << "Author"            << ">>  " << book.getAuthor().substr(0,25)    << endl;
    os << setw(20) << "Publisher"         << ">>  " << book.getPublisher().substr(0,25) << endl;
    os << setw(20) << "Date Added"        << ">>  " << book.getDateAdded() << endl;
    os << setw(20) << "Quantity on Hand"  << ">>  " << book.getQty() << endl;
    os << setw(20) << "Wholesale Cost"    << ">>  " << fixed << setprecision(2) << book.getWholesale() << endl;
    os << setw(20) << "Retail Price"      << ">>  " << fixed << setprecision(2) << book.getRetail()    << endl;
    return os;
}
istream& operator>>(istream& is, const bookType& book) {
    
    return is;
}
bool bookType::operator<(const bookType& other) {
    return this->getQty() < other.getQty();
}
bool bookType::operator>(const bookType& other) {
    return this->getQty() > other.getQty();
}
bool bookType::operator==(const bookType& other) {
    return this->getQty() == other.getQty();
}
bool bookType::operator!=(const bookType& other) {
    return this->getQty() != other.getQty();
}