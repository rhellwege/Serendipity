#include "../include/Serendipity.h"

const int COLS = 120;

#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

class BufferToggle
{
    private:
        struct termios t;

    public:

        /*
         * Disables buffered input
         */

        void off(void)
        {
            tcgetattr(STDIN_FILENO, &t); //get the current terminal I/O structure
            t.c_lflag &= ~ICANON; //Manipulate the flag bits to do what you want it to do
            tcsetattr(STDIN_FILENO, TCSANOW, &t); //Apply the new settings
            
        }


        /*
         * Enables buffered input
         */

        void on(void)
        {
            tcgetattr(STDIN_FILENO, &t); //get the current terminal I/O structure
            t.c_lflag |= ICANON; //Manipulate the flag bits to do what you want it to do
            tcsetattr(STDIN_FILENO, TCSANOW, &t); //Apply the new settings
        }
};

BufferToggle bt;

char kbhit() {
    bt.off();
    char c = std::getchar();
    if (c != ESCAPE_SEQ) {
        bt.on();
        return c;
    }
    // handle ANSI escape sequences:
    // add a timeout mechanism to detect if the input is just an escape character (with nothing following), just return K_ESC
    c = std::getchar();
    if (c == '[')  {
        c = std::getchar();
        switch (c) {
            case '5':   
                c = std::getchar(); // consume ~
                bt.on();
                return K_PGUP;
                break;
            case '6':
                c = std::getchar(); // consume ~
                bt.on();
                return K_PGDOWN;
                break;
            case '1': // function keys
                c = std::getchar();
                if (c == '5') {
                    c = std::getchar(); //consume next
                    bt.on();
                    return K_F5;
                }
                break;
            case 'D':     
                bt.on();
                return K_LEFT;
            case 'A':     
                bt.on();
                return K_UP;
            case 'C':     
                bt.on();
                return K_RIGHT;
            case 'B':     
                bt.on();
                return K_DOWN;
            default:   
                return 0;
        }
    } else {
        return 0;
    }
    bt.on();
    return c;
}

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

void wait()  {
    cout << "Press return to continue...";
    cin.ignore();
    cin.get();
}