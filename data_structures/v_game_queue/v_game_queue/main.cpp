//
//  main.cpp
//  v_game_queue
//
//  Implementation of a queue using an array of pointers as a data structure
//
//  Created by Masatoshi Nishiguchi on 10/5/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

/*
 Queueing analysis is used for
 - Air port traffic control
 - Restaurant
 */

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
 * Class that represents a queue in a fixed size array of pointers
 */
class VGameQueue {
public:
    // Array of nodes
    VGameNode* games;

    // Instance variables
    int headIndex;
    int tailIndex;
    int arraySize;

    // Functions
    VGameNode* popFirst();
    void printAll();
    void pushBack(string title, string genre, int minAge);

    // Constructor
    VGameQueue();

    // Destructor
    ~VGameQueue();
};

/**
 * constructor
 */
VGameQueue::VGameQueue() {
    headIndex = -1;
    tailIndex = -1;
    arraySize = 5;

    // Create a dynamic array of pointers of VGameNode type.
    games = new VGameNode[arraySize];
}

/**
 * destructor
 */
VGameQueue::~VGameQueue() {

    cout << "\ndeleting the internal dynamic array..." << endl;

    // Delete the dynamic array that was created in constructor
    delete[] games;
}

/**
 * Removes and returns a node from the top of the queue.
 * Caller of this functions must take care of deleting the popped object.
 */
VGameNode* VGameQueue::popFirst() {

    // Case1: empty array

    // Return if the queue is empty
    if (tailIndex < 0) {
        cout << "The queue is empty." << endl;
        return NULL;
    }

    // Case2: non-empty array

    // Copy the head element
    VGameNode* temp = new VGameNode(games[0].title, games[0].genre, games[0].minAge);

    // Shift the array elements by one index
    for (int i = 1; i < arraySize; i++) {
        games[i - 1].title = games[i].title;
        games[i - 1].genre = games[i].genre;
        games[i - 1].minAge = games[i].minAge;
    }

    // Update head and tail
    headIndex = 0;
    tailIndex -= 1;

    return temp;
}

void VGameQueue::printAll() {
    // Return if the queue is empty
    if (tailIndex < 0) {
        cout << "The queue is empty." << endl;
        cout << "head: " << headIndex << endl;
        cout << "tail: " << tailIndex << endl;
        return;
    }

    // Print the head and tail.
    cout << "head: " << headIndex << endl;
    cout << "tail: " << tailIndex << endl;
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
    for (int i = 0; i < arraySize; i++) {
        if (games[i].title == "") {
            return;
        }

        // Print current node
        cout << left;
        cout << setw(24) << games[i].title;
        cout << setw(16) << games[i].genre;
        cout << setw(8) << games[i].minAge;
        cout << endl;
    }
    cout << "--- tail of the queue---" << endl;
}

/**
 * Add a node at the back of the queue.
 */
void VGameQueue::pushBack(string title, string genre, int minAge) {

    cout << endl;
    cout << "pushBack" << endl;

    // Case1: Empty list
    if (tailIndex < 0) {
        headIndex = 0;
        tailIndex = 0;

    // Case2: Non-empty list
    } else {
        // Ensure that the queue is not full
        if (tailIndex < arraySize - 1) {
            tailIndex++;  // Go to the next element
        } else {
            cout << "No more room!" << endl;
            return;
        }
    }

    // Fill data in the node at this index
    games[tailIndex].title  = title;
    games[tailIndex].genre  = genre;
    games[tailIndex].minAge = minAge;

    cout << "tailIndex updated to " << tailIndex << endl;
}


int main() {

    // Create a queue
    VGameQueue* waitingLine = new VGameQueue();

    // Add nodes to the queue
    waitingLine->pushBack("Street Fighter II", "Action", 10);
    waitingLine->printAll();

    waitingLine->pushBack("Space Invaders", "Shooter", 10);
    waitingLine->printAll();

    waitingLine->pushBack("Final Fantasy IV", "Roll-playing", 10);
    waitingLine->printAll();

    waitingLine->pushBack("Mystery House", "Adventure", 10);
    waitingLine->printAll();

    waitingLine->pushBack("SimCity", "Simulation", 10);
    waitingLine->printAll();

    waitingLine->pushBack("Civilization", "Strategy", 10);
    waitingLine->printAll();

    // Pop first


    // Delete the queue
    delete waitingLine;

    return 0;
}
