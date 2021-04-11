#ifndef SERENDIPITY_H
#define SERENDIPITY_H
#include "bookType.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int DBSIZE = 20;

// cashier
void cashier(bookType* books[]);

// invmenu:
void invmenu(bookType* books[]);
int lookupBook(bookType* books[]);
void addBook(bookType* books[]);
void editBook(bookType* books[]);
void deleteBook(bookType* books[]);

// reports:
void reports(bookType* books[]);
void repListing(bookType* books[]);
void repWholesale(bookType* books[]); 
void repRetail(bookType* books[]); 
void repCost(bookType* books[]); 
void repQty(bookType* books[]); 
void repAge(bookType* books[]); 

// utils:
#define K_ESC -1
#define K_PGDOWN -2
#define K_PGUP -3
#define K_F5 -4
#define K_UP -5
#define K_DOWN -6
#define K_LEFT -7
#define K_RIGHT -8
#define ESCAPE_SEQ 27

void wait();
char kbhit();
void ruler();
bool searchInsensitive(const string& src, const string& substr);
string get_date();
#endif
