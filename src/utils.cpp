#include "../include/Serendipity.h"
#include <X11/Xlib.h>
#include <ctime>

const int COLS = 120;

string get_date() {
    char buff[30];
    time_t t = time(0);
    strftime(buff, 30, "%m/%d/%Y", localtime(&t)); // mm/dd/yy
    return buff;
}

void ruler() {
    // tens
    for (int i = 1; i < COLS; i++) {
        if (i % 10 == 0) 
            cout << i/10;
        else  
            cout << ' ';
    }
    cout << endl;
    for (int i = 1; i < COLS; i++) {
        cout << i % 10;
    }
    cout << endl;
}

// a couple of helper functions I made for convenience

// Function: searchInsensitive - helper function that searches for a substring in a source string without checking for case.
// pre-condition: 2 strings passed, src string bigger than substr.
// post-condition: return true if found, false if not found.
bool searchInsensitive(const string& src, const string& substr) {
    if (substr.length() > src.length())
        return false;
    for (int i = 0; i <= src.length()-substr.length(); i++) {
        bool found = true;
        for (int j = 0; j < substr.length(); j++) {
            if (tolower(src[i+j]) != tolower(substr[j]))
                found = false;
        }
        if (found)
            return true;
    }
    return false;
}

void pause()  {
    cout << "Press enter to continue...";
    cin.ignore();
    cin.get();
}