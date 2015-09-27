//
//  main.cpp
//  _02_volume_cylinder
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

    double height, radius;
    
    // Input
    cout << "Enter the height of the cylinder: ";
    cin >> height;
    
    cout << "Enter the radius of the base of the cylinder: ";
    cin >> radius;
    cout << endl;
    
    // Output
    cout << fixed << showpoint << setprecision(2);
    
    cout << "Volume       : "
         << setw(10) << M_PI * pow(radius, 2.0) * height << endl;
    
    cout << "Surface area : "
         << setw(10) << 2 * M_PI * radius * height + 2 * M_PI * pow(radius, 2.0);
    
    return 0;
}
