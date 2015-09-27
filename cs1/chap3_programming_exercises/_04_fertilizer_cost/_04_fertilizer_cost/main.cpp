//
//  main.cpp
//  _04_fertilizer_cost
//
//  Created by Masatoshi Nishiguchi on 9/27/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    double cost;
    double area;
    
    double bagSize;
    
    cout << fixed << showpoint << setprecision(2);
    
    cout << "Enter the amout of fertilizer, in pounds, in one bag: ";
    cin >> bagSize;
    cout << endl;
    
    cout << "Enter the cost of the " << bagSize << " fertilizer bag: ";
    cin >> cost;
    cout  << endl;
    
    cout << "Enter the area, in square feet, that can be fertilized by one bag: ";
    cin >> area;
    cout  << endl;
    
    cout << "The cost of the fertilizer per pound is:       $" << setw(6) << cost / bagSize << endl;
    cout << "The cost of the fertilizer per square foot is: $" << setw(6) << cost / area << endl;

    return 0;
}
