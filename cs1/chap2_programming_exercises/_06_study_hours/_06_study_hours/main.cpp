//
//  main.cpp
//  _06_study_hours
//
//  Prompts user to enter a name and study hours, then print an appropriate text
//  including the values of name and study hours.
//
//  Created by Masatoshi Nishiguchi on 9/18/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

/* === ANALYSIS ===
 
 // constant
 N/A
 
 // variables
 string name;
 double studyHours;
 
 // calculations
 N/A
 
 // assignment statement
 cin >> name >> studyHours;
 
 // Expected output
 If the value of name is "Donald" and the value of studyHours is 4.5:
    Hello, Donald! on Saturday, you need to study 4.5 hours for the exam.
 */

/* === PROGRAM === */

// a. include the header files iostream and string
#include <iostream>
#include <string>

// b. allows you to use cin, cout, and endl without the prefix std::
using namespace std;

int main() {
    // c. declare the following variables: name of type string and studyHours of type double
    string name;
    double studyHours;
    
    // d. prompt and input a string into name and a double value into studyHours
    cout << "Please enter your name and study hours: ";
    cin >> name >> studyHours;
    cout << endl;
    
    // e. output the values of name and studyHours with the appropriate text
    cout << "Hello, " << name << "! on Saturday, you need to study "
         << studyHours << " hours for the exam." << endl;
    
    return 0;
}

/* === ACTUAL OUTPUT ===

 Please enter your name and study hours: Donald 4.5
 
 Hello, Donald! on Saturday, you need to study 4.5 hours for the exam.
 */