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
#include <cassert>
using namespace std;


//====================================================//
// FunThing class and its subclasses
//====================================================//


/**
 * An abstract class that represents a fun thing.
 */
class FunThing {
public:
    // Requirement: Must contain two purely virtual methods.
    virtual bool isDangerous()=0;
    virtual int getNumberOfPlayers()=0;

    // Constructor that is called via subclasses.
    FunThing( string thingName, int funLevel ) {
        this->funLevel  = funLevel;
        this->thingName = thingName;
    }

    // The destructor of the base class must be virtual.
    virtual ~FunThing() {}

    // Copy constructor.
    // - No need for custom copy because this class does not contain any pointer members.

    // Setters & getters.
    int getFunLevel() const { return funLevel; }
    void setFunLevel( int funLevel ) { this->funLevel = funLevel; }
    string getThingName() const { return thingName; }
    void setThingName( string thingName ) { this->thingName = thingName; }

    string getDangerText() const;
    string getFunLevelText() const;

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

protected:
    int numberOfPlayers;
    bool dangerous;
private:
    int funLevel;
    string thingName;

}; // end FunThing

/**
 * if 8 or more        : super-fun
 * if 7                : very fun
 * if 3-6, inclusive   : ok fun
 * if 0 - 2, inclusive : no fun
 * if less than 0      : pretty boring
 * @return text that describes the fun level.
 */
string FunThing::getFunLevelText() const {
    if      ( funLevel >= 8 ) { return "super-fun"; }
    else if ( funLevel >= 7 ) { return "very fun"; }
    else if ( funLevel >= 3 ) { return "ok fun"; }
    else if ( funLevel >= 0 ) { return "no fun"; }

    // Anything else is "pretty boring".
    return "pretty boring";
}

/**
 * @return "Be careful, it can be dangerous" if the FunThing is dangerous,
 * else "It's fun for Everyone.
 */
string FunThing::getDangerText() const {
    return ( dangerous ) ? "Be careful, it can be dangerous" : "It's fun for Everyone";
}


/**
 * Subclass of FunThing. All instances of CrazySport considered dangerous.
 */
class CrazySport : public FunThing {
public:
    // Constructor
    CrazySport( string thingName, int funLevel, int numberOfPlayers )
        : FunThing( thingName, funLevel ) {

        this->numberOfPlayers = numberOfPlayers;
        this->dangerous       = true;  // By default considered dangerous.
    }

    int getNumberOfPlayers() { return this->numberOfPlayers; }
    bool isDangerous() { return this->dangerous; }

}; // end CrazySport


/**
 * Subclass of FunThing. All instances of DomesticChore are NOT dangerous.
 */
class DomesticChore : public FunThing {
public:
    // Constructor
    DomesticChore( string thingName, int funLevel, int numberOfPlayers )
        : FunThing( thingName, funLevel ) {

        this->numberOfPlayers = numberOfPlayers;
        this->dangerous       = false;  // By default considered NOT dangerous.
    }

    int getNumberOfPlayers() { return this->numberOfPlayers; }
    bool isDangerous() { return this->dangerous; }

}; // end DomesticChore


/**
 * Subclass of FunThing.
 */
class GenericThing : public FunThing {
public:
    // Constructor
    GenericThing( string thingName, int funLevel, int numberOfPlayers, bool isDangerous )
        : FunThing( thingName, funLevel ) {

        this->numberOfPlayers = numberOfPlayers;
        this->dangerous       = isDangerous;
    }

    int getNumberOfPlayers() { return this->numberOfPlayers; }
    bool isDangerous() { return this->dangerous; }

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
    Games( string title, int chunk ) {
        this->title = title;
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
    void makeMoreFun();
    string title;
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
        // cout << "Extending capacity ===> { count:" << count << ", size:" << size << " }" << endl;
    }

    data[ count ] = thing;  // Add it to the collection.
    count += 1;             // Update the count.
} // end add


/**
 * Clean up all the dynamic variables.
 */
void Games::deleteAll() {
    // Iterate over the collection for the current element count.
    for ( int i = 0; i < count; i++ ) { delete data[ i ]; }

} // end deleteAll


/**
 * @return true if a FunThing with the specified name contains in the collection,
 * else false.
 */
