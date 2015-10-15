/*
  CSCI-241C-01 Data structures
  Mid-Term Exam
  bank_accounts.cpp

  Name: Masatoshi Nishiguchi (N00263071)
  Date: 10/14/2015
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ios>
using namespace std;

/**
 * Class that represents an bank account.
 * Functions as a node in a linked list.
 */
class BankAccount {
public:
    // Constructor with parameters
    BankAccount(string acctName, string acctType, double balance);

    // Instance variables
    string acctName;
    string acctType;
    double acctBalance;
    BankAccount* next;
};

// Constructor with parameters
BankAccount::BankAccount(string name, string type, double balance) {
    next = NULL;
    acctName    = name;
    acctType    = type;
    acctBalance = balance;

    cout << "account created for " << acctName << endl;
}

/**
 * Class that represents a stack of BankAccount nodes
 */
class AccountStack {
public:
    // Functions
    int getSize();
    bool isEmpty();
    bool isFull();
    BankAccount* peek();
    void popFirstToSideCollection();
    void push(BankAccount* account);
    void removeAll();
    void removeFirst();
    void printAll();

    void incrementSize() { size++; }
    void decrementSize() { size--; }

    // Constructor
    AccountStack();

    // Destructor
    ~AccountStack();

private:
    const int MAX_SIZE = 4;
    int size;
    BankAccount* top;  // First node
};

/** Default constructor */
AccountStack::AccountStack() {
    top  = NULL;
    size = 0;
}

/** Destructor */
AccountStack::~AccountStack() {
    cout << "AccountStack is about to be destructed" << endl;
    removeAll();
}

/**
 * Returns the current size of the stack.
 */
int AccountStack::getSize() {
    return size;
}

/**
 * Returns true if the stack is empty.
 */
bool AccountStack::isEmpty() {
    return top == NULL;  // return !top; works also.
}

/**
 * Returns true if the stack is full.
 */
bool AccountStack::isFull() {
    return size >= MAX_SIZE;
}

/**
 * Returns the BankAccount node that is currently at the top of the stack.
 */
BankAccount* AccountStack::peek() {
    return top;
}

/**
 * TODO
 */
void AccountStack::popFirstToSideCollection() {
    // TODO
}

/**
 * Add a node at the top of the stack.
 */
void AccountStack::push(BankAccount* newNode) {

    // The new node becomes the top of the stack in either case.

    // Case1: Empty stack
    if (isEmpty()) {
        top = newNode;

    // Case2: Non-empty stack
    } else {
        newNode->next = top;
        top           = newNode;
    }

    incrementSize();
}

/**
 * Empty the stack deleting all the node from memory (if not already empty).
 */
void AccountStack::removeAll() {
    while (!isEmpty()) {
        removeFirst();
    }
}

/**
 * Delete the top node from memory.
 */
void AccountStack::removeFirst() {
    // Case1: Empty stack
    if (top == NULL) {
        cout << "The stack is empty." << endl;
        return;
    }

    // Case2: Non-empty stack
    BankAccount* temp = top;        // Remember the current top
    top               = top->next;  // Next node becomes top
    delete temp;

    decrementSize();
}

void AccountStack::printAll() {
    // Return if the stack is empty.
    if (top == NULL) {
        cout << "The stack is empty." << endl;
        cout << "Stack size: " << size << endl;
        return;
    }

    // Print the stack size.
    cout << "Stack size: " << size << endl;
    cout << endl;

    // Print the attributes names.
    cout << left  << setw(12) << "acctName"
         << right << setw(12) << "acctType"
                  << setw(12) << "acctBal" << endl;

    // Draw a horizonal line.
    cout << setfill('-') << setw(36) << "" << setfill(' ') << endl;

    // Formatting for floating-point numbers.
    cout << fixed << showpoint << setprecision(2);

    // Traverse the list and print each node.
    BankAccount* curr = top;
    while (curr != NULL) {
        cout << left  << setw(12) << curr->acctName
             << right << setw(12) << curr->acctType
                      << setw(12) << curr->acctBalance << endl;

        curr = curr->next;  // Move the cursor to next.
    }
}

/**
 * Class that represents a bank
 */
class Bank {
public:
    /*
     + Element index 0: A-D
     + Element index 1: E-G
     + Element index 2: H-M
     + Element index 3: N-S
     + Element index 4: T-Z
     */
    AccountStack accounts[5];
    string categories[5] = {"A-D", "E-G", "H-M", "N-S", "T-Z"};

    /**
     * Returns an appropriate index of the accounts array for the specified account name.
     */
    int findIndexFor(string name) {

        char initial = toupper(name[0]);
        if (initial >= 'A' && initial <= 'D') {
          return 0;
        } else if (initial >= 'E' && initial <= 'G') {
          return 1;
        } else if (initial >= 'H' && initial <= 'M') {
          return 2;
        } else if (initial >= 'N' && initial <= 'S') {
          return 3;
        } else if (initial >= 'T' && initial <= 'Z') {
          return 4;
        }

        // Error message
        cout << endl;
        cout << initial << " is an invalid initial for an account name." << endl;
        return -1;
    }

    /**
     * Add the specified bank account to an appropreate stack.
     */
    void addAccount(BankAccount* account) {
        // Determine the appropriate index based on the name.
        int index = findIndexFor(account->acctName);

        // Add the account to the stack.
        accounts[index].push(account);
        
        cout << account->acctName << " pushed to the stack (" << categories[index] << ")" << endl;
    }
};



int main() {

    ifstream reader;

    char acctName[101], acctType[11];
    double acctBal;

    // Print column names
    cout << left  << setw(12) << "acctName"
         << right << setw(12) << "acctType"
                  << setw(12) << "acctBal" << endl;

    // Open the appropriate file
    reader.open("/Users/masa/data_cpp_exercises/bank_data.txt");

    // Loop will terminate once there is no more data to read from file
    while(!reader.eof()) {

        // Reads the name of the account holder into acctName
        reader.getline(acctName, 100, ',');

        // Reads the account type of the account into acctType
        reader.getline(acctType, 10, ',');

        // Reads the balance into acctBal
        reader >> acctBal;

        reader.ignore();

        /************************************************

         In this section, fill the appropriate BankAccount instance with values retrieved
              (acctName, acctType, acctBal)

         ************************************************/


        // Print data for each person
        cout << fixed << showpoint << setprecision(2);
        cout << left  << setw(12) << acctName
             << right << setw(12) << acctType
                      << setw(12) << acctBal << endl;

        // Clear the temporary storage
        acctName[0] = '\0';
        acctType[0] = '\0';
        acctBal = NULL;
    }
    reader.close();   // Close the file

    return 0;
}
