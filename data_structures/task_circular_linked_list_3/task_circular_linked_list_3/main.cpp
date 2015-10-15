//
//  main.cpp
//  task_circular_linked_list_3
//
//  Created by Masatoshi Nishiguchi on 10/9/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

/**
 * Class that represents a node
 */
class Task {

public:
    // Functions
    bool isCompleted();
    void performTask(const int MSEC);

    // Constructors
    Task(int m);  // Constructor with parameters

    // Instance variables
    int taskTimeMilli;
    int taskID;
    Task* next;

private:
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
void Task::performTask(const int MSEC) {
    taskTimeMilli -= MSEC;
}

/**
 * Adds a new node to the beginning of the list if the list is not full.
 * Updates the list size counter. Returns a new tail node.
 */
Task* addTask(Task* newNode, Task* tail, int& listSize, const int CAPACITY) {

    bool isListFull = (listSize == CAPACITY);

    if (isListFull) {
        cout << endl;
        cout << "Could not add a node because the list is full" << endl;
        return NULL;
    }

    // Case1: Empty list
    if (tail == NULL) {
        tail       = newNode;  // The new node becomes the tail.
        tail->next = newNode;  // next is itself

    // Case2: Non-empty list
    } else {
        // Insert the newNode between head and tail.
        newNode->next = tail->next;  // Set the new node's next pointer.
        tail->next       = newNode;  // Set tail's next pointer.
    }

    // Update the size
    listSize++;
    cout << endl;
    cout << "Task added" << endl;
    cout << "Size updated to " << listSize << endl;

    return tail;
}

/**
 * Returns true if the list is empty.
 */
bool isListEmpty(int size) {
    return size <= 0;
}

/**
 * Returns true if the specified Task object contains the sentinel value(-1).
 */
bool isPoolEmpty(Task* pool, int index) {
    return pool[index].taskTimeMilli == -1;
}

/**
 * Print all the elements in the list to the console.
 */
void printList(Task* tail) {

    // Return if the list is empty
    if (tail == NULL) {
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
    Task* curr   = tail;
    bool isEndOfList = false;

    while (!isEndOfList) {
        // Print current node
        cout << setw(8) << curr->taskID;
        cout << setw(8) << curr->taskTimeMilli;
        cout << setw(8) << curr->next->taskID;
        cout << endl;

        if (curr->next != tail) {
            curr = curr->next;  // Move the cursor to next and continue.
        } else {
            isEndOfList = true; // Exit the loop.
        }
    }
}

/**
 * Utility function to draw a horizontal seperator.
 */
void drawLine() {
    cout << endl;
    cout << setfill('~') << setw(32) << "" << setfill(' ') << endl;
}



/**
 * Main function of this program.
 * Simulates running tasks that are stored in an array.
 */
int main() {

    // Configuration
    const int CAPACITY      = 3;
    const int TIME_TO_ALLOC = 10;

    // Variables for global use
    Task* tail   = NULL;
    int listSize = 0;  // Current size of the list
    int idx      = 0;  // Current index of the pool

    // The pool of tasks to be performed (Regular array)
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

    // Load and perform the tasks

    // variables for local use
    Task* curr = NULL;
    Task* temp = NULL;

    // Condition to terminate: Both pool and list are empty

    while ( !isPoolEmpty(pool, idx) || !isListEmpty(listSize) ) {

        // Section1: Adding tasks

        // If the pool is not empty and the list is not full,
        // add new tasks until the list is full

        if ( !isPoolEmpty(pool, idx) ) {
            while ( listSize != CAPACITY ) {
                // Add a new task and update the tail
                tail = addTask( &pool[idx], tail, listSize, CAPACITY );

                printList(tail);
                drawLine();

                idx++;  // Move the cursor to next item in the pool
            }
        } else  {
            cout << endl;
            cout << "The pool is empty" << endl;
        }

        // Section2: Performing tasks

        // Repeat performing the tasks until one node is completed
        // Delete the task if completed

        curr = tail;  // Initialize the cursor to tail
        for (;;) {
            curr->performTask(TIME_TO_ALLOC);

            // Check if next node is completed

            // Case1: Not completed => continue
            if ( !curr->next->isCompleted() ) {
                curr = curr->next;  // Move the cursor to next
                continue;
            }

            // Case2: Completed => need to delete it

            temp = curr->next;  // Remember the node to delete

            // Delete the node
            curr->next = curr->next->next;
            temp->next = NULL;

            // Note: Since the pool is a regular array,
            // there is no need to delete it out of memeory

            // Decrement the size
            listSize--;
            cout << endl;
            cout << "Task removed" << endl;
            cout << "Size updated to " << listSize << endl;

            // Update the tail if tail is the one that was deleted
            if ( temp == tail ) {
                tail = curr->next;
            }

            printList(tail);
            drawLine();

            break;  // Exit the loop
        }
    }

    cout << endl;
    cout << "All the tasks are completed" << endl;

    return 0;
}
