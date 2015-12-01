/*******************************************************************************

   CSCI-241C-01 Data structures
   bank_account_hashmap.cpp

   Name: Masatoshi Nishiguchi (N00263071)
   Date: 11/30/2015

 *******************************************************************************/

/*
- Assume that there is a list of BankAccts with centinnel node to indicate the end of the list.

- 1. Load them into a HashMap keyed by account number.
- 2. Use the hash function in class (Use 11 buckets)
- 3. At the end of the load,
    + go back through the buckets and
    + report how many collisions there were and how many empty buckets there are.
    + What do your results show about the hash function?
 */

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;


/**
 * BankAcct is a class that represents an bank account.
 */
class BankAcct {
public:
    BankAcct(string custName,
             string custGender,
             string acctType,
             double acctBalance,
             int acctId);

    ~BankAcct();

    // Accessers.
    string getCustName() const { return custName; }
    string getCustGender() const { return custGender; }
    string getAcctType() const { return acctType; }
    double getAcctBalance() const { return acctBalance; }
    int getAcctId() const { return acctId; }

    BankAcct* next;

private:
    string custName;
    string custGender;
    string acctType;
    double acctBalance;
    int acctId;
};


/**
 *  @param custName    Name of account holder
 *  @param custGender  m or f
 *  @param acctType    C=checking, S=savings, CD=certificate of deposit
 *  @param acctBalance
 *  @param acctId
 */
BankAcct::BankAcct(string custName,
                   string custGender,
                   string acctType,
                   double acctBalance,
                   int acctId) {

    this->next        = NULL;

    this->custName    = custName;
    this->custGender  = custGender;
    this->acctType    = acctType;
    this->acctBalance = acctBalance;
    this->acctId      = acctId;

    // DEBUG
    // cout << "Account created: #" << this->acctId   << " "
    //                              << this->custName << endl;
}


