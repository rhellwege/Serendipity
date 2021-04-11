#include <iostream>
using namespace std;
int main() {
    while (1) {
        int i;
        cout << "enter a number to be converted to a char: ";
        cin >> i;
        cout << '(' << (char)i << ')' << endl;
    }
    return 0;
}