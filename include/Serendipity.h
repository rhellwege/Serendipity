#ifndef SERENDIPITY_H
#define SERENDIPITY_H
#include "orderedLinkedList.h"
#include "bookType.h"
#include "templates.hpp"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int DBSIZE = 20;

// cashier
void cashier(orderedLinkedList<bookType*> &masterList);

// invmenu:
void invmenu(orderedLinkedList<bookType*> &masterList);
linkedListIterator<bookType*> lookupBook(orderedLinkedList<bookType*> &masterList);
void addBook(orderedLinkedList<bookType*> &masterList);
void editBook(orderedLinkedList<bookType*> &masterList);
void deleteBook(orderedLinkedList<bookType*> &masterList);

// reports:
void reports(orderedLinkedList<bookType*> &masterList);
void repListing(orderedLinkedList<bookType*> &masterList);
void repWholesale(orderedLinkedList<bookType*> &masterList); 
void repRetail(orderedLinkedList<bookType*> &masterList); 
void repCost(orderedLinkedList<bookType*> &masterList); 
void repQty(orderedLinkedList<bookType*> &masterList); 
void repAge(orderedLinkedList<bookType*> &masterList); 

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
int kbhit();
void ruler();
bool searchInsensitive(const string& src, const string& substr);
string get_date();
bool dateIsLess(string lhs, string rhs);
#endif
