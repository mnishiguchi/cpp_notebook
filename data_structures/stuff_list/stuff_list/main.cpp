/*****************************************************************************
    stuff_list.cpp
    Masatoshi Nishiguchi
    10/19/15

    Characteristics of this program
    - class template with a generic type
    - contains a list (implemented with an array)
    - sorting algorithm
    - operator overload for comparison operators
******************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;


/**
 * Class that represents a node
 */
class VGameNode {
public:

    // Constructors
    VGameNode();
    VGameNode(string title, string genre, int minAge);

    /**
     * Overloading comparison operators
     * Key: title
     * Note: rhs means "right-hand-side"
     */
    bool operator < (VGameNode rhs) {
        if (title < rhs.title) {
            return true;
        } else {
            return false;
        }
    }

    bool operator > (VGameNode rhs) {
        if (title > rhs.title) {
            return true;
        } else {
            return false;
        }
    }

    // Variables
    string title;
    string genre;
    int minAge;
};

/**
 * Constructor (default)
 */
VGameNode::VGameNode() {
    title  = "undefined";
    genre  = "undefined";
    minAge = -1;
}

/**
 * Constructor with parameters
 */
VGameNode::VGameNode(string t, string g, int a) {
    title  = t;
    genre  = g;
    minAge = a;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/**
 * A class that represents a list of stuff (of any type)
 */
template <typename Type>  // Generic type
class StuffList {
public:
    // Methods
    void addItem(Type item);
    int getItemCount();
    void insertionSort();
    void printAll();

    // Constructors
    StuffList();

    // Variables
    Type *stuff; // an array of list items
    int itemCount;
    const int MAX_ITEM_COUNT = 10;
};

/**
 * Constructor
 */
template <typename Type>
StuffList<Type>::StuffList() {
    stuff     = new Type[MAX_ITEM_COUNT];
    itemCount = 0;
}

/**
 * Adds an item to the list.
 */
template <typename Type>
void StuffList<Type>::addItem(Type item) {

    if ( itemCount >= MAX_ITEM_COUNT ) {
     cout << "List is full" << endl;
     return;
    }

    // Add the item to the array.
    stuff[itemCount] = item;
    cout << stuff[itemCount].title << " was added. " << endl;

    // Update the count.
    itemCount++;
    cout << "itemCount updated to: " << itemCount << endl;
}

/**
 * Returns itemCount.
 */
template <typename Type>
int StuffList<Type>::getItemCount() {
    return itemCount;
}

/**
 * Sort the list in ascending order.
 */
template <typename Type>
void StuffList<Type>::insertionSort() {
   int firstUnsorted;
   int position;
   Type temp;

   // Inspect the unsorted portion one by one.
   for (firstUnsorted = 1; firstUnsorted < itemCount; firstUnsorted++) {

       // If the value is less than previous
       if (stuff[firstUnsorted] < stuff[firstUnsorted - 1]) {
           temp     = stuff[firstUnsorted];  // Remember the value
           position = firstUnsorted;        // Remember the index of the value

           // Shift the sorted elements by one to the right
           // until the appropriate sorted position is determined.
           do {
               stuff[position] = stuff[position - 1];
               position--;

               // The value should be greater than the previous
           } while (position >= 1 && stuff[position - 1] > temp);

           // Set the value at the sorted position.
           stuff[position] = temp;
       }
   }
}

/**
 * Prints all the list items to the console.
 */
template <typename Type>
void StuffList<Type>::printAll() {
    cout << endl;
    for (int idx = 0; idx < itemCount; idx++) {
        cout << left;
        cout << setw(24) << stuff[idx].title;
        cout << setw(16) << stuff[idx].genre;
        cout << setw(8)  << stuff[idx].minAge;
        cout << endl;
    }
    cout << endl;
}

//----------------------------------------------------------------------------

/**
 * Main function of this program.
 */
int main() {

    // Create a list of VGameNode type
    StuffList<VGameNode> myStuff;

    cout << "\n-----Add items-----\n" << endl;

    // 1. Create a node
    // 2. Dereference the node
    // 3. Pass it in the addItem function

    myStuff.addItem( *(new VGameNode("Skyfall", "Action", 13)) );
    myStuff.addItem( *(new VGameNode("Minecraft", "Building", 4)) );

    myStuff.printAll();

    cout << "\n-----Add items-----\n" << endl;

    VGameNode* node;
    node = new VGameNode("Civilization", "Strategy", 10);
    myStuff.addItem(*node);

    myStuff.printAll();

    cout << "\n-----Sorting-----\n" << endl;

    myStuff.insertionSort();

    myStuff.printAll();

    return 0;
}
