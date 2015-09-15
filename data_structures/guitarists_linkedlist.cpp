//
//  guitarists_linked_list.cpp
//
//  Created by Masatoshi Nishiguchi on 9/12/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

// Represents a node of a linked list
class GuitaristNode {
public:
    // Fields
    string nickName;
    string guitar;
    
    // Address of the next node
    GuitaristNode* next;
    
    // Constructor
    GuitaristNode() {
        next = nullptr; // 0
    }
};

// Print a linked list from head to tail
void printGuitarists(GuitaristNode* head) {
    
    // Set the cursor to the head
    GuitaristNode* currentNode = head;
    
    // Print the entire list
    while (currentNode != nullptr) {
        cout << "Guitarist: "
        << currentNode->nickName
        << " using "
        << currentNode->guitar
        << endl;
        currentNode = currentNode->next;
    }
}


int main() {
    GuitaristNode* head;
    GuitaristNode* currentNode;
    GuitaristNode* temp;
    
    //==> Creating a list
    
    // Create first node
    currentNode = new GuitaristNode;
    currentNode->nickName = "Yngwie Malmsteen";
    currentNode->guitar   = "Stratocaster";
    
    // Give the address to the previous node
    head = currentNode;
    
    // Create second node
    currentNode = new GuitaristNode;
    currentNode->nickName = "Michael Schenker";
    currentNode->guitar   = "Flying V";
    
    // Give the address to the previous node
    head->next = currentNode;
    
    // Create third node
    currentNode = new GuitaristNode;
    currentNode->nickName = "Marty Friedmann";
    currentNode->guitar   = "Some nice guitar";
    
    // Give the address to the previous node
    head->next->next = currentNode;
    
    // Print the entire list
    printGuitarists(head);
    cout << "--------------------------------------------------------" << endl;
    
    //==> Deleting the first node
    
    // Remember the address of the new head
    temp = head->next;
    
    // Delete the node from the memory
    delete head;
    
    // Set the head to the new address
    head = temp;
    
    // Print the entire list
    printGuitarists(head);
    
    return 0;
}
