//
//  main.cpp
//  20160202
//
//  Created by Masatoshi Nishiguchi on 2/2/16.
//  Copyright © 2016 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;


/**
 * Represents a video game.
 */
class VGame {
public:

    // Constructor that takes the initial value for all of the attributes.
    VGame( string title, int minAge ) {

        this->title    = title;
        this->minAge   = minAge;

    }

    // Getter & setter for the title attribute.
    void setTitle( string title ) {
      this->title = title;
    }
    string getTitle() const {
      return this->title;
    }

    // Getter & setter for the minAge attribute.
    void setMinAge( int minAge ) {
      this->minAge = minAge;
    }

    int getMinAge() const {
      return this->minAge;
    }


private:

    string title;
    double cost;
    int minAge;
    bool isMature;

};


//==================================================//


//---
// Polymorphism - Is-a relationship
//---

/*

  Syntax
  baseAccessSpecifier :
      public
      protected
      private
  class Klass : baseAccessSpecifier {

  }



 */




/**
 * PCGame is a VGame.
 */
class PCGame : public VGame {

};

/**
 * Adventure is a PCGame.
 */
class Adventure : public PCGame {

};


//==================================================//


int main() {

    PCGame aPCGame;

    Adventure aAdventure;


    return 0;
}
