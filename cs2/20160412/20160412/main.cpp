//
//  main.cpp
//  20160412
//
//  Created by Masatoshi Nishiguchi on 4/12/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * An abstract class.
 */
class Person {
public:
    virtual bool isSuper()=0;
};

/**
 * A class that implements the Person class.
 */
class Programmer : public Person {
public:
    bool isSuper() { return true; }
};

int main() {

    // Bad example.
    // Programmer masa;
    // vector<Person> people;
    // people.push_back( masa );  // Error: because Person cannot be instantiated.

    //=================

    // Good example
    Programmer* masa = new Programmer;
    vector<Person*> people;
    people.push_back( masa );  // Good:

    return 0;
}
