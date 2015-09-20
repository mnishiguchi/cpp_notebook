//
//  doubly_linked_list.cpp
//  doubly_linked_list
//
//  Adopted from: C++ Programming (7th ed.) by D. S. Malik, p1150
//
//  Created by Masatoshi Nishiguchi on 9/20/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include "doubly_linked_list.h"
using namespace std;

/*
 * Defines a doubly linked list as an ADT
 */

//Definition of the node
template <class Type> class nodeType
{
    Type info;
    nodeType<Type> *next;
    nodeType<Type> *back;
};

template <class Type> class doublyLinkedList {
    
public:
    
    // Overload the assignment operator.
    const doublyLinkedList<Type>& operator=
    (const doublyLinkedList<Type> &);
    
    // Initialize the list to an empty state.
    // Postcondition: first = NULL; last = NULL; count = 0;
    void initializeList();
    
    // Determine whether the list is empty.
    // Postcondition: Returns true if the list is empty, otherwise returns false.
    bool isEmptyList() const;
    
    // Delete all the node from the list.
    // Postcondition: first = NULL; last = NULL; count = 0;
    void destroy();
    
    // Output the into contained in each node.
    void print() const;
    
    // Output the into contained in each node in reverse order.
    void reversePrint() const;
    
    // Return the number of nodes in the list.
    // Postcondition: The value of count is returned.
    int length() const;
    
    // Return the first element of the list.
    // Precondition:  The list must exist and must not be empty.
    // Postcondition: If the list is empty, the program terminates;
    //                otherwise, the first element of the list is returned.
    Type front() const;
    
    // Return the last element of the list.
    // Precondition: The list must exist and must not be empty.
    // Postcondition: If the list is empty, the program terminates;
    //                otherwise, the last element of the list is returned.
    Type back() const;
    
    // Determine whether searchItem is in the list.
    // Postcondition: Returns true if searchItem is found in the list, otherwise returns false.
    bool search(const Type& searchItem) const;
    
    // Insert insertItem in the list.
    // Precondition:  If the list is nonempty, it must be in order.
    // Postcondition: insertItem is inserted at the proper place in the list,
    //                first points to the first node,
    //                last points to the last node of the new list, and
    //                count is incremented by 1.
    void insert(const Type& insertItem);
    
    // Delete deleteItem from the list.
    // Postcondition: If found, the node containing deleteItem is deleted from the list;
    //                first points to the first node of the new list,
    //                last points to the last node of the new list, and
    //                count is decremented by 1;
    //                otherwise an appropriate message is printed.
    void deleteNode(const Type& deleteItem);
    
    // Default constructor
    // Initializes the list to an empty state.
    // Postcondition: first = NULL; last = NULL; count = 0;
    doublyLinkedList();
    
    // Copy constructor
    doublyLinkedList(const doublyLinkedList<Type>& otherList);
    
    // Destructor
    // Postcondition: The list object is destroyed.
    ~doublyLinkedList();
    
protected:
    
    int count;
    nodeType<Type> *first;  // pointer to the first
    nodeType<Type> *last;   // pointer to the last node
    
private:
    
    // Make a copy of otherList.
    // Postcondition: A copy of otherList is created and assigned to this list.
    void copyList(const doublyLinkedList<Type>& otherList);
};

/**
 * Default constructor
 * Initializes the list to an empty state.
 * Postcondition: first = NULL; last = NULL; count = 0;
 */
template <class Type> doublyLinkedList<Type>::doublyLinkedList() {
    first= NULL;
    last = NULL;
    count = 0;
}

/**
 * @return true if the list is empty; otherwise false.
 */
template <class Type>
bool doublyLinkedList<Type>::isEmptyList() const {
    return (first == NULL);
}

/**
 * Deletes all of the nodes in the list, leaving the list in an empty state.
 */
template <class Type>
void doublyLinkedList<Type>::destroy() {
    nodeType<Type> *temp; //pointer to delete the node
    while (first != NULL) {
        temp = first;
        first = first->next; delete temp;
    }
    last = NULL;
    count = 0;
}

/**
 * Reinitializes the doubly linked list to an empty state.
 */
template <class Type>
void doublyLinkedList<Type>::initializeList() {
    destroy();
}

/**
 * Return the number of nodes in the list.
 */
template <class Type>
int doublyLinkedList<Type>::length() const {
    return count;
}

/**
 * Output the into contained in each node.
 */
template <class Type>
void doublyLinkedList<Type>::print() const {
    nodeType<Type> *current; //pointer to traverse the list
    current = first;         //set current to point to the first node
    while (current != NULL) {
        cout << current->info << " "; //output info
        current = current->next;
    }//end while
}//end print

/**
 * Output the into contained in each node in reverse order.
 */
template <class Type>
void doublyLinkedList<Type>::reversePrint() const {
    nodeType<Type> *current; // pointer to traverse the list
    current = last;          // set current to point to the last node
    while (current != NULL) {
        cout << current->info << "  ";
        current = current->back;
    }//end while
}//end reversePrint

/**
 * Determine whether searchItem is in the list.
 * @return true if searchItem is found in the list; otherwise false.
 */
template <class Type>
bool doublyLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current; //pointer to traverse the list
    current = first;
    while (current != NULL && !found)
        if (current->info >= searchItem) {
            found = true;
        } else {
            current = current->next;
        }
    
    if (found) {
        found = (current->info == searchItem); //test for equality
    }
    
    return found;
}//end search

/**
 * @return the first element of the list.
 */
template <class Type>
Type doublyLinkedList<Type>::front() const {
    assert(first != NULL); return first->info;
}

/**
 * @return the last element of the list.
 */
template <class Type>
Type doublyLinkedList<Type>::back() const {
    assert(last != NULL); return last->info;
}

