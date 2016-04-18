//
//  Computer Science II
//  FunThing 3
//
//  Masatoshi Nishiguchi
//
//  Due: Tuesday, April 19
//


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <cassert>
using namespace std;


//====================================================//
// The FunThing root class
//====================================================//


/**
 * An abstract class that represents a fun thing.
 * We cannot instantiate this class.
 */
class FunThing {
public:
    // NOTE: Subclasses of this class must implement these methods so that they can be used.
    virtual bool isDangerous() =0;
    virtual int getNumberOfPlayers() =0;

    // Run-time binding.
    virtual void ouputToStream( ostream& stream );

    // Constructor that is called via subclasses.
    FunThing( string thingName, int funLevel ) {
        this->funLevel  = funLevel;
        this->thingName = thingName;
    }

    // NOTE: The destructor of the base class must be virtual.
    virtual ~FunThing() {}

    // Copy constructor.
    // - No need for custom copy because this class does not contain any pointer members.

    // Setters & getters.
    int getFunLevel() const { return funLevel; }
    void setFunLevel( int funLevel ) { this->funLevel = funLevel; }
    virtual string getThingName() const { return thingName; }
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

protected:
    int funLevel;
    string thingName;

}; // end FunThing


/**
 * Non-member Operator Overload.
 * http://en.cppreference.com/w/cpp/language/operators
 */
ostream& operator<<( ostream& os, FunThing& thing ) {
    os << "    Fun Thing : " << thing.getThingName() << endl;
    os << "    Fun Level : " << thing.getFunLevel() << endl;
    return os;
}


/**
 * Run-time binding.
 * Allows the insertion operator code to simply call this and pass the ostream as an argument.
 */
void FunThing::ouputToStream( ostream& stream ) {
    // printf("Called from FunThing\n");
    cout << *this << endl;
};


//====================================================//
// The FunThing family A
//====================================================//


/**
 * A subclass of FunThing that represents a generic thing.
 * An instance of this class can be either dangerous or not.
 */
class GenericThing : public FunThing {
public:
    // Constructor
    GenericThing( string thingName, int funLevel, int numberOfPlayers, bool isDangerous )
    : FunThing( thingName, funLevel ) {

        this->numberOfPlayers = numberOfPlayers;
        this->dangerous       = isDangerous;
    }

    // Implement methods that are required by parent class.
    int getNumberOfPlayers() { return this->numberOfPlayers; }
    bool isDangerous() { return this->dangerous; }

    // Run-time binding.
    virtual void ouputToStream( ostream& stream );

    // Other methods.
    string getFunLevelText() const;
    string getDangerText() const;

protected:
    bool dangerous;
    int numberOfPlayers;
}; // end GenericThing


/**
 * Allows the insertion operator code to simply call this and pass the ostream as an argument.
 */
void GenericThing::ouputToStream( ostream& st ) {
    // printf("Called from GenericThing\n");
    cout << *this << endl;
}


/**
 * if 8 or more        : super-fun
 * if 7                : very fun
 * if 3-6, inclusive   : ok fun
 * if 0 - 2, inclusive : no fun
 * if less than 0      : pretty boring
 * @return text that describes the fun level.
 */
string GenericThing::getFunLevelText() const {
    if      ( funLevel >= 8 ) { return "super-fun"; }
    else if ( funLevel >= 7 ) { return "very fun"; }
    else if ( funLevel >= 3 ) { return "ok fun"; }
    else if ( funLevel >= 0 ) { return "no fun"; }

    // Anything else is "pretty boring".
    return "pretty boring";
}


/**
 * @return "Be careful, it can be dangerous" if the GenericThing is dangerous,
 * else "It's fun for Everyone.
 */
string GenericThing::getDangerText() const {
    return ( dangerous ) ? "Be careful, it can be dangerous" : "It's fun for Everyone";
}


/**
 * Non-member Operator Overload.
 * http://en.cppreference.com/w/cpp/language/operators
 */
