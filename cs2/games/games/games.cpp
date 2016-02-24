//
//  Computer Science II
//  Lecture Project: Games List Class
//
//  Masatoshi Nishiguchi
//
//  Due: Wednesday, March 2, 2016 7:32 PM
//


#include <iostream>
#include <string>
using namespace std;


//---------------------------------------------------------
//  class FunThing
//---------------------------------------------------------


/**
 * The FunThing class represents a fun thing that has a name and fun level.
 */
class FunThing {
public:
  // Constructors.
  FunThing() {
    funLevel  = -999;
    thingName = "untitled";
  }
  FunThing( string thingName, int funLevel ) {
    this->funLevel  = funLevel;
    this->thingName = thingName;
  }

  // Destructor.
  // - No need for custom destructor because this class does not allocate any dynamic variables.

  // Copy constructor.
  // - No need for custom copy because this class does not contain any pointer members.

  // Setters & getters.
  int getFunLevel() const { return funLevel; }
  void setFunLevel( int funLevel ) { this->funLevel = funLevel; }
  string getThingName() const { return thingName; }
  void setThingName( string thingName ) { this->thingName = thingName; }

private:
  int funLevel;
  string thingName;

}; // end class FunThing


//---------------------------------------------------------
//  class Games
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
  Games( int chunk ) {
    this->chunk = chunk;
    this->count = 0;
    this->data  = NULL;
  }

  // Destructor. Clean up all the dynamic variables.
  ~Games() { deleteData(); }

  // Override the copy constructor because this class contains a pointer member.
  Games( const Games& other );

  // Public API.
  void add( string thingName, int funLevel );
  // void add( const FunThing& thing );
  void deleteData();
  bool exists( string thingName );
  int getCount() const { return count; }

private:
  int chunk;        // The current capacity of the list.
  int count;        // The current number of the elements.
  FunThing** data;  // Array of FunThing pointers.

  // Private helper methods.
  void extendCapacity();
  bool isEmpty() { return count == 0; }
  bool isFull() { return count == chunk; }

}; // end class Games


/**
 * The custom copy constructor.
 * Initialize the new instance. (Deep copy the other instance to the new one)
 */
Games::Games( const Games& other ) {

  // Copy the values of chunk and count.
  chunk = other.chunk;
  count = other.count;

  // Allocate the new array instance that is the same size as the other's.
  data = new FunThing*[ chunk ];

  // Deep-copy the values of other's data into this collection.
  for ( int i = 0; i < count; i++ ) {

    data[ i ]->setThingName( other.data[ i ]->getThingName() );
    data[ i ]->setFunLevel( other.data[ i ]->getFunLevel() );

  }

} // end constructor


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

} // end add


// void Games::add( const FunThing& thing ) {
//   FunThing ftp = FunThing( thing );
// }


/**
 * Clean up all the dynamic variables.
 */
void Games::deleteData() {

  // Iterate over the collection for the current element count.
  for ( int i = 0; i < count; i++ ) {

    delete data[ i ];

  }

} // end deleteData


/**
 * @return true if a FunThing with the specified name exists in the collection,
 * else false.
 */
bool Games::exists( string thingName ) {

  // Iterate over the collection for the current element count.
  for ( int i = 0; i < count; i++ ) {

      // Return true if found.
      if ( data[ i ]->getThingName() == thingName ) { return true; }

  }

  // If not found, return false.
  return false;

} // end exists


/**
 * Extend the capacity of the data by one chunk.
 */
void Games::extendCapacity() {

  // Remember the address of the old collection.
  FunThing** old = data;

  // Create a new collection that is longer than the old one by one chunk.
  data = new FunThing*[ count + chunk ];

  // Shallow-copy all the pointers stored in the old collection into the new one.
  for ( int idx = 0; idx < count; idx++ ) {

      data[ idx ] = old[ idx ];

  }

  // Delete the old collection.
  delete [] old;

} // end extendCapacity


//---------------------------------------------------------
//  The test functions
//---------------------------------------------------------


// TODO



//---------------------------------------------------------
//  The main function of this program
//---------------------------------------------------------


int main() {

//    Games* toyBox;
//    toyBox = new Games;
//
//    FunThing




    return 0;
}
