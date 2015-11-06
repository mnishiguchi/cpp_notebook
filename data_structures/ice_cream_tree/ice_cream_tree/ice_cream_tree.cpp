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


/*
 TODO: Overload comparison operators in order to make flavor the search key
 */

/**
 * Class that represents a node
 */
class IceCreamNode {
public:
    IceCreamNode();
    IceCreamNode(string);
    string getInfo() const { return flavor; }
    void setInfo(string name) { flavor = name; }
    IceCreamNode* left;
    IceCreamNode* right;
private:
    string flavor;
};

/**
 * default constructor
 */
IceCreamNode::IceCreamNode() {
    left  = NULL;
    right = NULL;
}

/**
 * Constructor with its flavor
 */
IceCreamNode::IceCreamNode(string flavor) {
    left  = NULL;
    right = NULL;
    this->flavor = flavor;
}

//*************************************

/**
 * Reequirements: Nodes (data NodeType) must have left and right pointers
 * as their members
 */
template <class NodeType>
class BSTree {
public:
    BSTree();




    void insert(string insertItemName);
    void removeFromTree(NodeType*);  // TODO: remove node (See textbook 6th ed p1331)
    NodeType* search(NodeType*);     // TODO: search node (See textbook 6th ed p1328)
    void destroyTree();              // TODO

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
    newNode = new NodeType(insertItemName);

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
               cout << "The newNode to be inserted is already in the tree" << endl
                    << "Dupulicateds are not allowed" << endl;
                return;

                // Left child
           } else if (current->getInfo() > insertItemName) {
                current = current->left;

                // Right child
           } else {
                current = current->left;
           }
       } // end while

       if (trailCurrent->getInfo() > insertItemName) {
            trailCurrent->left = newNode;
            cout << "Inserting " << left << setw(12) << insertItemName << " as "
                 << trailCurrent->getInfo() << "'s left child" << endl;

       } else  {
            trailCurrent->right = newNode;
            cout << "Inserting " << left << setw(12) << insertItemName << " as "
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

    parlor.insert("masa");
    parlor.insert("toshi");
    parlor.insert("christine");
    parlor.insert("abcde");

    // 1 search
    // 2 remove that node
    // removeThis = parlor.search("caramel");

    return 0;
}
