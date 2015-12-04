/**
 * Chapter 8 Programming exerciese
 * _07_five_election_candidates
 *
 *
 * Prompts the user to enter:
 *  - the last names of five candidates in a local election and
 *  - the number of votes received by each candidate.
 *
 * Outputs:
 *  - each candidate’s name,
 *  - the number of votes received, and
 *  - the percentage of the total votes received by the candidate
 *  - the winner of the election
 */
#include <iostream>
#include <string>
using namespace std;

/**
 * @param
 */
void promptNames(string names) {

    // Prompt user to enter a string.
    bool isFinished = false;
    while ( !isFinished ) {

        cout << "Enter a string:" << endl;
        cout << ">>> ";
        cin >> names;
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

    const int LENGTH = 5;
    string names[ LENGTH ];

    promptCharArray(aStr);
    charArrayToUpper(aStr, LENGTH);
    print(aStr);

    return 0;
}
