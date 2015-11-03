/********************************************************************

   CSCI-241C-01 Data structures
   v_game_sorting.cpp

   Name: Masatoshi Nishiguchi (N00263071)
   Date: 10/29/2015

 ********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**
 * Class that represents a node
 */
class VGameNode {
public:
    void setTitle(string);
    string getTitle() const;
    void setGenre(string);
    string getGenre() const;
    void setMinAge(int);
    int getMinAge() const;

    VGameNode* next;

    // Constructors
    VGameNode();
    VGameNode(string title, string genre, int minAge);

    // Opeartor overloading
    bool operator==(VGameNode& rhs) const;
    bool operator<(VGameNode& rhs) const;
    bool operator>(VGameNode& rhs) const;

private:
    string title;
    string genre;
    int minAge;
};

/** Default constructor */
VGameNode::VGameNode() {
    next = NULL;
}

/** Constructor to create a node with a specific set of data */
VGameNode::VGameNode(string title, string genre, int minAge) {
    next = NULL;
    this->title  = title;
    this->genre  = genre;
    this->minAge = minAge;
}

// Operator overloading

bool VGameNode::operator==(VGameNode& rhs) const {
    return title == rhs.title;
}
bool VGameNode::operator<(VGameNode& rhs) const {
    return title < rhs.title;
}
bool VGameNode::operator>(VGameNode& rhs) const {
    return title > rhs.title;
}

// Getters and setters

void VGameNode::setTitle(string title) {
    this->title = title;
}

string VGameNode::getTitle() const {
    return title;
}

void VGameNode::setGenre(string genre) {
    this->genre = genre;
}

string VGameNode::getGenre() const {
    return genre;
}

void VGameNode::setMinAge(int minAge) {
    this->minAge = minAge;
}

