//
//  main.cpp
//  _01_basic_file_input_output
//
//  Created by Masatoshi Nishiguchi on 9/19/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    // Declare the file variables
    ifstream inFile;
    ofstream outFile;

    string firstName, lastName, department;
    double monthlySalary, bonusRate, taxRate, payCheck;
    double distanceTraveled, travelingTime, averageSpeed;
    int numCoffeeSold;
    double costPerCup, salesAmount;

    // Open the files
    inFile.open("/Users/masa/data_cpp_exercises/chap3_1_inData.txt");
    outFile.open("/Users/masa/data_cpp_exercises/outData.txt");

    // name and department
    inFile >> firstName >> lastName >> department;
    outFile << "Name: " << firstName << " " << lastName << ", Department: " << department << endl;

    // salary, bonus, taxRate and paycheck
    inFile >> monthlySalary >> bonusRate >> taxRate;

    payCheck = monthlySalary * (1.0 + bonusRate / 100);
    payCheck *= (1.0 - taxRate / 100);

    outFile << "Monthly Gross Salary: " << monthlySalary
    << ", Monthly Bonus: " << bonusRate << "%, taxes: " << taxRate << "%" << endl
    << "Paycheck: $" << payCheck << endl;

    // traveling
    inFile >> distanceTraveled >> travelingTime;

    averageSpeed = distanceTraveled / travelingTime;

    outFile << endl;
    outFile << "Distance Traveled: " << distanceTraveled << " miles, "
    << "Traveling Time: " << travelingTime << " hours" << endl
    << "Average speed: " << averageSpeed << " miles per hour" << endl;

    // coffee sales
    inFile >> numCoffeeSold >> costPerCup;

    salesAmount = numCoffeeSold * costPerCup;

    outFile << endl;
    outFile << "Number of Coffee Sold: " << numCoffeeSold << " miles, "
    << "Cost: " << costPerCup << " per cup" << endl
    << "Sales Amount: $" << salesAmount << endl;

    // Close the files
    inFile.close();
    outFile.close();

    return 0;
}
