/*
  _05_even_and_odd_integers

  Reads a set of integers and then finds and prints the sum of
  the even and odd numbers.

  Created by Masatoshi Nishiguchi on 10/29/15.
  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
*/

#include <iostream>
using namespace std;

/**
 * Class that represents a node of interger value
 */
class intVal {
public:
    int value;
    intVal* next;

    intVal() {
      value = 0;
      next  = NULL;
    }
};

/**
 * Add a invVal node to a head of a linked list
 */
intVal* pushValue(intVal* head, int val) {
    intVal* newNode = new intVal;
    newNode->value  = val;

    if (head != NULL) {
      newNode->next = head;
    }
    return newNode;  // New head
}

/**
 * Deletes the top node from memory.
 * Returns the new head node of the stack.
 */
intVal* removeFirstNode(intVal* head) {
    // Return if the stack is empty
    if (head == NULL) {
        cout << "The stack is empty." << endl;
        return NULL;
    }

    // Case2: not empty
    intVal* temp = head;         // Remember the head
    head         = head->next;   // Next node becomes head

    //ncout << "removeFirstNode: " << temp->value << endl;
    delete temp;                 // Delete the node out of memory

    // Note: back did not change

    return head;
}

/**
 * Deletes all the intVal out of memory.
 */
void removeAllNodes(intVal* head) {
   while (head != NULL) {
       head = removeFirstNode(head);
   }
}

void printAllNodes(intVal* head) {
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return;
    }

    intVal* curr = head;
    while (curr != NULL) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}

void printSumOdd(intVal* head) {

    int sum  = 0;

    intVal* curr = head;
    while (curr != NULL) {
        if ( curr->value % 2 == 1 ) {
            sum += curr->value;
        }
        curr = curr->next;  // Update the curr
    }
    // Output
    cout << "The sum of odd integers:  " << sum << endl;
}

void printSumEven(intVal* head) {

    int sum  = 0;

    intVal* curr = head;
    while (curr != NULL) {
        if ( curr->value % 2 == 0 ) {
            sum += curr->value;
        }
        curr = curr->next;  // Update the curr
    }
    // Output
    cout << "The sum of even integers: " << sum << endl;
}

/**
 * The main function of this program
 */
int main() {

    intVal* list  = NULL;
    bool finished = false;
    int num;

    cout << "Enter as many integers as you like (Enter q to quit): " << endl;

    while (!finished) {
        cin >> num;  // Read a number

        // If cin is in a bad state, exit the loop
        if (!cin) {
            cin.clear();
            cin.ignore(1024, '\n');
            finished = true;

        } else {
          // Add number to a list
          list = pushValue(list, num);
        }
    }

    // Output
    
    cout << "\nYour numbers: ";

    printAllNodes(list);
    printSumEven(list);
    printSumOdd(list);

    // Remove all the nodes out of memory
    removeAllNodes(list);

    return 0;
}
