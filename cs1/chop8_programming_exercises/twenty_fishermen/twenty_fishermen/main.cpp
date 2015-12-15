/**
 * 4. twenty_fishermen.cpp
 * The following program skeleton contains a 20-element array of ints called fish.
 * When completed, the program should ask how many ﬁsh were caught by ﬁsher­men 1 through 20,
 * and store this data in the array. Complete the program.
 */
#include <iostream>
using namespace std;

int main() {
    
    // 20-element array of ints called fish
    const int NUM_FISH = 20;
    int fish[ NUM_FISH ];

    // Ask how many fish were caught by fishermen 1-20
    cout << "How many fish were caught by fishermen 1-20:" << endl;

    // store this data in the array fish.
    for (int i = 0; i < NUM_FISH; i++) {

        cout << "Fisherman #" << i + 1 << ": ";
        cin >> fish[ i ];  // Store it in the array.

    }

    cout << "--------------------------------------------------"  << endl;

    // Print the array.
    for (int i = 0; i < NUM_FISH; i++) {

        cout << "Fisherman #" << i + 1 << ": ";
        cout << fish[ i ] << endl;  // Print each array element.

    }

    cout << endl;

    return 0;
}
