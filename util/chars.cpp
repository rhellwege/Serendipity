#include <iostream>
#include <string>
using namespace std;
bool dateIsLess(string lhs, string rhs) {
    int numYearL;
    int numYearR;
    int numMonL;
    int numMonR;
    int numDayL;
    int numDayR;
    char yearL[5];
    char yearR[5];
    char monL[3];
    char monR[3];
    char dayL[3];
    char dayR[3];
    int i;

    // compare years
    for (i = 0; i < 4; i++) {
        yearL[i] = lhs[i+6];
    }
    yearL[4] = 0;
    for (i = 0; i < 4; i++) {
        yearR[i] = rhs[i+6];
    }
    yearR[4] = 0;
    numYearL = atoi(yearL);
    numYearR = atoi(yearR);
    if (numYearL != numYearR)
        return numYearL < numYearR;

    // compare months
    for (i = 0; i < 2; i++) {
        monL[i] = lhs[i];
    }
    monL[2] = 0;
    for (i = 0; i < 2; i++) {
        monR[i] = rhs[i];
    }
    monR[2] = 0;
    numMonL = atoi(monL);
    numMonR = atoi(monR);
    if (numMonL != numMonR)
        return numMonL < numMonR;
    // compare days
    for (i = 0; i < 2; i++) {
        dayL[i] = lhs[i+3];
    }
    dayL[2] = 0;
    for (i = 0; i < 2; i++) {
        dayR[i] = rhs[i+3];
    }
    dayR[2] = 0;
    numDayL = atoi(dayL);
    numDayR = atoi(dayR);
    if (numDayL != numDayR)
        return numDayL < numDayR;
    return false;
}

int main() {
    while (1) {
        string left;
        string right;
        cout << "Date 1: ";
        cin >> left;
        cout << "Date 2: ";
        cin >> right;
        if (dateIsLess(left, right)) {
            cout << "Date 1 is less than date 2." << endl;
        } else {
            cout << "Date 1 is greater than date 2." << endl;
        }
    }
    return 0;
}