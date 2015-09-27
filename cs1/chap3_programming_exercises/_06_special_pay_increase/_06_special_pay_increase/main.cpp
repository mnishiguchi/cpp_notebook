//
//  main.cpp
//  _06_special_pay_increase
//
//  Created by Masatoshi Nishiguchi on 9/27/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <ios>
using namespace std;

int main() {

    ifstream inFile;
    ofstream outFile;
    
    string firstName, lastName = "";
    double currentSalary, payIncreasePercentage, updatedSalary = 0.0;
    
    // Open the files
    inFile.open("/Users/masa/data_cpp_exercises/chap3_06_inData.txt");
    outFile.open("/Users/masa/data_cpp_exercises/outData.txt");
    
    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Error opening a file" << endl;
    }
    
    // Print the column names
    outFile << left;
    outFile << setw(10) << "First" << setw(10) << "Last";
    outFile << right;
    outFile << setw(10) << "Current"  << setw(10) << "Updated" << endl;
    outFile << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    
    // Formatting for the output
    outFile << fixed << showpoint << setprecision(2);
    
    // Read each line from the file
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        ss >> firstName >> lastName >> currentSalary >> payIncreasePercentage;
        
        updatedSalary = currentSalary * (1.0 + payIncreasePercentage / 100.0);
        outFile << left;
        outFile << setw(10) << firstName << setw(10) << lastName;
        outFile << right;
        outFile << setw(10) << currentSalary << setw(10) << updatedSalary;
        outFile << endl;
    }

    // Close the files
    inFile.close();
    outFile.close();
    
    return 0;
}
