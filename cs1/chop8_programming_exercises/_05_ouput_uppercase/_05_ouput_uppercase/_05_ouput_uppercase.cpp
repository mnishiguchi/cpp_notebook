/**
 * Chapter 8 Programming exerciese
 * _05_ouput_uppercase
 *
 * Prompts the user to input a string and outputs the string in uppercase letters.
 * (Use a character array to store the string.)
 */
#include <iostream>
#include <cctype>
using namespace std;


/**
 * @param
 */
void promptCharArray(char* aStr) {

    // Prompt user to enter a string.
    bool isFinished = false;
    while ( !isFinished ) {

        cout << "Enter a string:" << endl;
        cout << ">>> ";
        cin >> aStr;
        cout << endl;

        // VALIDATION: 1. Input failure, 2. Invalid input.
        if ( !cin ) {
            cout << "Error : Try again" << endl;

            cin.clear();            // Restore input stream
            cin.ignore(100, '\n');  // Clear the buffer
        } else {
            isFinished = true;  // Exit the loop.
        }
    }
}


/**
 * @param  a character array
 * @param  the length of the array
 */
void charArrayToUpper(char* aStr, int length) {

    for (int i = 0; i < length; i++) {

        aStr[ i ] = toupper( aStr[ i ] );

    }
}


/**
 * @param  a character array
 */
void print(char* aStr) {
    cout << aStr << endl;
}


/**
 * @return
 */
int main() {

    const int LENGTH = 32;
    char aStr[ LENGTH ];

    promptCharArray(aStr);
    charArrayToUpper(aStr, LENGTH);
    print(aStr);

    return 0;
}
