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
    VGame( string title,
           double cost,
           int minAge,
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

    double getCost() const {
      return this->cost;
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
 * Obtains the number of VGames whose min age is less than 13.
 */
int getCountKidGames( VGame games[], int size ) {

    int count = 0;

    for ( int i = 0; i < size; i++ ) {

        if ( games[ i ].getMinAge() < 13 ) { count += 1; }

    }

    return count;
}


int main() {

    // Instantiate an array in main with at least four instances.
    VGame games[] = {
        VGame( "some_title_1", 23.9, 10, false ),
        VGame( "some_title_2", 23.9, 10, false ),
        VGame( "some_title_3", 23.9, 10, false ),
        VGame( "some_title_4", 23.9, 10, false ),
        VGame( "some_title_5", 23.9, 10, false ),
    };


    // Test my code to ensure it works.
    cout << "getCountKidGames: " << getCountKidGames( games, 5 ) << endl;


    // // Set the title attribute.
    // myVGame.title = "white";

    // // Access the title attribute and output that.
    // cout << "title: " << myVGame.title << endl;
    // cout << "minAge:  " << myVGame.getMinAge() << endl;



    // ------------------------------------------ //
    // ------------------------------------------ //


    return 0;
}

