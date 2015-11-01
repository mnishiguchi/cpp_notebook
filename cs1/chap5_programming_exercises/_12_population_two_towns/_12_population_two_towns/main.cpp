/*
 _12_population_two_towns

 Prompts user to enter the populaton of town and growth rate of each town.
 Outputs after how many years the population of town A will be greater than or equal to
 the populaton of town B, and the populations of both the towns.

 Requirements
 - initially, town_a < town_b
 - growth_rate_a > growth_rate_b

 Created by Masatoshi Nishiguchi on 10/29/15.
 Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
 */

/*
ANALYSIS

    If the input is A: 5000, 10%; B: 8000, 1%...
    Year 1 - A: 5500, B: 8080
    Year 2 - A: 6050, B: 8160
    Year 3 - A: 6655, B: 8241
    Year 4 - A: 7320, B: 8323
    Year 5 - A: 8052, B: 8406
    Year 6 - A: 8857, B: 8490 <==Town A has outgrown after 6 years

OUTPUT 1
    >>>Enter population and growth rate(%) of Town A (Example: 5000 4):
    5000 10
    >>>Enter population and growth rate(%) of Town B (Example: 8000 2):
    8000 1
    Years elapsed: 6
    Town A: 8857
    Town B: 8490

OUTPUT 2
    >>>Enter population and growth rate(%) of Town A (Example: 5000 4):
    5000 4
    >>>Enter population and growth rate(%) of Town B (Example: 8000 2):
    8000 2
    Years elapsed: 25
    Town A: 13308
    Town B: 13110
 */

#include <iostream>
using namespace std;

/**
 * Represents a town
 */
class Town {
public:
    int population;
    double growthRate;

    void grow() {
        population = static_cast<int>( population * (1 + growthRate / 100.0) );
    }
};

/**
 * Validate the inputted data
 */
bool isValidData(Town townA, Town townB) {
    return (townA.population < townB.population) &&
           (townA.growthRate  > townB.growthRate);
}

/**
 * The main function of this program
 */
int main() {

    // Declare townA and townB of Town type
    Town townA, townB;

    // Prompt for Town A's data
    bool finished = false;
    while (!finished) {
        cout << ">>>Enter population and growh rate(%) of Town A (Example: 5000 4): " << endl;
        cin >> townA.population >> townA.growthRate;  // Read the input

        // If cin is in a bad state, retry
        if (!cin) {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << ">>>Invalid input" << endl;
        } else {
            finished = true;
        }
    }

    // Prompt for Town B's data
    finished = false;
    while (!finished) {
        cout << ">>>Enter population and growh rate(%) of Town B (Example: 8000 2): " << endl;
        cin >> townB.population >> townB.growthRate;  // Read the input

        // If cin is in a bad state or inputted data is invalid, retry
        if (!cin || !isValidData(townA, townB)) {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << ">>>Invalid input: Must meet the following requirement" << endl;
            cout << "                  pop A    < pop B" << endl;
            cout << "                  growth A > growth B" << endl;
        } else {
            finished = true;
        }
    }

    // Computation
    int yearCount = 0;

    while (townA.population < townB.population) {
        yearCount++;
        townA.grow();
        townB.grow();
    }

    // Output the result
    cout << "Years elapsed: " << yearCount << endl;
    cout << "Town A: " << townA.population << endl;
    cout << "Town B: " << townB.population << endl;

    return 0;
}
