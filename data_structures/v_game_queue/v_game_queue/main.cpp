//
//  main.cpp
//  v_game_queue
//
//  Created by Masatoshi Nishiguchi on 10/5/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

/*
    Implementation of a queue using an array of pointers as a data structure
 
 Queueing analysis
 - Air port
 - Restaurant
 */

/**
 * Class that represents a node
 */
class VGameNode {
public:
    string title;
    string genre;
    int minAge;
    
    VGameNode* next;
    
    // Constructors
    VGameNode();
    VGameNode(string title, string genre, int minAge);
};


class VGameQueue {
public:
    VGameNode* games;
    
    int headIndex;
    int tailIndex;
    int arraySize;
    
    VGameQueue() {
        headIndex = -1;
        tailIndex = -1;
        arraySize = 5;
        
        games = new VGameNode[arraySize];
    }
    
    /**
     * Add a node at the back of the queue.
     */
    void pushBack(string title, string genre, int minAge) {
        

        // Case1: Empty list
        if (headIndex < 0) {
            headIndex = 0;
            tailIndex = 0;
            
        // Case2: Non-empty list
        } else {
            // Ensure that the queus is not full
            if (tailIndex < arraySize - 1) {
                tailIndex++;  // Go to the next element
            } else {
                cout << "No more room!" << endl;
                return;
            }
    
        }
        
        games[tailIndex].title  = title;
        games[tailIndex].genre  = genre;
        games[tailIndex].minAge = minAge;
  
        
    }
};



//int isQueueFull(int tail, int size) {
//    return tail == size - 1;
//}


int main() {
//    const int CAPACITY = 10;  // Fixed size

    
//    // Create an array
//    int* list = new int[CAPACITY];
    
    
    
    
    

    return 0;
}
