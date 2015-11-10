/**
 *  ice_cream_tree.cpp
 *
 *  This program demonstrates a binary search tree of generic NodeType.
 *
 *  Created by Masatoshi Nishiguchi on 10/28/15.
 *  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
 */

/* Actual output

===>Creating a new tree...

BSTree created

===>Inserting nodes into the tree...

Inserting masatoshi    as a root
Inserting unagi        as masatoshi's right child
Inserting vanilla      as unagi's right child
Inserting chocolate    as masatoshi's left child
Inserting soba         as unagi's left child
Inserting udon         as soba's right child
Inserting peanut       as soba's left child
[Error: Dupulicateds are not allowed: chocolate]
Inserting sushi        as udon's left child
Inserting donburi      as chocolate's right child

===>Searching the specified nodes in the tree...

Searching for masa............Not found :(
Searching for masatoshi.......Found :)
Searching for chocolate.......Found :)

===>Printing the items that were found above...

masatoshi
chocolate

===>Removing those nodes from the tree...

Removing masatoshi.......Removed!
Removing chocolate.......Removed!

===>End of the program...

BSTree destructed
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/**
 * Class that represents a node
 */
class IceCreamNode {
public:
    IceCreamNode();
    IceCreamNode(string);

    string getInfo() const { return title; }
    void setInfo(string title) { this->title = title; }

    IceCreamNode* left;
    IceCreamNode* right;

private:
    string title;
};

/**
 * Default constructor of IceCreamNode
 */
IceCreamNode::IceCreamNode() {
    left  = NULL;
    right = NULL;
    this->title = "";
}

/**
 * Constructs an IceCreamNode with its title
 */
IceCreamNode::IceCreamNode(string title) {
    left  = NULL;
    right = NULL;
    this->title = title;
}

/**
 * Represents a binary search tree that accept generic NodeType that meets the
 * following requirements:
 *
 * ---Requirements---
 * - NodeType must have as members:
 *   + left and right - pointers
 *   + name/title     - a string that can be accessed by getInfo() and setInfo(string)
 * - NodeType must override comparison operators in a way that they can be compared by name string
 */
template <class NodeType>
class BSTree {
public:
    BSTree();
    ~BSTree();

    void insert(string insertItemName);
    void removeFromTree(NodeType*);
    NodeType* search(string searchKey) const;

    NodeType* root;
};

/**
 * Default constructor
 */
template <class NodeType>
BSTree<NodeType>::BSTree() {
    root = NULL;
    cout << "BSTree created" << endl;
}

/**
 * Default destructor
 */
template <class NodeType>
BSTree<NodeType>::~BSTree() {
    cout << "BSTree destructed" << endl;
};

/**
 * Create a new node with the specified name and insert it into the tree.
 */
template <class NodeType>
void BSTree<NodeType>::insert(string insertItemName) {
    NodeType* current;
    NodeType* trailCurrent;
    NodeType* newNode;

    // Create a new node with the specific name
    newNode = new NodeType();
    newNode->setInfo(insertItemName);

    // If there is no root, this becomes the root.
   if (root == NULL) {
       root = newNode;
        cout << "Inserting " << left << setw(12) << insertItemName << " as a root" << endl;

   } else {
       current      = root;
       trailCurrent = NULL;

       while (current != NULL) {
            trailCurrent = current;

            // Every node should be unique.
            if (current->getInfo() == insertItemName) {
                cout << "[Error: Dupulicateds are not allowed: " << insertItemName << "]" << endl;
                return;

                // Left child
           } else if (current->getInfo() > insertItemName) {
                current = current->left;

                // Right child
           } else {
                current = current->right;
           }
       } // end while

       if (trailCurrent->getInfo() > insertItemName) {
            trailCurrent->left = newNode;
            cout << "Inserting " << setw(12) << insertItemName << " as "
                 << trailCurrent->getInfo() << "'s left child" << endl;

       } else  {
            trailCurrent->right = newNode;
            cout << "Inserting " << setw(12) << insertItemName << " as "
                 << trailCurrent->getInfo() << "'s right child" << endl;
       }
   } // end insert
}

/**
 * Removes a node from the tree.
 * The node to remove can be searched for ahead of time using the search function.
 */
