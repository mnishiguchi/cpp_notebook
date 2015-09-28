//
//  main.cpp
//  _02_insertion_sort
//
//  Created by Masatoshi Nishiguchi on 9/28/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

void insertionSort(int list[], int size) {
    int firstUnsorted;
    int position;
    int temp;

    // Inspect the unsorted portion one by one.
    for (firstUnsorted = 1; firstUnsorted < size; firstUnsorted++) {

        // If the value is less than previous
        if (list[firstUnsorted] < list[firstUnsorted - 1]) {
            temp     = list[firstUnsorted];  // Remember the value
            position = firstUnsorted;        // Remember the index of the value

            // Shift the sorted elements by one to the right
            // until the appropriate sorted position is determined.
            do {
                list[position] = list[position - 1];
                position--;

                // The value should be greater than the previous
            } while (position >= 1 && list[position - 1] > temp);

            // Set the value at the sorted position.
            list[position] = temp;
        }
    }
}

int main(int argc, const char * argv[]) {

    const int NUM_NUMBERS = 3;
    int numbers[NUM_NUMBERS];

    // Input
    cout << "Enter three numbers: ";
    for (int i = 0; i < NUM_NUMBERS; i++) {
        cin >> numbers[i];
    }
    cout << endl;

    insertionSort(numbers, NUM_NUMBERS);

    // Output
    for (int i = 0; i < NUM_NUMBERS; i++) {
        cout << numbers[i] << " ";
    }

    return 0;
}
