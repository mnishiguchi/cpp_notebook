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
  // Requirement: Must now contain two purely virtual methods.
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
  virtual ~FunThing() {}

  // Copy constructor.
  // - No need for custom copy because this class does not contain any pointer members.

  // Setters & getters.
  int getFunLevel() const { return funLevel; }
  void setFunLevel( int funLevel ) { this->funLevel = funLevel; }
  string getThingName() const { return thingName; }
  void setThingName( string thingName ) { this->thingName = thingName; }

  // Overload the pre-increment operators that takes no argument.
  // @return The FunThing object that has been updated.
  FunThing& operator++() {
    // Increment the funLevel and return this instance by reference.
    ++( this->funLevel );
    return *this;
  }

  // Overload the pre-decrement operators that takes no argument.
  // @return The FunThing object that has been updated.
  FunThing& operator--() {
    // Decrement the funLevel and return this instance by reference.
    --( this->funLevel );
    return *this;
  }

private:
  int funLevel;
  string thingName;
}; // end FunThing


/**
 * Subclass of FunThing
 * CrazySport(thingName, funLevel, numberOfPlayers)
 * CrazySport must be able to take as a constructor argument the number of players.
 * All instances of CrazySport considered dangerous.
 */
class CrazySport : public FunThing {
public:
  // Constructor
  // CrazySport( int numberOfPlayers )
  CrazySport( string thingName, int funLevel, int numberOfPlayers )
    // Pass the funLevel and thingName to the parent's constructor if necessary.
    : FunThing( thingName, funLevel ) {

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
 * DomesticChore( thingName, funLevel, numberOfPlayers )
 * DomesticChore must be able to take as a constructor argument the number of players.
 * All instances of DomesticChore are NOT dangerous
 */
class DomesticChore : public FunThing {
public:
  // Constructor
  DomesticChore( string thingName, int funLevel, int numberOfPlayers )
    // Pass the funLevel and thingName to the parent's constructor if necessary.
    : FunThing( thingName, funLevel ) {

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
 * GenericThing( thingName, funLevel, numberOfPlayers, isdangerous )
 * GenericThing must accept number of players and whether or not it is dangerous.
 */
class GenericThing : public FunThing {
public:
  // Constructor
  GenericThing( string thingName, int funLevel, int numberOfPlayers, bool isDangerous )
    // Pass the funLevel and thingName to the parent's constructor if necessary.
    : FunThing( thingName, funLevel ) {

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
  void add( FunThing* thing );
  bool contains( string thingName ) const;
  void deleteAll();
  int getChunk() const { return chunk; }
  int getCount() const { return count; }
  int getSize() const { return size; }
  FunThing** getData() const { return data; }
  bool isEmpty() { return count == 0; }
  bool isFull() { return ! isEmpty() && ( count % chunk == 0 ); }
  void printDescription();
private:
  int chunk;        // The amount by which the list size increment
  int count;        // The current number of the elements.
  int size;         // The current list size.
  FunThing** data;  // Array of FunThing pointers.

  // Private helper methods.
  void extendCapacity();
  string getDangerText( FunThing* );
  string getFunLevelText( FunThing* );
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
  // NOTE: Although FunThing is an abstract class, this code is valid, because
  // it does not instantiate FunThing.
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
 * @param thing A FunThing pointer.
 */
void Games::add( FunThing* thing ) {

  // If the list is empty, initialize the data collection.
  // Dynamically creating an array of FunThing pointers.
  if ( isEmpty() ) { data = new FunThing*[ chunk ]; }

  // If the list is full, extend the capacity.
  if ( isFull() ) {
    extendCapacity();

    // DEBUG
    cout << "Extending capacity ===> { count:" << count << ", size:" << size << " }" << endl;
  }

  data[ count ] = thing;  // Add it to the collection.
  count += 1;             // Update the count.
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


/*


4)

FunThing: the name of the thing
Players: the number of players
Fun Level output
Last line

The Fun Level output must show the following text according to the funLevel:

It's super-fun if 8 or more
It's very fun if 7
It's ok fun if 3-6, inclusive
It's no fun if 0 - 2, inclusive
It's pretty boring if less than 0


For the last line

If the FunThing is not dangerous, the last line should read:
It's fun for Everyone
otherwise, it should read
Be careful, it can be dangerous
 */

/**
 * TODO
 * Requirement:
 * Output the following 4 lines for each FunThing in the following way.
 * The output MUST be created via the stream-insertion operator.
 */
void Games::printDescription() {

    // TODO: Overload the stream-insertion operator.

    for ( int i = 0; i < count; i++ ) {
        cout << "  Fun Thing : " << data[ i ]->getThingName() << endl;
        cout << "    Players : " << data[ i ]->getNumberOfPlayers() << endl;
        cout << "  Fun Level : " << data[ i ]->getFunLevel() << endl;
        cout << "Description : " << data[ i ]->isDangerous() << endl;
        cout << "-----------------------------------" << endl;
    }

}

/**
 * Requirement:
 * if 8 or more        : super-fun
 * if 7                : very fun
 * if 3-6, inclusive   : ok fun
 * if 0 - 2, inclusive : no fun
 * if less than 0      : pretty boring
 * @param  funThing*
 * @return text that describes the fun level.
 */
string Games::getFunLevelText( FunThing* funThing ) {
  int level = funThing->getFunLevel();
  if      ( level >= 8 ) { return "super-fun"; }
  else if ( level >= 7 ) { return "very fun"; }
  else if ( level >= 3 ) { return "ok fun"; }
  else if ( level >= 0 ) { return "no fun"; }

  // Anything else is "pretty boring".
  return "pretty boring";
}

/**
 * @return "Be careful, it can be dangerous" if the FunThing is dangerous
 * else "It's fun for Everyone.
 */
string getDangerText( FunThing* funThing ) {
  return ( funThing->isDangerous() ) ? "Be careful, it can be dangerous"
                                     : "It's fun for Everyone";
}


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

    cout << "Printing my collection..." << endl;
    // sleep(1);  // Simulate latency.

    FunThing** data = games.getData();

    for ( int i = 0, len = games.getCount(); i < len; i++ ) {
        if ( i%2 == 0 ) { sleep(1); }
        cout << "             ID : " << i << endl;
        cout << "       funLevel : " << data[ i ]->getFunLevel() << endl;
        cout << "      thingName : " << data[ i ]->getThingName() << endl;
        cout << "numberOfPlayers : " << data[ i ]->getNumberOfPlayers() << endl;
        cout << "    isDangerous : " << data[ i ]->isDangerous() << endl;
        cout << "-----------------------------------" << endl;
    }

}


/**
 * Print the capacity and current element count of the specified Games object.
 * @param games A Games object.
 */
void printCurrentElementCount( const Games& games ) {
    sleep(1);  // Simulate latency.
    cout << "  { count:" << games.getCount() << ", size:" << games.getSize() << " }" << endl;
}


//====================================================//
// Test functions
//====================================================//


// template <typename dataType>
// bool my_assert( bool ( *conditionalFun )( dataType value ), string errorMsg ) {
//   return true;
// }
// template <typename dataType>
// bool my_refute( bool ( *conditionalFun )( dataType value ), string errorMsg ) {
//   return ! my_assert<dataType>();
// }
// template <typename dataType>
// bool zeroOrGreater( dataType value ) { return value >= 0; }

template <typename dataType>
void assert_eq( dataType expected, dataType actual ) {
    if ( expected != actual ) {
        cout << "  Fail: " << actual << " should be equal to " << expected << endl;
        assert( false );
    }
    cout << "  " << actual << " is equal to " << expected << endl;
}
void test_pre_increment_op_of_fun_thing() {

    cout << "test_pre_increment_op_of_fun_thing..." << endl;

    // Set up.
    CrazySport cs1( "cs1", 43, 9 );
    assert_eq<int>( 43, cs1.getFunLevel() );

    // Increment the CrazySport object.
    ++cs1;
    assert_eq<int>( 44, cs1.getFunLevel() );
    ++cs1;
    assert_eq<int>( 45, cs1.getFunLevel() );

    cout << "  Pass" << endl;
}
void test_pre_decrement_op_of_fun_thing() {

    cout << "test_pre_decrement_op_of_fun_thing..." << endl;

    // Set up.
    DomesticChore dc1( "dc1", 43, 9 );
    assert_eq<int>( 43, dc1.getFunLevel() );

    // Decrement the DomesticChore object.
    --dc1;
    assert_eq<int>( 42, dc1.getFunLevel() );
    --dc1;
    assert_eq<int>( 41, dc1.getFunLevel() );

    cout << "  Pass" << endl;
}


//====================================================//
// Main Function
//====================================================//


int main() {
    // Tests.
    test_pre_increment_op_of_fun_thing();
    test_pre_decrement_op_of_fun_thing();

    // Requirement: Create some instances of each class.
    CrazySport* sumo        = new CrazySport( "sumo", 188, 2 );
    DomesticChore* laundry  = new DomesticChore( "laundry", 11, 1 );
    GenericThing* debugging = new GenericThing( "debugging", 13, 41, true );
    DomesticChore* homework = new DomesticChore( "homework", 43, 1 );
    CrazySport* hockey      = new CrazySport( "hokey", 83, 12 );
    GenericThing* coding    = new GenericThing( "coding", 255, 1, false );

    // Requirement: Add those instances to games.
    cout << "Creating my collection..." << endl;
    Games myCollection( 4 );
    myCollection.add( sumo ); printCurrentElementCount( myCollection );
    myCollection.add( laundry ); printCurrentElementCount( myCollection );
    myCollection.add( debugging ); printCurrentElementCount( myCollection );
    myCollection.add( homework ); printCurrentElementCount( myCollection );
    myCollection.add( hockey ); printCurrentElementCount( myCollection );
    myCollection.add( coding ); printCurrentElementCount( myCollection );

    printAll( myCollection );

    return 0;

} // end main
