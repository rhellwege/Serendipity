#include "../include/Serendipity.h"


/**
 *
 * @param ks  like XK_Shift_L, see /usr/include/X11/keysymdef.h
 * @return
 */
bool key_is_pressed(KeySym ks) { // checks to see if the inputted key is being pressed KeySym follows the pattern: XK_<key name>
    Display *dpy = XOpenDisplay(":0");
    char keys_return[32];
    XQueryKeymap(dpy, keys_return);
    KeyCode kc2 = XKeysymToKeycode(dpy, ks);
    bool isPressed = !!(keys_return[kc2 >> 3] & (1 << (kc2 & 7)));
    XCloseDisplay(dpy);
    return isPressed;
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