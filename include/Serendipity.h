#ifndef SERENDIPITY_H
#define SERENDIPITY_H
#include "bookType.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int DBSIZE = 20;

// cashier
void cashier(bookType books[]);

// invmenu:
void invmenu(bookType books[]);
int lookupBook(const bookType books[]);
void addBook(bookType books[]);
void editBook(bookType books[]);
void deleteBook(bookType books[]);

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
bool searchInsensitive(const string& src, const string& substr);
#endif
