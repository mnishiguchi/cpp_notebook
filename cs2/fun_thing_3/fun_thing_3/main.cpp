//
//  Computer Science II
//  FunThing 3
//
//  Masatoshi Nishiguchi
//
//  Due: Saturday, April 16
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
    virtual bool isDangerous()=0;
    virtual int getNumberOfPlayers()=0;
    virtual void ouputToStream( ostream& stream )=0;

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
    void ouputToStream( ostream& st );

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

    // TODO
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
 * An abstruct class that extends FunThing. Throws std::length_error when the rules are too long.
 */
class BoardGame : public FunThing {
public:
    // Requirement:
    // @return a VERY SHORT (50 characters or less) string of the basic rules of the game.
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
    void ouputToStream( ostream& st );

protected:
    bool dangerous;
    int numberOfPlayers;
}; // end BoardGame


/**
 * Allows the insertion operator code to simply call this and pass the ostream as an argument.
 */
void BoardGame::ouputToStream( ostream& st ) {

    // TODO
    cout << *this << endl;
}


/**
 * Non-member Operator Overload.
 * All BoardGame will output ONLY their rules when this operator is applied.
 */
ostream& operator<<( ostream& os, const BoardGame& obj ) {
    return os << "Rules of " << obj.getThingName() << "\n" << obj.getRules();
}


/**
 * Extends BoardGame. All TwoPlayerBG instances will always have two and exactly two players.
 */
class TwoPlayerBG : public BoardGame {
public:
    // Constructor
    TwoPlayerBG( string thingName, int funLevel, string rules )
        : BoardGame( thingName, funLevel ) {
        this->rules = "undefined";
        this->numberOfPlayers = 2;
    }

    string getRules() const {
        return rules;
    }
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
 * extends BoardGame
 */
class MultiPlayerBG : public BoardGame {
public:
    // Constructor
    MultiPlayerBG( string thingName, int funLevel, string rules, int numberOfPlayers )
        : BoardGame( thingName, funLevel ) {
        this->rules = rules;
        this->numberOfPlayers = numberOfPlayers;
    }

    string getRules() const { return this->rules; }
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
// Utility functions
//====================================================//



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

// TODO


//====================================================//
// Main Function
//====================================================//


int main() {
    // Tests.
    // TODO

    // Prepare the rules.
    map<string, string> rules;
    rules["chess"]   = "The Chess rules: Lorem ipsum dolor sit amet.";
    rules["poker"]   = "The Poker rules: Lorem ipsum dolor sit amet.";
    rules["trouble"] = "The Trouble rules: Lorem ipsum dolor sit amet.";
    rules["sorry"]   = "The Sorry rules: Lorem ipsum dolor sit amet.";

    // Instantiate at least two instances of TwoPlayerBG and MultiPlayerBG.
    TwoPlayerBG* chess     = new TwoPlayerBG( "chess", 43, rules["chess"] );
    TwoPlayerBG* poker     = new TwoPlayerBG( "poker", 55, rules["poker"] );
    MultiPlayerBG* trouble = new MultiPlayerBG( "trouble", 11, rules["trouble"], 5 );
    MultiPlayerBG* sorry   = new MultiPlayerBG( "sorry", 132, rules["sorry"], 6 );

    // Appropriately add each instance to the following vector:
    vector<FunThing*> v_boardGames;

    v_boardGames.push_back(chess);
    v_boardGames.push_back(poker);
    v_boardGames.push_back(trouble);
    v_boardGames.push_back(sorry);

    // Correctly iterate v_boardGames and << appropriately to output through
    // the left-shift operator.
    // Your loop must be coded in such a way that it will work for any number of
    // vector elements.

    // Create an iterator of vector<FunThing*> type.
    vector<FunThing*>::iterator iterator;

    // An temp variable to make the code easier to understand.
    FunThing* currentElement;

    // Iterate over the vector using that iterator.
    cout << "v_boardGames contains:\n";
    for ( iterator = v_boardGames.begin() ;
          iterator != v_boardGames.end() ;
          iterator++ ) {

        // Retrieve the current element.
        // - The iterator is a pointer pointing to the current element.
        // - That element is a FunThing pointer.
        currentElement = *iterator;

        // Output the info by dereferencing that FunThing pointer.
        currentElement->ouputToStream( cout );
    }

    return 0;

} // end main
