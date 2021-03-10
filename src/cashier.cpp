// =================================================
// Name: Ryan Hellwege
// Date: 27 Jan, 2021
// Professor: Jeff Barnett
// Assignment A(11)
// File Name: cashier.cpp
// ------------------------------------------------
// Algorithim:
// Step 1: ask the user for a book
// Step 2: ask the user for number of books to buy
// Step 3: ask the user to repeat
// STep 4: when done adding, store quantity of books to buy in a shopping cart
// Step 5: display the purchase
// Step 6: if the purchase is confirmed, update qty's
// =================================================

#include "../include/Serendipity.h"

const int wQty = 6, wIsbn = 14, wTitle = 27, wPrice = 19, wTotal = 18, spacing = 16;

// Function: cashier - display process a transaction
// pre-condition: navigated to from mainmenu
// post-condition: output transaction information.
void cashier(bookType books[]) {
     const float TAX_RATE = 0.06;
     bool confirmPurchase = false;

     if (bookType::getBookCount() <= 0) {
          system("clear");
          cout << "There are no records in the database to buy from." << endl;
          pause();
          return;
     }

     system("clear");
     bool addMore = false;
     int buyIndex = 0;
     float subtotal = 0.0f;
     float sales = 0.0f;
     char choice;
     int qtyToPurchase = 0;
     int shoppingCart[DBSIZE];
     float grandTotal = 0.0f;
     float grandTaxes = 0.0f;

     for (int i = 0; i < DBSIZE; i++) {
          shoppingCart[i] = 0; // make sure this array is set to zero so garbage isnt added
     }

     do {
          qtyToPurchase = 0;
          system("clear");
          
          buyIndex = lookupBook(books);
          while (buyIndex == -1)  { // keep resetting until the book is found, or the user decides to exit.
               system("clear");
               cout << "Couldn't find that item. Try again." << endl;
               cout << "exit? (y/n): ";
               cin >> choice;
               if (tolower(choice) == 'y') return; // the user wants to exit, so return to parent menu.
               buyIndex = lookupBook(books);
          }
          system("clear");

          do {
               cout << "How many orders of " << books[buyIndex].getTitle() 
               << " would you like to buy (" 
               << books[buyIndex].getQty()<< " books on hand): ";
               cin >> qtyToPurchase;
               if (qtyToPurchase > books[buyIndex].getQty()) {
                    cout << "You cannot buy more than " << books[buyIndex].getQty() << " orders of that book, try again." << endl;
                    pause();
                    system("clear");
               }
          } while (qtyToPurchase > books[buyIndex].getQty() || qtyToPurchase < 0);

          shoppingCart[buyIndex] += qtyToPurchase; // add however many items the user requested to the shopping cart
          system("clear");
          cout << "Would you like to add another book to this purchase? (y/n): ";
          cin >> choice;
          if (tolower(choice) == 'y')
               addMore = true;
          else 
               addMore = false;
     } while(addMore);
     
     system("clear");
     //Heading:
     cout << "-------------------------------------------" << endl;
     cout << "|          Serendipity Booksellers        |" << endl;
     cout << "|              Cashier Module             |" << endl;
     cout << "|                                         |" << endl;
     cout << "-------------------------------------------" << endl;
     
     //output formatted:
     cout << "\nSerendipity Book Sellers\n\n";
     //cout << "Date: " << books[buyIndex].getDateAdded() << "\n\n";
     cout << left << setw(wQty) << "Qty" << left << setw(wIsbn) << "ISBN" // table heading
          << left << setw(wTitle) << "Title" << left << setw(wPrice) 
          << "Price Per Item" << left << setw(wTotal) << "Total";
     cout << setfill('-') << setw(wQty+wIsbn+wTitle+wPrice+wTotal) << '\n';
     cout << setfill(' ') << '\n';

     for (int i = 0; i < DBSIZE; i++) { //iterate through the shopping cart
          if (shoppingCart[i] == 0) // user did not purchase this book, don't care about printing
               continue;
          
          subtotal = (float)shoppingCart[i] *(float)books[i].getRetail();
     
          //output transaction table:
          cout << left << setw(wQty) << shoppingCart[i] << left << setw(wIsbn) << books[i].getIsbn() 
               << left << setw(wTitle) << books[i].getTitle().substr(0,wTitle-1) << left << setw(2) 
               << "$ " << setw(wPrice-2) << fixed << setprecision(2) 
               << books[i].getRetail() << left << setw(2) << "$ "<< left << setw(wTotal) 
               << fixed << setprecision(2) << subtotal;

          sales = TAX_RATE*subtotal;
          cout << endl;
          grandTotal+=subtotal;
          grandTaxes += TAX_RATE*subtotal;
     }
     sales = grandTotal * TAX_RATE;
     cout << endl;
     cout << left << setw(35) << ' ' << setw(15) << "Subtotal" << setw(spacing) 
               << ' ' << setw(2) << "$ " << right << setw(5) << grandTotal << endl;
          cout << left << setw(35) << ' ' << setw(15) << "Tax"<< setw(spacing) 
               << ' ' << setw(2) << "$ " << right << setw(5) << sales << endl;
          cout << left << setw(35) << ' ' << setw(15) << "Total"<< setw(spacing) 
               << ' ' << setw(2) << "$ " << right << setw(5) << grandTotal + sales << endl;
     
     cout << endl << endl;
     cout << "Thank You for Shopping at Serendipity!\n\n";
     // ask for 1 more checkout:
     cout << "Confirm this purchase? (y/n): ";
     cin >> choice;

     if (tolower(choice) == 'y')
          confirmPurchase = true;

     if (confirmPurchase) { // decrease the quantities of the books we just bought if the user confirmed the purchase
          for (int i = 0; i < DBSIZE; i++) {
               books[i].setQty(books[i].getQty() - shoppingCart[i]);
          }
     }
}