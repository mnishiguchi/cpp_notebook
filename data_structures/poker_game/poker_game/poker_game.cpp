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
    static void countEachSuit(Card*, int*);
    static void countEachRank(Card*, int*);
    static bool isStraightFlush(int suitOccurrences[4], int rankOccurrences[14]);
    static bool isFlush(int suitOccurrences[4]);
    static bool isFourOfAKind(int rankOccurrences[14]);
    static bool isThreeOfAKind(int rankOccurrences[14]);
    static bool isOnePair(int rankOccurrences[14]);

    // Constructors.
    Hand(Deck);

    // Instance methods.
    void printAll() const;

    // Instance variables.
    Card cards[5]; // represent the 5 cards.
};


/**
 * Constructor. Initialize the hand.
 */
Hand::Hand(Deck deck) {

    // Draw five cards from the deck.
    for (int i = 0; i < 5; i++) {
        cards[i] = deck.drawCard();
    }
}


//--
// Static methods
//--


/**
 * @param cards
 * @param suitOccurrences
 */
 void Hand::countEachSuit(Card* cards, int suitOccurrences[4]) {

    // Initialize the contents of the array.
    for (int x = 0; x < 4; x++) {
        suitOccurrences[x] = 0;
    }

    // Increment occurrence array at the index of each card's suit.
    for (int idx = 0; idx < 4; idx++) {
        suitOccurrences[ cards[idx].getSuit() ] += 1;
    }
 }


/**
 * @param cards
 * @param rankOccurrences
 */
void Hand::countEachRank(Card* cards, int rankOccurrences[14]) {

    // Initialize the contents of the array.
    for (int x = 0; x < 14; x++) {
        rankOccurrences[x] = 0;
    }

    // Increment occurrence array at the index of each card's rank.
    for (int idx = 0; idx < 4; idx++) {
        rankOccurrences[ cards[idx].getRank() ] += 1;
    }
}


/**
 * All five cards are arranged in contiguous order of rank and are of the same suit.
 * @param suitOccurrences
 * @param rankOccurrences
 * @return true if the hand is straight flush.
 */
bool Hand::isStraightFlush( int suitOccurrences[4], int rankOccurrences[14] ) {

    // All the five cards must have the same suit.
    if ( ! Hand::isFlush( suitOccurrences ) ) {
        return false;
    }

    // All five cards must be arranged in contiguous order of rank.
    int counter = 0;
    for ( int i = 1; i < 14; i++ ) {

        // Count the contiguous succession of ranks.
        if ( rankOccurrences[i - 1] == 1 && rankOccurrences[i] == 1 ) {
            counter += 1;
        } else {
            counter = 0;
        }

        if ( counter == 5 ) {
            return true;
        }
    }

    return false;
}


/**
 * All the cards of a hand are of the same suit.
 * @param suitOccurrences
 * @return true if the hand is flush.
 */
bool Hand::isFlush( int suitOccurrences[4] ) {

    // All the five cards must have the same suit.
    for ( int i = 0; i < 4; i++ ) {

        if ( suitOccurrences[ i ] == 5 ) {
            return true;
        }
    }

    return false;
}


/**
 * Four cards are of a particular rank.
 * @param rankOccurrences
 * @return true if the hand is flush.
 */
bool Hand::isFourOfAKind( int rankOccurrences[4] ) {

    // Four cards must have the same rank.
    for ( int i = 0; i < 14; i++ ) {

        if ( rankOccurrences[ i ] == 4 ) {
            return true;
        }
    }

    return false;
}


/**
 * Three cards are of a particular rank.
 * @param rankOccurrences
 * @return true if the hand is three of a kind.
 */
bool Hand::isThreeOfAKind( int rankOccurrences[4] ) {

    // Four cards must have the same rank.
    for ( int i = 0; i < 14; i++ ) {

        if ( rankOccurrences[ i ] == 3 ) {
            return true;
        }
    }

    return false;
}


/**
 * Two cards shares the same rank.
 * @param rankOccurrences
 * @return true if the hand is one pair.
 */
bool Hand::isOnePair( int rankOccurrences[4] ) {

    // Four cards must have the same rank.
    for ( int i = 0; i < 14; i++ ) {

        if ( rankOccurrences[ i ] == 2 ) {
            return true;
        }
    }

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

    // Check the rankOccurrences.
    int rankOccurrences[14];
    Hand::countEachRank(aHand.cards, rankOccurrences);
    for (int i = 0; i < 14; i++) {
        cout << rankOccurrences[i] << " ";
    }
    cout << endl;

    // Check the suitOccurrences.
    int suitOccurrences[4];
    Hand::countEachSuit(aHand.cards, suitOccurrences);
    for (int i = 0; i < 4; i++) {
        cout << suitOccurrences[i] << " ";
    }
    cout << endl;

    // Determine the result.
    if ( Hand::isStraightFlush(suitOccurrences, rankOccurrences) ) {
        cout << "isStraightFlush" << endl;

    } else if ( Hand::isFlush(suitOccurrences) ) {
        cout << "isFlush" << endl;

    } else if ( Hand::isFourOfAKind(rankOccurrences) ) {
        cout << "isFourOfAKind" << endl;

    } else if ( Hand::isThreeOfAKind(rankOccurrences) ) {
        cout << "isThreeOfAKind" << endl;

    } else if ( Hand::isOnePair(rankOccurrences) ) {
        cout << "isOnePair" << endl;

    } else {
        cout << "High card" << endl;
    }

    cout << endl;

    return 0;
}

