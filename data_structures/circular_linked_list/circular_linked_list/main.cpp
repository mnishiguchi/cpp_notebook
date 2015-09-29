//
//  main.cpp
//  circular_linked_list
//
//  Created by Masatoshi Nishiguchi on 9/28/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 * Class that represents a node
 */
class TaskNode {

public:
    // Constructor
    TaskNode(int m);

    // Member variables
    int milliseconds;
    TaskNode* next;
};

/** constructor */
TaskNode::TaskNode(int m) {
    milliseconds = m;
    next         = NULL;
}

/**
 * Class that represents a circular linked list
 */
class TaskList {
    public:
        // Addresses of the beginning the list
        TaskNode* head;

        // Function prototypes
        void addFirst(int m);
        void removeAll();
        void showAll();

        // Constructor
        TaskList();

        // Destructor
        ~TaskList();
};

// Default constructor
TaskList::TaskList() {
    head = NULL;
}

// Destructor
TaskList::~TaskList() {
    cout << "TaskList is about to be destructed" << endl;
    removeAll();
}

int main() {
    /*

    // When next node is done
    if (curr->next->milliseconds == NULL) {
        temp = curr->next->next
        delete curr_>next
    }

    // inserting a new node
    newNode->next
    temp

    */

    TaskNode pool[] = {
        TaskNode(30),
        TaskNode(22),
        TaskNode(100),
        TaskNode(39),
        TaskNode(64),
        TaskNode(87),
        TaskNode(34),
        TaskNode(53),
        TaskNode(-1),  // Sentinel value indicating end of the list
                       // https://en.wikipedia.org/wiki/Sentinel_value
    };

    TaskNode* head = NULL;

    return 0;
}
