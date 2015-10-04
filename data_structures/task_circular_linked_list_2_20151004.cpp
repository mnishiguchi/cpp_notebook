//
//  main.cpp
//  circular_linked_list
//
//  Created by Masatoshi Nishiguchi on 10/02/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <ios>
using namespace std;

/**
 * Class that represents a node
 */
class Task {

public:
    // Functions
    bool isCompleted();
    void performTask(const int msec);

    // Constructors
    Task(int m);  // Constructor with parameters
    Task();       // Default constructor

    // Instance variables
    int taskTimeMilli;
    int taskID;
    Task* next;

    // Static
    static int count;
};

// Initialize the instance counter
int Task::count = 0;

/** constructor */
Task::Task(int m) {
    taskTimeMilli = m;
    next   = NULL;
    taskID = ++count;

    cout << "Task #" << taskID << " was created (" << taskTimeMilli << ")" << endl;
}

/**
 * Returns true if the task is completed
 */
bool Task::isCompleted() {
    if (taskTimeMilli <= 0) {
        cout << endl;
        cout << "Task #" << this->taskID << " completed (" << taskTimeMilli << ")" << endl;
        return true;
    }
    return false;
}

/**
 * Perform the specified task for the allocated timeslice.
 */
void Task::performTask(const int msec) {
    taskTimeMilli -= msec;
}



/**
 * Adds a new node to the beginning of the list if the list is not full.
 * Updates the list size counter. Returns a new head node.
 */
Task* addTask(Task* newNode, Task* head, int& currSize, const int CAPACITY) {

    bool isListFull = (currSize == CAPACITY);

    if (isListFull) {
        cout << endl;
        cout << "Could not add a node because the list is full" << endl;
        return NULL;
    }

    // Case1: Empty list
    if (head == NULL) {
        head       = newNode;  // The new node becomes the head.
        head->next = newNode;  // next is itself

    // Case2: Non-empty list
    } else {
        // Go to the last node.
        Task* curr = head;
        while (curr->next != head) {
            curr = curr->next;
        }

        // Note: Now curr is the last node.

        // Insert the newNode between head and tail.
        curr->next       = newNode;  // Set the last node's next pointer.
        curr->next->next = head;     // Set the new node's next pointer.

        // Update the head pointer.
        head = newNode;  // The new node becomes the head.
    }

    // Update the size
    currSize++;
    cout << endl;
    cout << "Task added" << endl;
    cout << "Size updated to " << currSize << endl;

    return head;
}

bool isListEmpty(int size) {
    return size <= 0;
}

bool isPoolEmpty(Task* t) {
    return t->taskTimeMilli == -1;
}

/**
 * Print all the elements in the list to the console.
 */
void printList(Task* head) {

    // Return if the list is empty
    if (head == NULL) {
        cout << endl;
        cout << "The list is empty" << endl;
        return;
    }

    cout << endl;

    // Print the attributes names.
    cout << setw(8) << "ID";
    cout << setw(8) << "msec";
    cout << setw(8) << "next";
    cout << endl;

    // Draw a horizonal line.
    cout << setfill('-') << setw(24) << "" << setfill(' ') << endl;

    // Traverse the list until the end of the list.
    Task* curr   = head;
    bool isEndOfList = false;

    while (!isEndOfList) {
        // Print current node
        cout << setw(8) << curr->taskID;
        cout << setw(8) << curr->taskTimeMilli;
        cout << setw(8) << curr->next->taskID;
        cout << endl;

        if (curr->next != head) {
            curr = curr->next;  // Move the cursor to next and continue.
        } else {
            isEndOfList = true; // Exit the loop.
        }
    }
    // cout << "--- end of the list ---" << endl << endl;
}

/**
 * Utility function to draw a horizontal seperator.
 */
void drawLine(int n) {
    cout << endl;
    cout << setfill('~') << setw(n) << "" << setfill(' ') << endl;
}



/**
 * Main function of this program.
 */
int main() {

    const int CAPACITY      = 3;
    const int TIME_TO_ALLOC = 10;

    // Initialize the global variables
    Task* head      = NULL;
    int currSize = 0;

    // The pool of tasks to be performed

    // Regular array
    Task pool[] = {
        Task(30),
        Task(22),
        Task(100),
        Task(39),
        Task(64),
        Task(87),
        Task(34),
        Task(53),
        Task(-1),  // Sentinel
    };

    // // Dynamic array
    // Task* pool[] = {
    //     new Task(30),
    //     new Task(22),
    //     new Task(100),
    //     new Task(39),
    //     new Task(64),
    //     new Task(87),
    //     new Task(34),
    //     new Task(53),
    //     new Task(-1),  // Sentinel
    // };


    // === Load and perform the tasks ===

    Task* curr = NULL;
    Task* temp = NULL;

    int idx = 0;

    // Condition to terminate: Both list and pool are empty

    while ( !isPoolEmpty(&pool[idx]) || !isListEmpty(currSize) ) {

        //==> Section1: Adding tasks

        // If the pool is not empty and the list is not full,
        // add new tasks until the list is full

        if ( !isPoolEmpty(&pool[idx]) ) {
            while ( currSize != CAPACITY ) {
                head = addTask( &pool[idx], head, currSize, CAPACITY );
                printList(head);
                drawLine(40);

                idx++;  // Move the cursor to next item in the pool
            }
        } else  {
            cout << endl;
            cout << "The pool is empty" << endl;
        }

        //==> Section2: Performing tasks

        // Repeat performing the tasks until one node is completed
        // Delete the task if completed

        curr = head;  // Initialize the cursor
        do {
            curr->performTask(TIME_TO_ALLOC);

            // Next node: not completed
            if ( !curr->next->isCompleted() ) {
                curr = curr->next;  // Move the cursor to next

            // Next node: completed => need to delete it
            } else {
                temp = curr->next;  // Remember the node to delete

                // Delete the node  // TODO
                curr->next = curr->next->next;
                temp->next = NULL;

                // Decrement the size
                currSize--;
                cout << endl;
                cout << "Task removed" << endl;
                cout << "Size updated to " << currSize << endl;

                // Update the head if head is the one that was deleted
                if ( temp == head ) {
                    head = curr->next;
                }

                printList(head);
                drawLine(40);

                break;  // Exit the loop
            }
        } while ( !isListEmpty(currSize) );
    }

    cout << endl;
    cout << "All the tasks are completed" << endl;

    return 0;
}
