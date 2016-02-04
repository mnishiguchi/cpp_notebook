#include <iostream>
using namespace std;


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
