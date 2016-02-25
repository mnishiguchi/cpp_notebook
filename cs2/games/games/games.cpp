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
#include <assert.h>
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
  void deleteAll();
  bool exists( string thingName ) const;
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
 * @return true if a FunThing with the specified name exists in the collection,
 * else false.
 */
bool Games::exists( string thingName ) const {

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


//---------------------------------------------------------
//  The test functions
//---------------------------------------------------------


/**
 * When instantiating a Games object, one of its members, data, should be set to NULL.
 */
void test_new_game_data_should_be_set_to_null() {

    sleep(1);  // Simulate latency.

    Games games( 5 );
    assert( games.getData() == NULL );

    cout << "PASS: test_new_game_data_should_be_set_to_null" << endl;
}


/**
 * The Games class must have the ability to add FunThings by allocating a new
 * instance of FunThing and adding that to the array.
 */
void test_games_should_be_able_to_dynamically_add_new_fun_thing_to_array() {

    sleep(1);  // Simulate latency.

    Games* games = new Games( 5 );

    // Initial element count should be 0.
    assert( games->getCount() == 0 );

    // Dynamically add a new element to the data array.
    games->add( "WordPress", 5 );
    assert( games->getCount() == 1 );
    games->add( "Sinatra", 8 );
    assert( games->getCount() == 2 );
    games->add( "Hanami", 6 );
    assert( games->getCount() == 3 );

    // Before deleting games.
    assert( games->getData()[ 0 ]->getThingName() == "WordPress" );
    assert( games->getData()[ 1 ]->getThingName() == "Sinatra" );
    assert( games->getData()[ 2 ]->getThingName() == "Hanami" );

    delete games;

    // After deleting games, elements of the data should be deallocated.
    // NOTE: The deallocated memory location may not have been reallocated yet.
    assert( games->getData()[ 0 ]->getThingName() != "WordPress" ||
            games->getData()[ 1 ]->getThingName() != "Sinatra"   ||
            games->getData()[ 2 ]->getThingName() != "Hanami"
    );

    cout << "PASS: test_games_should_be_able_to_dynamically_add_new_fun_thing_to_array" << endl;
}


/**
 * When the list gets full, it should dynamically grow in capacity by one chunk.
 */
void test_data_array_should_expand_capacity_by_chunk_when_full() {

    sleep(1);  // Simulate latency.

    // Set up games whose chunk is 3.
    Games g3( 3 );
    assert( g3.getChunk() == 3 );
    assert( g3.getSize() == 3 );

    // Dynamically add new elements to the data array.
    g3.add( "WordPress", 5 );
    assert( g3.getCount() == 1 );
    g3.add( "Sinatra", 8 );
    assert( g3.getCount() == 2 );
    g3.add( "Hanami", 6 );
    assert( g3.getCount() == 3 );
    // Size: 3, and the collection is full.
    assert( g3.getSize() == 3 );
    assert( g3.isFull() );

    // Dynamically add one more to go beyond the threshold.
    g3.add( "Ruby", 999 );
    assert( g3.getCount() == 4 );
    // Should have been expanded correctly.
    assert( g3.getChunk() == 3 );
    assert( g3.getSize() == 3 + 3 );
    assert( ! g3.isFull() );

    // Ensure that all the data is preserved after the resize operation.
    assert( g3.getData()[ 0 ]->getThingName() == "WordPress" );
    assert( g3.getData()[ 0 ]->getFunLevel() == 5 );
    assert( g3.getData()[ 1 ]->getThingName() == "Sinatra" );
    assert( g3.getData()[ 1 ]->getFunLevel() == 8 );
    assert( g3.getData()[ 2 ]->getThingName() == "Hanami" );
    assert( g3.getData()[ 2 ]->getFunLevel() == 6 );
    assert( g3.getData()[ 3 ]->getThingName() == "Ruby" );
    assert( g3.getData()[ 3 ]->getFunLevel() == 999 );

    // Add two more elements to make it full.
    for ( int i = 0; i < 2; i++ ) {
      g3.add( "Item #" + to_string(i + 100), i + 100 );
    }
    // Size 6, and the collection is full.
    assert( g3.getSize() == 6 );
    assert( g3.isFull() );

    // Dynamically add one more to go beyond the threshold.
    g3.add( "C++", 333 );
    assert( g3.getCount() == 7 );
    // Should have been expanded correctly.
    assert( g3.getChunk() == 3 );
    assert( g3.getSize() == 3 + 3 + 3 );
    assert( ! g3.isFull() );

    // Ensure that all the data is preserved after the resize operation.
    assert( g3.getData()[ 0 ]->getThingName() == "WordPress" );
    assert( g3.getData()[ 0 ]->getFunLevel() == 5 );
    assert( g3.getData()[ 1 ]->getThingName() == "Sinatra" );
    assert( g3.getData()[ 1 ]->getFunLevel() == 8 );
    assert( g3.getData()[ 2 ]->getThingName() == "Hanami" );
    assert( g3.getData()[ 2 ]->getFunLevel() == 6 );
    assert( g3.getData()[ 3 ]->getThingName() == "Ruby" );
    assert( g3.getData()[ 3 ]->getFunLevel() == 999 );
    assert( g3.getData()[ 4 ]->getThingName() == "Item #100" );
    assert( g3.getData()[ 4 ]->getFunLevel() == 100 );
    assert( g3.getData()[ 5 ]->getThingName() == "Item #101" );
    assert( g3.getData()[ 5 ]->getFunLevel() == 101 );
    assert( g3.getData()[ 6 ]->getThingName() == "C++" );
    assert( g3.getData()[ 6 ]->getFunLevel() == 333 );

    //---------------------------------//

    // Set up games whose chunk is 7.
    Games g7( 7 );
    assert( g7.getChunk() == 7 );
    assert( g7.getSize() == 7 );

    // Dynamically add new elements to the data array.
    for ( int i = 0; i < g7.getSize(); i++ ) {
      g7.add( "Item #" + to_string(i), i );
      assert( g7.getCount() == i + 1 );
    }

    // Size: 7, and the collection is full.
    assert( g7.getSize() == 7 );
    assert( g7.isFull() );

    // Dynamically add one more to go beyond the threshold.
    g7.add( "Ruby", 999 );
    assert( g7.getCount() == 8 );

    // Should have been expanded correctly.
    assert( g7.getChunk() == 7 );
    assert( g7.getSize() == 7 + 7 );
    assert( ! g7.isFull() );

    // Ensure that all the data is preserved after the resize operation.
    assert( g7.getData()[ 0 ]->getThingName() == "Item #0" );
    assert( g7.getData()[ 0 ]->getFunLevel() == 0 );
    assert( g7.getData()[ 1 ]->getThingName() == "Item #1" );
    assert( g7.getData()[ 1 ]->getFunLevel() == 1 );
    assert( g7.getData()[ 2 ]->getThingName() == "Item #2" );
    assert( g7.getData()[ 2 ]->getFunLevel() == 2 );
    assert( g7.getData()[ 3 ]->getThingName() == "Item #3" );
    assert( g7.getData()[ 3 ]->getFunLevel() == 3 );
    assert( g7.getData()[ 4 ]->getThingName() == "Item #4" );
    assert( g7.getData()[ 4 ]->getFunLevel() == 4 );
    assert( g7.getData()[ 5 ]->getThingName() == "Item #5" );
    assert( g7.getData()[ 5 ]->getFunLevel() == 5 );
    assert( g7.getData()[ 6 ]->getThingName() == "Item #6" );
    assert( g7.getData()[ 6 ]->getFunLevel() == 6 );
    assert( g7.getData()[ 7 ]->getThingName() == "Ruby" );
    assert( g7.getData()[ 7 ]->getFunLevel() == 999 );

    cout << "PASS: test_data_array_should_expand_capacity_by_chunk_when_full" << endl;
}


//---------------------------------------------------------
//  Utility functions
//---------------------------------------------------------


/**
 * Print the information about all the data that the specified Games object holds.
 * @param games A Games object.
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


//---------------------------------------------------------
//  The main function of this program
//---------------------------------------------------------


int main() {

    // Section 1: Call the test functions.

    test_new_game_data_should_be_set_to_null();
    test_games_should_be_able_to_dynamically_add_new_fun_thing_to_array();
    test_data_array_should_expand_capacity_by_chunk_when_full();

    // Section 2: Create an actual collection.

    cout << "Creating my collection..." << endl;
    sleep(1);  // Simulate latency.

    Games myCollection( 4 );
    myCollection.add( "Arkansas", 100 );
    myCollection.add( "Buffer overflow", 500 );
    myCollection.add( "Cake", 432 );
    myCollection.add( "Dad", 920 );
    myCollection.add( "Eating", 938 );
    myCollection.add( "Family", 484 );
    myCollection.add( "Gif", 232 );
    myCollection.add( "Hexagon", 606 );
    myCollection.add( "Imagination", 855 );
    myCollection.add( "Jagaimo", 293 );
    myCollection.add( "Kabocha", 846 );
    myCollection.add( "Lamb chops", 344 );
    myCollection.add( "Masatoshi", 764 );
    myCollection.add( "Networking", 123 );
    myCollection.add( "Ozzy", 989 );
    myCollection.add( "Popeyes", 765 );

    cout << "Done" << endl;

    // Print all
    cout << "Printing my collection..." << endl;
    printAll( myCollection );

    return 0;

}
