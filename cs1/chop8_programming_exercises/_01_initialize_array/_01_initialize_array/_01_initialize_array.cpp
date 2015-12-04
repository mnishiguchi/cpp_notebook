/**
 * Chapter 8 Programming exerciese
 * _01_initialize_array
 *
 * Declares an array alpha of 50 components of type double.
 * Initialize the array so that the first 25 components are equal to the square
 * of the index variable, and the last 25 components are equal to three times
 * the index variable. Output the array so that 10 elements per line are printed.
 */
#include <iostream>
using namespace std;


/**
 * Initializes an array.
 */
void initialize(double* alpha, int size) {

    // Initialize the first half.
    // equal to the square of the index variable.
    for (int i = 0; i < size / 2; i++) {

        alpha[ i ] = i * i;

    }

    // Initialize the second half.
    // equal to three times the index variable.
    for (int i = size / 2; i < size; i++) {

        alpha[ i ] = i * 3;

    }
}


/**
 * Prints an array.
 */
void print(double* alpha, int size) {

    // Output (10 elements per line)
    for (int i = 0; i < size; i++) {

        cout << alpha[ i ] << " ";

        if (i % 10 == 9) {
            cout << "\n";
        }
    }

    cout << endl;
}


/**
 * @return
 */
int main() {

    const int SIZE = 50;
    double alpha[ SIZE ];

    initialize(alpha, SIZE);
    print(alpha, SIZE);

    return 0;
}
