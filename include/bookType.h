#ifndef BOOKTYPE_H 
#define BOOKTYPE_H
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

enum compareBy {
    COMPARE_QTY,
    COMPARE_WHOLESALE,
    COMPARE_RETAIL,
    COMPARE_TITLE,
    COMPARE_AUTHOR
};

class bookType {
private:
    // static
    static int bookCount;
    //setters:
    static void incBookCount();
    static void decBookCount();
    //members:
    string bookTitle;
    string isbn;
    string author;  
    string publisher;
    string dateAdded;
    int    qtyOnHand;
    float  wholesale;
    float  retail;  

public:
    static int compare;
    //constructors:
    bookType();
    bookType(
        const string& title, const string& isbn, const string& author, 
        const string& publisher, const string& date, int qty, float wholesale, 
        float retail
    );
    ~bookType();
    
    //getters:
    static int getBookCount(); // static methods cannot have const

    string getTitle() const;
    string getIsbn() const;
    string getAuthor() const;
    string getPublisher() const;
    string getDateAdded() const;
    int getQty() const;
    float getWholesale() const;
    float getRetail() const;

    //setters

    void setTitle(const string& _title);
    void setISBN(const string& _isbn);
    void setAuthor(const string& _author);
    void setPublisher(const string& _publisher);
    void setDate(const string& _date);
    void setQty(int _qty);
    void setWholesale(float _wholesale);
    void setRetail(float _retail);

    // additional functionality:
    void print() const;
    bool equals(const bookType& other) const;

    // operator overloading
    friend ostream& operator<<(ostream& os, const bookType& book);
    friend istream& operator>>(istream& is, bookType& book);
    bool operator<(const bookType& other);
    bool operator<=(const bookType& other);
    bool operator>(const bookType& other);
    bool operator>=(const bookType& other);
    bool operator==(const bookType& other);
    bool operator!=(const bookType& other);
};


#endif
