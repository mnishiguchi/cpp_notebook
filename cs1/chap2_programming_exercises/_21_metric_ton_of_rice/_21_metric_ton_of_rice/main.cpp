//
//  main.cpp
//  _21_metric_ton_of_rice
//
//  Prompts the user to input the amount of rice, in pounds, in a bag.
//  Outputs the number of bags needed to store one metric ton of rice.
//
//  Created by Masatoshi Nishiguchi on 9/19/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    // One metric ton is approximately 2205 pounds.
    const int METRIC_TON_IN_POUNDS = 2205;
    
    // Variable declaration
    double amountPounds;
    double amountMetricTons;
    int numBags;
    
    //  Prompts the user to input the amount of rice, in pounds, in a bag.
    cout << "Enter the amount of rice, in pounds: ";
    cin >> amountPounds;
    cout << endl;
    
    // Convert the amount to metric tons
    amountMetricTons = amountPounds / METRIC_TON_IN_POUNDS;
    numBags = static_cast<int>(amountMetricTons);  // Rounding down
    
    //  Outputs the number of bags needed to store one metric ton of rice.
    cout << "the amount in metric tons: " << amountMetricTons << endl;
    cout << "the num bags needed:       " << numBags << endl;

    return 0;
}

