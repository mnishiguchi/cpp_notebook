//
//  Computer Science II
//  FunThing 4
//
//  Masatoshi Nishiguchi
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <stdexcept>
// #include <cstring>
// #include <cassert>

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

    // Minimal implementation that can be overriden by subclasses.
    virtual bool operator<( const FunThing& other ) {

      // printf("Called from FunThing\n");

      return funLevel < other.funLevel;
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
// The FunThing subclasses
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

    // Override the super's < operator.
    virtual bool operator<( const FunThing& other );

protected:
    bool dangerous;
    int numberOfPlayers;
}; // end GenericThing


/**
 * Non-member Operator Overload.
 * http://en.cppreference.com/w/cpp/language/operators
 */
ostream& operator<<( ostream& os, GenericThing& thing ) {
    os << "    Fun Level : "
       << thing.getFunLevelText() << " ("<< thing.getFunLevel() << ")" << endl;
    os << "       Danger : "
       << thing.getDangerText()   << " ("<< thing.isDangerous() << ")" << endl;
    os << "      Players : "
       << thing.getNumberOfPlayers() << endl;
    os << "         Name : "
       << thing.getThingName() << endl;

    return os;
}


/**
 * Allows the insertion operator code to simply call this and pass the ostream as an argument.
 * NOTE : operator<< must be overloaded before this line otherwise this method
 * will not know that the operator is overloaded.
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


// Override the super's < operator.
/* === REQUIREMENTS ===
1. greater funLevel
    A FunThing is greater than another if it's fun level is larger.

2. dangerous is greater
    If two FunThing's have the same funLevel, then the one that is dangerous
    s greater.

3. lesser number of players
    Should they have equal values for both of these, the one with the LESSER
    number of players is considered greater.

4. ASCII value of thingName
    if all these values are the same, use the alphabetical order of the thing
    name to determine which is "greater".
 */
bool GenericThing::operator<( const FunThing& _other ) {

    // http://stackoverflow.com/a/2825479/3837223
    const GenericThing* other = dynamic_cast< const GenericThing* >( &_other );

    // printf("Called from GenericThing\n");

    if ( funLevel != other->getFunLevel() ) {
        return funLevel < other->getFunLevel();

    } else if ( dangerous != other->dangerous ) {
        return dangerous < other->dangerous;

    } else if ( numberOfPlayers != other->numberOfPlayers ) {
        return numberOfPlayers > other->numberOfPlayers;
    }

    return thingName < other->getThingName();
}


/**
 * A subclass of GenericThing. All instances of this class are considered dangerous.
 */
class CrazySport : public GenericThing {
public:
    CrazySport( string thingName, int funLevel, int numberOfPlayers )
    : GenericThing( thingName, funLevel, numberOfPlayers, true ) { }
}; // end CrazySport


/**
 * A subclass of GenericThing. All instances of this class are NOT dangerous.
 */
class DomesticChore : public GenericThing {
public:
    DomesticChore( string thingName, int funLevel, int numberOfPlayers )
    : GenericThing( thingName, funLevel, numberOfPlayers, false ) { }
}; // end DomesticChore


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
// Main
//====================================================//


bool compareFunThingPointers( FunThing * const & lhs,  FunThing * const & rhs );
FunThing* createAppropriateFunThing( string* fields );
void getHighest( list<FunThing*> &collection, list<FunThing*> &highestThings, int howMany );
void getHighLowThings( list<FunThing*> &collection, FunThing* &min, FunThing* &max );
void printAll( list<FunThing*> &collection );


int main() {

    ifstream thingsFile;

    // Five fields: [tType, tName, funLevel, numPlayers, dangerous]
    string fields[ 5 ];

    cout << "Opening file..." << endl;
    thingsFile.open( "/Users/masa/Desktop/cpp_notebook/data_files/funthingfile.txt" );

    // cout << (thingsFile.good() ? "GOOD" : "BAD") << endl;  // DEBUG

    // Temp var to hold an instance.
    FunThing* funThing;

    // A collection to hold all the data that was read from a file.
    list<FunThing*> collection;

    // Read each row.
    // istream& getline (char* s, streamsize n, char delim );
    // http://www.cplusplus.com/reference/istream/istream/getline/
    // http://stackoverflow.com/a/19936571/3837223
    string row;
    while ( getline( thingsFile, row ) ) {

        int columnIndex = 0;  // Initialize columnIndex.

        // Read each field delimited by ',' from the row.
        istringstream rowStream( row );
        string field;
        while ( getline( rowStream, field, ',' ) ) {

            fields[ columnIndex ] = field; // Store value for each field.
            columnIndex += 1;              // Update columnIndex.
        }

        // Create a new FunThing instance based on data.
        funThing = createAppropriateFunThing( fields );

        // If the instantiation was successful.
        if ( funThing != NULL ) {

            collection.push_back( funThing ); // Push this item to collection.
        }

        // Clear all the temp variables.
        for ( int i = 0; i < 5; i++ ) { fields[ i ] = ""; }
        funThing = NULL;

        // // DEBUG: Print all the fields in this row.
        // for ( int i = 0; i < 5; i++ ) { cout << "Field " << i << ": " << fields[i] << endl; }

    } // end while

    cout << "Closing file..." << endl;
    thingsFile.close();

    // Printing all
    cout << "Printing all items that were loaded from file..." << endl;
    printAll( collection );

    // Printing min and max.
    cout << "Printing the least and the greatest of all..." << endl;
    FunThing* min;
    FunThing* max;
    getHighLowThings( collection, min, max );
    cout << "Min:\n" << *min << endl;
    cout << "Max:\n" << *max << endl;

    // Get top 4 items from the collection.
    // Ensure you are prepared to catch any exceptions thrown by getHighest().
    list<FunThing*> highestThings;
    try {
        cout << "Obtaining top 4 items from the collection..." << endl;
        getHighest( collection, highestThings, 4 );
        // getHighest( collection, highestThings, -1 ); //==> Error
        // getHighest( collection, highestThings, 42 ); //==> Error

    } catch( char const* error ) {  // Catch a string literal.
        cerr << error << endl;
    }

    // Iterate highestThings to see the results
    printAll( highestThings );

    // Delete all dynamic items in the collection.
    // NOTE: Since highestThings are alias of highest items in collection, they
    // need not be deleted.
    collection.clear();

    return 0;

} // end main