BankAcct::~BankAcct() {
    // DEBUG
    // cout << "Account destructed: #" << this->acctId   << " "
    //                              << this->custName << endl;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * BankAcctStack is a class that represents a stack of BankAcct nodes.
 */
class BankAcctStack {
public:
    BankAcctStack();
    ~BankAcctStack();

    // Instance methods.
    int getSize() const;
    bool isEmpty() const;
    BankAcct* peek() const;
    bool push(BankAcct* account);
    void removeAll();
    void removeFirst();
    void printAll() const;
    void incrementSize() { size++; }
    void decrementSize() { size--; }

private:
    int size;
    BankAcct* top;  // First node
};

/**
 * Default constructor.
 */
BankAcctStack::BankAcctStack() {
    top  = NULL;
    size = 0;

    // DEBUG
    // cout << "BankAcctStack created." << endl;
}

/**
 * Destructor.
 */
BankAcctStack::~BankAcctStack() {
    // DEBUG
    // cout << "BankAcctStack is about to be destructed." << endl;

    removeAll();
}

/**
 * @return the current size of the stack.
 */
int BankAcctStack::getSize() const {
    return size;
}

/**
 * @return true if the stack is empty.
 */
bool BankAcctStack::isEmpty() const {
    return top == NULL;  // return !top; works also.
}

/**
 * @return the BankAcct node that is currently at the top of the stack.
 */
BankAcct* BankAcctStack::peek() const {
    return top;
}

/**
 * Adds a node at the top of the stack.
 * The new node becomes the top of the stack.
 * @param newNode a BankAcct that is to be pushed into the BankAcctStack.
 * @return true if successful, else false.
 */
bool BankAcctStack::push(BankAcct* newNode) {

    if ( isEmpty() ) {
        top = newNode;

    } else {
        newNode->next = top;
        top           = newNode;
    }

    incrementSize();

    return true;
}

/**
 * Empties the stack deleting all the node from memory (if not already empty).
 */
void BankAcctStack::removeAll() {

    while ( !isEmpty() ) {
        removeFirst();
    }
}

/**
 * Deletes the top node from memory.
 */
void BankAcctStack::removeFirst() {

    // Ensure that an empty stack was rejected.
    if ( isEmpty() ) {
        // DEBUG
        // cout << "The stack is empty." << endl;

        return;
    }

    BankAcct* temp = top;        // Remember the current top.
    top            = top->next;  // Next node becomes top.

    // DEBUG
    // cout << temp->getCustName() << "is about to be destructed." << endl;

    delete temp;

    decrementSize();
}

/**
 * Prints the information on all the BankAcct instances to the console.
 */
void BankAcctStack::printAll() const {

    // Return if the stack is empty.
    if (isEmpty()) {
        cout << "The stack is empty." << endl;
        return;
    }

    // Print the stack size.
    cout << "Size: " << size << endl;
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
    BankAcct* curr = top;
    while (curr != NULL) {
        cout << left  << setw(12) << curr->getCustName()
             << right << setw(12) << curr->getAcctType()
                      << setw(12) << curr->getAcctBalance() << endl;

        curr = curr->next;  // Move the cursor to next.
    }
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


// Holds the total number of the buckets.
const int NUM_BUCKETS = 11;


/**
 * Class that represents the United accountBuckets.
 */
class BankHashMap {
public:
    BankHashMap();

    // Instance methods.
    void addAcct(BankAcct& account) const;
    void addAccts(BankAcct* accounts) const;
    void getCollisionData(int* collisionList);
    int getHash(BankAcct account) const;
    int getNumAccounts() const;
    void printAccts() const;

    // Instance variables.
    BankAcctStack* accountBuckets[ NUM_BUCKETS ];  // An array of top pointers of the stacks.
};


/**
 * Constructor to create a node with a specific set of data
 */
BankHashMap::BankHashMap() {

    // NOTE: The array accountBuckets must be initialized.
    for (int i = 0; i < NUM_BUCKETS; i++) {
        accountBuckets[i] = new BankAcctStack;
    }
}


/**
 * @param collisionList an int array on which the data will be written.
 */
void BankHashMap::getCollisionData(int* collisionList) {

    // Map the size of each stack to the collisionList.
    for (int i = 0; i < NUM_BUCKETS; i++) {
        collisionList[i] = accountBuckets[i]->getSize();
    }
}


/**
 * Hash function based on the algorithm used in Java.
 * http://stackoverflow.com/questions/15518418/whats-behind-the-hashcode-method-for-string-in-java
 * h(s) = s[0]   * 31^(n-1)
 *      + s[1]   * 31^(n-2)
 *      + ...
 *      + s[n-1] * 31^(n-n)
 *   # s[i] denotes the ith character of the string
 *   # n is the length of s
 * https://en.wikipedia.org/wiki/Java_hashCode()
 * @param
 * @param
 * @return
 */
int BankHashMap::getHash(BankAcct account) const {

    int hash = 0;

    // Get the key that is to be used for hashing.
    string key = to_string( account.getAcctId() );

    // Get the key length.
    int len  = (int)key.length();

    // Compute the hash.
    for (int i = 0; i < len; i++) {

        hash += key[0] * pow( 31.0, double(len - i) );

    }

    return hash;
}


/**
 * @return a total number of the account in the BankHashMap.
 */
int BankHashMap::getNumAccounts() const {
    int count = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        count += accountBuckets[i]->getSize();
    }

    return count;
}


/**
 * @param account
 */
void BankHashMap::addAcct(BankAcct& account) const {

    // Allocate the index.
    int hash = getHash(account) % NUM_BUCKETS;

    // DEBUG
    // cout << "hash: " << hash << endl;

    // Add the item to the appropriate element of the list.
    BankAcctStack* stack = accountBuckets[ hash ];

    stack->push(&account);
}


/**
 * @param accounts
 */
void BankHashMap::addAccts(BankAcct* accounts) const {

    // NOTE: the sentinel record of `BankAcct("","N","N",0,-1)` indicates that
    // the end of the list has been reached.
    int i = 0;
    while (accounts[i].getCustName() != ""
        && accounts[i].getAcctType() != "N"
        && accounts[i].getAcctId()   != -1 ) {

        addAcct( accounts[i] );

        i++;  // Update the counter.
    }
}


/**
 *  Prints the information on all the BankAcct instances in the BankHashMap.
 */
void BankHashMap::printAccts() const {

    for (int i = 0; i < NUM_BUCKETS; i++) {
        cout << "\nStack#" << i << endl;
        accountBuckets[i]->printAll();
    }
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


int main() {

    // Data to be processed.

    cout << "\n1. Reading account data................";
    BankAcct accts[] = {
        BankAcct("Nancy","f","C",8.20,72),
        BankAcct("Melvin","m","C",78.23,73),
        BankAcct("Verna","f","CD",8277.00,74),
        BankAcct("Ellen","f","S",23.57,75),
        BankAcct("Gordon","m","C",66.17,76),
        BankAcct("Benjamin","m","S",23.91,77),
        BankAcct("Hillery","m","C",20.00,78),
        BankAcct("Bradford","m","C",0.12,79),
        BankAcct("Jesse","m","C",41.02,80),
        BankAcct("Pratt","m","c",0.00,81),
        BankAcct("Peter","m","S",49872.40,82),
        BankAcct("Graham","m","S",12.68,83),
        BankAcct("Eli","m","CD",8277.00,84),
        BankAcct("Kimberly","f","C",100.00,85),
        BankAcct("Rebecca","f","C",1177.71,86),
        BankAcct("Dale","m","C",58.94,87),
        BankAcct("Andrew","m","C",123.17,88),
        BankAcct("Wallace","m","C",19.99,89),
        BankAcct("Edward","m","CD",98382.45,90),
        BankAcct("Amos","m","C",92811.84,91),
        BankAcct("Chase","m","S",12.04,92),
        BankAcct("Verna","f","S",1802.00,93),
        BankAcct("Sanjay","m","S",20.00,94),
        BankAcct("John","m","C",0.00,95),
        BankAcct("Zoe","f","S",34.00,96),
        BankAcct("Kelly","f","S",102.00,97),
        BankAcct("Alex","f","S",13982.00,98),
        BankAcct("Alex","f","C",1098.47,99),
        BankAcct("Alex","m","C",529.34,100),
        BankAcct("Sally","f","S",1.98,101),
        BankAcct("Jessie","f","C",478.82,102),
        BankAcct("Julia","f","S",0.00,103),
        BankAcct("Dante","m","S",256.70,104),
        BankAcct("Lewis","m","S",1.01,105),
        BankAcct("Raphael","m","C",6720.00,106),
        BankAcct("Myren","m","C",6727.00,107),
        BankAcct("Francis","m","S",2371.00,108),
        BankAcct("Lamar","m","C",200.12,109),
        BankAcct("Quinton","m","C",25.34,110),
        BankAcct("Paul","m","C",197.42,111),
        BankAcct("James","m","C",5.40,1),
        BankAcct("John","m","S",0.00,2),
        BankAcct("Sally","f","C",0.00,3),
        BankAcct("Mary","f","S",1.80,4),
        BankAcct("Delphine","f","C",92.00,5),
        BankAcct("Robert","m","S",86.00,6),
        BankAcct("Joseph","m","C",31.31,7),
        BankAcct("Stanley","m","C",7.00,8),
        BankAcct("Marsha","f","S",873.73,9),
        BankAcct("Bernie","f","S",884.44,10),
        BankAcct("Marcus","m","C",66.87,11),
        BankAcct("Mei-Ling","f","S",20.50,12),
        BankAcct("Arturus","m","C",893.00,13),
        BankAcct("Katherine","f","C",4721.00,14),
        BankAcct("Michael","m","CD",245.00,15),
        BankAcct("Michelle","f","S",175.00,16),
        BankAcct("Jean-Michel","m","C",3416.00,17),
        BankAcct("Dante","m","C",1624.00,18),
        BankAcct("Harold","m","S",266.77,19),
        BankAcct("Betsy","f","S",19.05,20),
        BankAcct("Richard","m","C",19.00,21),
        BankAcct("Ronald","m","S",55.55,22),
        BankAcct("Wayne","m","C",746.00,23),
        BankAcct("Kevin","m","S",823.00,24),
        BankAcct("Phillip","m","C",28.00,25),
        BankAcct("Brutus","m","C",98.99,26),
        BankAcct("Betty","f","C",2349.34,27),
        BankAcct("Tyrone","m","S",1.19,28),
        BankAcct("Schelly","f","S",1.01,29),
        BankAcct("Brian","m","C",2.59,30),
        BankAcct("Cameron","m","S",2.99,31),
        BankAcct("David","m","S",238.10,32),
        BankAcct("Amy","f","S",300.01,33),
        BankAcct("Jacob","m","S",70.00,34),
        BankAcct("Alex","f","CD",29931.54,35),
        BankAcct("Rafael","m","C",6727.00,36),
        BankAcct("Reginald","m","C",200.00,37),
        BankAcct("Tamra","f","S",100.00,38),
        BankAcct("Kelly","m","S",100.00,39),
        BankAcct("Hazel","f","CD",140.00,40),
        BankAcct("Zoe","f","C",2323.00,41),
        BankAcct("Piper","f","C",1233.10,42),
        BankAcct("Kenneth","m","C",499.00,43),
        BankAcct("Pierre","m","C",234.00,44),
        BankAcct("Carlos","m","C",0.01,45),
        BankAcct("George","m","C",23.62,46),
        BankAcct("Jorge","m","S",463.90,47),
        BankAcct("Juan","m","CD",5092.30,48),
        BankAcct("Lewis","m","C",0.01,49),
        BankAcct("Deborah","f","CD",1007.93,50),
        BankAcct("Scott","m","C",702.88,51),
        BankAcct("Adrian","m","C",22.64,52),
        BankAcct("Brooks","m","C",792.00,53),
        BankAcct("Avery","m","S",904.69,54),
        BankAcct("Hillary","f","S",1000.00,55),
        BankAcct("William","m","C",12.01,56),
        BankAcct("Ezra","m","C",17.00,57),
        BankAcct("Jason","m","C",18.60,58),
        BankAcct("Sanjay","m","C",19.32,59),
        BankAcct("Matthew","m","S",26.00,60),
        BankAcct("Daniel","m","C",400.00,61),
        BankAcct("Julia","f","C",87230.00,62),
        BankAcct("Xavier","m","C",10.00,64),
        BankAcct("Yannick","m","CD",20100.64,65),
        BankAcct("Joel","m","C",398.55,66),
        BankAcct("DeJean","m","C",23.44,67),
        BankAcct("Paul","m","S",2.01,68),
        BankAcct("Fran","f","S",782.90,69),
        BankAcct("Ingrid","f","CD",9243.92,70),
        BankAcct("Enid","f","C",432.10,71),
        BankAcct("","N","N",0,-1)  //sentinel
    };
    cout << "done." << endl;
    cout << endl;

    // Create a map to store accounts.

    cout << "\n2. Creating a BankHashMap..............";
    BankHashMap map;
    cout << "done." << endl;
    cout << endl;

    // Add accounts to the map.

    cout << "\n3. Adding accounts to the map..........";
    map.addAccts( accts );
    cout << map.getNumAccounts() << " accounts added." << endl;
    cout << endl;

    // Print collisions.

    cout << "\n4. Printing collision counts..........." << endl;
    int collisionList[ NUM_BUCKETS ];
    map.getCollisionData( collisionList );

    for (int i = 0; i < NUM_BUCKETS; i++) {
        cout << "  " << setw(2) << i << ": "
                     << setw(2) << collisionList[i] << endl;
    }
    cout << ".......................................done." << endl;
    cout << endl;

    // Print all the accounts in the BankHashMap.

    cout << "\n5. Printing accounts in each stack....." << endl;
    map.printAccts();
    cout << ".......................................done." << endl;
    cout << endl;

    return 0;
}
