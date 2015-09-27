//
//  main.cpp
//  _05_ticket_sales
//
//  Calculates the total ticket sales after each game.
//  Reads the sales data of four types of tickets from a file.
//  Write the total ticket sales in another file.
//
//  Created by Masatoshi Nishiguchi on 9/27/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {

    ifstream inFile;
    ofstream outFile;

    double priceBox;
    double priceSideline;
    double pricePremium;
    double priceGeneral;

    int numBox;
    int numSideline;
    int numPremium;
    int numGeneral;

    // Open the files
    inFile.open("/Users/masa/data_cpp_exercises/chap3_05_inData.txt");
    outFile.open("/Users/masa/data_cpp_exercises/outData.txt");

    // Read the file
    inFile >> priceBox >> numBox
           >> priceSideline >> numSideline
           >> pricePremium >> numPremium
           >> priceGeneral >> numGeneral;

    // Output
    outFile << fixed << showpoint << setprecision(2);
    outFile << setw(8) << "TYPE" << setw(8) << "PRICE" << setw(8) << "COUNT" << endl
        << setfill('-') << setw(24) << "" << setfill(' ') << endl
        << setw(8) << "Box" << setw(8) << priceBox << setw(8) << numBox << endl
        << setw(8) << "Sideline" << setw(8) << priceSideline << setw(8) << numSideline << endl
        << setw(8) << "Premium" << setw(8) << pricePremium << setw(8)<< numPremium << endl
        << setw(8) << "General" << setw(8) << priceGeneral << setw(8) << numGeneral << endl;

    outFile << endl;
    outFile << "TOTAL SALES: $" << (priceBox * numBox)
        + (priceSideline * numSideline)
        + (pricePremium * numPremium)
        + (priceGeneral * numGeneral)
        << endl;

    // Close the files
    inFile.close();
    outFile.close();

    return 0;
}
