//
//  main.cpp
//  20151027_lec
//
//  Created by Masatoshi Nishiguchi on 10/27/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    
    const int SIZE = 3;
    double nums[SIZE];
    double first  = 0.0;
    double second = 0.0;
    double last   = 0.0;
    
    cout << "Enter three numbers: ";
    cin >> nums[0] >> nums[1] >> nums[2];
    cout << endl;
    
    // Find the min and max
    first = min(nums[0], min(nums[1], nums[2]));
    last  = max(nums[0], max(nums[1], nums[2]));
    
    // Find the second
    bool found = false;
    for (int i = 0; i < SIZE && !found; i++) {
        if (nums[i] != first && nums[i] != last) {
            second = nums[i];
            found = true;
        }
    }
    
    // Print the result
    cout << "Sorted: " << first << " " << second << " " << last << endl;
    
    return 0;
}
