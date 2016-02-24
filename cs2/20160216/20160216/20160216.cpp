//
//  main.cpp
//  20160216
//
//  Created by Masatoshi Nishiguchi on 2/16/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


//====================================================//
// Declaration of the classes
//====================================================//


/**
 * Include only a 2-param constructor that set sthe initial values of the attributes.
 */
class FunThing {
public:

  FunThing( int funLevel, string thingName );

  // Setter & getter
  int getFunLevel() const;
  void setFunLevel( int funLevel );

  string getThingName() const;
  void setThingName( string thingName );

private:
  int funLevel;
  string thingName;

}; // end FunThing


/**
 * Subclass of FunThing
 * MUST implement the same 2-arg constructor as FunThing.
 */
class ParlorGame : public FunThing {
public:

  // Constructor
  ParlorGame( int funLevel, string thingName )
    // Pass the funLevel and thingName to the parent's constructor.
    : FunThing( funLevel, thingName ) {}

  // Contains a string method called getPeopleNames().
  string* getPeopleNames() const;

private:
  string* peopleNames;

}; // end ParlorGame


/**
 * A subclass of ParlorGame.
 */
class Modern : public ParlorGame {
public:

  /**
   * Default constructor
   * Set the default value of the funLevel to 0 and thingName to "Unknown".
   */
  Modern()
    // Pass the default values of the funLevel and thingName to the parent's constructor.
    : ParlorGame( 0, "Unknown" ) {}

};


/**
 * A subclass of FunThing that is an interface (virtual class).
 * Any subclass of BoardGame MUST implement an int method called howManyPieces().
 */
class BoardGame : public FunThing {
public:

  virtual int howManyPieces();

}; // end BoardGame



//====================================================//
// Implementation of the classes
//====================================================//


/**
 * A 2-param constructor that sets the initial values of the attributes.
 */
FunThing::FunThing( int funLevel, string thingName ) {

  this->funLevel  = funLevel;
  this->thingName = thingName;

}

// Setter & getter
int FunThing::getFunLevel() const {

  return this->funLevel;

}
void FunThing::setFunLevel( int funLevel ) {

  this->funLevel = funLevel;

}
string FunThing::getThingName() const {

  return this->thingName;

}
void FunThing::setThingName( string thingName ) {

  this->thingName = thingName;

}


//====================================================//
// Utility functions
//====================================================//


/**
 * getThingNameFunnest
 * @param  things    The list of the FunThing objects.
 * @param  size      The size of the list.
 * @return  the thingName of the element with the highest funLevel.
 */
string getThingNameFunnest( FunThing things[], int size ) {

  int funnestIndex = 0;

  // Iterate over the list.
  for ( int i = 0; i < size; i++ ) {

    // If the item is funner than the current funnest, update the funnestIndex.
    if ( things[ i ].getFunLevel() > things[ funnestIndex ].getFunLevel() ) {

      funnestIndex = i;

    }

  }

  // Return the thingName of the funnest thing.
  return things[ funnestIndex ].getThingName();

} // end getThingNameFunnest


/**
 * getPointerLeastFun
 * @param  things    The list of the FunThing objects.
 * @param  size      The size of the list.
 * @return  the memory address of the instance with the lowest funLevel.
 */
FunThing* getPointerLeastFun( FunThing things[], int size ) {

  int leastFunIndex = 0;

  // Iterate over the list.
  for ( int i = 0; i < size; i++ ) {

    // If the item is less fun than the current funnest, update the leastFunIndex.
    if ( things[ i ].getFunLevel() < things[ leastFunIndex ].getFunLevel() ) {

      leastFunIndex = i;

    }

  }

  // Return the memory address of the least fun thing.
  return &( things[ leastFunIndex ] );

} // end getPointerLeastFun


/**
 * Return a pointer to the FunThing instance where the thingName will match a parameter.
 * @param  matchThis The name of the FunThing to be searched for.
 * @param  things    The list of the FunThing objects.
 * @param  size      The size of the list.
 * @return           a pointer to the FunThing instance
 */
FunThing* findFunThing( string matchThis, FunThing things[], int size ) {

  // Iterate over the list.
  for ( int i = 0; i < size; i++ ) {

    // If the item's name matches the search term, return the address of that instance.
    if ( things[ i ].getThingName() == matchThis ) {

        return &( things[ i ] );

    }

  }

  // Return NULL if not found.
  return NULL;

} // end findFunThing


void printFunThing( const FunThing& thing ) {

    cout << "name      : " << thing.getThingName()  << endl;
    cout << "fun level : " << thing.getFunLevel() << endl;
    cout << "address   : " << &(thing) << endl;

} // end printFunThing


void printFunThings( FunThing things[], int size ) {

  // Iterate over the list.
  for ( int i = 0; i < size; i++ ) {

      cout << "----------------------------" << endl;
      printFunThing( things[ i ] );

  }

} // end printFunThings


//====================================================//
// Main Function
//====================================================//


int main() {

  double* d_1;
  d_1 = new double(11);

  double* d_2 = new double;
  *d_2 = 22;

  cout << "d_1: "  << d_1 << endl;  // d_1: 0x100100020
  cout << "d_2: "  << d_2 << endl;  // d_2: 0x100102c80
  cout << "*d_1: " << *d_1 << endl; // *d_1: 11
  cout << "*d_2: " << *d_2 << endl; // *d_2: 22

  return 0;

} // end main