ostream& operator<<( ostream& os, GenericThing& thing ) {
    os << "    Fun Thing : " << thing.getThingName() << endl;
    os << "      Players : " << thing.getNumberOfPlayers() << endl;
    os << "    Fun Level : " << thing.getFunLevelText() << endl;
    os << "  Description : " << thing.getDangerText() << endl;
    return os;
}


/**
 * A subclass of GenericThing. All instances of this class are considered dangerous.
 */
class CrazySport : public GenericThing {
public:
    CrazySport( string thingName, int funLevel, int numberOfPlayers )
    : GenericThing( thingName, funLevel, numberOfPlayers, true ) {
    }
}; // end CrazySport


/**
 * A subclass of GenericThing. All instances of this class are NOT dangerous.
 */
class DomesticChore : public GenericThing {
public:
    DomesticChore( string thingName, int funLevel, int numberOfPlayers )
        : GenericThing( thingName, funLevel, numberOfPlayers, false ) {
    }
}; // end DomesticChore


//====================================================//
// The FunThing family B
//====================================================//


/**
 * An abstruct class that Extends FunThing.
 */
class BoardGame : public FunThing {
public:
    virtual string getRules() const =0;
    virtual void setRules( string ) =0;

    // NOTE: This is an abstract class; it does not hold any attributes.
    // Instead, add appropriate attributes in subclasses.

    // Constructor
    BoardGame( string thingName, int funLevel )
    : FunThing( thingName, funLevel ) {

        // All BoardGame instances are not considered dangerous.
        this->dangerous = false;
    }

    // Implement methods that are required by parent class.
    int getNumberOfPlayers() { return this->numberOfPlayers; }
    bool isDangerous() { return this->dangerous; }

    // Run-time binding.
    virtual void ouputToStream( ostream& st );

protected:
    bool dangerous;
    int numberOfPlayers;
}; // end BoardGame


/**
 * Non-member Operator Overload.
 * All BoardGame will output ONLY their rules when this operator is applied.
 */
ostream& operator<<( ostream& os, const BoardGame& obj ) {
    return os << "--- " << obj.getThingName() << " ---\n" << obj.getRules();
}


/**
 * Run-time binding. Override super's implementation.
 * Allows the insertion operator code to simply call this and pass the ostream as an argument.
 */
void BoardGame::ouputToStream( ostream& st ) {
    // printf("Called from BoardGame\n");
    cout << *this << endl;
};


/**
 * Extends BoardGame. All TwoPlayerBG instances will always have two and exactly two players.
 * Throws std::length_error when the rules are too long.
 */
class TwoPlayerBG : public BoardGame {
public:
    // Constructor
    TwoPlayerBG( string thingName, int funLevel, string rules )
    : BoardGame( thingName, funLevel ) {

        setRules(rules);
        this->numberOfPlayers = 2;
    }

    string getRules() const { return rules; }

    // Requirement:
    // @return a VERY SHORT (50 characters or less) string of the basic rules of the game.
    void setRules( string rules ) {
        if ( rules.length() > 50 ) {
            throw std::length_error( std::string("Error: max length is 50 characters for rules") );
        }
        this->rules = rules;
    }

private:
    string rules;
}; // end TwoPlayerBG


/**
 * Extends BoardGame
 * Throws std::length_error when the rules are too long.
 */
class MultiPlayerBG : public BoardGame {
public:
    // Constructor
    MultiPlayerBG( string thingName, int funLevel, string rules, int numberOfPlayers )
    : BoardGame( thingName, funLevel ) {

        setRules(rules);
        this->numberOfPlayers = numberOfPlayers;
    }

    string getRules() const { return this->rules; }

