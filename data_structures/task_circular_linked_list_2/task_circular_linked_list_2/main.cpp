//
//  main.cpp
//  circular_linked_list
//
//  Created by Masatoshi Nishiguchi on 10/02/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

/*
 
 Make a program that will simulate a computer and its tasks.
 
 # use only one class
 
 class Task
 - taskID
 - taskTimeMilli
 - next
 
 # the taskPool array
 
 - (an array that prof will give out)
 - essentially a collection of Tasks that must be processed
 - A taskTimeMilli value of -1 will indicate the sentinel value for the array
 
 # flow of the process
 
 1. Initially, your code will load the circular linked list with 3 instances from the pool.
 2. The code must then process each task in a round-robin fashion allocating a maximum of TIME_TO_ALLOC milliseconds to each Task.
 3. To simulate the processing, subtract a maximum of TIME_TO_ALLOC milliseconds from each task's taskTimeMilli member.
 4. Tasks that have a zero taskTimeMilli should be removed from the circular list and destroyed.
 5. When a task is removed, the code should check the TaskPool array to see if any tasks need to be done.
 If so, the next task should be added to the circle.
 
 At this point, try to think of some strategies to do this processing.
 See the attached diagram for what I am looking for.
 
 */

#include <iostream>
#include <iomanip>
#include <ios>
using namespace std;

/**
 * Class that represents a node
 */
class TaskNode {
    
public:
    // Functions
    bool isCompleted();
    
    // Constructors
    TaskNode(int m);  // Constructor with parameters
    TaskNode();       // Default constructor
    
    int milliseconds;
    TaskNode* next;
};

/** constructor */
TaskNode::TaskNode() {
    next         = NULL;
}

/** constructor */
TaskNode::TaskNode(int m) {
    milliseconds = m;
    next         = NULL;
}

/**
 * Returns true if the task is completed
 */
bool TaskNode::isCompleted() {
    
    if (milliseconds <= 0) {
        cout << "Task #" << this << " completed " << this->milliseconds << endl << endl;
        return true;
    }
    return false;
}

/**
 * Class that represents a circular linked list
 */
class TaskList {
public:
    // Address of the beginning of the list
    TaskNode* head;
    int maxSize;
    int size;
    int timeSlice;
    
    // Functions
    void addNode(TaskNode* node);
    bool isEmpty();
    bool isFull();
    void loadPool(TaskNode[]);
    void showAll();
    
    // Default constructor
    TaskList();
};

/** Default constructor */
TaskList::TaskList() {
    head = NULL;
    maxSize = 3;
    timeSlice = 10;
    size = 0;
}

/**
 * Add a new node to the beginning of the list.
 */
void TaskList::addNode(TaskNode* newNode) {
    
    if (isFull()) {
        cout << "Could not add a node because the list is full" << endl;
        return;
    }
    
    // Case1: Empty list
    if (head == NULL) {
        head       = newNode;  // The new node becomes the head.
        head->next = newNode;  // next is itself
        
        // Case2: Non-empty list
    } else {
        // Go to the last node.
        TaskNode* curr = head;
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
    size++;
    cout << "Size updated to " << size << endl << endl;
}

/**
 * Add a pool of TaskNode objects to the list.
 * Last element's milliseconds is expected to be -1.
 *
 * 1. Add nodes until the max size
 * 2. Run the circular list
 * 3. Switch tasks every time slice
 * 4. Reload the list when one task is completed and removed
 * 5. Repeat until all the tasks are completed and removed
 */
void TaskList::loadPool(TaskNode* pool) {
    TaskNode* curr;
    TaskNode* temp;
    
    int i = 0;
    bool isPoolEmpty = false;
    
    // Keep on adding nodes until the end of the pool is reached
    while ( !isPoolEmpty || !isEmpty() ) {
        
        // Check if the pool is empty
        if ( pool[i].milliseconds == -1 ) {
            isPoolEmpty = true;
            cout << "isPoolEmpty = true;" << endl;
            
            // Add a node unless the stack is full
        } else {
            while ( !isFull() ) {
                addNode( &pool[i] );
                showAll();
                i++; // Move the cursor to next item in the pool
            }
        }
        
        // Repeat performing the tasks until one node is completed and disconnected
        curr = head;
        while ( !isEmpty() ) {
            
            // Subtract msecs (Performing a task)
            curr->milliseconds -= timeSlice;
            
            if ( curr->next->isCompleted() ) {
                // Remember the node to disconnect
                temp = curr->next;
                
                // Disconnect the node
                curr->next = curr->next->next;
                temp->next = NULL;
                
                // Decrement the size
                size--;
                cout << "Size updated to " << size << endl << endl;
                
                // Update the head if head is the one that was disconnected
                if ( temp == head ) {
                    head = curr->next;
                }
                
                showAll();
                
                // Exit the loop
                break;
                
                // Move the cursor to next in order to add a new node
            } else {
                curr = curr->next;
            }
        }
    }
    cout << "Outside the loop" << endl;
    showAll();
    
    return;
}

/**
 * Returns true if the list is empty.
 */
bool TaskList::isEmpty() {
    return size == 0;
}

/**
 * Returns true if the list is full.
 */
bool TaskList::isFull() {
    return size == maxSize;
}

/**
 * Print all the elements in the list to the console.
 */
void TaskList::showAll() {
    
    // Return if the list is empty
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    
    // Print the attributes names.
    cout << left;
    cout << setw(16) << "   pid";
    cout << right;
    cout << setw(8)  << "msec";
    cout << setw(16) << "next";
    cout << endl;
    
    // Draw a horizonal rule.
    cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    
    // Traverse the list until the end of the list.
    TaskNode* curr   = head;
    bool isEndOfList = false;
    
    while (!isEndOfList) {
        // Print current node
        cout << left;
        cout << setw(16) << curr;
        cout << right;
        cout << setw(8) << curr->milliseconds;
        cout << setw(16) << curr->next;
        cout << endl;
        
        if (curr->next != head) {
            curr = curr->next;  // Move the cursor to next and continue.
        } else {
            isEndOfList = true; // Exit the loop.
        }
    }
    
    cout << "--- end of the list ---" << endl << endl;
}

/**
 * Utility function to draw a horizontal seperator.
 */
void drawLine(int n) {
    cout << endl;
    cout << setfill('~') << setw(n) << "" << setfill(' ') << endl;
    cout << endl;
}

int main() {
    
    // 1. Dynamically create a circular linked list
    
    TaskList* tasks = new TaskList();
    
    // 2. Load and run a pool of nodes
    
    TaskNode pool[] = {
        TaskNode(30),
        TaskNode(22),
        TaskNode(100),
        TaskNode(39),
        TaskNode(64),
        TaskNode(87),
        TaskNode(34),
        TaskNode(53),
        TaskNode(-1),  // Sentinel
    };
    
    tasks->loadPool(pool);
    
    drawLine(40);
    
    return 0;
}
