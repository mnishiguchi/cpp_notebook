/*
 *  main.cpp
 *  20151028_lec
 *
 *  Created by Masatoshi Nishiguchi on 10/28/15.
 *  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
 */

// TODO: remove node (See textbook 6th ed p1331)
// TODO: insert node (See textbook 6th ed p1329)
// TODO: search node (See textbook 6th ed p1328)

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

    void insert(string key);         // TODO
    NodeType* search(NodeType* key); // TODO
    void destroyTree();              // TODO

    void removeFromTree(NodeType* itemToRemove);
    NodeType* root;


// private:
//     void destroyTree(NodeType* leaf);
//     void insert(int key, NodeType* leaf);
//     NodeType* search(int key, NodeType* leaf);
};

/**
 *  Default constructor
 */
template <class NodeType>
BSTree<NodeType>::BSTree() {
    root = NULL;
}

// template <class NodeType>
// void BSTree<NodeType>::insert(int key, NodeType* leaf) {
//   if(root != NULL) {
//     insert(key, root);

//   } else {
//     root            = new NodeType;
//     root->setInfo(key);
//     root->left      = NULL;
//     root->right     = NULL;
//   }
// }

template <class NodeType>
void BSTree<NodeType>::removeFromTree(NodeType* itemToRemove) {

    NodeType* current;
    NodeType* trailCurrent;
    NodeType* temp;

    if (itemToRemove == NULL) {
        cout << "Error: The node to be deleted is NULL" << endl;

    } else if (itemToRemove->left == NULL && itemToRemove->right == NULL) {
        temp         = itemToRemove;
        itemToRemove = NULL;
        delete temp;

    } else if (itemToRemove->left == NULL) { // If only has a right child
        temp         = itemToRemove;
        itemToRemove = temp->right;
        delete temp;

    } else if (itemToRemove->right == NULL) { // If only has a left child
        temp         = itemToRemove;
        itemToRemove = temp->left;
        delete temp;

    } else {  // Node has both left and right subtrees
        current      = itemToRemove->left;
        trailCurrent = NULL;

        // Go to the right all the way down to the rightmost grandchild
        while (current->right != NULL) {
            trailCurrent = current;
            current      = current->right;
        }

        // Replaca the itemToRemove with the rightmost grandchild
        itemToRemove->setInfo( current->getInfo() );

        if (trailCurrent == NULL) {
            trailCurrent->left = current->left;
        } else {
            trailCurrent->right = current->left;
        }

        // Finally delete the node
        delete current;
    }
}

// TODO: insert node (See textbook 6th ed p1329)
/** TODO
 *  Insert a node into the tree
 */
template <class NodeType>
void BSTree<NodeType>::insert(NodeType* insertItem) {
    NodeType* current;
    NodeType* trailCurrent;
    NodeType* newNode;

    newNode = new nodeType<NodeType>;
    newNode->getInfo() = insertItem;



   if (root == NULL) {
       root = key;

   } else {

       NodeType* trailCurrent = root;

       while (current != NULL) {
            trailCurrent = current;

            // Every node should be unique.
           if (trailCurrent->getInfo() == key) {
               cout << "The key to be inserted is already in the tree" << endl
                    << "Dupulicateds are not allowed" << endl;
                return;

                // Left child
           } else if (current->getInfo() > key) {
                current = current->left;


                // Right child
           } else if (current->getInfo() < key) {
                current = current->left;
           }
       } // end while

       if (trailCurrent->getInfo() > key) {
            trailCurrent->left = key;
            cout << "Adding " << key->getInfo() << " to parent: "
                 << trailCurrent->getInfo() << " on the left " << endl;

       } else  {
            trailCurrent->right = key;
            cout << "Adding " << key->getInfo() << " to parent: "
                 << trailCurrent->getInfo() << " on the right " << endl;
       }
   }
}

/** TODO
 *  Search a node into the tree
 */
template <class NodeType>
NodeType* BSTree<NodeType>::search(string searchKey) {

}


//*************************************

int main() {

    BSTree<IceCreamNode> parlor;

    IceCreamNode* iceCream;

    // iceCream = new IceCreamNode;
    // iceCream->flavor = "GMR";
    // parlor.insert(iceCream);

    // 1 search
    // 2 remove that node
    // removeThis = parlor.search("caramel");

    return 0;
}