bool Games::contains( string thingName ) const {

    // Iterate over the collection for the current element count. Return true if found.
    for ( int i = 0; i < count; i++ ) {
        if ( data[ i ]->getThingName() == thingName ) { return true; }
    }
    return false;  // If not found, return false.

} // end contains


/**
 * Extend the capacity of the data by one chunk.
 */
void Games::extendCapacity() {

    FunThing** old = data;         // Remember the address of the old collection.
    size += chunk;                 // Update the size by one chunk.
    data = new FunThing*[ size ];  // Create a new collection with new size.

    // Shallow-copy all the pointers stored in the old collection into the new one.
    for ( int i = 0; i < count; i++ ) { data[ i ] = old[ i ]; }

    delete [] old;  // Delete the old collection.

} // end extendCapacity


/**
 * Iterate all of the FunThings held in Games and increment each FunThing by 1.
 * This must be done by invoking the ++ operator on each method.
 */
void Games::makeMoreFun() {
    for ( int i = 0; i < count; i++ ) {

        // cout << data[ i ]->getFunLevel() << "===>";  // Debugging::before

        // Since an array element is a pointer, we dereference it and then increment it.
        ++( *data[ i ] );

        // cout << data[ i ]->getFunLevel() << endl;    // Debugging::after
    }
}


//====================================================//
// Utility functions
//====================================================//


/**
 * Requirement:
 * Non-member Operator Overload.
 * Output the Games object via the stream-insertion operator.
 * http://en.cppreference.com/w/cpp/language/operators
 */
ostream& operator<<( ostream& os, FunThing& thing ) {
    os << "    Fun Thing : " << thing.getThingName() << endl;
    os << "      Players : " << thing.getNumberOfPlayers() << endl;
    os << "    Fun Level : " << thing.getFunLevelText() << endl;
    os << "  Description : " << thing.getDangerText() << endl;
    return os;
}
ostream& operator<<( ostream& os, Games& collection ) {
    os << "Printing " << collection.title << "..." << endl;

    // Output all the items in the collection to ostream.
    FunThing** data = collection.getData();
    for ( int i = 0; i < collection.getCount(); i++ ) {
        if ( i%2 == 0 ) { sleep(1); }  // Simulate latency.
        os << *data[ i ];
        os << "  -----------------------------------" << endl;
    }
    return os;
}


/**
 * Print the capacity and current element count of the specified Games object.
 * @param games A Games object.
 */
void printElementCount( const Games& games ) {
    sleep(1);  // Simulate latency.
    cout << "  { count:" << games.getCount() << ", size:" << games.getSize() << " }" << endl;
}


//====================================================//
// Test functions
//====================================================//


template <typename DataType>
void assert_eq( DataType expected, DataType actual ) {
    if ( expected != actual ) {
        cout << "  Fail: \"" << actual << "\" should be equal to \"" << expected << "\"" << endl;
        assert( false );
    }
    cout << "  \"" << actual << "\" is equal to \"" << expected << "\"" << endl;
}

void test_fun_thing_pre_increment() {

    cout << "test_fun_thing_pre_increment..." << endl;

    // Create a FunThing with initial funlevel being 43.
    CrazySport cs1( "cs1", 43, 99 );
    assert_eq<int>( 43, cs1.getFunLevel() );

    // Increment the CrazySport object.
    ++cs1; assert_eq<int>( 44, cs1.getFunLevel() );
    ++cs1; assert_eq<int>( 45, cs1.getFunLevel() );

    cout << "  Pass" << endl;
}

void test_fun_thing_pre_decrement() {

    cout << "test_fun_thing_pre_decrement..." << endl;

    // Create a FunThing with initial funlevel being 43.
    DomesticChore dc1( "dc1", 43, 99 );
    assert_eq<int>( 43, dc1.getFunLevel() );

    // Decrement the DomesticChore object.
    --dc1; assert_eq<int>( 42, dc1.getFunLevel() );
    --dc1; assert_eq<int>( 41, dc1.getFunLevel() );

    cout << "  Pass" << endl;
}

/**
 * if 8 or more        : super-fun
 * if 7                : very fun
 * if 3-6, inclusive   : ok fun
 * if 0 - 2, inclusive : no fun
 * if less than 0      : pretty boring
 */
