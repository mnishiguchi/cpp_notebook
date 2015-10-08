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
    int maxArraySize;
    int size;

    // Functions
    VGameNode* getTop();
    bool isQueueFull();
    void removeFirst();
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
    maxArraySize = 5;
    size = 0;

    // Create a dynamic array of pointers of VGameNode type.
    games = new VGameNode[maxArraySize];
}

/**
 * destructor
 */
VGameQueue::~VGameQueue() {

    cout << "\ndeleting the internal dynamic array..." << endl;

    // Delete the dynamic array that was created in constructor
    delete[] games;
}

bool VGameQueue::isQueueFull() {
    return maxArraySize == size;
}

/**
 * Removes a node from the top of the queue.
 * Caller of this functions must take care of deleting the popped object.
 */
void VGameQueue::removeFirst() {

    // Case1: empty array

    // Do nothing and return if the queue is empty
    if (size == 0) {
        cout << "The queue is empty." << endl;
        return;
    }

    // Case2: non-empty array


    if (headIndex < maxArraySize - 1) {
        headIndex++;    // Increment the head index
    } else {
        headIndex = 0;  // Move the head index to index 0
    }

    size--;
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
    for (int i = 0; i < maxArraySize; i++) {
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
 * Returns a head node if any.
 */
VGameNode* VGameQueue::getTop() {
    if (size < 1) {
        return NULL;
    }

    return &games[headIndex];
}

/**
 * Add a node at the back of the queue.
 */
void VGameQueue::pushBack(string title, string genre, int minAge) {

    cout << endl;
    cout << "pushBack" << endl;

    // Case1: Empty list
    if (headIndex < 0) {
        headIndex = 0;
        tailIndex = 0;

    // Case2: Non-empty list
    } else {

        if (isQueueFull()) {
            cout << "No more room!" << endl;
            return;
        }

        // Ensure that the queue is not full
        if (tailIndex < maxArraySize - 1) {
            tailIndex++;  // Go to the next element
        } else {
            // Move the tail index back to 0
            tailIndex = 0;
        }
    }

    // Fill data in the node at this index
    games[tailIndex].title  = title;
    games[tailIndex].genre  = genre;
    games[tailIndex].minAge = minAge;

    size++;

    cout << "size updated to" << size << endl;
    cout << "tailIndex updated to " << tailIndex << endl;
}


int main() {

    // Create a queue
    VGameQueue* gamesQueue = new VGameQueue();

    // Add nodes to the queue
    gamesQueue->pushBack("Street Fighter II", "Action", 10);
    gamesQueue->printAll();

    gamesQueue->pushBack("Space Invaders", "Shooter", 10);
    gamesQueue->printAll();

    gamesQueue->pushBack("Final Fantasy IV", "Roll-playing", 10);
    gamesQueue->printAll();

    gamesQueue->pushBack("Mystery House", "Adventure", 10);
    gamesQueue->printAll();

    gamesQueue->pushBack("SimCity", "Simulation", 10);
    gamesQueue->printAll();

    gamesQueue->pushBack("Civilization", "Strategy", 10);
    gamesQueue->printAll();

    // Check the first node

    VGameNode* aGame;
    aGame = gamesQueue->getTop();
    cout << "First game: " << aGame->title << endl;

    // Pop the first

    gamesQueue->removeFirst();

    // Check the first node

    aGame = gamesQueue->getTop();
    cout << "First game: " << aGame->title << endl;

    // Pop the first

    gamesQueue->removeFirst();
    gamesQueue->removeFirst();
    gamesQueue->removeFirst();
    gamesQueue->removeFirst();

    // Check the first node

    aGame = gamesQueue->getTop();
    cout << "First game: " << aGame->title << endl;

    // Delete the queue
    delete gamesQueue;

    return 0;
}
