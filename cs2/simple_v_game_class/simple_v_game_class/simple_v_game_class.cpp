//
//  Computer Science II
//  Assignment: VGame Class
//
//  Masatoshi Nishiguchi
//
//  Due: January 31, 2016
//

#include <iostream>
using namespace std;


//========================================================================//
// Declaration for the VGame class.
//========================================================================//


/**
 * The VGame class represents a video game.
 */
class VGame {
public:
    VGame( string title, double cost, int minAge, bool matureThemed );

    void setTitle( string );
    string getTitle() const;

    void setCost( double cost );
    double getCost() const;

    void setMinAge( int minAge );
    int getMinAge() const;

    void setMature( bool matureThemed );
    bool isMature() const;

private:
    string title;
    double cost;
    int minAge;
    bool matureThemed;

}; // end class VGame


//========================================================================//
// Implementation for the VGame class
//========================================================================//


// Constructor that takes the initial value for all of the attributes.
VGame::VGame( string title, double cost, int minAge, bool matureThemed ) {

    this->title        = title;
    this->cost         = cost;
    this->minAge       = minAge;
    this->matureThemed = matureThemed;

}

// Getter & setter for the title attribute.
void VGame::setTitle( string title ) {

  this->title = title;

}
string VGame::getTitle() const {

  return this->title;

}

// Getter & setter for the cost attribute.
void VGame::setCost( double cost ) {

  this->cost = cost;

}
double VGame::getCost() const {

  return this->cost;

}

// Getter & setter for the minAge attribute.
void VGame::setMinAge( int minAge ) {

  this->minAge = minAge;

}
int VGame::getMinAge() const {

  return this->minAge;

}

// Getter & setter for the matureThemed attribute.
void VGame::setMature( bool matureThemed ) {

  this->matureThemed = matureThemed;

}
bool VGame::isMature() const {

  return this->matureThemed;

}


//========================================================================//
// Declaration for the utility functions.
//========================================================================//


double getAvgAge( VGame[], int );
int countMature( VGame[], int );
int countNonMature( VGame[], int );
void printVGame( VGame );
void printVGames( VGame[], int );


//========================================================================//
// Main function.
//========================================================================//


/**
 * Test the required functionalities.
 * - Test1. VGame's four attributes should be private.
 * - Test2. VGame should have accessors and mutators for all four attributes.
 * - Test3. The countMature function.
 * - Test4. The getAvgAge function.
 */
int main() {

    // Configure the size of the list.
    const int listSize = 10;

    // Instantiate an array in main with at least four instances.
    // NOTE: Ensure that we instantiate correct number of elements.
    VGame games[ listSize ] = {

        VGame( "Super Mario Bros", 39.99, 9, false ),
        VGame( "Donkey Kong", 29.99, 12, false ),
        VGame( "Sim City", 49.99, 20, true ),
        VGame( "Sangokushi", 99.99, 20, true ),
        VGame( "Dragon Quest", 45.88, 10, false ),
        VGame( "Pac-man", 29.99, 8, false ),
        VGame( "Space Invaders", 33.50, 20, true ),
        VGame( "Frogger", 44.50, 10, false ),
        VGame( "Street Fighter", 45.6, 20, true ),
        VGame( "Tetris", 25.99, 12, false )
    };

    /*
        INFORMATION

        - Total count: 10 ( Mature: 4, Non-mature: 6 )

        - Total minAge of non-mature: 9 + 12 + 10 + 8 + 10 + 12 = 61
        - Average minAge of non-mature: 61 / 6 = 10.1666...
     */

    // ---------------------------------------------- //

    cout << "Test1. VGame's four attributes should be private." << endl;
        cout << "Manually tested" << endl;
        cout << endl;
        // games[ 0 ].title;          //==> Should cause a compile-time error.
        // games[ 0 ].cost;           //==> Should cause a compile-time error.
        // games[ 0 ].minAge;         //==> Should cause a compile-time error.
        // games[ 0 ].matureThemed;   //==> Should cause a compile-time error.

    // ---------------------------------------------- //

    cout << "Test2. VGame should have accessors and mutators for all four attributes." << endl;

        printVGames( games, listSize );

    // ---------------------------------------------- //

    cout << "Test3. countMature" << endl;

        cout << "The number of games that are mature-themed: "
             << countMature( games, listSize ) << endl;
             //==> Should be 2.

        cout << endl;

    // ---------------------------------------------- //

    cout << "Test4. getAvgAge" << endl;

        cout << "The average minimum age of games that are NOT mature-themed: "
             << getAvgAge( games, listSize ) << endl;
             //==> Should be 10.

        cout << endl;

    // ---------------------------------------------- //

    return 0;

} // end main


//========================================================================//
// Implementation for  the utility functions.
//========================================================================//


/**
 * @param  vGame[] an array of VGame
 * @return         the number of games that are mature-themed
 */
int countMature( VGame games[], int size ) {

    int count = 0;

    for ( int i = 0; i < size; i++ ) {

        if ( games[ i ].isMature() ) { count += 1; }

    }

    return count;
}


/**
 * @param  vGame[] an array of VGame
 * @return         the number of games that are not mature-themed
 */
int countNonMature( VGame games[], int size ) {

    return size - countMature( games, size );

}


/**
 * @param vGame[] an array of VGame
 * @return        the average minimum age of games that are NOT mature-themed.
 */
double getAvgAge( VGame games[], int size ) {

    // NOTE: Since the return value will be of double type, we choose double type here.
    double sumMinAgesNonMature = 0.0;

    // Iterate over the array.
    for ( int i = 0; i < size; i++ ) {

        // If an element is NOT mature-themed, add its min age to the accumulator.
        if ( ! games[ i ].isMature() ) {

            sumMinAgesNonMature += games[ i ].getMinAge();

        }

    }

    // Rerurn the average.
    // NOTE: Ensure that the result will not be trucated which can cause inacurracy.
    return sumMinAgesNonMature / countNonMature( games, size );
}


/**
 * Prints the information on the specified VGame.
 * @param game  A VGame object.
 */
void printVGame( VGame game ) {

    string matureString = ( game.isMature() ) ? "Yes" : "No";

    cout << "   Title    : " << game.getTitle()  << endl;
    cout << "   Cost     : " << game.getCost()   << endl;
    cout << "   Min. Age : " << game.getMinAge() << endl;
    cout << "   Mature?  : " << matureString     << endl;

    cout << endl;
}


/**
 * Prints information on all the VGames in the specified array.
 * @param games An array of VGame objects.
 * @param size  The size of the array.
 */
void printVGames( VGame games[], int size ) {

    for ( int i = 0; i < size; i++ ) {

        cout << "#" << i << ":" << endl;
        printVGame( games[ i ] );

    }

    cout << endl;

}
