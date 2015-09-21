//
//  main.cpp
//  v_game_doubly_linked_list
//
//  Created by Masatoshi Nishiguchi on 9/20/15.
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
 */
void VGameList::removeByTitle(string titleToDelete) {

    /* Key points
     * - Assign the previous pointer and the tail pointer correctly.
     */

    VGameNode* curr;      // Pointer to traverse the list
    VGameNode* trailCurr; // Pointer to remember the previous node

    bool found = false;

    // Case1: If the list is empty, there are nothing to delete.
    if (head == NULL) {
        cout << "Cannot delele from an empty list" << endl;
        return;
    }

    // Case2: If the head node is the one we are looking for.
    if (head->title == titleToDelete) {
        // Current node is head.
        curr = head;

        // The next node becomes the head.
        head = head->next;

        // Update prev pointer.
        if (head != NULL) {
            head->prev = NULL;
        }

        // Note: Next pointer need not be updated.

        // Delete the node that was previously the head.
        delete curr;

    // Otherwise, traverse the list and examine each node.
    } else {
        // Initialize trailCurr and curr.
        trailCurr = head;
        curr      = head->next;

        // Traverse the list until the item is found or the end is reached.
        while (curr != NULL && !found) {

            // Equality checking
            if (curr->title == titleToDelete) {
                found = true;  // Then exit the loop.
            } else {
                // Update trailCurr and curr.
                trailCurr = curr;
                curr      = curr->next;
            }
        }

        // Case3: The item was found
        if (found) {
            // Update the next pointer of the node before the one to be deleted.
            trailCurr->next = curr->next;

            // Note: Now curr is the item to be deleted.

            // Set up the previous node's next pointer.
            trailCurr = curr->prev;
            trailCurr->next = curr->next;

            // Case3-1: The item is in the middle of the list.
            // Set up the next node's previous pointer.
            if (curr->next != NULL) {
                curr->next->prev = trailCurr;
            }

            /// Case3-2: The item is at the end of the list.
            if (curr == tail) {
                tail = trailCurr;
            }

            // Delete the node from memory.
            delete curr;

        // Case4: The item was not found in the list.
        } else {
            cout << "The item to be deleted is not in the list" << endl;
        }
    }
}

/**
 * Prints info of all the elements in the list.
 */
void VGameList::showAll() {

    // Empty list
    if (head == NULL) {
        cout << "The list is empty." << endl;
    }

    // Traverse the list.
    VGameNode* curr = head;
    while (curr != NULL) {
        cout << left;

        // Print one element at a time
        cout << setw(16) << curr->title;

        // For debugging
        if (curr->prev != NULL) {
            cout << setw(6) << "prev:"
                 << setw(14) << curr->prev->title;
        } else {
            cout << setw(20) << "prev:";
        }

        if (curr->next != NULL) {
            cout << setw(6) << "next:"
                 << setw(14) << curr->next->title;
        } else {
            cout << setw(20) << "next:";
        }

        cout << endl;

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

    cout << "------------------------------------------" << endl;
    myGames.removeByTitle("Some title12");
    myGames.showAll();

    cout << "------------------------------------------" << endl;
    myGames.removeByTitle("Some title45");
    myGames.showAll();

    cout << "------------------------------------------" << endl;
    myGames.removeByTitle("Some title67");
    myGames.showAll();

    cout << "------------------------------------------" << endl;
    myGames.removeByTitle("Some title23");
    myGames.showAll();

    cout << "------------------------------------------" << endl;
    myGames.removeByTitle("Some title56");
    myGames.showAll();

    cout << "------------------------------------------" << endl;
    myGames.removeByTitle("Some title34");
    myGames.showAll();

    return 0;
}
