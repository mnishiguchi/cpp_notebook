//
//  main.cpp
//  _08_compute_circle
//
//  Created by Masatoshi Nishiguchi on 11/17/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

/*
 ANALYSIS
 The distance of the two points P1: (2, 2) P2: (3, 3)
 distance = sqrt of { (3-2)^2 + (3-2)^2 } = 1.414...

 OUTPUT
 1.41421
 */
double computeDistance(double x1,
                       double y1,
                       double x2,
                       double y2) {
    double delta_x = x1 - x2;
    double delta_y = y1 - y2;

    return sqrt( pow(delta_x, 2.0) + pow(delta_y, 2.0) );
}

/*
 ANALYSIS
 The distance of P1: (3, 1) P2: (4, 7)
 distance = sqrt of { (3-4)^2 + (1-7)^2 } = 6.0827625...

 OUTPUT
 6.08276
 */
double computeRadius(double ox,
                     double oy,
                     double px,
                     double py) {
    return computeDistance( ox, oy, px, py );
}

/*
 ANALYSIS
 The circumference of a circle with the radius of 7
 circumference = 2 * 3.1416 * 7 = 43.9824

 OUTPUT
 43.9824
 */
double computeCircumference( double radius ) {
    const double PI = 3.1416;
    return 2 * PI * radius;
}

/*
 ANALYSIS
 The area of a circle with the radius of 7
 area = 3.1416 * 7^2 = 153.9384

 OUTPUT
 153.938
 */
double computeArea( double radius ) {
    const double PI = 3.1416;
    return PI * pow( radius, 2.0 );
}


int main() {
    double x1, y1, x2, y2, radius;

    // distance between P1(2, 2) and P2(3, 3)
    x1 = 2;
    y1 = 2;
    x2 = 3;
    y2 = 3;
    cout << "The distance between (" << x1 << ", " << y1 << ") and ("
         << x2 << ", " << y2 << ") is "
         << computeDistance(2,2,3,3) << endl;

    cout << "-----------------------------" << endl;

    // radius of the circle with O(3, 1) and P(4, 7)
    x1 = 3;
    y1 = 1;
    x2 = 4;
    y2 = 7;
    cout << "The radius of a circle with the center O(" << x1 << ", " << y1
         << ") and another point P(" << x2 << ", " << y2 << ") is "
         << computeRadius(3,1,4,7) << endl;

    cout << "-----------------------------" << endl;

    // circumference of a circle with the radius of 7
    radius = 7.0;
    cout << "The circumference of a circle with the radius of " << radius << " is "
         << computeCircumference(7) << endl;

    cout << "-----------------------------" << endl;

    // area of a circle with the radius of 7
    radius = 7.0;
    cout << "The area of a circle with the radius of " << radius << " is "
         << computeArea(7) << endl;

    return 0;
}

/*
 OUTPUT
 
 The distance between (2, 2) and (3, 3) is 1.41421
 -----------------------------
 The radius of a circle with the center O(3, 1) and another point P(4, 7) is 6.08276
 -----------------------------
 The circumference of a circle with the radius of 7 is 43.9824
 -----------------------------
 The area of a circle with the radius of 7 is 153.938
 */