//====================================================//
// Ulils
//====================================================//


bool compareFunThingPointers( FunThing * const & lhs, FunThing * const & rhs ) {
    return *lhs < *rhs;
}


/**
 * @param  fields An string array of five data items.
 * @return A new instance of FunThing that is of the specified type or
 * NULL if the passed in fields are invalid.
 */
FunThing* createAppropriateFunThing( string* fields ) {

    if ( "GT" == fields[ 0 ] ) {
        // Signature: GenericThing( string thingName, int funLevel, int numberOfPlayers, bool isDangerous )
        return new GenericThing(  fields[ 1 ],
                                  stoi( fields[ 2 ] ),
                                  stoi( fields[ 3 ] ),
                                  "1" == fields[ 4 ] );
    } else if ( "DC" == fields[ 0 ] ) {
        // Signature: DomesticChore( string thingName, int funLevel, int numberOfPlayers )
        return new DomesticChore( fields[ 1 ],
                                  stoi( fields[ 2 ] ),
                                  stoi( fields[ 3 ] ) );
    } else if ( "CS" == fields[ 0 ] ) {
        // Signature: CrazySport( string thingName, int funLevel, int numberOfPlayers )
        return new CrazySport(    fields[ 1 ],
                                  stoi( fields[ 2 ] ),
                                  stoi( fields[ 3 ] ) );
    }
    return NULL;
}


/**
 * Fill a vector with x highest FunThings contained in a supplied STL container.
 * A string exception must be thrown if the number of highest elements sought (x)
 * is greater than the number of elements in the container or if that number is
 * less-than 1.
 * @param collection    An STL container list<FunThing*> used as data source.
 * @param highestThings An STL container list<FunThing*> to store the result.
 * @param howMany       Specifies how many items to obtain from the highest.
 */
void getHighest( list<FunThing*> &collection,
                 list<FunThing*> &highestThings,
                 int howMany ) {

    // A string exception must be thrown if the number of highest elements
    // sought (x) is greater than the number of elements in the container or if
    // that number is less-than 1.
    if ( howMany < 1 ) {
        // throw new out_of_range();
        throw("Error: the number of highest elements sought must be greater than 1");

    } else if ( howMany > collection.size() ) {
        // throw new out_of_range();
        throw( "Error: the number of highest elements sought must not be greater than the number of elements in the container" );
    }

    collection.sort( compareFunThingPointers );

    // Create a reverse-iterator of list<FunThing*> type.
    list<FunThing*>::reverse_iterator iterator;

    // An temp variable to make the code easier to understand.
    FunThing* currentElement;

    // Iterate over the list using that iterator.
    int count = 0;
    for ( iterator  = collection.rbegin() ;
          iterator != collection.rend() && count < howMany ;
          iterator++, count++ ) {

        // Retrieve the current element.
        currentElement = *iterator;

        // Push the element to the highestThings list.
        highestThings.push_back( currentElement );
    }
}


/**
 * Sort the passed-in collection by ASC order and assign min and max to the
 * variables passed in as 2nd and 3rd arguments.
 * @param collection An STL container list<FunThing*>
 * @param min        A reference to FunThing* to which the "least" will be assigned.
 * @param max        A reference to FunThing* to which the "greatest" will be assigned.
 */
void getHighLowThings( list<FunThing*> &collection,
                       FunThing* &min,
                       FunThing* &max ) {

    collection.sort( compareFunThingPointers );
    min = collection.front();  // Assign min.
    max = collection.back();   // Assign max.
}


/**
 * Output all the elements in a collection.
 */
void printAll( list<FunThing*> &collection ) {

    // Create an iterator of list<FunThing*> type.
    list<FunThing*>::iterator iterator;

    // An temp variable to make the code easier to understand.
    FunThing* currentElement;

    // Iterate over the list using that iterator.
    for ( iterator  = collection.begin() ;
          iterator != collection.end()   ;
          iterator++ ) {

        // Retrieve the current element.
        currentElement = *iterator;

        // Output the info.
        currentElement->ouputToStream( cout );
    }
}
