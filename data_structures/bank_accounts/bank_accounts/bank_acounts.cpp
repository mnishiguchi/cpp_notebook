/*****************************************************************************

   CSCI-241C-01 Data structures
   Mid-Term Exam
   bank_accounts.cpp

   Name: Masatoshi Nishiguchi (N00263071)
   Date: 10/14/2015

 *****************************************************************************

   This program creates a collection of bank accounts and process them several ways.
   Its basic functionalities are as follows:

   1. Reads the data of bank accounts from a file.
   2. For each account, dynamically creates a BankAccount object and
      adds it to an apporiate stack.
   3. If the assigned stack is full pops one and moves it to a side collection.
   4. After reading all the data, moves all the accounts to a side collection.
   5. Prompts user for a search key (name) and shows the result.
   6. Prints all the accounts.
   7. Deletes all the dynamically created objects out of memory.

 *****************************************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ios>
using namespace std;


/**
 * Class that represents an bank account. Functions as a node in a linked list.
 */
class BankAccount {
public:

    // Functions
    static int getInstanceCount() { return count; };

    // Constructor with parameters
    BankAccount(string acctName, string acctType, double balance);

    // Instance variables
    string acctName;
    string acctType;
    double acctBalance;
    int acctID;
    BankAccount* next;

private:
    static int count;
};

// Initialize the instance counter
int BankAccount::count = 0;

/** Constructor with parameters */
BankAccount::BankAccount(string name, string type, double balance) {
    next = NULL;
    acctName    = name;
    acctType    = type;
    acctBalance = balance;
    acctID      = ++count;

    cout << "Account created: #" << acctID << " " << acctName << endl;
}

//****************************************************************************

/**
 * Class that represents a linked list of BankAccount nodes.
 * In this particular program, this class is used for the side collection.
 */
class AccountLinkedList {
public:
    // Functions
    int getSize() const;
    bool isEmpty() const;
    void insertByName(BankAccount* account);
    BankAccount* peek() const;
    void removeAll();
    void removeFirst();
    void printAll() const;

    void incrementSize() { size++; }
    void decrementSize() { size--; }

    // Constructor
    AccountLinkedList();

    // Destructor
    ~AccountLinkedList();

private:
    int size;
    BankAccount* head;  // First node
};

/** Default constructor */
AccountLinkedList::AccountLinkedList() {
    head  = NULL;
    size = 0;
}

/** Destructor */
AccountLinkedList::~AccountLinkedList() {
    cout << "AccountLinkedList is about to be destructed." << endl;
    removeAll();
}

/**
 * Returns the current size of the stack.
 */
int AccountLinkedList::getSize() const {
    return size;
}

/**
 * Returns true if the stack is empty.
 */
bool AccountLinkedList::isEmpty() const {
    return head == NULL;
}

/**
 * Insert the specified account in an appropriate position so that the list is
 * alphabetically sorted by account name.
 * The list must be already sorted or empty in order to get the intended result.
 */
void AccountLinkedList::insertByName(BankAccount* newNode) {

    bool isFound;

    if(isEmpty()) {
        head = newNode;

    } else {
        BankAccount* curr      = head;
        BankAccount* trailCurr = NULL;

        // Case1: Insert before the first node
        if (newNode->acctName < head->acctName) {
            newNode->next = head;
            head          = newNode;

        // Case2: Search the list for the node before which we have to insert.
        } else {
            // Initialze the cursors.
            trailCurr = head;        // Initially pointing to the first node.
            curr      = head->next;  // Initially pointing to the second node.

            // Traverse the list until the insertion position is found.
            isFound = false;
            while (curr != NULL && !isFound) {
                if (curr->acctName < newNode->acctName) {
                    trailCurr = curr;
                    curr      = curr->next;

                } else {
                    isFound = true;
                }
            }

            // Insert the new node there.
            trailCurr->next = newNode;
            newNode->next   = curr;
        }
    }

    incrementSize();
}

/**
 * Returns the BankAccount node that is currently at the head of the stack.
 */
BankAccount* AccountLinkedList::peek() const {
    return head;
}

/**
 * Empties the stack deleting all the node from memory (if not already empty).
 */
void AccountLinkedList::removeAll() {
    while (!isEmpty()) {
        removeFirst();
    }
}

/**
 * Deletes the head node from memory.
 */
void AccountLinkedList::removeFirst() {

    if (isEmpty()) {
        cout << "The list is empty." << endl;
        return;
    }

    BankAccount* temp = head;        // Remember the current head
    head              = head->next;  // Next node becomes head

    cout << temp->acctName << " is about to be destructed." << endl;
    delete temp;

    decrementSize();
}

