#include "../include/Serendipity.h"

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