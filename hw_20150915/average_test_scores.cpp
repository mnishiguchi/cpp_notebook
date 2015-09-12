//
//  average_test_scores.cpp
//
//  Created by Masatoshi Nishiguchi on 9/12/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

// prompts the user to enter five test scores
// prints the average test score

int main() {
    // Declare variables to store five test scores
    const int NUM_SCORES = 5;
    double scores[NUM_SCORES];
    double average = 0.0;
    double sum     = 0.0;

    // Prompt the user to input five test scores and store them in variables
    cout << "Please enter five test scores (one at a time)" << endl;
    for (int i = 0; i < NUM_SCORES; i++) {

        // Prompt the user for each score
        cout << "Score#" << i + 1 << ": ";

        // Store a score
        cin >> scores[i];

        // Add the score to the sum
        sum += scores[i];
    }

    // Calculate the average score
    average = sum / NUM_SCORES;

    // Print the average score
    cout << "Your average score: " << average << endl;

    return 0;
}
