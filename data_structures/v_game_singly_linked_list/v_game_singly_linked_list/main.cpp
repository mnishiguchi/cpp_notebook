//
//  main.cpp
//  v_game_singly_linked_list
//
//  Created by Masatoshi Nishiguchi on 9/16/15.
//  Copyright (c) 2015 Masatoshi Nishiguchi. All rights reserved.
//

#include <iostream>
using namespace std;

// Represents a node
class VGameNode {
    
public:
    
    // Fields
    string title;
    string genre;
    int minAge;
    
    // Address of the next node
    VGameNode* next;
    
    // Constructor
    VGameNode() {
        next = NULL;
    }
};

// Represents a linked list
class VGameList {
    
public:
    
    VGameNode* head;
    VGameList() {
        head = NULL;
    }
    
    /**
     * Based on the code I got from Mr. Belcher
     * TODO
     */
    void insertGameByTitle(string title, string genre, int minAge) {
        
        VGameNode* node = new VGameNode();
        node->genre   = genre;
        node->minAge  = minAge;
        node->title   = title;
        
        bool found;
        
        if(head == 0) {
            head = node;
        
        } else {
            VGameNode *curr=head, *trailCurr=0;
            
            // insert before first item
            if (node->title < head->title) {
                node->next = head;
                head = node;
            
            //search the list for the node before where we have to insert
            } else {
                found = false;
                
                trailCurr = head;        //set trailCurrent to point to the first node
                curr      = head->next;  //set current to point to the second node
                
                while (curr != NULL && !found) {
                    
                    if (curr->title < node->title) {
                        trailCurr = curr;
                        curr      = curr->next;
                        
                    } else {
                        found = true;
                    }
                }//end while
                
                trailCurr->next = node;
                node->next = curr;
            }//end else
        }//end else
    }
    
    void addGame(string title, string genre, int minAge) {
        
        VGameNode* node = new VGameNode;
        node->title  = title;
        node->genre  = genre;
        node->minAge = minAge;
        
        // Head is the only element at the moment
        if (head == NULL) {
            head = node;
            
        } else {
            VGameNode* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            
            // node is NULL here
            
            curr->next = node;
        }
    }
    
    void removeByTitle(string titleToDelete) {
        
        VGameNode* curr;      // Pointer to traverse the list
        VGameNode* trailCurr; // Pointer to remember the previous node
        
        bool found;
        
        if (head == NULL) {
            cout << "Cannot delele from an empty list" << endl;
            
        } else {
            if (head->title == titleToDelete) {
                curr = head;
                head = head->next;
                
                delete curr;
                
            } else {
                found = false;
                
                trailCurr = head;
                curr      = head->next;
                
                while (curr != NULL && !found) {
                    // Found????
                    if (curr->title != titleToDelete) {
                        trailCurr = curr;
                        curr      = curr->next;
                        
                    } else {
                        found = true;
                    }
                }
                
                if (found) {
                    // Update the next pointer of the node before the one to be deleted
                    trailCurr->next = curr->next;
                    
                    // Delete the node
                    delete curr;
                    
                    // Thee whole list was exhausted
                } else {
                    cout << "The item to be deleted is not in the list" << endl;
                }
            }
        }
    }
    
    void showGames() {
        
        // The cursor
        VGameNode* curr = head;
        
        while (curr != NULL) {
            // Print a game at a time
            cout << "Game: " << curr->title << endl;
            
            // Move the cursor to next
            curr = curr->next;
        }
    }
};

int main() {
    
    VGameList myGames;
    
    myGames.insertGameByTitle("Donkey kong jr", "Some genre", 10);
    myGames.insertGameByTitle("Packman", "Some genre", 10);
    myGames.insertGameByTitle("Super Mario bros", "Some genre", 10);
    myGames.insertGameByTitle("Zelda", "Some genre", 10);
    myGames.insertGameByTitle("FF", "Some genre", 10);
    myGames.insertGameByTitle("Street Fighter", "Some genre", 10);
    
    myGames.showGames();
    
    cout << "------------------------------------------" << endl;
    
    myGames.removeByTitle("Zelda");
    myGames.removeByTitle("Packman");
    
    myGames.showGames();
    
    return 0;
}
