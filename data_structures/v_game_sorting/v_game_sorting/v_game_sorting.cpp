/********************************************************************

    v_game_sorting.cpp
    Created by Masatoshi Nishiguchi on 10/29/15.
    Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.

********************************************************************/

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
//    List
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/**
 * Class that represents a stack
 */
template <typename NodeType>
class SimpleStack {
public:
    // Instance methods
    int getSize() const;
    bool isEmpty();
    NodeType* peek();
    NodeType* pop();
    void push(string title, string genre, int minAge);
    void removeAll();
    void removeFirst();
    void showAll();

    // Constructor
    SimpleStack();

    // Destructor
    ~SimpleStack();

private:
    NodeType* top;  // First element
    NodeType* back; // Last element
    int size;
};

// Default constructor
template <typename NodeType>
SimpleStack<NodeType>::SimpleStack() {
    top  = NULL;
    back = NULL;
    size = 0;
}

// Destructor
template <typename NodeType>
SimpleStack<NodeType>::~SimpleStack() {
    cout << "SimpleStack's destructor was called" << endl;
    removeAll();
}

/**
 * Returns the size of the stack.
 */
template <typename NodeType>
int SimpleStack<NodeType>::getSize() const {
    return size;
}

/**
 * Returns true if the stack is empty.
 */
template <typename NodeType>
bool SimpleStack<NodeType>::isEmpty() {
    return top == NULL;
}

template <typename NodeType>
NodeType* SimpleStack<NodeType>::peek() {
    return top;
}

/**
 * Removes and returns a node from the top of the stack a la Java's ArrayList.
 * In C++, usually it is not preferred because the popped element will stay in memeory.
 * The section of code that creates an object in memory should take care of
 * deleting it as well.
 */
template <typename NodeType>
NodeType* SimpleStack<NodeType>::pop() {

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
void SimpleStack<NodeType>::push(string title, string genre, int minAge) {

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
void SimpleStack<NodeType>::removeAll() {
    cout << "SimpleStack's removeAll() was called" << endl;
    while (!isEmpty()) {
        removeFirst();
    }
}

/**
 * Delete the top node from memory.
 * Alternative to pop()
 */
template <typename NodeType>
void SimpleStack<NodeType>::removeFirst() {
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
void SimpleStack<NodeType>::showAll() {

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
bool compareByTitle(VGameNode* g1, VGameNode* g2, bool isAscend) {

    // No need to sort
    if (g1 == NULL || g2 == NULL) {
        return true;
    }

    bool answer = g1->getTitle() < g2->getTitle();

    if (!isAscend) {
        answer = !answer;
    }

    cout << "Compared" << endl;
    return answer;
}

/**
 * Insertion sort
 */
 void sortLinkedList( bool ( *vGameComparator )(VGameNode*, VGameNode*, bool),
                      VGameNode* listhead,
                      int len ) {
    /*
    Any sorting algorithm can be implemented here.
    Use the function pointer vGameComparator to determine which of any two
    VGameNode's come before the other.
    This info will enable the sort algorithm to operate as needed.
    */

    // 0 node
    if (listhead == NULL) {
        cout << "The list is empty" << endl;
        return;
    }

    // 1 node
    if (listhead->next == NULL) {
        cout << "The list has only one node" << endl;
        return;
    }

    // 2 or more nodes
    // Inspect the unsorted portion one by one.
    VGameNode* firstUnsorted = listhead->next;
    VGameNode* resultHead    = listhead;
    resultHead->next         = NULL;

    // Special case: firstUnsorted to be added as first node
    if( resultHead == NULL || vGameComparator(firstUnsorted, resultHead, true) ) {
        firstUnsorted->next = resultHead;
        resultHead          = firstUnsorted;

        return;
    }

    // Insert each node into the resultHead list
    while (firstUnsorted != NULL) {


        // Otherwise: Insert firstUnsorted into an appropriate position in the result list.
        VGameNode* curr = resultHead;
        VGameNode* prev = NULL;

        // Finding the position
        while ( curr != NULL && vGameComparator(curr, firstUnsorted, true) ) {
            prev = curr;
            curr = curr->next;
        }

        // Inserting firstUnsorted into the result list
        firstUnsorted->next = curr;
        prev->next          = firstUnsorted;

        cout << "Inserted" << endl;

        firstUnsorted = firstUnsorted->next;
    }

    cout << "sorting done" << endl;
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

    SimpleStack<VGameNode> gameStack;

    // 2. Push elements to the stack.

    gameStack.push("Foo", "Action", 10);
    gameStack.push("Pqr", "Shooter", 10);
    gameStack.push("Bar", "Roll-playing", 10);
    gameStack.push("Mno", "Adventure", 10);
    gameStack.push("Abc", "Simulation", 10);
    gameStack.push("Xyz", "Strategy", 10);
    gameStack.showAll();

    drawLine();

    // 3. Sorting

    sortLinkedList( &compareByTitle, gameStack.peek(), gameStack.getSize() );
    gameStack.showAll();

    drawLine();

    // 6. Remove all the rest

    gameStack.removeAll();
    gameStack.showAll();

    drawLine();

    return 0;
}
