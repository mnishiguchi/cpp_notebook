//
//  sequential_sort.cpp
//
//  Created by Masatoshi Nishiguchi on 10/19/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 Sequential search
 - Worst: array size, O(n)
 - Best:  1
 - Ave:   n / 2
 */

void lookForNum(int vals[], int arraySize, int valueToFind) {  // int vals[] or int* vals
    
    bool isFound = false;
    
    // Search for the number
    for (int i = 0; i < arraySize && !isFound; i++) {
        
        if (vals[i] == valueToFind) {
            isFound = true;
        }
    }
    
    // Print the result of the search
    if (isFound) {
        cout << "I found it" << endl;
    } else {
        cout << "I did not find it" << endl;
    }
}


int main() {
    
    int lengths[] = { 12, 43, 656, 82, 43, 21 };
    
    lookForNum(lengths, 6, -21);
    
    return 0;
}
