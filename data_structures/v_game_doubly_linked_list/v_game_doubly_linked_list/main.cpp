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
    title  = t;
    genre  = g;
    minAge = a;
}

/**
 * Class that represents a linked list
 */
class VGameList {
    public:
        // Addresses of the beginning and end of the list
        VGameNode* head;  // First element
        VGameNode* tail;  // Last element

        // Function prototypes
        void addLast(string title, string genre, int minAge);
        void insertByTitle(string title, string genre, int minAge);
        void removeByTitle(string titleToDelete);
        void showAll();
        void debugPrint();

        // Constructor
        VGameList();
};

// Default constructor
VGameList::VGameList() {
    head = NULL;
}

/**
 * Append a new node to the end of the list.
 * This is for creating an unordered list.
 */
void VGameList::addLast(string title, string genre, int minAge) {

    // Create a new node base on the specified data.
    VGameNode* newNode = new VGameNode(title, genre, minAge);

    // Case1: Empty list
    if (head == NULL) {
        head = newNode;  // The new node becomes the head.
        tail = newNode;  // The new node is also tail.

    // Case2: Non-empty list
    } else {
        // Set the new node at the end of the list.
        tail->next    = newNode;  // Connect the last element to the new node.
        newNode->prev = tail;     // Set new node's prev pointer.

        // Update the tail pointer.
        tail = newNode;

        // Note: head need not be updated since newNode was added to the ent of the list.
    }
}

/**
 * Insert a node by title in ascending order.
 * This is for creating an ordered list.
 * The list must be sorted by title in ascending order in the first place.
 */
void VGameList::insertByTitle(string title, string genre, int minAge) {

    // Local variables to remember which node we are currently working on.
    VGameNode* curr;       // Pointer to traverse the list.
    VGameNode* trailCurr;  // Pointer to remember the one before.

    // Create a new node base on the specified data.
    VGameNode *newNode = new VGameNode();
    newNode->genre  = genre;
    newNode->minAge = minAge;
    newNode->title  = title;

    bool found = false;

    // Case1: If the list is empty, just make it be the head of the list.
    if(head == NULL) {
        head = newNode;  // The new node becomes the head.
        tail = newNode;  // The new node is also tail.
        return;
    }

    // Case2: If the head node is greater than the new node, insert before the head node.
    if (newNode->title < head->title) {

        // Connect newNode to current head.
        newNode->next = head;     // Set newNode's next pointer.
        head->prev    = newNode;  // Set current head node's prev pointer.

        // Update the head pointer.
        head = newNode;  // Now newNode is the head

        // Note: tail need not be updated since newNode was added before the old head.

    // Otherwise, traverse the list in search for the node before where we have to insert.
    } else {
        found = false;

        // Initialize trailCurr and curr.
        trailCurr = head;        // Set trailCurrent to point to the first node.
        curr      = head->next;  // Set current to point to the second node.

        // Traverse the list.
        while (curr != NULL && !found) {

            // Look for the appropriate location for insertion.
            if (curr->title < newNode->title) {
                trailCurr = curr;
                curr      = curr->next;
            } else {
                found = true;  // Then exit the loop.
            }
        }

        // Note: Now we are at the point where we do the insertion.

        // Insert the new node before the node that curr is pointng to,
        // connecting trailCurr, newNode and curr, which involves max 4 pointers.
        trailCurr->next = newNode;
        newNode->prev   = trailCurr;
        newNode->next   = curr;

        // Unless curr is pointing to NULL, set curr's prev to newNode's address.
        if (curr != NULL) {
            curr->prev = newNode;
        }
    }
}

/**
 * Remove a node with the specified title if any.
 */
void VGameList::removeByTitle(string titleToDelete) {

    // Local variables to remember which node we are currently working on.
    VGameNode* curr;       // Pointer to traverse the list.
    VGameNode* trailCurr;  // Pointer to remember the one before.

    bool found = false;

    // Case1: If the list is empty, there are nothing to delete.
    if (head == NULL) {
        cout << "Cannot delele from an empty list" << endl;
        return;
    }

    // Case2: If the head node is the one we are looking for.
    if (head->title == titleToDelete) {
        // Initialize trailCurr and curr.
        curr      = head;  // Current node is head.
        trailCurr = NULL;

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
        found = false;

        // Initialize trailCurr and curr.
        trailCurr = head;        // Set trailCurrent to point to the first node.
        curr      = head->next;  // Set current to point to the second node.

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
            trailCurr       = curr->prev;
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

    // Return if the list is empty
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    // Print the attributes names.
    cout << left;
    cout << setw(24) << "TITLE";
    cout << setw(16) << "GENRE";
    cout << setw(8) << "MIN AGE";
    cout << endl;

    // Draw a horizonal rule.
    cout << setfill('-') << setw(48) << "" << setfill(' ') << endl;

    // Traverse the list.
    VGameNode* curr = head;
    while (curr != NULL) {
        cout << left;

        // Print current node
        cout << setw(24) << curr->title;
        cout << setw(16) << curr->genre;
        cout << setw(8) << curr->minAge;
        cout << endl;

        // Move the cursor to next
        curr = curr->next;
    }
}
/**
 * Prints each node with its previous and next nodes for debugging purposes.
 */
void VGameList::debugPrint() {

    // Return if the list is empty
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    // Traverse the list.
    VGameNode* curr = head;
    while (curr != NULL) {
        cout << left;

        // Print current node
        cout << setw(24) << curr->title;

        // Print previous node
        if (curr->prev != NULL) {
            cout << setw(6) << "prev:"
                 << setw(24) << curr->prev->title;
        } else {
            cout << setw(30) << "prev:";
        }

        // Print next node
        if (curr->next != NULL) {
            cout << setw(6) << "next:"
                 << setw(24) << curr->next->title;
        } else {
            cout << setw(30) << "next:";
        }

        cout << endl;

        // Move the cursor to next
        curr = curr->next;
    }
}

/**
 * Utility function to draw a horizontal seperator.
 */
void drawLine() {
    cout << endl;
    cout << setfill('~') << setw(80) << "" << setfill(' ') << endl;
    cout << endl;
}

/**
 * Main function for the program.
 */
int main() {

    // 1. Create an empty list.

    VGameList myGames;

    // 2. Add elements to the list.

    myGames.addLast("Street Fighter II", "Action", 10);
    myGames.addLast("Space Invaders", "Shooter", 10);
    myGames.addLast("Final Fantasy IV", "Roll-playing", 10);
    myGames.addLast("Mystery House", "Adventure", 10);
    myGames.addLast("SimCity", "Simulation", 10);
    myGames.addLast("Civilization", "Strategy", 10);
    myGames.showAll();

    // 3. Remove the elements by title, one at a time, until the list is empty.

    drawLine();

    myGames.removeByTitle("Final Fantasy IV");
    myGames.showAll();

    drawLine();

    myGames.removeByTitle("SimCity");
    myGames.showAll();

    drawLine();

    myGames.removeByTitle("Space Invaders");
    myGames.showAll();

    drawLine();

    myGames.removeByTitle("Street Fighter II");
    myGames.showAll();

    drawLine();

    myGames.removeByTitle("Civilization");
    myGames.showAll();

    drawLine();

    myGames.removeByTitle("Mystery House");
    myGames.showAll();

    drawLine();

    return 0;
}
