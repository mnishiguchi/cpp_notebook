//
//  main.cpp
//  resizable_array
//
//  Created by Masatoshi Nishiguchi on 10/4/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 * Print all the elements in an integer array.
 */
void printAll(int* list, int size) {
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

/**
 * Resize an integer array.
 */
int* resize(int* &list, int size, int increment) {

    int* temp = list;  // The link to old list

    // Create a new list
    list = new int[size + increment];

    // Copy all the element to the new list
    for (int idx = 0; idx < size; idx++) {
        list[idx] = temp[idx];
    }

    delete[] temp;  // Delete the old list

    return list;
}

/**
 * The main function of this program
 */
int main() {

    const int INCREMENT = 3;

    int capacity = INCREMENT;
    int idx = 0;
    int num;
    int* list = new int[capacity];

    cout << "Enter positive integers ";
    cout << "(To quit, type a negative number):" << endl;

    for (;;) {
        cin >> num;  // Read a number
        
        // If cin is in a bad state, fix it
        if (!cin) {
            cout << "Error reading input" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        
        // Ensure that the number is a positive integer
        if (num < 0) {
            break;
        }

        list[idx] = num; // Add the num to the list
        idx++;           // Update idx

        // If next index is out of range, resize it
        if (idx == capacity) {
            cout << "Resizing the list..." << endl;
            list = resize(list, capacity, INCREMENT);

            idx = capacity;        // Update idx
            capacity += INCREMENT; // Update capacity
        }
    }

    cout << "\nYour numbers:" << endl;
    printAll(list, capacity);

    delete[] list;

    return 0;
}
