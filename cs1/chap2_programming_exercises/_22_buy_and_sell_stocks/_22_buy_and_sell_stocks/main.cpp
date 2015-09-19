//
//  main.cpp
//  _22_buy_and_sell_stocks
//
//  Allows the user to input:
//    the number of shares sold,
//    the purchase price of each share, and
//    the selling price of each share.
//
//  Outputs:
//    the amount invested,
//    the total service charges,
//    the amount gained or lost, and
//    the amount received after selling the stock.
//
//  Created by Masatoshi Nishiguchi on 9/19/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

/*
 Cindy uses the services of a brokerage firm to buy and sell stocks.
 The firm charges 1.5% service charges on the total amount for each transaction, buy or sell.
 When Cindy sells stocks, she would like to know if she gained or lost on a particular investment.
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {

    const double SERVICE_CHARGE = 0.015;
    
    // Variables
    int numSharesSold = 0;
    double purchasePrice = 0.0;
    double sellingPrice  = 0.0;
    
    double amountInvested = 0.0;
    double amountSelling  = 0.0;
    double gainOrLoss     = 0.0;

    double totalServiceCharges = 0.0;
    double amountReceived      = 0.0;
    
    // Input
    cout << "the number of shares sold: ";
    cin >> numSharesSold;

    cout << "the purchase price of each share: $";
    cin >> purchasePrice;

    cout << "the selling price of each share:  $";
    cin >> sellingPrice;
    
    // Processing
    amountInvested       = numSharesSold * purchasePrice;
    totalServiceCharges += (amountInvested * SERVICE_CHARGE);
    
    amountSelling        = numSharesSold * sellingPrice;
    totalServiceCharges += (amountSelling * SERVICE_CHARGE);
    
    gainOrLoss     =  amountSelling - amountInvested;
    
    amountReceived = amountSelling - totalServiceCharges;
    
    // Output
    cout << fixed << setprecision(2) << right;
    
    cout << setw(40) << setfill('*') << "" << setfill(' ') << endl;  // Separator
    cout << "the amount invested:       " << setw(10) << amountInvested << endl;
    cout << "the amount gained or lost: " << setw(10) << gainOrLoss << endl;
    cout << "the total service charges: " << setw(10) << totalServiceCharges << endl;
    cout << endl;
    cout << "the amount received:       " << setw(10) << amountReceived << endl;

    return 0;
}