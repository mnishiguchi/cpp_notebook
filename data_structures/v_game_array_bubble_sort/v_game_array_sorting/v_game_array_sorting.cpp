/********************************************************************

 CSCI-241C-01 Data structures
 Sorting Project
 v_game_array_sorting.cpp

 Name: Masatoshi Nishiguchi (N00263071)
 Date: 11/03/2015

 This program demonstrates a sorting function that takes as an argument
 a function pointer to a stand-alone comparator.
 The sorting requirements are determined by the comparater, which enables us to
 switch sorting requirements without modifying the sorting algorithm.

 ********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**
 * Class that represents a video game
 */
class VGame {
public:
    // Constructor
    VGame(string title, string genre, int minAge);

    // Accessor functions
    string getTitle() const;
    string getGenre() const;
    int getMinAge() const;

    // Opeartor overloading
    bool operator==(VGame& rhs) const;
    bool operator<(VGame& rhs) const;
    bool operator>(VGame& rhs) const;
    bool operator<=(VGame& rhs) const;
    bool operator>=(VGame& rhs) const;

private:
    string title;
    string genre;
    int minAge;
};

/**
 * Constructor to instantiate a VGame with a specific set of data
 */
VGame::VGame(string title, string genre, int minAge) {
    this->title  = title;
    this->genre  = genre;
    this->minAge = minAge;
}

//==> Operator overloading

bool VGame::operator==(VGame& rhs) const {
    return title == rhs.title;
}

bool VGame::operator<(VGame& rhs) const {
    return title < rhs.title;
}

bool VGame::operator>(VGame& rhs) const {
    return title > rhs.title;
}

bool VGame::operator<=(VGame& rhs) const {
    return title <= rhs.title;
}

bool VGame::operator>=(VGame& rhs) const {
    return title >= rhs.title;
}

//==> Getters

string VGame::getTitle() const {
    return title;
}

string VGame::getGenre() const {
    return genre;
}

int VGame::getMinAge() const {
    return minAge;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    Sorting related functions
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/**
 * Compare two VGames by title.
 * In ASC mode, returns true if g1 < g2, else false.
 * In DESC mode, returns true if g1 > g2, else false.
 * In case of g1 == g2, returns true.
 */
bool compareByTitle(VGame& g1, VGame& g2, bool isAscend) {
    bool answer = (g1 <= g2);
    cout << "Result of comparison: " << (answer ? "true" : "false") << endl;
    return (isAscend) ? answer : !answer;
}

/**
 * Compare two VGames by age.
 * In ASC mode, returns true if g1 < g2, else false.
 * In DESC mode, returns true if g1 > g2, else false.
 * In case of g1 == g2, compares the items by title.
 */
bool compareByMinAge(VGame& g1, VGame& g2, bool isAscend) {
    bool answer;

    if (g1.getMinAge() != g2.getMinAge()) {
        answer = g1.getMinAge() < g2.getMinAge();
    } else {
        answer = (g1 <= g2);
    }

    cout << "Result of comparison: " << (answer ? "true" : "false") << endl;
    return (isAscend) ? answer : !answer;
}

/**
 * Compare two VGames by genre.
 * In ASC mode, returns true if g1 < g2, else false.
 * In DESC mode, returns true if g1 > g2, else false.
 * In case of g1 == g2, compares the items by title.
 */
bool compareByGenre(VGame& g1, VGame& g2, bool isAscend) {
    bool answer;

    if (g1.getGenre() != g2.getGenre()) {
        answer = g1.getGenre() < g2.getGenre();
    } else {
        answer = (g1 <= g2);
    }

    cout << "Result of comparison: " << (answer ? "true" : "false") << endl;
    return (isAscend) ? answer : !answer;
}

/**
 * Swap two VGames that are passed in by reference.
 */
void swap(VGame& d1, VGame& d2) {
    VGame temp = d1;
    d1 = d2;
    d2 = temp;
    cout << "---Swapped---" << endl;
}

/**
 * Sorts an array of VGame using the specified comparator function.
 * list       - a pointer to an array of VGame
 * listSize   - the size of the array
 * sortFncPtr - a pointer to a comparator function that takes three arguments:
 *              VGame&, VGame& and bool.
 */
void bubbleSort( VGame list[],
                 int listSize,
                 bool (*sortFncPtr)(VGame&, VGame&, bool) ) {

    bool swapped;
    do {
        swapped = false; // Initialize the flag

        // Iterate over the entire list.
        for (int i = 1; i < listSize; i++) {

            // Swap if the sorting requirement is not met.
            if ( !sortFncPtr( list[i - 1], list[i], true ) ) {
                swap( list[i - 1], list[i] );
                swapped = true; // Swapping occurred.
            }
        }
    } while (swapped); // Exit the loop if no swapping occurred.

    cout << "Sorted" << endl;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    Utility functions
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/**
 * Prints all the items of an array of VGames.
 * list[]   - an array of pointers to VGames
 * listSize - the number of the list items
 */
void printAll(VGame list[], int listSize) {
    for (int i = 0; i < listSize; i++) {
        cout << left;
        cout << setw(24) << list[i].getTitle();
        cout << setw(16) << list[i].getGenre();
        cout << setw(8)  << list[i].getMinAge();
        cout << endl;
    }
}

/**
 * Utility function to draw a horizontal seperator.
 */
void drawSeparatorLine() {
    cout << endl;
    cout << setfill('~') << setw(48) << "" << setfill(' ') << endl;
    cout << endl;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    Main
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main() {
    const int LIST_SIZE = 8;

    cout << "\nCreating a list of " << LIST_SIZE << " VGames...\n" << endl;

    VGame games[] = {
        VGame("Street Fighter II", "Action", 10),
        VGame("Killer Shark", "Shooter", 18),
        VGame("Final Fantasy IV", "Roll-playing", 10),
        VGame("Mystery House", "Adventure", 5),
        VGame("SimCity", "Simulation", 17),
        VGame("Civilization", "Strategy", 18),
        VGame("Tetris", "Puzzle", 10),
        VGame("Break out", "Arcade", 10),
    };
    printAll(games, LIST_SIZE);
    drawSeparatorLine();

    cout << "\nSorting by title...\n" << endl;

    bubbleSort( games, LIST_SIZE, compareByTitle );
    cout << "\nAfter sorting by title\n" << endl;
    printAll(games, LIST_SIZE);
    drawSeparatorLine();

    cout << "\nSorting by minage (secondary key: title)\n" << endl;

    bubbleSort( games, LIST_SIZE, compareByMinAge );
    cout << "\nAfter sorting by minage \n" << endl;
    printAll(games, LIST_SIZE);
    drawSeparatorLine();

    cout << "\nSorting by genre (secondary key: title)\n" << endl;

    bubbleSort( games, LIST_SIZE, compareByGenre );
    cout << "\nAfter sorting by genre\n" << endl;
    printAll(games, LIST_SIZE);
    drawSeparatorLine();

    return 0;
}
