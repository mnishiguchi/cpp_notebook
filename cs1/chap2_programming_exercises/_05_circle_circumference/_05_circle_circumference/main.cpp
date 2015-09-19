//
//  main.cpp
//  _05_circle_circumference
//
//  Prompt user to enter the radius, then calculate and print
//  the area and circumference of a circle
//
//  Created by Masatoshi Nishiguchi on 9/18/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

/* === ANALYSIS ===
 
 // constant
 const double PI = 3.14;
 
 // variables
 double radius;
 double area;
 double circumference;
 
 // calculations
 formula for the area of a circle:          PI * radius * radius
 formula for the circumference of a circle: 2 * PI * radius
 
 If the radius is 4:
    area          = 3.14 * 4 * 4 = 50.24
    circumference = 2 * 3.14 * 4 = 25.12
 
 // assignment statements
 cin >> radius;
 area          = PI * radius * radius;
 circumference = 2 * PI * radius;
 */

/* === PROGRAM === */

#include <iostream>
using namespace std;

int main() {
    
    // Declare identifiers
    const double PI = 3.14;
    double radius;
    double area;
    double circumference;

    // Prompt user to enter the radius
    cout << "Enter the radius: ";
    cin >> radius;
    cout << endl;
    
    // Calculate the area and circumference
    area = PI * radius * radius;
    circumference = 2 * PI * radius;
    
    // Print the area and circumference
    cout << "Area = " << area << endl;
    cout << "Circumference = " << circumference << endl;
    
    return 0;
}

/* === ACTUAL OUTPUT ===
 
 Enter the radius: 4
 
 Area = 50.24
 Circumference = 25.12
 
 */