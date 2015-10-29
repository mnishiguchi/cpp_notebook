//
//  main.cpp
//  v_game_sorting
//
//  Created by Masatoshi Nishiguchi on 10/29/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    Node
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

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
//    List
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/**
 * Class that represents a stack
 */
template <typename NodeType>
class VGameStack {
public:
    // Instance methods
    bool isEmpty();
    NodeType* peek();
    NodeType* pop();
    void push(string title, string genre, int minAge);
    void removeAll();
    void removeFirst();
    void showAll();

    // Constructor
    VGameStack();

    // Destructor
    ~VGameStack();

private:
    NodeType* top;  // First element
    NodeType* back; // Last element
    int size;
};

// Default constructor
template <typename NodeType>
VGameStack<NodeType>::VGameStack() {
    top  = NULL;
    back = NULL;
    size = 0;
}

// Destructor
template <typename NodeType>
VGameStack<NodeType>::~VGameStack() {
    cout << "VGameStack's destructor was called" << endl;
    removeAll();
}

/**
 * Returns true if the stack is empty.
 */
template <typename NodeType>
bool VGameStack<NodeType>::isEmpty() {
    return top == NULL;
}

template <typename NodeType>
NodeType* VGameStack<NodeType>::peek() {
    return top;
}

/**
 * Removes and returns a node from the top of the stack a la Java's ArrayList.
 * In C++, usually it is not preferred because the popped element will stay in memeory.
 * The section of code that creates an object in memory should take care of
 * deleting it as well.
 */
template <typename NodeType>
NodeType* VGameStack<NodeType>::pop() {

    // Return if the stack is empty
    if (top == NULL) {
        cout << "The stack is empty." << endl;
        return NULL;
    }

    // Case2: not empty
    NodeType* curr = top;   // Remember the top
    top        = top->next;  // Next node becomes top
    curr->next = NULL;       // The popped node's next is NULL.

    // Note: back did not change

    size--;  // Update the size

    return curr;
}

/**
 * Add a node before the top of the stack
 */
template <typename NodeType>
void VGameStack<NodeType>::push(string title, string genre, int minAge) {

    // Create a new node base on the specified data.
    NodeType* newNode = new NodeType(title, genre, minAge);

    // Case1: Empty list
    if (top == NULL) {
        top  = newNode;  // The new node becomes the top.
        back = newNode;  // The new node is also back.

        // Case2: Non-empty list
    } else {
        // Set the new node at the top of the stack.
        newNode->next = top;

        // Update top
        top = newNode;

        // Note: back did not change
    }
    size++;  // Update the size
}

/**
 * Empty the stack.
 */
template <typename NodeType>
void VGameStack<NodeType>::removeAll() {
    cout << "VGameStack's removeAll() was called" << endl;
    while (!isEmpty()) {
        removeFirst();
    }
}

/**
 * Delete the top node from memory.
 * Alternative to pop()
 */
template <typename NodeType>
void VGameStack<NodeType>::removeFirst() {
    // Return if the stack is empty
    if (top == NULL) {
        cout << "The stack is empty." << endl;
        return;
    }

    // Case2: not empty
    NodeType* temp = top;   // Remember the top
    top        = top->next;  // Next node becomes top

    cout << temp->getTitle() << " is about to be destructed." << endl;
    delete temp;             // Delete the node out of memory

    // Note: back did not change

    size--;  // Update the size
}

/**
 * Prints info of all the elements in the stack.
 */
template <typename NodeType>
void VGameStack<NodeType>::showAll() {

    // Return if the stack is empty
    if (isEmpty()) {
        cout << "The stack is empty." << endl;
        cout << "Stack size: " << size << endl;
        return;
    }

    // Print the stack size.
    cout << "Stack size: " << size << endl;
    cout << endl;

    // Print the attributes names.
    cout << left;
    cout << setw(24) << "TITLE";
    cout << setw(16) << "GENRE";
    cout << setw(8) << "MIN AGE";
    cout << endl;

    // Draw a horizonal rule.
    cout << setfill('-') << setw(48) << "" << setfill(' ') << endl;

    // Traverse the list.
    NodeType* curr = top;
    while (curr != NULL) {

        // Print current node
        cout << left;
        cout << setw(24) << curr->getTitle();
        cout << setw(16) << curr->getGenre();
        cout << setw(8)  << curr->getMinAge();
        cout << endl;

        // Move the cursor to next
        curr = curr->next;
    }
    cout << "--- bottom of the stack---" << endl;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    Stand-alone functions
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/**
 * Compare two VGameNodes by title.
 * In ASC mode, returns true if g1 < g2, else false.
 * In DESC mode, returns true if g1 > g2, else false.
 */
bool compareByTitle(VGameNode &g1, VGameNode &g2, bool isAscend) {
    if (isAscend) {
        return (g1.getTitle() < g2.getTitle());
    } else {
        return (g1.getTitle() > g2.getTitle());
    }
}

/** TODO
 * Insertion sort
 */
void insertionSort(int list[], int size) {
    int firstUnsorted;
    int position;
    int temp;

    // Inspect the unsorted portion one by one.
    for (firstUnsorted = 1; firstUnsorted < size; firstUnsorted++) {

        // If the value is less than previous
        if (list[firstUnsorted] < list[firstUnsorted - 1]) {
            temp     = list[firstUnsorted];  // Remember the value
            position = firstUnsorted;        // Remember the index of the value

            // Shift the sorted elements by one to the right
            // until the appropriate sorted position is determined.
            do {
                list[position] = list[position - 1];
                position--;

                // The value should be greater than the previous
            } while (position >= 1 && list[position - 1] > temp);

            // Set the value at the sorted position.
            list[position] = temp;
        }
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

/**
 * Main function for the program.
 */
int main() {

    // 1. Create an empty stack.

    VGameStack<VGameNode> gameStack;

    // 2. Push elements to the stack.

    gameStack.push("Street Fighter II", "Action", 10);
    gameStack.push("Space Invaders", "Shooter", 10);
    gameStack.push("Final Fantasy IV", "Roll-playing", 10);
    gameStack.push("Mystery House", "Adventure", 10);
    gameStack.push("SimCity", "Simulation", 10);
    gameStack.push("Civilization", "Strategy", 10);
    gameStack.showAll();

    drawLine();



    // 6. Remove all the rest

    gameStack.removeAll();
    gameStack.showAll();

    drawLine();

    return 0;
}
