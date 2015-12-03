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


#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <string>
#include <iomanip>
using namespace std;

// Random generator function.
// http://www.cplusplus.com/reference/algorithm/random_shuffle/
int randomGenerator(int aInt) { return std::rand() % aInt; }


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * Card is a class that represents a game card that contains a rank and suit.
 * The rank and suit are read-only.
 */
class Card {
public:

    // Static constants.
    static const string suits[4];
    static const string ranks[14]; // [0] is not used.

    // Static methods.
    // static string suitAsString(int);
    // static string rankAsString(int);

    // Constructors.
    Card();
    Card(short suit, short rank);

    // Accessers.
    short getRank() const { return rank; }
    short getSuit() const { return suit; }

    // Instance methods.
    string toString() const;

private:
    short rank;
    short suit;
};

// Initialize the static constants
const string Card::suits[4] = {
    "Hearts", "Spades", "Diamonds", "Clubs"
};
const string Card::ranks[14] = {
    "#", "A","2","3","4","5","6","7","8","9","10","J","Q","K"
};


/**
 * Default constructor.
 */
Card::Card() {
    this->suit = -1;
    this->rank = -1;
}


/**
 * Constructor. Initialize a card when created.
 */
Card::Card(short suit, short rank) {
    this->suit = suit;
    this->rank = rank;
}


//--
// Static methods
//--


// /**
//  * @param
//  * @return
//  */
// string Card::suitAsString( int suit ) {

//     return suits[suit];
// }


// /**
//  * @param
//  * @return
//  */
// string Card::rankAsString( int rank ) {

//     return ranks[rank];
// }


//--
// Instance methods
//--


/**
 * @return the string representation of the card.
 */
string Card::toString() const {

    return Card::ranks[ rank ] + " of " + Card::suits[ suit ];
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * Deck is a class that represents a deck to hold our cards.
 */
class Deck {
public:

    Deck();
    Card drawCard();
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

        for (int rank = 1; rank <= 13; rank++) {

            this->cards.push_back( Card( suit, rank ) );
        }
    }

    // Shuffle the deck.
    std::random_shuffle( cards.begin(), cards.end(), randomGenerator );
}


/**
 * @return a card from the deck.
 */
Card Deck::drawCard() {

    Card card = cards.back();  // Get the card.
    cards.pop_back();          // Remove the card from the deck.

    return card;
}


/**
 * Prints all the cards in the deck.
 */
void Deck::printAll() const {

    for (int i = 0, size = getSize(); i < size; i++) {

        cout << cards.at(i).toString() << endl;
    }
    cout << endl;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * Hand is a class that represents a Hand.
 */
class Hand {
public:
    // Static methods.
    static void countEachRank(Card*, int ranks[14]);
    static bool isStraight(Card);
    static bool isFlush(Card);
    static bool isFourOfAKind(Card);
    static bool isThreeOfAKind(Card);
    static bool isOnePair(Card);

    Hand(Deck);
    void printAll() const;
    Card cards[5]; // represent the 5 cards.

private:
    int value[6];  // represent the value of the hand.
};


/**
 * Constructor. Initialize the hand.
 */
Hand::Hand(Deck deck) {

    for (int i = 0; i < 6; i++) {
        value[i] = 0;
    }

    for (int i = 0; i < 5; i++) {
        cards[i] = deck.drawCard();
    }
}


//--
// Static methods
//--


/**
 *
 */
void Hand::countEachRank(Card* cards, int rankOccurrences[14]) {

    // Initialize the contents of the array.
    for (int x = 0; x <= 13; x++) {

        rankOccurrences[x] = 0;
    }

    // Increment occurrence array at the index of each card's rank.
    for (int idx = 0; idx < 4; idx++) {

        rankOccurrences[ cards[idx].getRank() ] += 1;
    }
}


/**
 *
 */
bool Hand::isStraight(Card) {
    // TODO

    return false;
}


/**
 *
 */
bool Hand::isFlush(Card) {
    // TODO

    return false;
}


/**
 *
 */
bool Hand::isFourOfAKind(Card) {
    // TODO

    return false;
}


/**
 *
 */
bool Hand::isThreeOfAKind(Card) {
    // TODO

    return false;
}


/**
 *
 */
bool Hand::isOnePair(Card) {
    // TODO

    return false;
}


//--
// Instance methods
//--


/**
 * Prints all the cards in the hand.
 */
void Hand::printAll() const {

    for (int i = 0; i < 5; i++) {

        cout << cards[i].toString() << endl;
    }
    cout << endl;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


int main() {

    // Seed the random.
    std::srand ( unsigned ( std::time(0) ) );

    // Create a deck.
    Deck aDeck;
    // aDeck.printAll();

    // Create a hand by drawing five cards from the deck.
    Hand aHand = Hand(aDeck);
    aHand.printAll();

    int rankOccurrences[14];
    Hand::countEachRank(aHand.cards, rankOccurrences);

    for (int i = 0; i < 14; i++) {
        cout << rankOccurrences[i] << " ";
    }

    cout << endl;

    return 0;
}

