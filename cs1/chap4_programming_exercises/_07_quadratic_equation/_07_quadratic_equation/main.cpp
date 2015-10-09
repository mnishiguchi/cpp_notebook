//
//  main.cpp
//  _07_quadratic_equation
//
//    ax^2 + bx + c = 0
//
//  Created by Masatoshi Nishiguchi on 10/8/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

/*
 Analysis
 
 Formula to obtain root(s)
   ( -b + sqrt(b^2 - 4ac) ) / 2a
   OR
   ( -b - sqrt(b^2 - 4ac) ) / 2a
 
 Formula to obtain discriminant
   b^2 - 4ac
 
 Type of the root(s)
   if 0, single root
   if positive, two real roots
   if negative, two complex roots
 */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    
    // Prompt user for a, b and c of a quadratic equation
    double a, b, c;
    double r1, r2;
    
    cout << "Enter a, b and c of a quadratic equation: ";
    cin >> a >> b >> c;
    cout << endl;
    
    // Determinant
    double determinant = pow(b, 2.0) - (4 * a * c);
    
    // Type of roots of the quadratic equation
    string type;
    cout << fixed << showpoint << setprecision(2);
    
    if (determinant == 0) {
        type = "single root";
        r1 = -b / (2 * a);
        cout << "Type:  " << type << endl;
        cout << "Root:  " << r1 << endl;
        
    } else if (determinant > 0) {
        type = "two real roots";
        r1 = (-b + sqrt(determinant)) / (2 * a);
        r2 = (-b - sqrt(determinant)) / (2 * a);
        cout << "Type:  " << type << endl;
        cout << "Root1: " << r1 << endl;
        cout << "Root2: " << r2 << endl;
        
    } else {
        type = "two complex roots";
        cout << "Type: " << type << endl;
    }
    
    return 0;
}