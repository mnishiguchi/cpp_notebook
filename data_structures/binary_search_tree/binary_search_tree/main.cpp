/*
binary_search_tree_integer

*/
/*****************************************************************************

    Binary search tree

    Name: Masatoshi Nishiguchi\
    Date: 10/14/2015

    Reference: http://www.cprogramming.com/tutorial/lesson18.html

 *****************************************************************************/


#include <iostream>
using namespace std;

/**
 *  Represents a leaf of a binary tree.
 */
class LeafNode {
public:
    LeafNode(int val) {
        value = val;
        left  = NULL;
        right = NULL;
    }

    int value;
    LeafNode* left;
    LeafNode* right;
};


/**
 *  Encapsulates the workings of the tree into a single area.
 */
class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();

    // Public methods
    void insert(int key);
    LeafNode* search(int key);
    void destroy_tree();

private:
    void destroy_tree(LeafNode* leaf);
    void insert(int key, LeafNode* leaf);
    LeafNode* search(int key, LeafNode* leaf);

    LeafNode* root;
};

/**
 *  Constructor
 */
BinaryTree::BinaryTree() {
    root = NULL;

    cout << "A new binary tree was created" << endl;
}

/**
 *  Destructor
 *  Sets off the recursive function destroy_tree which will actually delete
 *  all nodes of the tree.
 */
BinaryTree::~BinaryTree() {
    destroy_tree();
    cout << "Deletion completed" << endl;
}

//===============================================
//  BinaryTree's internal methods
//===============================================

/**
 *  Recursively goes to the bottom of each part of the tree,
 *  deletes that leaf, and then works its way back up.
 */
void BinaryTree::destroy_tree(LeafNode *leaf) {
    if(leaf != NULL) {  // Base case: Stop recursion when leaf is NULL
        destroy_tree(leaf->left);  // Go to the left child and delete all
        destroy_tree(leaf->right); // Go to the right child and delete all
        cout << "Deleting " << leaf->value << "..." << endl;
        delete leaf; // Delete this leaf
    }
}

/**
 *  Inserts a new leaf into the specified sub-tree.
 *  key:  the key to be inserted
 *  leaf: the root node of a subtree.
 */
void BinaryTree::insert(int key, LeafNode *leaf) {
    // Go to the left child
    if (key < leaf->value) {

        if(leaf->left != NULL) {
            insert(key, leaf->left);

        } else {
            cout << "Inserting " << key << " under " << leaf->value
                 << " on the left" << endl;
            leaf->left = new LeafNode(key);
        }
    }
    // Go to the right child
    else if(key >= leaf->value) {

        if(leaf->right != NULL) {
            insert(key, leaf->right);

        } else {
            cout << "Inserting " << key << " under " << leaf->value
                 << " on the right" << endl;
            leaf->right = new LeafNode(key);
        }
    }
}

/**
 *  Searches for the node with the specified key in the specified sub-tree.
 *  key:  the key to be searched for.
 *  leaf: the root node of a subtree.
 */
LeafNode* BinaryTree::search(int key, LeafNode *leaf) {
    // There is possibility that a child's value matches the key.
    if(leaf != NULL) {
        // Base case: If found, return the pointer to that leaf
        if(key == leaf->value) {
            cout << key << " was found" << endl;
            return leaf;
        }

        // Recursively go down the tree and check each node in the path.
        if(key < leaf->value) {
            return search(key, leaf->left);
        } else {
            return search(key, leaf->right);
        }
    }
    // Deadend
    else {
        cout << key << " was not found" << endl;
        return NULL;
    }
}

//===============================================
//  BinaryTree's public methods
//===============================================

/**
 *  Public method to insert the specified key to the tree.
 *  Note: The root is hidden.
 */
void BinaryTree::insert(int key) {
    if(root != NULL) {
        insert(key, root);
    } else {
        cout << "Setting " << key << " as a root of the tree" << endl;
        root = new LeafNode(key);
    }
}

/**
 *  Public method to search for the specified key in the tree.
 *  Note: The root is hidden.
 */
LeafNode* BinaryTree::search(int key) {
  return search(key, root);
}

/**
 * Initializes the tree.
 * The recursive destroy_tree function deletes all the nodes of the tree.
 */
void BinaryTree::destroy_tree() {
    cout << "Initializing the tree..." << endl;
    destroy_tree(root);
}

//===============================================
//  The main function
//===============================================

int main() {

    cout << "\n===Creating a binary tree===\n" << endl;
    BinaryTree* myTree = new BinaryTree;

    cout << "\n===Inserting leaves===\n" << endl;
    myTree->insert(35);
    myTree->insert(12);
    myTree->insert(4);
    myTree->insert(65);

    cout << "\n===Searching for some values===\n" << endl;
    myTree->search(34);
    myTree->search(35);

    cout << "\n===Deleting the tree===\n" << endl;
    delete myTree;

    return 0;
}