    // Requirement:
    // @return a VERY SHORT (50 characters or less) string of the basic rules of the game.
    void setRules( string rules ) {
        if ( rules.length() > 50 ) {
            throw std::length_error( std::string("Error: max length is 50 characters for rules") );
        }
        this->rules = rules;
    }

private:
    string rules;
}; // end MultiPlayerBG

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
    // Constructors.
    Games() {
        this->title = "untitled";
        this->chunk = 8;
        this->count = 0;
        this->data  = NULL;
        this->size  = chunk;  // Initial size is initially set to chunk.
    }
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

    // Operator overload for [].
    FunThing* operator[]( int index ) const {

        if ( index < 0 ) {
            throw std::runtime_error( "Negative index" );
        } else if ( index > count - 1 ) {
            throw std::runtime_error( "Index out of bounds" );
        }

        return this->data[ index ];
    }

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
// Test functions
//====================================================//


// template <typename DataType>
// void assert_eq( DataType expected, DataType actual ) {
//     if ( expected != actual ) {
//         cout << "  Fail: \"" << actual << "\" should be equal to \"" << expected << "\"" << endl;
//         assert( false );
//     }
//     // cout << "  \"" << actual << "\" is equal to \"" << expected << "\"" << endl;
// }


//====================================================//
// Extras
//====================================================//

void extra_credit() {
    Games games;

    //FunThings added to g here
    FunThing* sumo            = new CrazySport( "sumo", 53, 2 );
    FunThing* bungee_jumping  = new CrazySport( "bungee_jumping", 23, 1 );
    FunThing* marathon        = new CrazySport( "marathon", 71, 1 );
    FunThing* street_fighting = new CrazySport( "street_fighting", 93, 30 );
    games.add( sumo );
    games.add( bungee_jumping );
    games.add( marathon );
    games.add( street_fighting );

    FunThing* val = games[ 3 ];  //This should be valid code that returns the pointer at index 3
    cout << "val: " << val->getThingName() << endl;

    try {
        val = games[ -3 ];  //This code must throw a char array string exception stating "Negative index"
        val = games[ 456 ]; //This code must throw a char array string exception stating "Index out of bounds", assuming you haven't added this many FunThings

    } catch ( std::exception& ex ) {
        std::cerr << "Exception caught: " << ex.what() << '\n';
    }

}


//====================================================//
// Main Function
//====================================================//


int main() {

    // Prepare the rules.
    map<string, string> rules;
    rules["chess"]   = "Each player begins the game with 16 pieces";
    rules["poker"]   = "The right to deal a hand rotates among the players";
    rules["trouble"] = "Land on an opponent's peg to bump it back home!";
    rules["sorry"]   = "Each player in turn draws one card from the stack";


    // Instantiate at least two instances of TwoPlayerBG and MultiPlayerBG.
    TwoPlayerBG* chess     = new TwoPlayerBG( "chess", 43, rules["chess"] );
    TwoPlayerBG* poker     = new TwoPlayerBG( "poker", 55, rules["poker"] );
    MultiPlayerBG* trouble = new MultiPlayerBG( "trouble", 11, rules["trouble"], 5 );
    MultiPlayerBG* sorry   = new MultiPlayerBG( "sorry", 132, rules["sorry"], 6 );


    // Appropriately add each instance to the following vector:
    vector<FunThing*> v_boardGames;

    v_boardGames.push_back( chess );
    v_boardGames.push_back( poker );
    v_boardGames.push_back( trouble );
    v_boardGames.push_back( sorry ) ;


    // Correctly iterate v_boardGames and << appropriately to output through
    // the left-shift operator (via ouputToStream method).
    // Your loop must be coded in such a way that it will work for any number of
    // vector elements.

    // Create an iterator of vector<FunThing*> type.
    vector<FunThing*>::iterator iterator;

    // An temp variable to make the code easier to understand.
    FunThing* currentElement;

    // Iterate over the vector using that iterator.
    cout << "v_boardGames contains:\n";
    for ( iterator  = v_boardGames.begin() ;
          iterator != v_boardGames.end()   ;
          iterator++ ) {

        // Retrieve the current element.
        // - The iterator is a pointer pointing to the current element.
        // - That element is a FunThing pointer.
        currentElement = *iterator;

        // Output the info.
        currentElement->ouputToStream( cout );
    }

    extra_credit();

    return 0;

} // end main
