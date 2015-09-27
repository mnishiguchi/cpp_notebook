//
//  main.cpp
//  _03_kilograms_to_pounds
//
//  Created by Masatoshi Nishiguchi on 9/27/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() {

    const double KG_TO_LB = 2.2;
    double weightKG, weightLB;
    
    // Input
    cout << "Enter a weight in kilograms: ";
    cin >> weightKG;
    
    // Processing
    weightLB = weightKG * KG_TO_LB;
    
    // Output
    cout << fixed << showpoint << setprecision(2);
    cout << weightLB << " pounds" << endl;
    
    return 0;
}
