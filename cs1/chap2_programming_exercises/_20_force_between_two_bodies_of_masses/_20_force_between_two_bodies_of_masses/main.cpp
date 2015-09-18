//
//  main.cpp
//  _20_force_between_two_bodies_of_masses
//
//  Prompts the user to input the masses of the bodies and the distance between the bodies.
//  Then outputs the force between the bodies.
//
//  Created by Masatoshi Nishiguchi on 9/18/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

/* === ANALYSIS ===
 
 // constants
 const double GRAVITATIONAL_CONSTANT = 6.67E-8;
 
 // variables
 double mass1, mass2;  // The two bodies of masses
 double distance;      // The distance between the two bodies
 double force;
 
 // assignment statements
 cin >> mass1;
 cin >> mass2;
 cin >> distance;
 
 // calculations
 The formula to calculate the force between the bodies
    force = GRAVITATIONAL_CONSTANT * ( (mass1 * mass2) / (distance * distance) );
 
 If mass1 is 70000, mass2 is 80000, distance is 250,
    force = ( 6.67E-8 ) * ( (70000 * 80000) / (250 * 250) ) = 0.00597632
 */

/* === PROGRAM === */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    // Constants
    const double GRAVITATIONAL_CONSTANT = 6.67E-8;
    
    // Variable declaration
    double mass1, mass2 = 0.0;  // The two bodies of masses
    double distance = 0.0;
    double force    = 0.0;
    
    // Prompt the masses of the bodies and the distance between the bodies
    cout << "Enter the mass1: ";
    cin >> mass1;
    
    cout << "Enter the mass2: ";
    cin >> mass2;
    
    cout << "Enter the distance between the bodies: ";
    cin >> distance;
    
    cout << endl;

    // Calculate the force between the bodies
    force = GRAVITATIONAL_CONSTANT * ( (mass1 * mass2) / pow(distance, 2) );
    
    // Print the result
    cout << "The force between the bodies is " << force << endl;
    
    return 0;
}

/* === ACTUAL OUTPUT ===
 
 Enter the mass1: 70000
 Enter the mass2: 80000
 Enter the distance between the bodies: 250
 
 The force between the bodies is 0.00597632
 */
