/*******************************************************************************

   CSCI-241C-01 Data structures
   poker_game.cpp

   Name: Masatoshi Nishiguchi (N00263071)
   Date: 12/02/2015

   Due: Monday, December 7, 2015

 *******************************************************************************/

/*
# Description

1. Create a deck of 52 cards in a random order.
2. Create a hand of 5 card that are drawn from the deck.
3. Print the value of the card.


# Designing

- Write about how you would approach this problem.
- What classes will you use?

    As a whole, I will take the object-oriented approach where I design a class
    for each component of the program, and each class takes responsibily for their
    assigned tasks.

    The Card class:
        - represents a card with suit and rank.
        - contains toString method that returns its string representation.
    The Deck class:
        - represents the deck.
        - creates a pile of cards.
        - shuffles the deck.
        - provides five cards to a hand.
    The Hand class:
        - represents a hand of five cards.
        - contains static methods to judge the value of the hand.

    I determine the type of a hand by analysing the patterns of the occurrences
    of suits and ranks. For example, I may obtain the following data:

        Data set A
            Suits: { 0, 1, 4, 0 }
            Ranks: { 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0 }

            - Four cards have the same suit.       => no match
            - All the cards have different ranks.  => no match

            => [Value] High card

        Data set B
            Suits: { 1, 0, 3, 1 }
            Ranks: { 0, 0, 0, 0, 0, 2, 0, 2, 0, 1, 0, 0, 0, 0  }

            - Three cards have the same suit.      => no match
            - Two cards share the same rank.       => One pair

            => [Value] One pair


- How will the function indicate the hand?

    In this program, I will create an instance method in the Hand class, which
    is made up of several components:
        1. obtain the occurrences of suits in a hand as an int array.
        2. obtain the occurrences of ranks in a hand as an int array.
        3. judge the hand against each type of hand based on the occurrence data.
        4. print the result to the console.
        5. return the result as a string in case we need it in the subsequent processes.

- What data structures would be useful here?

    For the cards in a deck object:
        - dynamic array, vector or stack can be used since the size of the deck will change
        when distribuging cards in the course of the actual game.
        - Since we need pushing, popping and shuffling operations for the deck,
        C++ vector would be convinient because it has many built-in utility functions
        available, such as push_back, shuffle, etc.

    For the cards in a hand object:
        - fixed-size array would be appropriate because the size of the hand is
        always five also we want a constant-time access to each element.

- What problems do you see in your approach?

    - Considering the repetitive nature of the card game, if we have improper
    creation or deletion of objects exists in the program, it may waste memory
    and slow down the program.


# A function that accepts the five cards of a hand and will examine the cards
and returns some way to indicate the highest hand.

    - I create an instance method of Hand class, determineAndPrintValue(), which
    determine the value of the hand, print the result and return the result as
    a string in case that we need it later in the program.
    - In order to keep each Hand object small, I decided to make the hand-judging
    methods be static methods.
 */


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


#include <iostream>     // std::cout
#include <string>
#include <iomanip>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <chrono>       // std::this_thread::sleep_for(std::chrono::seconds(1))
#include <thread>       // std::this_thread::sleep_for(std::chrono::seconds(1))

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
    static const string ranks[14]; // NOTE: [0] is not used.

    // Constructors.
    Card();
    Card(short suit, short rank);

    // Accessers.
    short getRank() const { return rank; }
    short getSuit() const { return suit; }

    // Instance methods.
    string toString() const;

private:
    short rank;  // Of short-type to save memory space.
    short suit;  // ditto
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
    void printCards() const;

private:
    vector<Card> cards; // I use a vector in case of resizing the list in the future
                        // implementations, also std::random_shuffle(...) utility is convenient.
};


/**
 * Constructor. Initialize the deck.
 */
