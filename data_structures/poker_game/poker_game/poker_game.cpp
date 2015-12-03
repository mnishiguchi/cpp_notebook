/*******************************************************************************

   CSCI-241C-01 Data structures
   poker_game.cpp

   Name: Masatoshi Nishiguchi (N00263071)
   Date: 12/02/2015

   Due: Monday, December 7, 2015

 *******************************************************************************/

/*
DESCRIPTION

 */



// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;


/**
 * Card is a class that represents a game card that contains a rank and suit.
 */
class Card {
public:
    // Static constants.
    static const string suits[4];
    static const string ranks[13];

    // Static methods.
    static string suitAsString(int);
    static string rankAsString(int);

    // Constructors.
    Card(short suit, short rank);

    // Accessers.
    short getRank() const { return rank; }
    short getSuit() const { return suit; }

private:
    short rank;
    short suit;
};

// Initialize the static constants
const string Card::suits[4] = {
    "Hearts", "Spades", "Diamonds", "Clubs"
};
const string Card::ranks[13] = {
    "A","2","3","4","5","6","7","8","9","10","J","Q","K"
};


/**
 * Constructor. Initialize a card when created.
 */
Card::Card(short suit, short rank) {
    this->suit = suit;
    this->rank = rank;
}


/**
 * @param
 * @return
 */
string Card::suitAsString( int suit ) {

    return suits[suit];
}


/**
 * @param
 * @return
 */
string Card::rankAsString( int rank ) {

    return ranks[rank];
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * Deck is a class that represents a deck to hold our cards.
 */
class Deck {
public:

    Deck();
    Card drawFromDeck();
    short getSize() const { return cards.size(); }
    void printAll() const;

private:
    vector<Card> cards;
};


/**
 * Constructor. Initialize the deck.
 */
Deck::Deck() {

    // Create the deck.
    for (int suit = 0; suit < 4; suit++) {

        for (int rank = 0; rank < 13; rank++) {

            this->cards.push_back( Card( suit, rank ) );
        }
    }

    // Shuffle the deck.
    std::random_shuffle( cards.begin(), cards.end() );
}


/**
 * @return a card from the deck.
 */
Card Deck::drawFromDeck() {

    Card card = cards.back();  // Get the card.
    cards.pop_back();          // Remove the card from the deck.

    return card;
}


/**
 * Prints all the cards in the deck.
 */
void Deck::printAll() const {

    for (int i = 0, size = getSize(); i < size; i++) {

        cout << Card::suitAsString( cards.at(i).getSuit() ) << "-"
             << Card::rankAsString( cards.at(i).getRank() ) << endl;
    }
    cout << endl;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //



// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


int main() {

    Deck aDeck;
    aDeck.printAll();

    return 0;
}

