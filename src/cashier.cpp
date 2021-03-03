// =================================================
// Name: Ryan Hellwege
// Date: 27 Jan, 2021
// Professor: Jeff Barnett
// Assignment A(1)
// File Name: cashier.cpp
// ------------------------------------------------
// Algorithim:
// Step 1: prompt the user for input
// Step 2: calculate taxes and the sale
// Step 3: output formatted.
// Step 4: ask the user if they want to repeat.
// =================================================

#include "../include/Serendipity.h"

const int wQty = 6, wIsbn = 17, wTitle = 25, wPrice = 18, wTotal = 18, spacing = 16;

// Function: cashier - display process a transaction
// pre-condition: navigated to from mainmenu
// post-condition: output transaction information.
void cashier(bookType books[]) {
     const float TAX_RATE = 0.06;
     bool exitmenu = false;

     if (bookType::getBookCount() <= 0) {
          system("clear");
          cout << "There are no records in the database to buy from." << endl;
          pause();
          return;
     }

     do {
          system("clear");
          int buyIndex;
          float subtotal;
          float sales;

          char choice;
          
          buyIndex = lookupBook(books);
          if (buyIndex == -1)  {
               cout << "Couldn't find that item. Try again." << endl;
               pause();
               return;
          }
          //Heading:
          cout << "-------------------------------------------" << endl;
          cout << "|          Serendipity Booksellers        |" << endl;
          cout << "|              Cashier Module             |" << endl;
          cout << "|                                         |" << endl;
          cout << "-------------------------------------------" << endl;
          
          //output formatted:
          cout << "\nSerendipity Book Sellers\n\n";
          cout << "Date: " << books[buyIndex].getDateAdded() << "\n\n";

          subtotal = books[buyIndex].getQty()*books[buyIndex].getWholesale();
          system("clear");
          
          //output transaction table:
          cout << left << setw(wQty) << "Qty" << left << setw(wIsbn) << "ISBN" 
               << left << setw(wTitle) << "Title" << left << setw(wPrice) 
               << "Price" << left << setw(wTotal) << "Total";
          
          cout << setfill('-') << setw(wQty+wIsbn+wTitle+wPrice+wTotal) << '\n';
          cout << setfill(' ') << '\n';
          cout << left << setw(wQty) << books[buyIndex].getQty() << left << setw(wIsbn) << books[buyIndex].getIsbn() 
               << left << setw(wTitle) << books[buyIndex].getTitle().substr(0,wTitle-1) << left << setw(2) 
               << "$ " << setw(wPrice-2) << fixed << setprecision(2) 
               << books[buyIndex].getWholesale() << left << setw(2) << "$ "<< left << setw(wTotal) 
               << fixed << setprecision(2) << subtotal;

          sales = TAX_RATE*subtotal;
          cout << endl << endl;
          
          cout << left << setw(35) << ' ' << setw(15) << "Subtotal" << setw(spacing) 
               << ' ' << setw(2) << "$ " << right << setw(5) << subtotal << endl;
          cout << left << setw(35) << ' ' << setw(15) << "Tax"<< setw(spacing) 
               << ' ' << setw(2) << "$ " << right << setw(5) << sales << endl;
          cout << left << setw(35) << ' ' << setw(15) << "Total"<< setw(spacing) 
               << ' ' << setw(2) << "$ " << right << setw(5) << subtotal + sales << endl;
          cout << endl << endl;
          cout << "Thank You for Shopping at Serendipity!\n\n";

          // ask for 1 more checkout:
          cout << "Would you like to check out another book? (y/n): ";
          cin >> choice;
          if (tolower(choice) != 'y')
               exitmenu = true;
     } while (!exitmenu);
}