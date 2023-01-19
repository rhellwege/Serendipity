/*
vt sequences:
<esc>[1~    - Home        <esc>[16~   -             <esc>[31~   - F17
<esc>[2~    - Insert      <esc>[17~   - F6          <esc>[32~   - F18
<esc>[3~    - Delete      <esc>[18~   - F7          <esc>[33~   - F19
<esc>[4~    - End         <esc>[19~   - F8          <esc>[34~   - F20
<esc>[5~    - PgUp        <esc>[20~   - F9          <esc>[35~   - 
<esc>[6~    - PgDn        <esc>[21~   - F10         
<esc>[7~    - Home        <esc>[22~   -             
<esc>[8~    - End         <esc>[23~   - F11         
<esc>[9~    -             <esc>[24~   - F12         
<esc>[10~   - F0          <esc>[25~   - F13         
<esc>[11~   - F1          <esc>[26~   - F14         
<esc>[12~   - F2          <esc>[27~   -             
<esc>[13~   - F3          <esc>[28~   - F15         
<esc>[14~   - F4          <esc>[29~   - F16         
<esc>[15~   - F5          <esc>[30~   -             

xterm sequences:
<esc>[A     - Up          <esc>[K     -             <esc>[U     -
<esc>[B     - Down        <esc>[L     -             <esc>[V     -
<esc>[C     - Right       <esc>[M     -             <esc>[W     -
<esc>[D     - Left        <esc>[N     -             <esc>[X     -
<esc>[E     -             <esc>[O     -             <esc>[Y     -
<esc>[F     - End         <esc>[1P    - F1          <esc>[Z     -
<esc>[G     - Keypad 5    <esc>[1Q    - F2       
<esc>[H     - Home        <esc>[1R    - F3       
<esc>[I     -             <esc>[1S    - F4       
<esc>[J     -             <esc>[T     - 
*/



#include <iostream>   
using namespace std;
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define K_ESC -1
#define K_PGDOWN -2
#define K_PGUP -3
#define K_F5 -4

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

#define ESCAPE_SEQ 27

int kbhit() { // processes ansi escape sequences if it encounters an escape character
    bt.off();
    char c = std::getchar();
    if (c != ESCAPE_SEQ) {
        return c;
    }
    // handle ANSI escape sequences:
    // add a timeout mechanism to detect if the input is just an escape character (with nothing following), just return K_ESC
    cout << '(' << (int)c << ')' << endl;
    c = std::getchar();
    cout << '(' << (int)c << ')' << endl;
    if (c == '[')  {
        c = std::getchar();
        cout << '(' << (int)c << ')' << endl;
        switch (c) {
            case '5':   
                c = std::getchar(); // consume ~
                cout << '(' << (int)c << ')' << endl;
                return K_PGUP;
                break;
            case '6':
                c = std::getchar(); // consume ~
                cout << '(' << (int)c << ')' << endl;
                return K_PGDOWN;
                break;
            case '1': // function keys
                c = std::getchar();
                cout << '(' << (int)c << ')' << endl;
                if (c == '5') {
                    c = std::getchar(); //consume next
                    cout << '(' << (int)c << ')' << endl;
                    return K_F5;
                }
                break;
            default:   
                return 0;
        }
    } else {
        return 0;
    }
    
    bt.on();
    return c;
}

int main(){
    cout << "Press any key." << endl;
    int c;
    while (1) {
        c = kbhit();
        cout << endl;
        switch (c) {
            case K_ESC:   
                cout << "You pressed escape" << endl;
                break;
            case K_PGDOWN:   
                cout << "You page downed" << endl;
                break;
            case K_PGUP:   
                cout << "You page upped" << endl;
                break;
            case 'q':   
                exit(0);
                break;
            case K_F5:   
                cout << "you pressed: F5" << endl;
                break;
            default: 
                cout << "you pressed: " << (char)c << endl;
        }
    }
    
    
    return 0;
}