//
//  Computer Science II
//  Assignment: Class Work (VGame) Lecture
//
//  Masatoshi Nishiguchi
//
//  Due: January 31, 2016
//

#include <iostream>
using namespace std;


/**
 * Represents a video game.
 */
class VGame {
public:

    // Constructor that takes the initial value for all of the attributes.
    VGame( string title
           double cost
           int minAge
           bool isMature ) {

        this->title    = title;
        this->cost     = cost;
        this->minAge   = minAge;
        this->isMature = isMature;

    }


    // Getter & setter for the title attribute.
    void setTitle( string title ) {
      this->title = title;
    }
    string getTitle() const {
      return this->title;
    }


    // Getter & setter for the cost attribute.
    void setCost( double cost ) {
      this->cost = cost;
    }

    double getTitle() const {
      return this->title;
    }


    // Getter & setter for the minAge attribute.
    void setMinAge( int minAge ) {
      this->minAge = minAge;
    }

    int getMinAge() const {
      return this->minAge;
    }

    // Getter & setter for the isMature attribute.
    void setMature( bool isMature ) {
      this->isMature = isMature;
    }

    bool getMature() const {
      return this->isMature;
    }

private:

    string title;
    double cost;
    int minAge;
    bool isMature;

};


/**
 * @param  vGame[] an array of VGame
 * @return the number of games that are mature-themed
 * Call it countMature.
 */
int countMature( VGame games[] ) {

    // TODO
    return 0;
}


/**
 * @param vGame[]  an array of VGame
 * @return the average minimum age of games that are NOT mature-themed.
 */
double getAverageAgeNonMature( vGame[] ) {


    // TODO
    return 0.0;
}


/**
 * Prints all the VGames in the specified array.
 * @param games An array of VGame objects.
 * @param size  The size of the array.
 */
void printVGames( VGame games[], int size ) {

    for ( int i = 0; i < size; i++ ) {

        cout <<

    }

}



int main() {

    // Instantiate an array in main with at least four instances.
    VGame myGames[] = {
        VGame( "some_title_1", 23.9, 10, false ),
        VGame( "some_title_2", 23.9, 10, false ),
        VGame( "some_title_3", 23.9, 10, false ),
        VGame( "some_title_4", 23.9, 10, false ),
        VGame( "some_title_5", 23.9, 10, false ),
    }


    // Test my code to ensure it works.

    // // Set the title attribute.
    // myVGame.title = "white";

    // // Access the title attribute and output that.
    // cout << "title: " << myVGame.title << endl;
    // cout << "minAge:  " << myVGame.getMinAge() << endl;



    // ------------------------------------------ //
    // ------------------------------------------ //


    return 0;
}

