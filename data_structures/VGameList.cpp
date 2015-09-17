//
//  VGameList.cpp
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
        next = NULL;  // 0
    }

};

// Represents a linked list
class VGameList {
public:
    VGameNode* head;
    VGameList() {
        head = NULL;
    }
    
    void addGame(string title, string genre, int minAge) {
        VGameNode* node = new VGameNode;
        node->title = title;
        node->genre = genre;
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
    
    myGames.addGame("Some title12", "Some genre", 10);
    myGames.addGame("Some title23", "Some genre", 10);
    myGames.addGame("Some title34", "Some genre", 10);
    myGames.addGame("Some title45", "Some genre", 10);
    myGames.addGame("Some title56", "Some genre", 10);
    myGames.addGame("Some title67", "Some genre", 10);
    
    myGames.showGames();
    
    cout << "------------------------------------------" << endl;
    
    myGames.removeByTitle("Some title45");
    myGames.removeByTitle("Some title67");
    
    myGames.showGames();
    
    return 0;
}
