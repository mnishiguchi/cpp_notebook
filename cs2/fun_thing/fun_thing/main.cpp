//
//  main.cpp
//  fun_thing
//
//  Created by Masatoshi Nishiguchi on 2/9/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//
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

  // A pointer for testing.
  FunThing* testPtr = NULL;


  // 2) Declare an instance.
  FunThing coding( 56, "C++" );


  // 3) Declare an array of 3 instances.
  // Make up attribute values as needed.
  // Note, we are using only the 2-param constructor.
  // That is, you should NOT make a default constructor at this time.

  FunThing things[ 3 ] = {

    FunThing( 83, "TypeScript" ),
    FunThing( 48, "JavaScript" ),   // Least fun
    FunThing( 95, "Ruby" )          // Funnest

  };


  // 8) Declare a pointer to FunThing called ftp.
  // Point ftp to a new dynamic instance of FunThing.
  FunThing* ftp = new FunThing( 100, "Vacation" );


  // 10) Declare an array of Modern to four elements like: Modern funGames[4];
  Modern funGames[4];

  // 11) Set the funLevel of all the modern games to 3 in an efficient way.
  for ( int i = 0; i < 4; i++ ) {
    funGames[ i ].setFunLevel(3);
  }
  cout << "printing all the modern games' fun levels..." << endl;
  for ( int i = 0; i < 4; i++ ) {
    cout << "Modern #" << i << ": " << funGames[ i ].getFunLevel() << endl;
  }

  cout << "====================================================================" << endl;

  // Print all
  cout << "Printing all the fun things..." << endl;
  printFunThings(things, 3);
  cout << endl;

  cout << "====================================================================" << endl;

  // Test : getThingNameFunnest( FunThing things[], int size )

  string thingName = "";
  cout << "===>Test : getThingNameFunnest( FunThing things[], int size )" << endl;
  cout << endl;

  thingName = getThingNameFunnest( things, 3 );
  cout << "getThingNameFunnest:  " << thingName << endl;
  cout << "====================================================================" << endl;

  // Test : getPointerLeastFun( FunThing things[], int size )

  cout << "===>Test : getPointerLeastFun( FunThing things[], int size )" << endl;
  cout << endl;

  testPtr = getPointerLeastFun( things, 3 );
  cout << "getPointerLeastFun:  " << testPtr << endl;
  cout << "accessing its members..." << endl;
  cout << "  name:              " << testPtr->getThingName() << endl;
  cout << "  fun level:         " << testPtr->getFunLevel() << endl;
  cout << "====================================================================" << endl;

  // Test : findFunThing( string matchThis, FunThing things[], int size )

  cout << "===>Test : findFunThing( string matchThis, FunThing things[], int size )" << endl;
  cout << endl;

  cout << "searching for \"Ruby\"..." << endl;
  testPtr = findFunThing( "Ruby", things, 3 );
  if ( testPtr != NULL ) {
    cout << "findFunThing:        " << testPtr << endl;
    cout << "accessing its members..." << endl;
    cout << "  name:              " << testPtr->getThingName() << endl;
    cout << "  fun level:         " << testPtr->getFunLevel() << endl;
  } else {
    cout << "not found" << endl;
  }

  cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

  cout << "searching for \"C++\"..." << endl;
  testPtr = findFunThing( "C++", things, 3 );
  if ( testPtr != NULL ) {
    cout << "findFunThing:        " << testPtr << endl;
    cout << "accessing its members..." << endl;
    cout << "  name:              " << testPtr->getThingName() << endl;
    cout << "  fun level:         " << testPtr->getFunLevel() << endl;
  } else {
    cout << "not found" << endl;
  }

  cout << "====================================================================" << endl;

  cout << endl;

  return 0;

} // end main
