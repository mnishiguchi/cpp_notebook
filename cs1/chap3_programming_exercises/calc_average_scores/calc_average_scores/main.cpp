//
//  main.cpp
//  calc_average_scores
//
//  Calculates the average scores.
//  Reads a name and five scores from the file named "test_scores.txt".
//  Write the result tot he file named "test_scores_average.out".
//
//  Created by Masatoshi Nishiguchi on 9/27/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    // Declare variables
    ifstream inFile;
    ofstream outFile;

    const int NUM_SCORES = 5;
    double scores[NUM_SCORES];
    double sum;
    string firstName, lastName;

    // Open the files (absolute path)
    inFile.open("/Users/masa/data_cpp_exercises/test_scores.txt");
    outFile.open("/Users/masa/data_cpp_exercises/test_scores_average.txt");

    // Format the output
    // a fixed decimal format with a decimal point and trailing zeros
    outFile << fixed << showpoint;
    // with two decimal places
    outFile << setprecision(2);

    outFile << "Processing data" << endl;

    // Read the username
    inFile >> firstName >> lastName;
    // Output the username
    outFile << "Name: " << firstName << " " << lastName << endl;

    // Read the five scores
    for (int i = 0; i < NUM_SCORES; i++) {
        inFile >> scores[i];
    }
    // Output the five scores
    outFile << "Scores: ";
    for (int i = 0; i < NUM_SCORES; i++) {
        outFile << setw(6) << scores[i];
    }
    outFile << endl;

    // Calculate the sum of the five scores
    for (int i = 0; i < NUM_SCORES; i++) {
        sum += scores[i];
    }
    // Output the average
    outFile << "Average score: " << setw(6) << (sum / NUM_SCORES) << endl;

    // Close the files
    inFile.close();
    outFile.close();

    return 0;
}
