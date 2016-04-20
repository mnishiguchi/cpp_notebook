//
//  main.cpp
//  Read FunThing from file
//
//  Created by Masatoshi Nishiguchi on 4/19/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
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
// Main Function
//====================================================//


int main() {
    
    ifstream dataFile;
    
    dataFile.open( "/absolute/path/to/file.txt" );
    
    char fttype[ 3 ], name[ 50 ], funLevel[ 3 ], nPlayers[ 8 ],  danger[ 3 ];
    
    // Temp var to hold an instance.
    FunThing* thing;
    
    // Temp var to hold a string version of fttype.
    string fttypeStr;
    
    // A collection to hold all the data that was read from a file.
    vector<FunThing*> collection;
    
    // Read data until the end of file is reached.
    while ( ! dataFile.eof() ) {
        
        // Read data from a file.
        // istream& getline (char* s, streamsize n, char delim );
        // http://www.cplusplus.com/reference/istream/istream/getline/
        dataFile.getline( fttype, 3, ',' );   // Read up to ','
        dataFile.getline( name, 50, ',' );    // Read up to ','
        dataFile.getline( funLevel, 3, ',' ); // Read up to ','
        dataFile.getline( nPlayers, 8, ',' ); // Read up to ','
        dataFile.getline( danger, 3, '\n' );  // Read up to '\n'
        
        // Determine the FunThing type.
        // NOTE: We cannot directly compare char array with stiring literal.
        // - Use std::strcmp function or convert them to string type.
        if        ( strcmp("GT", fttype) == 0 ) {
            // GenericThing( string thingName, int funLevel, int numberOfPlayers, bool isDangerous )
            thing = new GenericThing( name,
                                     atoi(funLevel),
                                     atoi(nPlayers),
                                     atoi(danger)
                                     );
        } else if ( strcmp("DC", fttype) == 0 ) {
            // DomesticChore( string thingName, int funLevel, int numberOfPlayers )
            thing = new DomesticChore( name,
                                      atoi(funLevel),
                                      atoi(nPlayers)
                                      );
        } else if ( strcmp("CS", fttype) == 0 ) {
            // CrazySport( string thingName, int funLevel, int numberOfPlayers )
            thing = new CrazySport( name,
                                   atoi(funLevel),
                                   atoi(nPlayers)
                                   );
        }
        
    }
    
    dataFile.close();  // Close the file
    
    
    return 0;
}

