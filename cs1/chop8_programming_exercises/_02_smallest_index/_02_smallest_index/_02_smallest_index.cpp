/**
 * Chapter 8 Programming exerciese
 * _02_smallest_index
 */
#include <iostream>
using namespace std;


// Function prototypes.
int smallestIndex(double[], int);
void inputNumbers(double[], int& , const int);


/**
 * @return
 */
int main() {

    // Create an double array to store user's input.
    const int MAX_COUNT = 32;
    double numbers[ MAX_COUNT ];

    // The store for how many numbers the user inputs.
    int itemCount;

    // Prompt the user to enter numbers.
    inputNumbers(numbers, itemCount, MAX_COUNT);

    // Output the smallest index.
    cout << "The smallest index: " << smallestIndex(numbers, itemCount) << endl;

    return 0;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * @param  aArray     An int array
 * @param  arraySize  The size of the array
 * @return the index of the first occurrence of the smallest element in the array.
 */
int smallestIndex(double aArray[], int arraySize) {

    // Store for the index of the smallest element.
    int smallestIndex = 0;

    // Iterate over the array.
    for (int i = 1; i < arraySize; i++) {

        // If the element is currently the smallest, remember the index.
        // Ignore the second occurrence of the same number.
        if ( aArray[ i ]  < aArray[ smallestIndex ] ) {

            smallestIndex = i;

        }

    }

    // Finally, return the index.
    return smallestIndex;
}


/**
 * Prompts the user for numbers up to the specified maximum count.
 * @param numbers    An array of double-type numbers in which user's inputted
 *                   numbers are to be stored.
 * @param itemCount  An variable in which we record how many numbers the user enter.
 * @param MAX_COUNT  The maximum count of the numbers we can accept as input.
 */
void inputNumbers(double numbers[], int& itemCount, const int MAX_COUNT) {

    // The prompt message.
    cout << "Enter numbers (Max: " << MAX_COUNT << ", q: quit)" << endl;

    // Accept numbers until max count is reached or cin enters fail state.
    itemCount = 0;

    for ( int i = 0; i < MAX_COUNT; i++ ) {

        cout << ">>> ";
        cin >> numbers[ i ];

        // If input is valid, increment the counter.
        if ( cin.fail() || itemCount == MAX_COUNT - 1 ) {

            break;

        } else {

            itemCount += 1;

        }
    }
}

/* OUTPUT

Enter numbers (Max: 32, q: quit)
>>> 3
>>> 2
>>> 1
>>> 1
>>> 1
>>> 1
>>> 1
>>> q
The smallest index: 2
Program ended with exit code: 0
 */
