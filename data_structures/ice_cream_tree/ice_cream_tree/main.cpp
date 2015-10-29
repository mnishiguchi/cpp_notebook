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

//*************************************

///**
// * Class that represents a node
// */
//class IntVal {
//public:
//    IntVal* left;
//    IntVal* right;
//
//    string info;
//
//    // Constructors
//    IntVal();
//};
//
///** Default constructor */
//IntVal::IntVal() {
//    left  = NULL;
//    right = NULL;
//
//    info = 0;
//}

//*************************************

/**
 * Class that represents a node
 */
class IceCreamNode {
public:
    IceCreamNode* left;
    IceCreamNode* right;
    
    string flavor;
    
    // Constructors
    IceCreamNode();
};

/** Default constructor */
IceCreamNode::IceCreamNode() {
    left  = NULL;
    right = NULL;
    
    flavor = "";
}

//*************************************

/**
 *  Note: Nodes (data type) must have left and right pointers as their members
 */
template <class T>
class BSTree {
public:
    T* root;  // Root node of the tree
    
    void add(T* t);     // TODO
    void remove(T* t); // TODO
    
    
    BSTree() {
        root = NULL;
    }
    
    
};


//void BSTree::add(T* t) {
//    if (root == NULL) {
//        root = t;
//    } else {
//
//        T* curr = root;
//        if (curr->left == NULL) {
//            curr->left = t;
//        } else if (curr->right == NULL) {
//            curr->right = t;
//        }
//    }
//}




//*************************************

int main() {
    
    BSTree<IceCreamNode> myFlavors;
    
    IceCreamNode* curr;
    
    curr = new IceCreamNode;
    curr->flavor = "GMR";
    myFlavors.add(curr);
    
    
    
    
    return 0;
}