int VGameNode::getMinAge() const {
    return minAge;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    Sorting related functions
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/**
 * Compare two VGameNodes by title.
 * In ASC mode, returns true if g1 < g2, else false.
 * In DESC mode, returns true if g1 > g2, else false.
 */
bool compareByTitle(VGameNode* g1, VGameNode* g2, bool isAscend) {

    // No need to sort
    if (g1 == NULL || g2 == NULL) {
        return true;
    }

    bool answer = g1->getTitle() < g2->getTitle();

    if (!isAscend) {
        answer = !answer;
    }

    cout << "Compared" << endl;
    return answer;
}

/**
 * Compare two VGameNodes by age.
 * In ASC mode, returns true if g1 < g2, else false.
 * In DESC mode, returns true if g1 > g2, else false.
 */
bool compareByMinAge(VGameNode* g1, VGameNode* g2, bool isAscend) {

    // No need to sort
    if (g1 == NULL || g2 == NULL) {
        return true;
    }

    bool answer = g1->getMinAge() < g2->getMinAge();

    if (!isAscend) {
        answer = !answer;
    }

    cout << "Compared" << endl;
    return answer;
}

/**
 * Compare two VGameNodes by genre.
 * In ASC mode, returns true if g1 < g2, else false.
 * In DESC mode, returns true if g1 > g2, else false.
 */
bool compareByGenre(VGameNode* g1, VGameNode* g2, bool isAscend) {

    // No need to sort
    if (g1 == NULL || g2 == NULL) {
        return true;
    }

    bool answer = g1->getGenre() < g2->getGenre();

    if (!isAscend) {
        answer = !answer;
    }

    cout << "Compared" << endl;
    return answer;
}

/**
 * Insert a new VGameNode object into a linked list based on the sorting key
 * that is specified by one of the vGameComparator functions.
 */
VGameNode* insertNewNode( VGameNode* head, VGameNode* newNode,
    bool ( *vGameComparator )(VGameNode*, VGameNode*, bool) ) {

    // Special case: newnode to be added as first node.
    if( head == NULL || !vGameComparator(head, newNode, true) ) {
        newNode->next = head;
        head          = newNode;
        return head;
    }

    VGameNode *ptr  = head;
    VGameNode *prev = NULL;
    while ( ptr != NULL && vGameComparator(ptr, newNode, true) ) {
        prev = ptr;
        ptr = ptr->next;
    }

    newNode->next = ptr;
    prev->next    = newNode;
    return head;
}

/**
 * Sorts a linked list based on the sorting key
 * that is specified by one of the vGameComparator functions.
 */
VGameNode* insertionSort( bool ( *vGameComparator )(VGameNode*, VGameNode*, bool),
                      VGameNode* head) {

    if( !head || !head->next ) {
        return head;
    }

    VGameNode * ptr    = head->next;
    VGameNode * result = head;
    result->next       = NULL;

    while ( ptr ) {
        VGameNode *temp = ptr;
        ptr             = ptr->next;
        result          = insertNewNode(result, temp, vGameComparator);
    }
    return result;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    Utility functions
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/**
 * Adds a node before the top of the stack
 * Returns a new head node
 */
VGameNode* addNodeFirst(VGameNode* head, string title, string genre, int minAge) {

    // Create a new node base on the specified data.
    VGameNode* newNode = new VGameNode(title, genre, minAge);

    // Case1: Empty list
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return newNode;

        // Case2: Non-empty list
    } else {
        // Set the new node at the top of the stack.
        newNode->next = head;

        // Update top
        return newNode;

        // Note: back did not change
    }
}

/**
 * Utility function to print all the nodes in the linked list.
 */
void printAll(VGameNode* head) {

    // Return if the stack is empty
    if (head == NULL) {
        cout << "The stack is empty." << endl;
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

        // Print current node
        cout << left;
        cout << setw(24) << curr->getTitle();
        cout << setw(16) << curr->getGenre();
        cout << setw(8)  << curr->getMinAge();
        cout << endl;

        // Move the cursor to next
        curr = curr->next;
    }
}

/**
 * Deletes the top node from memory.
 * Returns the new head node of the stack.
 */
VGameNode* removeFirstNode(VGameNode* head) {
    // Return if the stack is empty
    if (head == NULL) {
        cout << "The stack is empty." << endl;
        return NULL;
    }

    string name = head->getTitle();

    // Case2: not empty
    VGameNode* temp = head;        // Remember the head
    head            = head->next;  // Next node becomes head

    cout << "emoveFirstNode: " << name << endl;
    delete temp;                   // Delete the node out of memory

    // Note: back did not change

    return head;
}

/**
 * Deletes all the VGameNode out of memory.
 * Returns the new head node of the stack.
 */
VGameNode* removeAllNodes(VGameNode* head) {
   while (head != NULL) {
       head = removeFirstNode(head);
   }
   return head;
}

/**
 * Utility function to draw a horizontal seperator.
 */
void drawLine() {
    cout << endl;
    cout << setfill('~') << setw(48) << "" << setfill(' ') << endl;
    cout << endl;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    Main
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main() {

    // 1. Create an empty stack.
    cout << "\nCreating a new empty stack\n" << endl;
    VGameNode* gameStack = new VGameNode("Stu", "Action", 3);

    // 2. Push elements to the stack.
    cout << "\nAdding nodes to the stack\n" << endl;

    gameStack = addNodeFirst(gameStack, "Foo", "Action", 4);
    gameStack = addNodeFirst(gameStack, "Pqr", "Shooter", 6);
    gameStack = addNodeFirst(gameStack, "Bar", "Roll-playing", 9);
    gameStack = addNodeFirst(gameStack, "Mno", "Adventure", 1);
    gameStack = addNodeFirst(gameStack, "Abc", "Simulation", 2);
    gameStack = addNodeFirst(gameStack, "Xyz", "Strategy", 5);

    cout << "\nBefore sorting\n" << endl;
    printAll(gameStack);
    drawLine();

    // 3. Sorting
    cout << "\nSorting\n" << endl;

    gameStack = insertionSort( &compareByMinAge, gameStack);
    cout << "\nAfter sorting by minage\n" << endl;
    printAll(gameStack);
    drawLine();

    gameStack = insertionSort( &compareByTitle, gameStack);
    cout << "\nAfter sorting by title\n" << endl;
    printAll(gameStack);
    drawLine();

    gameStack = insertionSort( &compareByGenre, gameStack);
    cout << "\nAfter sorting by genre\n" << endl;
    printAll(gameStack);
    drawLine();

    // 4. Remove all the rest
    cout << "\nClean up\n" << endl;

    gameStack = removeAllNodes(gameStack);
    cout << "\nAfter clean up\n" << endl;
    printAll(gameStack);
    drawLine();

    return 0;
}
