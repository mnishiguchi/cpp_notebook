//
//  main.cpp
//  v_game_doubly_linked_list
//
//  Created by Masatoshi Nishiguchi on 9/20/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 * Class that represents a node
 */
class VGameNode {
    public:

        // Fields
        string title;
        string genre;
        int minAge;

        // Pointers for the links
        VGameNode* next;
        VGameNode* prev;

        // Constructors
        VGameNode();
        VGameNode(string title, string genre, int minAge);
};

// Default constructor
VGameNode::VGameNode() {
    next = NULL;
}

// Constructor to create a node with a specific set of data
VGameNode::VGameNode(string t, string g, int a) {
    next = NULL;
    title = t;
    genre = g;
    minAge = a;
}

/**
 * Class that represents a linked list
 */
class VGameList {
    public:
        // Addresses of the beginning and end of the list
        VGameNode* head;
        VGameNode* tail;

        // Function prototypes
        void addLast(string title, string genre, int minAge);
        void removeByTitle(string titleToDelete);
        void showAll();
    
        // Constructor
        VGameList();
};

// Default constructor
VGameList::VGameList() {
    head = NULL;
}

/**
 * Append a new node to the end of the list.
 * If the list is empty, the new node will become the head node.
 */
void VGameList::addLast(string title, string genre, int minAge) {
    
    /* Key points
     * - Assign the previous pointer and the tail pointer correctly.
     * - Use the tail pointer as a quick way to append to the linked list.
     */
    
    // Create a new node base on the specified data
    VGameNode* newNode = new VGameNode(title, genre, minAge);

    // Case1: Empty list
    if (head == NULL) {
        // The new node becomes the head.
        head = newNode;
        tail = newNode;

    // Case2: Non-empty list
    } else {
        // Set the new node at the end of the list.
        tail->next    = newNode;  // Connect the last element to the new node
        newNode->prev = tail;     // Set new node's prev pointer
        
        // Update the tail pointer.
        tail = newNode;
    }
}

/**
 * Remove a node with the specified title if any.
 * TODO: assign the previous pointer and the tail pointer correctly
 */
void VGameList::removeByTitle(string titleToDelete) {

    VGameNode* curr;      // Pointer to traverse the list
    VGameNode* trailCurr; // Pointer to remember the previous node

    bool found;

    if (head == NULL) {
        cout << "Cannot delele from an empty list" << endl;

    } else {

        if (head->title == titleToDelete) {
            curr = head;
            head = head->next;
            delete curr;

        } else {
            found = false;

            trailCurr = head;
            curr      = head->next;

            while (curr != NULL && !found) {
                // Found????
                if (curr->title != titleToDelete) {
                    trailCurr = curr;
                    curr      = curr->next;

                } else {
                    found = true;
                }
            }

            if (found) {
                // Update the next pointer of the node before the one to be deleted
                trailCurr->next = curr->next;

                // Delete the node
                delete curr;

            // The whole list was exhausted
            } else {
                cout << "The item to be deleted is not in the list" << endl;
            }
        }
    }
}

/**
 * Prints info of all the elements in the list.
 */
void VGameList::showAll() {

    // The cursor
    VGameNode* curr = head;

    while (curr != NULL) {
        // Print one element at a time
        cout << "Game: " << curr->title << endl;

        // Move the cursor to next
        curr = curr->next;
    }
}

/**
 * Main function for the program.
 */
int main() {

    // Create an empty list.
    VGameList myGames;

    // Add elements
    myGames.addLast("Some title12", "Some genre", 10);
    myGames.addLast("Some title23", "Some genre", 10);
    myGames.addLast("Some title34", "Some genre", 10);
    myGames.addLast("Some title45", "Some genre", 10);
    myGames.addLast("Some title56", "Some genre", 10);
    myGames.addLast("Some title67", "Some genre", 10);

    myGames.showAll();

//    cout << "------------------------------------------" << endl;
//
//    myGames.removeByTitle("Some title45");
//    myGames.removeByTitle("Some title67");
//
//    myGames.showAll();

    return 0;
}
