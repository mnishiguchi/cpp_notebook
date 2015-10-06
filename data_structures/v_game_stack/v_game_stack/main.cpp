//
//  main.cpp
//  v_game_stack
//
//  Created by Masatoshi Nishiguchi on 10/1/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

/**
 * Class that represents a node
 */
class VGameNode {
public:
    string title;
    string genre;
    int minAge;

    VGameNode* next;

    // Constructors
    VGameNode();
    VGameNode(string title, string genre, int minAge);
};

/** Default constructor */
VGameNode::VGameNode() {
    next = NULL;
}

/** Constructor to create a node with a specific set of data */
VGameNode::VGameNode(string t, string g, int a) {
    next = NULL;
    title  = t;
    genre  = g;
    minAge = a;
}

/**
 * Class that represents a stack
 */
class VGameStack {
public:
    // Addresses of the beginning and end of the list
    VGameNode* top;  // First element
    VGameNode* back; // Last element

    int size;

    // Functions
    bool isEmpty();
    VGameNode* peek();
    VGameNode* pop();
    void push(string title, string genre, int minAge);
    void removeAll();
    void removeFirst();
    void showAll();

    // Constructor
    VGameStack();

    // Destructor
    ~VGameStack();
};

// Default constructor
VGameStack::VGameStack() {
    top = NULL;
    back = NULL;
    size = 0;
}

// Destructor
VGameStack::~VGameStack() {
    cout << "VGameStack is about to be destructed" << endl;
    removeAll();
}

/**
 * Returns true if the stack is empty.
 */
bool VGameStack::isEmpty() {
    return top == NULL;  // return !top; works also.
}

VGameNode* VGameStack::peek() {
    return top;
}

/**
 * Removes and returns a node from the top of the stack a la Java's ArrayList.
 * In C++, usually it is not preferred because the popped element will stay in memeory.
 * The section of code that creates an object in memory should take care of
 * deleting it as well.
 */
VGameNode* VGameStack::pop() {

    // Return if the stack is empty
    if (top == NULL) {
        cout << "The stack is empty." << endl;
        return NULL;
    }

    // Case2: not empty
    VGameNode* curr = top;   // Remember the top
    top        = top->next;  // Next node becomes top
    curr->next = NULL;       // The popped node's next is NULL.

    // Note: back did not change

    size--;  // Update the size

    return curr;
}

/**
 * Add a node before the top of the stack
 */
void VGameStack::push(string title, string genre, int minAge) {

    // Create a new node base on the specified data.
    VGameNode* newNode = new VGameNode(title, genre, minAge);

    // Case1: Empty list
    if (top == NULL) {
        top = newNode;  // The new node becomes the top.
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
void VGameStack::removeAll() {

    while (!isEmpty()) {
        removeFirst();
    }
}

/**
 * Delete the top node from memory.
 * Alternative to pop()
 */
void VGameStack::removeFirst() {
    // Return if the stack is empty
    if (top == NULL) {
        cout << "The stack is empty." << endl;
        return;
    }

    // Case2: not empty
    VGameNode* temp = top;   // Remember the top
    top        = top->next;  // Next node becomes top
    delete temp;             // Delete the node out of memory

    // Note: back did not change

    size--;  // Update the size
}

/**
 * Prints info of all the elements in the stack.
 */
void VGameStack::showAll() {

    // Return if the stack is empty
    if (top == NULL) {
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
    VGameNode* curr = top;
    while (curr != NULL) {

        // Print current node
        cout << left;
        cout << setw(24) << curr->title;
        cout << setw(16) << curr->genre;
        cout << setw(8) << curr->minAge;
        cout << endl;

        // Move the cursor to next
        curr = curr->next;
    }
    cout << "--- bottom of the stack---" << endl;
}

/**
 * Utility function to draw a horizontal seperator.
 */
void drawLine() {
    cout << endl;
    cout << setfill('~') << setw(48) << "" << setfill(' ') << endl;
    cout << endl;
}

/**
 * Main function for the program.
 */
int main() {

    // 1. Create an empty stack dynamically.

    VGameStack* gameStack = new VGameStack;

    // 2. Push elements to the stack.

    gameStack->push("Street Fighter II", "Action", 10);
    gameStack->push("Space Invaders", "Shooter", 10);
    gameStack->push("Final Fantasy IV", "Roll-playing", 10);
    gameStack->push("Mystery House", "Adventure", 10);
    gameStack->push("SimCity", "Simulation", 10);
    gameStack->push("Civilization", "Strategy", 10);
    gameStack->showAll();

    drawLine();

    // 3. Pop nodes

    while (!gameStack->isEmpty()) {
        VGameNode* theTop = gameStack->pop();
        cout << "The top was " << theTop->title << endl << endl;
        gameStack->showAll();

        drawLine();
    }

    // 4. Push elements to the stack.

    gameStack->push("Street Fighter II", "Action", 10);
    gameStack->push("Space Invaders", "Shooter", 10);
    gameStack->push("Final Fantasy IV", "Roll-playing", 10);
    gameStack->push("Mystery House", "Adventure", 10);
    gameStack->push("SimCity", "Simulation", 10);
    gameStack->push("Civilization", "Strategy", 10);
    gameStack->showAll();

    drawLine();

    // 5. Remove one

    gameStack->removeFirst();
    gameStack->showAll();

    drawLine();

    // 6. Remove all the rest

    gameStack->removeAll();
    gameStack->showAll();

    drawLine();

    return 0;
}
