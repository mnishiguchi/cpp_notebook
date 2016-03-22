//
//  Computer Science II
//  Assignment: FunThing Part 2
//
//  Masatoshi Nishiguchi
//
//  Due: Wednesday, March 29
//


#include <iostream>
#include <string>
#include <assert.h>
using namespace std;


/*
------------
REQUIREMENTS
------------
1. DONE
2. DONE
3. DONE
-------
4. TODO
5. TODO
 */


//====================================================//
// FunThing class and its subclasses
//====================================================//


/**
 * An abstract class that represents a fun thing.
 * Include only a 2-param constructor that set sthe initial values of the attributes.
 */
class FunThing {
public:
  // Must now contain two purely virtual methods.
  virtual bool isDangerous()=0;
  virtual int getNumberOfPlayers()=0;

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
  // The destructor of the base class must be virtual.
  ~FunThing() {}

  // Copy constructor.
  // - No need for custom copy because this class does not contain any pointer members.

  // Setters & getters.
  int getFunLevel() const { return funLevel; }
  void setFunLevel( int funLevel ) { this->funLevel = funLevel; }
  string getThingName() const { return thingName; }
  void setThingName( string thingName ) { this->thingName = thingName; }

  // Overload the pre-increment operators that takes no argument.
  int operator++() {
    // Increment the funLevel and return.
    return ++funLevel;
  }

  // Overload the pre-decrement operators that takes no argument.
  int operator--() {
    // Decrement the funLevel and return.
    return --funLevel;
  }

private:
  int funLevel;
  string thingName;

}; // end FunThing


/**
 * Subclass of FunThing
 * CrazySport( numberOfPlayers )
 * CrazySport must be able to take as a constructor argument the number of players.
 * All instances of CrazySport considered dangerous.
 */
class CrazySport : public FunThing {
public:

  // Constructor
  CrazySport( int numberOfPlayers )
    // Pass the funLevel and thingName to the parent's constructor.
    : FunThing() {

      // Set the number of the players.
      this->numberOfPlayers = numberOfPlayers;

      // By default considered dangerous.
      this->dangerous = true;
    }

  int getNumberOfPlayers() { return this->numberOfPlayers; }
  bool isDangerous() { return this->dangerous; }

private:
  int numberOfPlayers;
  bool dangerous;

}; // end CrazySport


/**
 * Subclass of FunThing
 * DomesticChore( numberOfPlayers )
 * DomesticChore must be able to take as a constructor argument the number of players.
 * All instances of DomesticChore are NOT dangerous
 */
class DomesticChore : public FunThing {
public:

  // Constructor
  DomesticChore( int numberOfPlayers )
    // Pass the funLevel and thingName to the parent's constructor.
    : FunThing() {

      // Set the number of the players.
      this->numberOfPlayers = numberOfPlayers;

      // By default considered NOT dangerous.
      this->dangerous = false;
    }

  int getNumberOfPlayers() { return this->numberOfPlayers; }
    bool isDangerous() { return this->dangerous; }

private:
  int numberOfPlayers;
  bool dangerous;

}; // end DomesticChore


/**
 * Subclass of FunThing
 * GenericThing( numberOfPlayers, isdangerous )
 * GenericThing must accept number of players and whether or not it is dangerous.
 */
class GenericThing : public FunThing {
public:

  // Constructor
  GenericThing( int numberOfPlayers, bool isDangerous )
    // Pass the funLevel and thingName to the parent's constructor.
    : FunThing() {

      // Set the number of the players.
      this->numberOfPlayers = numberOfPlayers;

      // Set whether or not it is dangerous.
      this->dangerous = isDangerous;
    }

  int getNumberOfPlayers() { return this->numberOfPlayers; }
  bool isDangerous() { return this->dangerous; }

private:
  int numberOfPlayers;
  bool dangerous;

}; // end GenericThing


//====================================================//
// Games class
//====================================================//


/**
 * The Games class represents a dynamic collection of the FunThing pointers.
 * - When the list gets full, it will be extended by chunk.
 * - Upon instantiation, this dynamic array should be set to NULL.
 * - Has the ability to dynamically allocate a new instance of FunThing and
 * add that to the internal array.
 */
class Games {
public:
  // Constructor.
  Games( int chunk ) {
    this->chunk = chunk;
    this->count = 0;
    this->data  = NULL;
    this->size  = chunk;  // Initial size is initially set to chunk.
  }

  // Destructor. Clean up all the dynamic variables.
  ~Games() { deleteAll(); }

  // Override the copy constructor because this class contains a pointer member.
  Games( const Games& other );

