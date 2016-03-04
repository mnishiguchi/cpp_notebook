//
//  Computer Science II
//  Mid-tem exam : Problem 2
//
//  Masatoshi Nishiguchi
//
//  Created by Masatoshi Nishiguchi on 3/3/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//


#include <iostream>
#include <string>
using namespace std;


class Building {
public:
  // Constructor.
  Building( int a, char b ) {

    this->a = a;
    this->b = b;

  }

  int a;
  char b;
};


//===================================================================//


/**
 * Problem #2
 * A subclass of the class Building.
 * Add code to HouseOfCards class that will enable this code to run.
 * Required.
 * Add code ONLY to HouseOfCards.
 * The code doesn't have to make sense,
 * just add code so that the program runs.
 */
class HouseOfCards : public Building {
public:

  // Constructor that takes two arguments and
  // pass them to its parent constructor.
  HouseOfCards( int a, char b ) : Building( a, b ) {}



};

// Operator overload so that we can use the << operator to output HouseOfCards
// objects.
ostream& operator<<( ostream& os, const HouseOfCards& obj ) {

    return os << "{ a: " << obj.a << ", b: " << obj.b << " }" << endl;

}


//===================================================================//


/**
 * The main function.
 */
int main() {

  HouseOfCards* hoc = new HouseOfCards( 3, 'h' );
  cout << hoc[ 0 ];

}
