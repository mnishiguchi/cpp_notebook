//
//  main.cpp
//  _16_milk_production
//
//  a. Prompts the user to enter the total amount of milk produced in the morning.
//  b. Outputs the number of milk cartons needed to hold milk. (Round your answer to the nearest integer.)
//  c. Outputs the cost of producing milk.
//  d. Outputs the profit for producing milk.
//
//  Created by Masatoshi Nishiguchi on 9/19/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>

/*
A milk carton can hold 3.78 liters of milk.
Each morning, a dairy farm ships cartons of milk to a local grocery store.
The cost of producing one liter of milk is $0.38, and
the profit of each carton of milk is $0.27.
 */

/*
 Analysis
 
 // Constants
 const double CAPACITY_CARTON  (3.78)
 const double COST_PER_LITER   (0.38)
 const double PROFIT_PER_LITER (0.27)
 
 // Variables
 int numCarton
 double cost
 double profit
 
 // Input
 double amountMilk
 
 // Processing
 numCartons = amountMilk / CAPACITY_CARTON
 cost       = amountMilk * COST_PER_LITER
 profit     = amountMilk * PROFIT_PER_LITER
 
 // Output
 numCarton
 cost
 profit
 */

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // Constants
    const double CAPACITY_CARTON  = 3.78;
    const double COST_PER_LITER   = 0.38;
    const double PROFIT_PER_LITER = 0.27;
    
    // Variables
    int numCartons;
    double cost;
    double profit;
    
    // Input
    double amountMilk;
    cout << "Please enter the total amount of milk produced: ";
    cin >> amountMilk;
    cout << endl;
    
    // Processing
    numCartons = amountMilk / CAPACITY_CARTON;
    cost       = amountMilk * COST_PER_LITER;
    profit     = amountMilk * PROFIT_PER_LITER;
    
    // Output
    cout << "the number of milk cartons needed: " << numCartons << endl;
    cout << "the cost of producing milk:        " << cost << endl;
    cout << "the profit for producing milk:     " << profit << endl;
    
    return 0;
}