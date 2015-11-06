/**
 *  ice_cream_tree.cpp
 *
 *  Created by Masatoshi Nishiguchi on 10/28/15.
 *  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
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

    // bool operator==(IceCreamNode& rhs) const { return this->title == rhs.title; };
    // bool operator<(IceCreamNode& rhs)  const { return this->title <  rhs.title; };
    // bool operator>(IceCreamNode& rhs)  const { return this->title >  rhs.title; };
    // bool operator<=(IceCreamNode& rhs) const { return this->title <= rhs.title; };
    // bool operator>=(IceCreamNode& rhs) const { return this->title >= rhs.title; };

private:
    string title;
};

/**
 * Default constructor of IceCreamNode
 */
IceCreamNode::IceCreamNode() {
    left  = NULL;
    right = NULL;
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

    void insert(string insertItemName);
    void removeFromTree(NodeType*);  // TODO: remove node (See textbook 6th ed p1331)
    NodeType* search(NodeType*);     // TODO: search node (See textbook 6th ed p1328)
    void destroyTree();              // TODO

private:
    NodeType* root;
};

/**
 * Default constructor
 */
template <class NodeType>
BSTree<NodeType>::BSTree() {
    root = NULL;
}

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
                cout << "[Dupulicateds are not allowed: " << insertItemName << "]" << endl;
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

/** TODO: search node (See textbook 6th ed p1328)
 *  Search a node into the tree
 */
//template <class NodeType>
//NodeType* BSTree<NodeType>::search(string searchKey) {
//    return new NodeType*;
//}


//template <class NodeType>
//void BSTree<NodeType>::removeFromTree(NodeType* itemToRemove) {

    // NodeType* current;
    // NodeType* trailCurrent;
    // NodeType* temp;

    // if (itemToRemove == NULL) {
    //     cout << "Error: The node to be deleted is NULL" << endl;

    // } else if (itemToRemove->left == NULL && itemToRemove->right == NULL) {
    //     temp         = itemToRemove;
    //     itemToRemove = NULL;
    //     delete temp;

    // } else if (itemToRemove->left == NULL) { // If only has a right child
    //     temp         = itemToRemove;
    //     itemToRemove = temp->right;
    //     delete temp;

    // } else if (itemToRemove->right == NULL) { // If only has a left child
    //     temp         = itemToRemove;
    //     itemToRemove = temp->left;
    //     delete temp;

    // } else {  // Node has both left and right subtrees
    //     current      = itemToRemove->left;
    //     trailCurrent = NULL;

    //     // Go to the right all the way down to the rightmost grandchild
    //     while (current->right != NULL) {
    //         trailCurrent = current;
    //         current      = current->right;
    //     }

    //     // Replaca the itemToRemove with the rightmost grandchild
    //     itemToRemove->setInfo( current->getInfo() );

    //     if (trailCurrent == NULL) {
    //         trailCurrent->left = current->left;
    //     } else {
    //         trailCurrent->right = current->left;
    //     }

    //     // Finally delete the node
    //     delete current;
    // }
//}

//*************************************

int main() {

    BSTree<IceCreamNode> parlor;

    parlor.insert("vanilla");
    parlor.insert("chocolate");
    parlor.insert("masa");
    parlor.insert("toshi");
    parlor.insert("chocolate");
    parlor.insert("abcde");

    // 1 search
    // 2 remove that node

    return 0;
}
