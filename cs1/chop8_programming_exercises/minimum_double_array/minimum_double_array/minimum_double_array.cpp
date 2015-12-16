/**
 * APCT-233C-01
 * C++ Lab final 2015 - PART B
 * December 15, 2015
 *
 * minimum_double_array.cpp
 *
 * Masatoshi Nishiguchi
 *
 * DESCRIPTION
 * 1. prompts the user to enter ten numbers,
 * 2. invokes this function, and
 * 3. displays the minimum value.
 */
#include <iostream>
using namespace std;


// Function prototypes.
void inputNumbers(double[], int& , const int);
double min(double aArray[], int size);


// The capacity of the array.
const int MAX_COUNT = 10;


/**
 * Prompts the user to en
 * Runs the min(double[], int) function with and prints the output the function yields.
 * @return an exit code.
 */
int main() {

    // Create an double array to store user's input.
    double numbers[ MAX_COUNT ];

    // The store for recording how many numbers the user inputs.
    int itemCount;

    // Prompt the user to enter numbers.
    inputNumbers(numbers, itemCount, MAX_COUNT);

    // Output the smallest index.
    cout << "The minimum number: " << min(numbers, itemCount) << endl << endl;

    return 0;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * Finds the smallest element in an array of double.
 * @param  aArray An double array.
 * @param  size   The size of the array.
 * @return the smallest element in an array of double.
 */
double min(double aArray[], int size) {

    // Store for the smallest element.
    double smallest = aArray[ 0 ];  // Initially the first element.

    // Iterate over the array.
    for (int i = 1; i < size; i++) {

        // If the element is currently the smallest, remember the number.
        // Ignore the second occurrence of the same number.
        if ( aArray[ i ] < smallest ) {

            smallest = aArray[ i ];

        }

    }

    // Finally, return the smallest number.
    return smallest;

}


/**
 * Prompts the user for the arbitrary count of numbers up to the specified maximum count.
 * @param numbers    An array of double-type numbers in which user's inputted
 *                   numbers are to be stored.
 * @param itemCount  An variable in which we record how many numbers the user enter.
 * @param MAX_COUNT  The maximum count of the numbers we can accept as input.
 */
void inputNumbers(double numbers[], int& itemCount, const int MAX_COUNT) {

    // Print the prompt message for entering numbers.
    cout << "Enter numbers (Max: " << MAX_COUNT << ", q: quit)" << endl;

    // Accept numbers until max count is reached or cin enters fail state.
    itemCount = 0;

    for ( int i = 0; i < MAX_COUNT; i++ ) {

        cin >> numbers[ i ];

        // If input is valid, increment the counter.
        if ( cin.fail() || itemCount == MAX_COUNT - 1 ) {

            break;  // Exit the loop.

        } else {

            itemCount += 1;

        }
    }
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/* OUTPUT

Enter numbers (Max: 10, q: quit)
1.9 2.5 3.7 2 1.5 6 3 4 5 2
The minimum number: 1.5

Program ended with exit code: 0
*/
