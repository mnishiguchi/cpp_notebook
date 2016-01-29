//
//  Computer Science II
//  Assignment: VGame Class
//
//  Masatoshi Nishiguchi
//
//  Due: January 31, 2016
//

#include <iostream>
#include <iomanip>
using namespace std;


/**
 * The VGame class represents a video game.
 */
class VGame {
public:

    // Constructor that takes the initial value for all of the attributes.
    VGame( string title, double cost, int minAge, bool matureThemed ) {

        this->title         = title;
        this->cost          = cost;
        this->minAge        = minAge;
        this->matureThemed  = matureThemed;

    }

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


// ---
// IMPLEMENTATION OF GETTERS AND SETTERS
// ---


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


// ---
// DECLARATION FOR UTILITY FUNCTIONS
// ---


double averageMinAgeForNonMature( VGame[], int );
int countMature( VGame[], int );
int countNonMature( VGame[], int );
void printVGame( VGame );
void printVGames( VGame[], int );


// ---
// MAIN FUNCTIONS
// ---


int main() {

    // Instantiate an array in main with at least four instances.
    VGame myGames[] = {

        VGame( "title_1", 12.3, 8, false ),
        VGame( "title_2", 23.4, 20, true ),
        VGame( "title_3", 34.5, 20, true ),
        VGame( "title_4", 45.6, 16, false ),
        VGame( "title_5", 56.7, 6, false )

    };


    VGame aGame( "a_game", 99.9, 18, false );

    //---------------------------------------------- //

    cout << "Test1. VGame's four attributes should be private." << endl;
        cout << "Manually tested" << endl;
        cout << endl;
        // aGame.title;          //==> Should cause a sytax error.
        // aGame.cost;           //==> Should cause a sytax error.
        // aGame.minAge;         //==> Should cause a sytax error.
        // aGame.matureThemed;   //==> Should cause a sytax error.

    //---------------------------------------------- //

    cout << "Test2. VGame should have accessors and mutators for all four attributes." << endl;

        printVGame( aGame );
        printVGames( myGames, 5 );

    //---------------------------------------------- //

    cout << "Test3. countMature" << endl;

        cout << "The number of games that are mature-themed: "
             << countMature( myGames, 5 ) << endl;
             //==> Should be 2.

        cout << endl;

    //---------------------------------------------- //

    cout << "Test4. averageMinAgeForNonMature" << endl;

        cout << "The average minimum age of games that are NOT mature-themed: "
             << averageMinAgeForNonMature( myGames, 5 ) << endl;
             //==> Should be 10.

        cout << endl;

    //---------------------------------------------- //

    return 0;
}


// ---
// IMPLEMENTATION OF UTILITY FUNCTIONS
// ---


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
double averageMinAgeForNonMature( VGame games[], int size ) {

    int sumMinAgesNonMature = 0;

    // Iterate over the array.
    for ( int i = 0; i < size; i++ ) {

        // If an element is mature theme, add its min age to the accumulator.
        if ( ! games[ i ].isMature() ) {

            sumMinAgesNonMature += games[ i ].getMinAge();

        }

    }

    // Rerurn the average.
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