template <class NodeType>
void BSTree<NodeType>::removeFromTree(NodeType* itemToRemove) {

    NodeType* current;
    NodeType* trailCurrent;
    NodeType* temp;

    // Reject if the item to remove is empty
    if (itemToRemove == NULL) {
        cout << "[Error: The node to be deleted is NULL]" << endl;
        return;
    }

    // There are four different cases...
    cout << "Removing " << left << setfill('.')
         << setw(16) << itemToRemove->getInfo()
         << right << setfill(' ');

    // Case 1 - has no child
    if (itemToRemove->left == NULL && itemToRemove->right == NULL) {
        temp         = itemToRemove;
        itemToRemove = NULL;
        delete temp;

    // Case 2 - only has a right child
    } else if (itemToRemove->left == NULL) {
        temp         = itemToRemove;
        itemToRemove = temp->right;
        delete temp;

    // Case 3 - only has a left child
    } else if (itemToRemove->right == NULL) {
        temp         = itemToRemove;
        itemToRemove = temp->left;
        delete temp;

    // Case 4 - has both left and right subtrees
    } else {
        current      = itemToRemove->left;
        trailCurrent = NULL;

        // Go to the right all the way down to the rightmost grandchild
        while (current->right != NULL) {
            trailCurrent = current;
            current      = current->right;
        }

        // Replace the itemToRemove with the rightmost grandchild
        itemToRemove->setInfo( current->getInfo() );

        if (trailCurrent == NULL) {
            itemToRemove->left = current->left;
        } else {
            trailCurrent->right = current->left;
        }

        // Finally delete the node
        delete current;
    }

    cout << "Removed!" << endl;
}

/**
 * Searches a node with the specified search key in the tree.
 * If found, returns a pointer to the node; else NULL.
 */
template <class NodeType>
NodeType* BSTree<NodeType>::search(string searchKey) const {
    NodeType* current;
    bool found = false;

    // Reject if the tree is empty
    if (root == NULL) {
        cout << "Cannot search an empty tree" << endl;
        return NULL;
    }

    cout << "Searching for " << left << setfill('.')
         << setw(16) << searchKey
         << right << setfill(' ');

    // Traverse down the tree from the root node
    current = root;
    while (current != NULL && !found) {

        if (current->getInfo() == searchKey) {
            found = true;

        } else if (current->getInfo() > searchKey) {
            current = current->left;

        } else {
            current = current->right;
        }
    }  // end while

    // Report the result
    cout << ( (found) ? "Found :)" : "Not found :(" ) << endl;

    // Return the pointer to the node
    return current;
} // end search

//*************************************

/**
 * Utility function to print the node the specified pointer points to.
 */
void printIceCream(IceCreamNode* node) {
    cout << ((node) ? node->getInfo() : "[Error: This object is NULL]") << endl;
}

/**
 * Utility function to print the node the specified pointer points to.
 */
void printIceCreamList(IceCreamNode* list[]) {
    for (int i = 0; i < 10; i++) {
        if (list[i] != NULL) {
            printIceCream(list[i]);
        }
    }
}

//*************************************

int main() {

    cout << "\n===>Creating a new tree...\n" << endl;

    BSTree<IceCreamNode> parlor;
    IceCreamNode* tempList[10] = {};  // Initially all elems are NULL

    cout << "\n===>Inserting nodes into the tree...\n" << endl;

    parlor.insert("masatoshi");
    parlor.insert("unagi");
    parlor.insert("vanilla");
    parlor.insert("chocolate");
    parlor.insert("soba");
    parlor.insert("udon");
    parlor.insert("peanut");
    parlor.insert("chocolate");
    parlor.insert("sushi");
    parlor.insert("donburi");

    cout << "\n===>Searching the specified nodes in the tree...\n" << endl;

    tempList[0] = parlor.search("masa");
    tempList[1] = parlor.search("masatoshi");
    tempList[2] = parlor.search("chocolate");

    cout << "\n===>Printing the items that were found above...\n" << endl;
    printIceCreamList(tempList);

    cout << "\n===>Removing those nodes from the tree...\n" << endl;

    for (int i = 0; i < 10; i++) {
        if (tempList[i] != NULL) {
            parlor.removeFromTree(tempList[i]);
        }
    }

    cout << "\n===>End of the program...\n" << endl;
    return 0;
}
