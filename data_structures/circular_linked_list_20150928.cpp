//
//  main.cpp
//  circular_linked_list
//
//  Created by Masatoshi Nishiguchi on 9/28/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

class TaskNode {

public:
    // Constructor
    TaskNode(int m);

    // Member variables
    int milliSecond;
    TaskNode* next;
};

/** constructor */
TaskNode::TaskNode(int m) {
    milliSecond = m;
    next        = NULL;
}

int main() {
    /*
     # circular linked list
    - Used by many OS for managing tasks
    - Create one when needed
    - Delete when it is done

    // When next node is done
    if (curr->next->milliSecond == NULL) {
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