void AccountLinkedList::printAll() const {

    if (isEmpty()) {
        cout << "The list is empty." << endl;
        cout << "List size: " << size << endl;
        return;
    }

    // Print the list size.
    cout << "List size: " << size << endl;
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
    BankAccount* curr = head;
    while (curr != NULL) {
        cout << left  << setw(12) << curr->acctName
             << right << setw(12) << curr->acctType
                      << setw(12) << curr->acctBalance << endl;

        curr = curr->next;  // Move the cursor to next.
    }
}

//****************************************************************************

/**
 * Class that represents a stack of BankAccount nodes
 */
class AccountStack {
public:

    // Functions
    int getSize() const;
    bool isEmpty() const;
    bool isFull() const;
    BankAccount* peek() const;
    void popFirstTo(AccountLinkedList* sideCollection);
    bool push(BankAccount* account);
    void removeAll();
    void removeFirst();
    void printAll() const;

    void incrementSize() { size++; }
    void decrementSize() { size--; }

    // Constructor
    AccountStack();

    // Destructor
    ~AccountStack();

private:
    const int MAX_STACK_SIZE = 4;
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
    cout << "AccountStack is about to be destructed." << endl;
    removeAll();
}

/**
 * Returns the current size of the stack.
 */
int AccountStack::getSize() const {
    return size;
}

/**
 * Returns true if the stack is empty.
 */
bool AccountStack::isEmpty() const {
    return top == NULL;  // return !top; works also.
}

/**
 * Returns true if the stack is full.
 */
bool AccountStack::isFull() const {
    return size >= MAX_STACK_SIZE;
}

/**
 * Returns the BankAccount node that is currently at the top of the stack.
 */
BankAccount* AccountStack::peek() const {
    return top;
}

/**
 * Removes a top node from the stack and adds the node to a side collection.
 */
void AccountStack::popFirstTo(AccountLinkedList* sideCollection) {

    if (isEmpty()) {
        cout << "The stack is empty." << endl;
        return;
    }

    BankAccount* curr = top;        // Remember the top
    top               = top->next;  // Next node becomes top
    curr->next        = NULL;       // The popped node's next is NULL

    // Add the popped node to the side collection.
    sideCollection->insertByName(curr);
    decrementSize();

    cout << curr->acctName << " was transferred to a sideCollection." << endl;
}

/**
 * Adds a node at the top of the stack.
 * Returns true if successful, else false.
 */
bool AccountStack::push(BankAccount* newNode) {

    if (isFull()) {
        cout << "The stack is full." << endl;
        return false;
    }

    // The new node becomes the top of the stack in either case.

    if (isEmpty()) {    // Case1: Empty stack
        top = newNode;
    } else {            // Case2: Non-empty stack
        newNode->next = top;
        top           = newNode;
    }
    incrementSize();
    return true;
}

/**
 * Empties the stack deleting all the node from memory (if not already empty).
 */
void AccountStack::removeAll() {
    while (!isEmpty()) {
        removeFirst();
    }
}

/**
 * Deletes the top node from memory.
 */
void AccountStack::removeFirst() {

    if (isEmpty()) {
        cout << "The stack is empty." << endl;
        return;
    }

    BankAccount* temp = top;        // Remember the current top
    top               = top->next;  // Next node becomes top

    cout << temp->acctName << "is about to be destructed." << endl;
    delete temp;

    decrementSize();
}

