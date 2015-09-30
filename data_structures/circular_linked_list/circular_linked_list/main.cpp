//
//  main.cpp
//  circular_linked_list
//
//  Created by Masatoshi Nishiguchi on 9/28/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <ios>
using namespace std;

/**
 * Class that represents a node
 */
class TaskNode {

public:
    bool isCompleted();
    TaskNode(int m);  // Constructor with parameters
    TaskNode();       // Default constructor

    int milliseconds;
    TaskNode* next;
};

/** constructor */
TaskNode::TaskNode(int m) {
    milliseconds = m;
    next         = NULL;
}

/**
 * Returns true if the task is completed
 */
bool TaskNode::isCompleted() {

    // TODO
    if (milliseconds <= 0) {
        cout << "Task #" << this << " completed" << endl;
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

    // Functions
    void addNode(TaskNode* node);
    void addPool(TaskNode[]);
    void removeAll();
    void run();
    void showAll();

    // Default constructor
    TaskList();

    // Destructor
    ~TaskList();
};

/** Default constructor */
TaskList::TaskList() {
    head = NULL;
}

/** Destructor */
TaskList::~TaskList() {
    cout << "TaskList is about to be destructed" << endl;
    removeAll();
}

/**
 * Add a new node to the beginning of the list.
 */
void TaskList::addNode(TaskNode* newNode) {

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
}

/**
 * Add a pool of TaskNode objects to the list.
 * Last element's milliseconds is expected to be -1.
 */
void TaskList::addPool(TaskNode* pool) {

    // Keep on adding nodes until the end is reached.
    for (int i = 0; pool[i].milliseconds != -1; i++) {
        addNode(&pool[i]);
    }
}

/**
 * Remove all the elements in the list.
 */
void TaskList::removeAll() {

    // TODO

}

/**
 * Run the scheduler.
 */
void TaskList::run() {
    
//    // TODO
//    // When next node is done
//    if (this->next->milliseconds == NULL) {
//        temp = this->next->next
//        delete this->next
//    }
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
    cout << setw(8) << "msec";
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

    cout << "--- end of the list ---" << endl;
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

    // 2. Add nodes individually

    tasks->addNode(new TaskNode(12));
    tasks->showAll();

    drawLine(40);

    tasks->addNode(new TaskNode(24));
    tasks->showAll();

    drawLine(40);

    // 3. Add a pool of nodes
    
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
    
    tasks->addPool(pool);
    tasks->showAll();
    
    drawLine(40);
    
    return 0;
}
