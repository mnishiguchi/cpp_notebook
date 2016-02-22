/**
 * Games List Class - Lecture Project
 * Due Date: Wednesday, March 2, 2016 7:32 PM
 *
 * Masatoshi Nishiguchi
 */

#include <iostream>
#include <string>
using namespace std;


//---------------------------------------------------------
//  Declare class FunThing
//---------------------------------------------------------


/**
 * The FunThing class represents a fun thing that has a name and fun level.
 */
class FunThing {
public:
  // Constructors
  FunThing();
  FunThing( string thingName, int funLevel );

  // Destructor
  // - No need for custom destructor because this class does not allocate any dynamic variables.

  // Copy constructor
  // - No need for custom copy because this class does not contain any pointer members.

  // Setter & getter
  int getFunLevel() const;
  void setFunLevel( int funLevel );

  string getThingName() const;
  void setThingName( string thingName );

private:
  int funLevel;
  string thingName;
}; // end FunThing


//---------------------------------------------------------
//  Implement class FunThing
//---------------------------------------------------------


/**
 * The default constructor that sets the default values of the attributes.
 */
FunThing::FunThing() {

  this->funLevel  = -999;
  this->thingName = "untitled";

}
/**
 * A 2-param constructor that sets the initial values of the attributes.
 */
FunThing::FunThing( string thingName, int funLevel ) {

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


//---------------------------------------------------------
//  Declare class Games
//---------------------------------------------------------


/**
 * The Games class represents a dynamic collection of the FunThing pointers.
 * - When the list gets full, it will be extended by chunk.
 * - Upon instantiation, this dynamic array should be set to NULL.
 *
 * - The Games class must have the ability to add FunThings by allocating a new
 * instance of FunThing and adding that to the array.
 * - The array should dynamically grow in capacity by a certain number of elements
 * called chunk.
 * - That chunk number of elements will be indicated by a private class member
 * called chunk.
 *
 * IMPORTANT: Dealloacate all the dynamically created instances.
 */
class Games {
public:

  // Constructor.
  Games( int chunk );

  // Destructor
  // This class allocates dynamic variables.
  ~Games();

  // Copy constructor
  // This class contains a pointer member.
  Games( const Games& other );

  void add( string thingName, int funLevel );
  void deleteData();
  int getCount() const;
  bool exists( string thingName );

private:

  // Array of FunThing pointers
  FunThing** data;

  // The current capacity of the list.
  int chunk;

  // The current number of the elements.
  int count;

  bool isEmpty() { return count == 0; }
  bool isFull() { return count == this->chunk; }

  void extendCapacity();
};


//---------------------------------------------------------
//  Implement class FunThing
//---------------------------------------------------------


/**
 * The default constructor.
 */
Games::Games( int chunk ) {

  this->data  = NULL;
  this->chunk = chunk;
  this->count = 0;
}

/**
 * The custom destructor.
 */
Games::~Games() {

  // Clean up all the dynamic variables.
  deleteData();

}

/**
 * The custom copy constructor.
 * Initialize the new instance. (Deep copy the other instance to the new one)
 */
Games::Games( const Games& other ) {

  // Copy the values of chunk and count.
  this->chunk = other.chunk;
  this->count = other.count;

  // Allocate the new array instance that is the same size as the other's.
  this->data = new FunThing*[ chunk ];

  // Deep-copy the values of other's data into this collection.
  for ( int i = 0; i < count; i++ ) {

    data[ i ]->setThingName( other.data[ i ]->getThingName() );
    data[ i ]->setFunLevel( other.data[ i ]->getFunLevel() );

  }

}

/**
 * Create a newFunThing and add it to the collection.
 * @param thingName [description]
 * @param funLevel  [description]
 */
void Games::add( string thingName, int funLevel ) {

  // Allocate a new FunThing.
  FunThing* thing = new FunThing( thingName, funLevel );

  // If empty, initialize the data collection.
  // Dynamically creating an array of FunThing pointers.
  if ( isEmpty() ) { data = new FunThing*[ chunk ]; }

  // If full, extend the capacity.
  if ( isFull() ) { extendCapacity(); }

  // Add it to the collection.
  data[ count ] = thing;

  // Update the count.
  count += 1;

}

/**
 * Clean up all the dynamic variables.
 */
void Games::deleteData() {

  for ( int i = 0; i < count; i++ ) {

    delete data[ i ];

  }

}


/**
 * @return the current number of elements it is holding.
 */
int Games::getCount() const {

  return count;

}

/**
 * @return true if a FunThing with the specified name exists in the collection, else false.
 */
bool Games::exists( string thingName ) {

  // Iterate over the collection for the current element count.
  for ( int i = 0; i < count; i++ ) {

      if ( data[ i ]->getThingName() == thingName ) { return true; }

  }

  // If not found, return false.
  return false;

}


/**
 * Extend the capacity of the data by one chunk.
 */
void Games::extendCapacity() {

  // The link to old collection.
  FunThing** temp = data;

  // Create a new collection.
  data = new FunThing*[ count + chunk ];

  // Shallow-copy all pointers ionto the new collection.
  for ( int idx = 0; idx < count; idx++ ) {

      data[ idx ] = temp[ idx ];

  }

  // Delete the old collection.
  delete[] temp;

}


//---------------------------------------------------------
//  The test functions
//---------------------------------------------------------


// TODO



//---------------------------------------------------------
//  The main function of this program
//---------------------------------------------------------


int main() {






    return 0;
}
