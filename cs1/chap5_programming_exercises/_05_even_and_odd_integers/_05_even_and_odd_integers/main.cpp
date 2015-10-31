/*
  _05_even_and_odd_integers

  Reads a set of integers and then finds and prints the sum of
  the even and odd numbers.

  Created by Masatoshi Nishiguchi on 10/29/15.
  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
*/

/*
ANALYSIS
    If the input is 1, 2, 3, 9, 12, 34, the output is expected to be:
    Sum of odd numbers  => 2 + 12 + 34 = 48
    Sum of even numbers => 1 + 3 + 9   = 13

OUTPUT
    Enter as many integers as you like (Enter q to quit):
    1 2 3 9 12 34 q

    The sum of even integers: 48
    The sum of odd integers:  13
*/


#include <iostream>
using namespace std;

/**
 * Class that represents a node of interger value
 */
class intNode {
public:
    int value;
    intNode* next;

    intNode() {
      value = 0;
      next  = NULL;
    }
};

/**
 * Add a invVal node to a head of a linked list
 */
intNode* pushValue(intNode* head, int val) {
    intNode* newNode = new intNode;
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
intNode* removeFirstNode(intNode* head) {
    // Return if the stack is empty
    if (head == NULL) {
        cout << "The stack is empty." << endl;
        return NULL;
    }

    // Case2: not empty
    intNode* temp = head;         // Remember the head
    head         = head->next;   // Next node becomes head

    // cout << "removeFirstNode: " << temp->value << endl;
    delete temp;                 // Delete the node out of memory

    // Note: back did not change

    return head;
}

/**
 * Deletes all the intNode out of memory.
 */
void removeAllNodes(intNode* head) {
   while (head != NULL) {
       head = removeFirstNode(head);
   }
}

void printAllNodes(intNode* head) {
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return;
    }

    cout << "\nYour numbers: ";

    intNode* curr = head;
    while (curr != NULL) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}

void printSumOdd(intNode* head) {

    int sum  = 0;

    intNode* curr = head;
    while (curr != NULL) {
        if ( curr->value % 2 == 1 ) {
            sum += curr->value;
        }
        curr = curr->next;  // Update the curr
    }
    // Output
    cout << "The sum of odd integers:  " << sum << endl;
}

void printSumEven(intNode* head) {

    int sum  = 0;

    intNode* curr = head;
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

    intNode* list  = NULL;
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

    // Output the result
    printSumEven(list);
    printSumOdd(list);

    // Remove all the nodes out of memory
    removeAllNodes(list);

    return 0;
}
