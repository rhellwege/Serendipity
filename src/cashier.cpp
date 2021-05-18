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
// Step 4: when done adding, store quantity of books to buy in a shopping cart
// Step 5: display the purchase
// Step 6: if the purchase is confirmed, update qty's
// =================================================

#include "../include/Serendipity.h"
#include <ctime>
const int wQty = 6, wIsbn = 14, wTitle = 27, wPrice = 19, wTotal = 18, spacing = 16;

// Function: cashier - display process a transaction
// pre-condition: navigated to from mainmenu
// post-condition: output transaction information.
void cashier(orderedLinkedList<bookType*> &masterList) {
     const float TAX_RATE = 0.06;
     bool confirmPurchase = false;

     if (bookType::getBookCount() <= 0) {
          system("clear");
          cout << "There are no records in the database to buy from." << endl;
          wait();
          return;
     }

     system("clear");
     bool addMore = false;
     bookType* buyBook = nullptr;
     float subtotal = 0.0f;
     float sales = 0.0f;
     char choice;
     int qtyToPurchase = 0;
     orderType shoppingCart[bookType::getBookCount()];
     int orders = 0;
     float grandTotal = 0.0f;
     float grandTaxes = 0.0f;

     do {
          qtyToPurchase = 0;
          system("clear");
          
          buyBook = lookupBook(books);
          while (buyBook == nullptr)  { // keep resetting until the book is found, or the user decides to exit.
               system("clear");
               cout << "Couldn't find that item." << endl;
               cout << "Try again? (y/n): ";
               cin >> choice;
               if (tolower(choice) == 'n') return; // the user wants to exit, so return to parent menu.
               buyBook = lookupBook(books);
          }
          system("clear");

          do { // buy prompt
               cout << "How many orders of " << buyBook->getTitle() <<endl
               << "would you like to buy (" 
               << buyBook->getQty()<< " books on hand, " <<  shoppingCart[buyBook] << " in shopping cart): ";
               cin >> qtyToPurchase;
               if (qtyToPurchase < 0) {
                    cout << "You cannot buy negative books, try again." << endl;
                    qtyToPurchase = 0;
                    wait();
                    system("clear");
                    continue;
               }
               if (qtyToPurchase + shoppingCart[buyBook] > buyBook->getQty()) {
                    cout << "You cannot buy more than " << buyBook->getQty() << " orders of that book, try again." << endl;
                    qtyToPurchase = 0;
                    wait();
                    system("clear");
               }
          } while (qtyToPurchase > buyBook->getQty() || qtyToPurchase < 0);

          shoppingCart[buyBook] += qtyToPurchase; // add however many items the user requested to the shopping cart
          system("clear");
          cout << "Would you like to add another book to this purchase? (y/n): ";
          cin >> choice;
          if (tolower(choice) == 'y')
               addMore = true;
          else 
               addMore = false;
     } while(addMore);
     
     system("clear");
     //Order Summary
     cout << "-------------------------------------------" << endl;
     cout << "|          Serendipity Booksellers        |" << endl;
     cout << "|              Cashier Module             |" << endl;
     cout << "|                                         |" << endl;
     cout << "-------------------------------------------" << endl;
     
     //output formatted:
     cout << "\nSerendipity Book Sellers\n\n";

     cout << "Date: " << get_date() << endl << endl;

     cout << left << setw(wQty) << "Qty" << left << setw(wIsbn) << "ISBN" // table heading
          << left << setw(wTitle) << "Title" << left << setw(wPrice) 
          << "Price Per Item" << left << setw(wTotal) << "Total";
     cout << setfill('-') << setw(wQty+wIsbn+wTitle+wPrice+wTotal) << '\n';
     cout << setfill(' ') << '\n';

     for (int i = 0; i < bookType::getBookCount(); i++) { //iterate through the shopping cart
          if (shoppingCart[i] == 0) // user did not purchase this book, don't care about printing
               continue;
          
          subtotal = (float)shoppingCart[i] *(float)books[i]->getRetail();
     
          //output transaction table:
          cout << left << setw(wQty) << shoppingCart[i] 
               << left << setw(wIsbn) << books[i]->getIsbn() 
               << left << setw(wTitle) << books[i]->getTitle().substr(0,wTitle-5) 
               << left << setw(2) << "$ " 
               << setw(wPrice-2) << fixed << setprecision(2) << setw(6) << right << books[i]->getRetail() 
               << setw(11) << " "
               << left << setw(2) << "$ "
               << fixed << setprecision(2) << setw(6) << right << subtotal;

          sales = TAX_RATE*subtotal;
          cout << endl;
          grandTotal+=subtotal;
          grandTaxes += TAX_RATE*subtotal;
     }
     sales = grandTotal * TAX_RATE;
     cout << endl;

     cout << left << setw(35) << ' ' << setw(15) << "Subtotal" << setw(spacing) 
          << ' ' << setw(2) << "$ " << right << setw(6) << grandTotal << endl;
     cout << left << setw(35) << ' ' << setw(15) << "Tax"<< setw(spacing) 
          << ' ' << setw(2) << "$ " << right << setw(6) << sales << endl;
     cout << left << setw(35) << ' ' << setw(15) << "Total"<< setw(spacing) 
          << ' ' << setw(2) << "$ " << right << setw(6) << grandTotal + sales << endl;
     
     cout << endl << endl;
     cout << "Thank You for Shopping at Serendipity!\n\n";
     // ask for 1 more checkout:
     cout << "Confirm this purchase? (y/n): ";
     cin >> choice;

     if (tolower(choice) == 'y')
          confirmPurchase = true;

     if (confirmPurchase) { // decrease the quantities of the books we just bought if the user confirmed the purchase
          for (int i = 0; i < bookType::getBookCount(); i++) {
               books[i]->setQty(books[i]->getQty() - shoppingCart[i]);
          }
     }
} // after confirm purchase, add a prompt asking another time.