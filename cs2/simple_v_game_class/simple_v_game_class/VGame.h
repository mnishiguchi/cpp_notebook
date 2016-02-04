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