  // Public API.
  void add( string thingName, int funLevel );
  bool contains( string thingName ) const;
  void deleteAll();
  int getChunk() const { return chunk; }
  int getCount() const { return count; }
  int getSize() const { return size; }
  FunThing** getData() const { return data; }
  bool isEmpty() { return count == 0; }
  bool isFull() { return ! isEmpty() && ( count % chunk == 0 ); }

private:
  int chunk;        // The amount by which the list size increment
  int count;        // The current number of the elements.
  int size;         // The current list size.
  FunThing** data;  // Array of FunThing pointers.

  // Private helper methods.
  void extendCapacity();

}; // end class Games


/**
 * The custom copy constructor.
 * Initialize the new instance. (Deep copy the other instance to the new one)
 */
Games::Games( const Games& other ) {

  // Copy the values of chunk and count.
  chunk = other.chunk;
  count = other.count;
  size  = other.size;

  // Allocate the new array instance that is the same size as the other's.
  data = new FunThing*[ chunk ];

  // Deep-copy the values of other's data into this collection.
  for ( int i = 0; i < count; i++ ) {

    data[ i ]->setThingName( other.data[ i ]->getThingName() );
    data[ i ]->setFunLevel( other.data[ i ]->getFunLevel() );

  }

} // end constructor


/**
 * TODO
 * Create a newFunThing and add it to the collection.
 * @param thingName A string
 * @param funLevel  An int
 */
void Games::add( string thingName, int funLevel ) {

  // Allocate a new FunThing.
  FunThing* thing = new FunThing( thingName, funLevel );

  // If empty, initialize the data collection.
  // Dynamically creating an array of FunThing pointers.
  if ( isEmpty() ) { data = new FunThing*[ chunk ]; }

  // If full, extend the capacity.
  if ( isFull() ) {
    extendCapacity();

    // // DEBUG
    // cout << "---extendCapacity---" << endl;
    // cout << "  count:" << count << endl;
    // cout << "  size:" << size  << endl;
  }

  // Add it to the collection.
  data[ count ] = thing;

  // Update the count.
  count += 1;

} // end add


/**
 * Clean up all the dynamic variables.
 */
void Games::deleteAll() {

  // Iterate over the collection for the current element count.
  for ( int i = 0; i < count; i++ ) {

    delete data[ i ];

  }

} // end deleteAll


/**
 * @return true if a FunThing with the specified name contains in the collection,
 * else false.
 */
bool Games::contains( string thingName ) const {

  // Iterate over the collection for the current element count.
  for ( int i = 0; i < count; i++ ) {

      // Return true if found.
      if ( data[ i ]->getThingName() == thingName ) { return true; }

  }

  // If not found, return false.
  return false;

} // end contains


/**
 * Extend the capacity of the data by one chunk.
 */
void Games::extendCapacity() {

  // Remember the address of the old collection.
  FunThing** old = data;

  // Update the size by one chunk.
  size += chunk;

  // Create a new collection with new size.
  data = new FunThing*[ size ];

  // Shallow-copy all the pointers stored in the old collection into the new one.
  for ( int i = 0; i < count; i++ ) {

      data[ i ] = old[ i ];

  }

  // Delete the old collection.
  delete [] old;

} // end extendCapacity


//====================================================//
// Utility functions
//====================================================//


/**
 * Print the information about all the data that the specified Games object holds.
 * @param games A Games object.
 * IMPORTANT: The Games object must be passed in by reference so that we can access
 * their memory locations.
 */
void printAll( const Games& games ) {

    sleep(1);  // Simulate latency.

    FunThing** data = games.getData();

    for ( int i = 0, len = games.getCount(); i < len; i++ ) {
        cout << "       ID : "  << i << endl;
        cout << " funLevel : "  << data[ i ]->getFunLevel() << endl;
        cout << "thingName : " << data[ i ]->getThingName() << endl;
        cout << "-----------------------------------" << endl;
    }

}


/**
 * Print the capacity and current element count of the specified Games object.
 * @param games A Games object.
 */
void printCurrentElementCount( const Games& games ) {
    cout << "Element count : " << games.getCount() << " out of " << games.getSize() << endl;
    cout << "-----------------------------------" << endl;
}


//====================================================//
// Main Function
//====================================================//


int main() {

  // TODO
  // 3. Create some instances of each and add to games.
  // FunThing funThing; // Abstract class.
  CrazySport crazySport( 11 );
  DomesticChore domesticChore( 22 );
  GenericThing genericThing( 33, true );

    // Section 2: Create an actual collection.

    cout << "Creating my collection..." << endl;
    sleep(1);  // Simulate latency.

    Games myCollection( 4 );
    myCollection.add( "Arkansas", 100 ); printCurrentElementCount( myCollection );


  return 0;

} // end main
