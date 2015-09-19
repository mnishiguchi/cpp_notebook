//
//  main.cpp
//  _13_selling_price_final_price
//
//  To make a profit, a local store marks up the prices of its items by a certain percentage.
//  Reads the original price of the item sold, the percentage of the marked-up price,
//  and the sales tax rate.
//  Outputs the original price of the item, the percentage of the mark-up,
//  the store’s selling price of the item, the sales tax rate, the sales tax,
//  and the final price of the item.
//  (The final price of the item is the selling price plus the sales tax.)
//
//  Created by Masatoshi Nishiguchi on 9/18/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    // Variable declaration
    double cost, markUpPercentage, salesTaxPercentage = 0.0;
    double sellingPrice, salesTax, finalPrice = 0.0;

    // Prompt the user for the original price, the mark-up percentage and the sales tax rate
    cout << "The original price of the item: ";
    cin >> cost;
    
    cout << "The mark up percentage:   ";
    cin >> markUpPercentage;
    
    cout << "The sales tax percentage: ";
    cin >> salesTaxPercentage;
    
    // Calculate the selling price, sales tax, and final price
    sellingPrice = cost * (1 + (markUpPercentage / 100) );
    salesTax     = sellingPrice * (salesTaxPercentage / 100);
    finalPrice   = sellingPrice + salesTax;
    
    //  Output
    cout << endl;
    cout << "the original price:            $" << cost << endl;
    cout << "the percentage of the mark-up: " << markUpPercentage<< "%"  << endl;
    cout << "the store’s selling price:     $" << sellingPrice << endl;
    cout << "the sales tax rate:            " << salesTaxPercentage << "%" << endl;
    cout << "the sales tax:                 $" << salesTax << endl;
    cout << "the final price:               $" << finalPrice << endl;
    
    return 0;
}
