/********************************************************************

 CSCI-241C-01 Data structures
 v_game_array_sorting.cpp

 Name: Masatoshi Nishiguchi (N00263071)
 Date: 11/03/2015

 ********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**
 * Class that represents a node
 */
class VGameNode {
public:
    void setTitle(string);
    string getTitle() const;
    void setGenre(string);
    string getGenre() const;
    void setMinAge(int);
    int getMinAge() const;

    VGameNode* next;

    // Constructors
    VGameNode();
    VGameNode(string title, string genre, int minAge);

    // Opeartor overloading
    bool operator==(VGameNode& rhs) const;
    bool operator<(VGameNode& rhs) const;
    bool operator>(VGameNode& rhs) const;

private:
    string title;
    string genre;
    int minAge;
};

/** Default constructor */
VGameNode::VGameNode() {
    next = NULL;
}

/** Constructor to create a node with a specific set of data */
VGameNode::VGameNode(string title, string genre, int minAge) {
    next = NULL;
    this->title  = title;
    this->genre  = genre;
    this->minAge = minAge;
}

// Operator overloading

bool VGameNode::operator==(VGameNode& rhs) const {
    return title == rhs.title;
}
bool VGameNode::operator<(VGameNode& rhs) const {
    return title < rhs.title;
}
bool VGameNode::operator>(VGameNode& rhs) const {
    return title > rhs.title;
}

// Getters and setters

void VGameNode::setTitle(string title) {
    this->title = title;
}

string VGameNode::getTitle() const {
    return title;
}

void VGameNode::setGenre(string genre) {
    this->genre = genre;
}

string VGameNode::getGenre() const {
    return genre;
}

void VGameNode::setMinAge(int minAge) {
    this->minAge = minAge;
}

int VGameNode::getMinAge() const {
    return minAge;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    Sorting related functions
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/**
 * Compare two VGameNodes by title.
 * In ASC mode, returns true if g1 < g2, else false.
 * In DESC mode, returns true if g1 > g2, else false.
 */
bool compareByTitle(VGameNode& g1, VGameNode& g2, bool isAscend) {

    bool answer = g1.getTitle() < g2.getTitle();
    cout << "Compared" << endl;
    return (isAscend) ? answer : !answer;
}

/**
 * Compare two VGameNodes by age.
 * In ASC mode, returns true if g1 < g2, else false.
 * In DESC mode, returns true if g1 > g2, else false.
 */
bool compareByMinAge(VGameNode& g1, VGameNode& g2, bool isAscend) {

    bool answer = g1.getMinAge() < g2.getMinAge();
    cout << "Compared" << endl;
    return (isAscend) ? answer : !answer;
}

/**
 * Compare two VGameNodes by genre.
 * In ASC mode, returns true if g1 < g2, else false.
 * In DESC mode, returns true if g1 > g2, else false.
 */
bool compareByGenre(VGameNode& g1, VGameNode& g2, bool isAscend) {

    bool answer = g1.getGenre() < g2.getGenre();
    cout << "Compared" << endl;
    return (isAscend) ? answer : !answer;
}

void swap(VGameNode& d1, VGameNode& d2) {
    VGameNode temp = d1;
    d1 = d2;
    d2 = temp;
    cout << "Swapped" << endl;
}

/**
 * Sorts a linked list based on the sorting key
 * that is specified by one of the sortFncPtr functions.
 * list       - a pointer to an array
 * listSize   - the size of the array
 * sortFncPtr - a pointer to a function that determines the comparison requirements.
 */
void bubbleSort(VGameNode list[], int listSize,
    bool (*sortFncPtr)(VGameNode&, VGameNode&, bool)) {

    bool swapped;
    do {
        // Repeat until there is no need for swapping.
        swapped = false;
        // Iterate over the entire list.
        for (int i = 1; i < listSize; i++) {
            // Swap if the sorting requirement is not met.
            if ( !sortFncPtr(list[i-1], list[i], true) ) {
                swap(list[i-1], list[i]);
                swapped = true;
            }
        }
    } while (swapped);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    Utility functions
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/**
 * list[]   - an array of pointers to VGameNodes
 * listSize - the number of the list items
 */
void printAll(VGameNode list[], int listSize) {
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
void drawLine() {
    cout << endl;
    cout << setfill('~') << setw(48) << "" << setfill(' ') << endl;
    cout << endl;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    Main
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main() {

    cout << "\nCreating a list of VGameNodes\n" << endl;

    int LIST_SIZE = 6;

    VGameNode games[] = {
        VGameNode("Foo", "Action", 4),
        VGameNode("Pqr", "Shooter", 6),
        VGameNode("Bar", "Roll-playing", 9),
        VGameNode("Mno", "Adventure", 1),
        VGameNode("Abc", "Simulation", 2),
        VGameNode("Xyz", "Strategy", 5),
    };

    cout << "\nBefore sorting\n" << endl;
    printAll(games, LIST_SIZE);
    drawLine();

    bubbleSort( games, LIST_SIZE, &compareByMinAge );
    cout << "\nAfter sorting by minage\n" << endl;
    printAll(games, LIST_SIZE);
    drawLine();

    bubbleSort( games, LIST_SIZE, &compareByTitle );
    cout << "\nAfter sorting by title\n" << endl;
    printAll(games, LIST_SIZE);
    drawLine();

    bubbleSort( games, LIST_SIZE, &compareByGenre );
    cout << "\nAfter sorting by genre\n" << endl;
    printAll(games, LIST_SIZE);
    drawLine();

    return 0;
}
