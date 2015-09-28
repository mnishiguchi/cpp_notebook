//
//  main.cpp
//  _02_bubble_sort
//
//  Created by Masatoshi Nishiguchi on 9/28/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

void swap(double& d1, double& d2) {
    double temp = d1;
    d1 = d2;
    d2 = temp;
}

int main(int argc, const char * argv[]) {
    
    const int NUM_NUMBERS = 3;
    double numbers[NUM_NUMBERS];
    bool swapped;
    
    // Input
    cout << "Enter three numbers: ";
    for (int i = 0; i < NUM_NUMBERS; i++) {
        cin >> numbers[i];
    }
    cout << endl;
    
    // Bubble sort(ASC)
    do {
        // Repeat until there is no need for swapping.
        swapped = false;
        // Iterate over the entire list.
        for (int i = 1; i < NUM_NUMBERS; i++) {
            // Swap if the previous number is greater.
            if (numbers[i-1] > numbers[i]) {
                swap(numbers[i-1], numbers[i]);
                swapped = true;
            }
        }
    } while (swapped);
    
    // Output
    for (int i = 0; i < NUM_NUMBERS; i++) {
        cout << numbers[i] << " ";
    }
    
    return 0;
}
