#ifndef SERENDIPITY_H
#define SERENDIPITY_H
#include "BookData.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int DBSIZE = 20;

void bookInfo(const BookData &book);

// cashier
void cashier(const int recordCount, const BookData books[]);

// invmenu:
void invmenu(int &recordCount, BookData books[]);
int lookupBook(const int recordCount, const BookData books[]);
void addBook(int &recordCount, BookData books[]);
void editBook(const int recordCount, BookData books[]);
void deleteBook(int &recordCount, BookData books[]);

// reports:
void reports();
void repListing();
void repWholesale(); 
void repRetail(); 
void repCost(); 
void repQty(); 
void repAge(); 

// utils:
void pause();
bool searchInsensitive(const string src, const string substr);
#endif
