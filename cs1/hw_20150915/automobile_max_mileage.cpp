//
//  automobile_max_mileage.cpp
//
//  Created by Masatoshi Nishiguchi on 9/12/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

// Prompts the capacity, in gallons, of an automobile fuel tank and
// the miles per gallon the automobile can be driven.
// Outputs the number of miles the automobile can be driven without refueling.

int main() {
    // Declare variables
    double fuelCapacityInGallons = 0.0;
    double milesPerGallon = 0.0;
    
    // Prompts the capacity, in gallons, of an automobile fuel tank
    cout << "Please enter the capacity of an automobile fuel tank, in gallons: " << endl;
    cin >> fuelCapacityInGallons;
    
    // Prompts the miles per gallon the automobile can be driven
    cout << "Please enter the miles per gallon: " << endl;
    cin >> milesPerGallon;

    // Print number of miles the automobile can be driven without refueling
    cout << endl;
    cout << "This automobile can be driven for "
         << fuelCapacityInGallons / milesPerGallon << " miles without refueling" << endl;
    
    return 0;
}
