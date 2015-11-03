/*
 *  main.cpp
 *  20151028_lec
 *
 *  Created by Masatoshi Nishiguchi on 10/28/15.
 *  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
 */


#include <iostream>
#include <string>
using namespace std;

/*
 TODO
 - Overload comparison operators in order to make flavor the search key

 */


/**
 * Class that represents a node
 */
class IceCreamNode {
public:
    string flavor;
    IceCreamNode* left;
    IceCreamNode* right;

    string getInfo() {
        return flavor;
    }

    void setInfo(string info) {
        flavor = info;
    }

    // Constructors
    IceCreamNode();
    IceCreamNode(string);
};

/**
 * Default constructor
 */
IceCreamNode::IceCreamNode() {
    left  = NULL;
    right = NULL;

    flavor = "";
}
/**
 * Constructor with its flavor
 */
IceCreamNode::IceCreamNode(string flav) {
    left  = NULL;
    right = NULL;

    flavor = flav;
}

//*************************************

/**
 *  Reequirements: Nodes (data NodeType) must have left and right pointers
 *  as their members
 */
template <class NodeType>
class BSTree {
public:
    // constructor and destructor
    BSTree();
    ~BSTree();

    void insert(string key); // TODO
    NodeType* search(NodeType* key); // TODO
    void destroyTree(); // TODO

private:
    void destroyTree(NodeType* leaf);
    void insert(int key, NodeType* leaf);
    NodeType* search(int key, NodeType* leaf);

    NodeType* root;
};

/**
 *  Default constructor
 */
template <class NodeType>
BSTree<NodeType>::BSTree() {
    root = NULL;
}

template <class NodeType>
void BSTree<NodeType>::insert(int key) {
  if(root != NULL) {
    insert(key, root);

  } else {
    root            = new NodeType;
    root->setInfo(key);
    root->left      = NULL;
    root->right     = NULL;
  }
}






/** TODO
 *  Insert a node into the tree
 */
// template <class NodeType>
// void BSTree<NodeType>::insert(NodeType* key) {
//     NodeType* current = NULL;

//    if (root == NULL) {
//        root = key;

//    } else {

//        NodeType* trailCurrent = root;

//        while (current != NULL) {
//             trailCurrent = current;

//             // Every node should be unique.
//            if (trailCurrent->getInfo() == key) {
//                cout << "The key to be inserted is already in the tree" << endl
//                     << "Dupulicateds are not allowed" << endl;
//                 return;

//                 // Left child
//            } else if (current->getInfo() > key) {
//                 current = current->left;


//                 // Right child
//            } else if (current->getInfo() < key) {
//                 current = current->left;
//            }
//        } // end while

//        if (trailCurrent->getInfo() > key) {
//             trailCurrent->left = key;
//             cout << "Adding " << key->getInfo() << " to parent: "
//                  << trailCurrent->getInfo() << " on the left " << endl;

//        } else  {
//             trailCurrent->right = key;
//             cout << "Adding " << key->getInfo() << " to parent: "
//                  << trailCurrent->getInfo() << " on the right " << endl;
//        }
//    }
// }

//*************************************

int main() {

    BSTree<IceCreamNode> parlor;

    IceCreamNode* iceCream;

    iceCream = new IceCreamNode;
    iceCream->flavor = "GMR";
    parlor.insert(iceCream);



    return 0;
}
