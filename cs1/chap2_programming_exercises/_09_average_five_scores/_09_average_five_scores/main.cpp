//
//  main.cpp
//  _09_average_five_scores
//
//  Created by Masatoshi Nishiguchi on 9/18/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    const int NUM_SCORES = 5;
    
    double scores[NUM_SCORES];
    double sum = 0.0;
    
    // Prompt user to enter five scores
    cout << "Please enter five scores, one at a time" << endl;
    
    for (int i = 0; i < NUM_SCORES; i++) {
        
        // Get one score at a time and store it in a variable
        cout << "  Score #" << (i + 1) << ": ";
        cin >> scores[i];
        
        cin.clear();            // Restore input stream
        cin.ignore(100, '\n');  // Clear the buffer
        
        // Add the score to the sum
        sum += scores[i];
    }
    
    // Calculate and print the avarage
    cout << endl;
    cout << "The average score is " << sum / NUM_SCORES << endl;
    
    return 0;
}