void AccountStack::printAll() const {
    // Return if the stack is empty.
    if (isEmpty()) {
        cout << "The stack is empty." << endl;
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

//****************************************************************************

/**
 * Class that represents a bank
 */
class Bank {
public:

    // Functions
    void addAccount(BankAccount* account);
    int findIndexFor(string name) const;
    void moveAllToSideCollection();
    void printAccount(string acctName) const;

    // Destructor
    ~Bank() {
        cout << "Bank is about to be destructed." << endl;
        delete sideCollection;
    }

    /*
     + Element index 0: A-D
     + Element index 1: E-G
     + Element index 2: H-M
     + Element index 3: N-S
     + Element index 4: T-Z
     */
    const int NUM_STACKS = 5;
    string categories[5] = { "A-D", "E-G", "H-M", "N-S", "T-Z" };
    AccountStack acctStacks[5];
    AccountLinkedList* sideCollection = new AccountLinkedList;
};

/**
 * Returns an appropriate index of the accounts array for the specified account name.
 */
int Bank::findIndexFor(string name) const {

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
 * Adds the specified bank account to an appropreate stack.
 */
void Bank::addAccount(BankAccount* account) {

    // Determine the appropriate index based on the name.
    int index = findIndexFor(account->acctName);

    // Attempt top add the account to the stack.
    // If the push is unsuccessful, pop one to the side collection and retry.
    while (!acctStacks[index].push(account)) {
        acctStacks[index].popFirstTo(sideCollection);
    }

    cout << account->acctName << " pushed to the stack (" << categories[index] << ")" << endl;
}

/**
 * Transfers all the accounts in the stacks to a side collection.
 */
void Bank::moveAllToSideCollection() {
    for (int index = 0; index < NUM_STACKS; index++) {
        while (!acctStacks[index].isEmpty()) {
            acctStacks[index].popFirstTo(sideCollection);
        }
    }
}

/**
 * Outputs the balance and account type for an account that matches a name
 * passed as a parameter. If the name is not found, output the account data.
 * Does NOT search the side collection.
 */
void Bank::printAccount(string acctName) const {

    // Determine the appropriate index based on the name.
    int index = findIndexFor(acctName);

    // Formatting for floating-point numbers.
    cout << fixed << showpoint << setprecision(2);

    // Search for the item that matches the name.
    BankAccount* curr = acctStacks[index].peek();
    while (curr != NULL) {
        // If found, output the account data.
        if (curr->acctName == acctName) {
            cout << left  << setw(12) << curr->acctName
                 << right << setw(12) << curr->acctType
                          << setw(12) << curr->acctBalance << endl;
            cout << endl;
            return;
        } else {
            curr = curr->next;
        }
    }
    cout << "Name not found\n" << endl;
}

//****************************************************************************

/**
 * Utility function to draw a horizontal seperator.
 */
void drawLine() {
    cout << setfill('~') << setw(48) << "" << setfill(' ') << endl;
}

/**
 * The main function of this program.
 */
int main() {

    ifstream reader;

    // Temporary data containers for each line.
    char acctName[101], acctType[11];
    double acctBal;
    BankAccount* newAccount;

    // Create a bank
    Bank* bank = new Bank;

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

        //************************************************

        // Data validation (rejecting data with an empty string)
        if (acctName[0] == '\0' || acctType[0] == '\0') {
           cout << "Ignored data with empty name or empty type." << endl;
           continue;
        }

        // Create a new account with this data set and add to the bank.
        newAccount = new BankAccount(acctName, acctType, acctBal);
        bank->addAccount(newAccount);

        drawLine();

        // Clear the variables.
        acctName[0] = '\0';
        acctType[0] = '\0';
        acctBal     = NULL;

        //************************************************
    }
    reader.close();  // Close the file

    cout << "\n-----After reading all the data-----\n" << endl;

    // Print the total number of the bank accounts.
    int numAccounts = BankAccount::getInstanceCount();
    cout << "Total number of accounts: " << numAccounts << endl;

    // Print the number of account in each stack.
    for (int i = 0; i < bank->NUM_STACKS; i++) {
        cout << "Stack (" << bank->categories[i] << ") : " << bank->acctStacks[i].getSize() << endl;
    }

    // Print the number of account in the side collection.
    cout << "Side collection : " << bank->sideCollection->getSize() << endl;

    drawLine();

    cout << "\n-----Account search-----\n" << endl;

    // Prompt the user for an account names to be searched for.
    string searchName;

    for (;;) {
        cout << "Enter an accout name (hit enter to exit): ";
        getline(cin, searchName);
        if (!searchName.empty()) {
            bank->printAccount(searchName);
        } else {
            break;
        }
    }

//    cout << "\n-----Transfering the rest-----\n" << endl;
//
//    // Transfer all the accounts to a side collection.
//    cout << "Moving all the accounts in the stacks to a side collection.\n" << endl;
//    bank->moveAllToSideCollection();
//
//    drawLine();

    cout << "\n-----Stacks-----\n" << endl;

    // Print all the stacks.
    for (int i = 0; i < bank->NUM_STACKS; i++) {
        cout << "Stack (" << bank->categories[i] << ")" << endl;
        bank->acctStacks[i].printAll();
        drawLine();
    }

    cout << "\n-----Side collection-----\n" << endl;

    // Print the side collection.
    bank->sideCollection->printAll();

    drawLine();

    cout << "\n-----Clean up-----\n" << endl;

    // Delete all the dynamically created objects via bank.
    delete bank;

    return 0;
}