Deck::Deck() {

    // Create the deck with 52 cards.
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 1; rank <= 13; rank++) {  // NOTE: [0] is not used.

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
void Deck::printCards() const {

    for (int i = 0, size = getSize(); i < size; i++) {

        cout << "Card#" << setw(2) << i+1 << ": " << cards.at(i).toString() << endl;

    }

    cout << endl;  // Insert a blank line.
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * Hand is a class that represents a Hand.
 * The static methods are used to analyse the value of a hand.
 */
class Hand {
public:
    // Constructors.
    Hand(Deck);

    // Instance methods.
    string determineAndPrintValue();
    void printCards() const;

private:
    // Instance variables.
    Card cards[5]; // represent the 5 cards.

    // Static constants.
    static const int NUM_CARDS;

    // Static methods.
    static void countEachSuit(Card*, int*);
    static void countEachRank(Card*, int*);
    static string determineAndPrintValue(int suitOccurrences[4], int rankOccurrences[14]);
    static bool isStraightFlush(int suitOccurrences[4], int rankOccurrences[14]);
    static bool isFlush(int suitOccurrences[4]);
    static bool isFourOfAKind(int rankOccurrences[14]);
    static bool isThreeOfAKind(int rankOccurrences[14]);
    // static bool isTwoPairs(int rankOccurrences[14]);
    static bool isOnePair(int rankOccurrences[14]);
};


// Initialize static constants.
const int Hand::NUM_CARDS = 5;


/**
 * Constructor. Initialize the hand by drawing five cards from the deck.
 */
Hand::Hand(Deck deck) {

    // Draw five cards from the deck.
    for (int i = 0; i < Hand::NUM_CARDS; i++) {
        cards[ i ] = deck.drawCard();
    }
}


//--
// Static methods.
//--


/**
 * Report the occurrences of all the suits as an int array.
 * @param cards
 * @param suitOccurrences
 */
 void Hand::countEachSuit(Card* cards, int suitOccurrences[4]) {

    // Initialize the contents of the array.
    for (int i = 0; i < 4; i++) {
        suitOccurrences[ i ] = 0;
    }

    // Increment occurrence array at the index of each card's suit.
    for (int idx = 0; idx < Hand::NUM_CARDS; idx++) {
        suitOccurrences[ cards[idx].getSuit() ] += 1;
    }
 }


/**
 * Report the occurrences of all the ranks as an int array.
 * @param cards
 * @param rankOccurrences
 */
void Hand::countEachRank(Card* cards, int rankOccurrences[14]) {

    // Initialize the contents of the array.
    for (int i = 0; i < 14; i++) {
        rankOccurrences[ i ] = 0;
    }

    // Increment occurrence array at the index of each card's rank.
    for (int idx = 0; idx < Hand::NUM_CARDS; idx++) {
        rankOccurrences[ cards[idx].getRank() ] += 1;
    }
}


/**
 * Determine the result based on suits and ranks of the cards.
 * @param suitOccurrences
 * @param rankOccurrences
 */
string Hand::determineAndPrintValue( int suitOccurrences[4], int rankOccurrences[14] ) {

    string valueStr;

    // Determine the result based on suits and ranks of the cards.
    if ( Hand::isStraightFlush(suitOccurrences, rankOccurrences) ) {
        valueStr =  "Straight flush";
    } else if ( Hand::isFlush(suitOccurrences) ) {
        valueStr =  "Flush";
    } else if ( Hand::isFourOfAKind(rankOccurrences) ) {
        valueStr =  "Four of a kind";
    } else if ( Hand::isThreeOfAKind(rankOccurrences) ) {
        valueStr =  "Three of a kind";
    // } else if ( Hand::isTwoPairs(rankOccurrences) ) {
    //     valueStr =  "Two pairs";
    } else if ( Hand::isOnePair(rankOccurrences) ) {
        valueStr =  "One pair";
    } else {
        valueStr =  "High card";
    }

    cout << "[Value] " << valueStr << endl;
    cout << endl;  // Insert a blank line.

    return valueStr;
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
        if ( rankOccurrences[ i - 1 ] > 0 && rankOccurrences[ i ] > 0 ) {
            counter += 1;
        } else {
            counter = 0;
        }

        if ( counter == Hand::NUM_CARDS ) {
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

    // Iterate through all the four suits.
    for ( int i = 0; i < 4; i++ ) {

        // The occurrence of the suits must be 5 concentrated on one suit.
        if ( suitOccurrences[ i ] == Hand::NUM_CARDS ) {
            return true;
        }
    }

    return false;
}


/**
 * Four cards share the same rank.
 * @param rankOccurrences
 * @return true if the hand is flush.
 */
bool Hand::isFourOfAKind( int rankOccurrences[4] ) {

    // Iterate through all the fourteen ranks.
    for ( int i = 0; i < 14; i++ ) {

        // Four cards must have the same rank.
        if ( rankOccurrences[ i ] == 4 ) {
            return true;
        }
    }

    return false;
}


/**
 * Three cards share the same rank.
 * @param rankOccurrences
 * @return true if the hand is three of a kind.
 */
bool Hand::isThreeOfAKind( int rankOccurrences[4] ) {

    // Iterate through all the fourteen ranks.
    for ( int i = 0; i < 14; i++ ) {

        // Three cards must have the same rank.
        if ( rankOccurrences[ i ] == 3 ) {
            return true;
        }
    }

    return false;
}


/**
 * Two cards shares the same rank, and that occurs twice in the hand.
 * @param rankOccurrences
 * @return true if the hand is one pair.
 */
// bool Hand::isTwoPairs( int rankOccurrences[4] ) {

//     int count = 0;

//     // Iterate through all the fourteen ranks.
//     for ( int i = 0; i < 14; i++ ) {

//         // Two cards must have the same rank.
//         if ( rankOccurrences[ i ] == 2 ) {
//             count += 1;
//         }
//     }

//     return count == 2;
// }


/**
 * Two cards shares the same rank.
 * @param rankOccurrences
 * @return true if the hand is one pair.
 */
bool Hand::isOnePair( int rankOccurrences[4] ) {

    // Iterate through all the fourteen ranks.
    for ( int i = 0; i < 14; i++ ) {

        // Two cards must have the same rank.
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
 * Determine the result based on suits and ranks of the cards.
 */
string Hand::determineAndPrintValue() {

    // Check the rankOccurrences.
    int rankOccurrences[14];
    Hand::countEachRank( this->cards, rankOccurrences );

    // Check the suitOccurrences.
    int suitOccurrences[4];
    Hand::countEachSuit( this->cards, suitOccurrences );

    // Determine the result based on suits and ranks of the cards.
    return Hand::determineAndPrintValue( suitOccurrences, rankOccurrences );
}


/**
 * Prints all the cards in the hand.
 */
void Hand::printCards() const {

    cout << "[Your hand]" << endl;

    for (int i = 0; i < Hand::NUM_CARDS; i++) {

        cout << "  " << this->cards[ i ].toString() << endl;

    }

    cout << endl;  // Insert a blank line.
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


int main() {

    // Loop the whole thing.
    while (true) {

        // Seed the random.
        std::srand ( unsigned ( std::time(0) ) );

        // Create a deck.
        Deck theDeck;
        // theDeck.printCards();

        // Create a hand by drawing five cards from the deck.
        Hand aHand = Hand( theDeck );
        aHand.printCards();

        // Check the rankOccurrences.
        // int rankOccurrences[14];
        // Hand::countEachRank( aHand.cards, rankOccurrences );
        // for (int i = 0; i < 14; i++) {
        //     cout << rankOccurrences[ i ] << " ";
        // }
        // cout << endl;  // Move to next line.

        // Check the suitOccurrences.
        // int suitOccurrences[4];
        // Hand::countEachSuit( aHand.cards, suitOccurrences );
        // for (int i = 0; i < 4; i++) {
        //     cout << suitOccurrences[ i ] << " ";
        // }
        // cout << endl;  // Move to next line.
        // cout << endl;  // Insert a blank line.

        // Print the value of the hand.
        string valueStr = aHand.determineAndPrintValue();
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        // Terminate the program when the specified value is obtained.
        if (valueStr == "One pair") break;

        // Sleep for a sec.
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // // Ask the user if s/he wants to continue.
        // char ch = '?';
        // cout << "c: continue, q: quit: ";
        // cin >> ch;
        // if (cin.fail() || toupper(ch) != 'C') {
        //     break;
        // }
    }

    return 0;
}

/* OUTPUT

[Your hand]
  3 of Hearts
  5 of Spades
  A of Diamonds
  J of Clubs
  10 of Hearts

[Value] High card

[Your hand]
  Q of Clubs
  Q of Hearts
  Q of Diamonds
  4 of Clubs
  Q of Spades

[Value] Four of a kind

Program ended with exit code: 0

 */