void test_fun_thing_fun_level_text() {

    cout << "test_fun_thing_fun_level_text" << endl;

    // Create a FunThing with initial funlevel being 9.
    DomesticChore dc1( "dc1", 9, 1000 );

    // Check if the text is correct according to fun level.
    assert_eq<string>( dc1.getFunLevelText(), "super-fun" );

    dc1.setFunLevel( 8 );
    assert_eq<string>( dc1.getFunLevelText(), "super-fun" );

    dc1.setFunLevel( 7 );
    assert_eq<string>( dc1.getFunLevelText(), "very fun" );

    dc1.setFunLevel( 6 );
    assert_eq<string>( dc1.getFunLevelText(), "ok fun" );

    dc1.setFunLevel( 3 );
    assert_eq<string>( dc1.getFunLevelText(), "ok fun" );

    dc1.setFunLevel( 2 );
    assert_eq<string>( dc1.getFunLevelText(), "no fun" );

    dc1.setFunLevel( 0 );
    assert_eq<string>( dc1.getFunLevelText(), "no fun" );

    dc1.setFunLevel( -1 );
    assert_eq<string>( dc1.getFunLevelText(), "pretty boring" );

    cout << "  Pass" << endl;
}

/**
 * "Be careful, it can be dangerous" if the FunThing is dangerous,
 * else "It's fun for Everyone."
 */
void test_fun_thing_danger_text() {

    cout << "test_fun_thing_danger_text" << endl;

    // Create a dangerous thing and a safe thing.
    CrazySport danger( "danger", 8, 9 );
    DomesticChore safe( "safe", 8, 9 );

    assert_eq<string>( "Be careful, it can be dangerous", danger.getDangerText() );
    assert_eq<string>( "It's fun for Everyone", safe.getDangerText() );

    cout << "  Pass" << endl;
}

void test_games_make_more_fun() {

    cout << "test_games_make_more_fun" << endl;

    // Create FunThing objects.
    CrazySport* sumo        = new CrazySport( "sumo", 10, 2 );
    DomesticChore* laundry  = new DomesticChore( "laundry", 20, 1 );
    GenericThing* debugging = new GenericThing( "debugging", 30, 41, true );

    // Create a collection.
    Games myCollection( "myCollection", 4 );
    myCollection.add( sumo );
    myCollection.add( laundry );
    myCollection.add( debugging );

    // Make them more fun for the first time.
    myCollection.makeMoreFun();
    assert_eq<int>( 11, sumo->getFunLevel() );
    assert_eq<int>( 21, laundry->getFunLevel() );
    assert_eq<int>( 31, debugging->getFunLevel() );

    // Make them more fun for the second time.
    myCollection.makeMoreFun();
    assert_eq<int>( 12, sumo->getFunLevel() );
    assert_eq<int>( 22, laundry->getFunLevel() );
    assert_eq<int>( 32, debugging->getFunLevel() );

    cout << "  Pass" << endl;
}


//====================================================//
// Main Function
//====================================================//


int main() {
    // Tests.

     test_fun_thing_pre_increment();
     test_fun_thing_pre_decrement();
     test_fun_thing_fun_level_text();
     test_fun_thing_danger_text();
     test_games_make_more_fun();

    // Requirement: Create some instances of each class.

    CrazySport* sumo        = new CrazySport( "sumo", 188, 2 );
    DomesticChore* laundry  = new DomesticChore( "laundry", 11, 1 );
    GenericThing* debugging = new GenericThing( "debugging", 13, 41, true );
    DomesticChore* homework = new DomesticChore( "homework", 43, 1 );
    CrazySport* hockey      = new CrazySport( "hokey", 83, 12 );
    GenericThing* coding    = new GenericThing( "coding", 255, 1, false );

    // Requirement: Add those instances to games.

    Games myCollection( "myCollection", 4 );
    cout << "Creating " << myCollection.title << "..." << endl;
    myCollection.add( sumo ); printElementCount( myCollection );
    myCollection.add( laundry ); printElementCount( myCollection );
    myCollection.add( debugging ); printElementCount( myCollection );
    myCollection.add( homework ); printElementCount( myCollection );
    myCollection.add( hockey ); printElementCount( myCollection );
    myCollection.add( coding ); printElementCount( myCollection );
    cout << "  Done" << endl;

    // Output the Games object using a Stream insertion operator.
    cout << myCollection;
    cout << "  Done" << endl;

    return 0;

} // end main
