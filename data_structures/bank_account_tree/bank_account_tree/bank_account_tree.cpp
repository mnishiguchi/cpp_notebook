/*****************************************************************************

   CSCI-241C-01 Data structures
   bank_account_tree.cpp

   Name: Masatoshi Nishiguchi (N00263071)
   Date: 11/10/2015

   This program demonstrates a binary search tree of hypothetical bank accounts.

    == Validations ==
    - A person with same name and gender is a single person.
    - A single person can NOT have multiple accounts of the same type.
    - The account number must be unique.

 *****************************************************************************/

/*
Analysis

1) What key would you use and why? (5 pts)

=== Key to be used ===
As a key, I would use jointly name and gender of a Customer object.
The Customer class holds as members name, gender and list of pointers to
his/her account(s). Customer objects will function as nodes of a binary tree.

=== Reason ===
That way, once a Customer has been found in the tree, we can access the other
accounts that belongs to the same account holder.
The user of the program is very likely to inspect different accounts that
the same account holder has.

2) Assume that you expect to get many requests for your BankAcct instances
where only the name and account type is known.
Does your answer somehow change?  How so?  (5 pts)

=== My answer change? ===
No. My implementation lets us access all the accounts that belongs to him/her
once we have found a Customer in the binary search tree.
I would further improve the Customer class's internals
so that we can get quick access to each customer's account whenever necessary.
For constant access, we could use map of accout type to account pointer; however
I decided to use vector in this particular project because we only have 3 account
types and vector's linear search will not significantly affect performance.
Also, using vector, we can keep our code simple.

3) Assume your key is the account number.
What problems will you potentially face when retrieving the data from your BST
(again, assume the data has been loaded in the order shown.)?
What could you do to fix the problem(s), if any?
Hint: you should pay attention to the actual values of the account numbers in the array.  (10 pts)

=== Potential problems ===
If we use the account number as a key in the binary search tree, we would have
difficulty accessing different accounts that the same account holder holds.
Assuming we do not have any information other than this binary search tree,
everytime we search for an account, it will require full scan on the entire tree.

=== How to fix ===
My solution is to use name and gender of a Customer object as keys in the tree
as mentioned in Question 1), then create a map of account number to account pointer
in the static field so that we can keep track of the account number while
achieving efficient searching by account holder name and gender.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

/*================================================
  Class declaration
=================================================*/

class Customer;
class BankAcct;
class BankBSTree;

/**
 *  Class that represents an account holder, which has links to BankAcct objects.
 */
class Customer {
public:
    Customer(BankAcct account);
    Customer(string custName, string gender, BankAcct account);

    bool addAccount(BankAcct account);
    BankAcct* getBankAcct(string acctType);
    vector<BankAcct> getBankAccts() { return accounts; }

    string custName;
    string gender;

    Customer* l_link;
    Customer* r_link;

private:
    vector<BankAcct> accounts;
};

/**
 *  Class that represents an bank account.
 */
class BankAcct {
public:
    BankAcct(string name, string gender,
             string acctType, double balance, int acctId);
    ~BankAcct();

    // Functions
    string getCustName() const { return customer->custName; }
    string getCustGender() const { return customer->gender; }
    string getAcctType() const { return acctType; }
    double getBalance() const { return balance; }
    int getAcctId() const { return acctId; }
    void printAcct() const;

    // Keep track of the registered account IDs
    static BankAcct* getAcct(int acctId);
    static bool isTakenAcctId(int acctId);
    static void printAllRegisteredAccts();

private:
    Customer* customer;
    string acctType;
    double balance;
    int acctId;

    // Keep track of the registered account IDs
    static map<int, BankAcct*> acctDictionary;
};

/**
 *  Class that represents a binary search tree of Customers.
 */
class BankBSTree {
public:
    BankBSTree();
    ~BankBSTree();

    // Public functions
    void destroyTree();
    void insertAcct(BankAcct account);
    void insertAccts(BankAcct accounts[]);
    void printAll() const;

    Customer* search(string custName, string gender) const;
    Customer* search(int acctId) const;

private:
    void destroyTree(Customer* node);
    void insert(Customer* cusToInsert, Customer *node);
    void printAll(Customer *node) const;
    Customer* search(string custName, string gender, Customer* node) const;
    Customer* search(int acctId, Customer* node) const;
    Customer* root;
};

/*================================================
  Implementation of class Customer
=================================================*/

/**
 *  Constructor of the Customer class
 */
Customer::Customer(BankAcct account) {
    this->custName = account.getCustName();
    this->gender   = account.getCustGender();
    this->accounts.push_back(account);

    l_link = NULL;
    r_link = NULL;
}

/**
 *  Constructor of the Customer class
 */
Customer::Customer(string custName, string gender, BankAcct account) {
    this->custName = custName;
    this->gender   = gender;
    this->accounts.push_back(account);

    l_link = NULL;
    r_link = NULL;
}

/**
 *  @param account
 *  @return true if the adding is successful; else false
 */
bool Customer::addAccount(BankAcct account) {
  bool acctAlreadyExists = getBankAcct( account.getAcctType() );
  if ( !acctAlreadyExists ) {
    accounts.push_back(account);
    return true;  // Success
  }
  cout << "Error adding an account" << endl;
  return false;   // Fail
}

/**
 *  @param acctType
 *  @return true if this Customer instance already has the specified account type
 */
BankAcct* Customer::getBankAcct(string acctType) {
    int len = (int)accounts.size();
    for ( int i = 0; i < len; i++ ) {
        if ( accounts.at(i).getAcctType() == acctType ) {
            cout << custName << " has " << acctType << endl;
            return &accounts.at(i);
        }
    }
    return NULL;
}

/*================================================
  Implementation of class BankAcct
=================================================*/

// Initialize the static map to keep track of all the used IDs
map<int, BankAcct*> BankAcct::acctDictionary;

/**
 *  Constructor of the BankAcct class
 *  @param Name of account holder
 *  @param gender(m or f)
 *  @param account type (C=checking, S=savings, CD=certificate of deposit)
 *  @param account balance, account number
 */
BankAcct::BankAcct(string name, string gender, string acctType,
                   double balance, int acctId) {

    // Reject if acctId is already taken (Ignore sentinel -1)
    if (acctId > 0 && isTakenAcctId(acctId)) {
        cout << "Error creating BankAcct - acctId was taken" << endl;
        return;
    }

    this->customer = new Customer(name, gender, *this);
    this->acctType = acctType;
    this->balance  = balance;
    this->acctId   = acctId;

    // Keep track of the used ids
    if (acctId > 0) {
        acctDictionary[ acctId ] = this;
    }

    // Report the user about the accout that has been created
    cout << "Account created: #" << acctId << " " << name << endl;
}

BankAcct::~BankAcct() {
    //acctDictionary.erase(acctId); // Unregister from the acctDictionary
}

/**
 *  A static function to obtain the pointer to a BankAcct with the specified account ID
 *  @param acctId
 *  @return pointer to a BankAcct with the specified account ID or false if nonexistent
 */
BankAcct* BankAcct::getAcct(int acctId) {
    cout << "Searching for Account#" << setw(4) << acctId << "......";
    BankAcct* acct = acctDictionary.find(acctId)->second;
    cout << ((acct) ? " Found!!!!!!" : " not found") << endl;
    return acct;
}

/**
 *  A static function to check the availability of the specified account ID
 *  @param acctId
 *  @return true if the specified ID is available; false otherwise
 */
bool BankAcct::isTakenAcctId(int acctId) {
    bool isTaken = (getAcct(acctId) == NULL) ? false : true;
    cout << acctId << ((isTaken) ? ": Taken" : ": Available") << endl;
    return isTaken;
}

/**
 *  A static function to print all the currently issued IDs
 */
void BankAcct::printAllRegisteredAccts() {
    for (auto it : acctDictionary) {
        cout << setfill(' ') << right;
        cout << setw(4)  << it.first
             << setw(12) << it.second->customer->custName
             << setw(4)  << it.second->customer->gender
             << setw(4)  << it.second->getAcctType()
             << fixed << setprecision(2)
             << setw(10) << it.second->getBalance()
             << endl;
    }
}

/**
 *  A static function to print all the currently issued IDs
 */
void BankAcct::printAcct() const {
    cout << setfill(' ') << right;
    cout << setw(4)  << getAcctId()
         << setw(12) << getCustName()
         << setw(4)  << getCustGender()
         << setw(4)  << getAcctType()
         << fixed << setprecision(2)
         << setw(10) << getBalance()
         << endl;
}

/*================================================
  Implementation of class BankBSTree
=================================================*/

/**
 *  Constructor of the BankBSTree class
 */
BankBSTree::BankBSTree() {
    root = NULL;
    cout << "A new binary tree was created" << endl;
}

/**
 *  Destructor of the BankBSTree class
 *  Deletes all the nodes of the tree.
 */
BankBSTree::~BankBSTree() {
    destroyTree();
    cout << "Deletion completed" << endl;
}

/** PUBLIC
 *  Initializes the tree.
 *  The recursive destroyTree function deletes all the nodes of the tree.
 */
void BankBSTree::destroyTree() {
    cout << "Initializing the tree..." << endl;
    destroyTree(root);
}

/** PRIVATE
 *  Recursively goes to the bottom of each part of the tree,
 *  deletes that node, and then works its way back up.
 *  @param node the root node of a subtree
 */
void BankBSTree::destroyTree(Customer* node) {
    if(node != NULL) {  // Base case: Stop recursion when node is NULL
        destroyTree(node->l_link);  // Go to the left child and delete all
        destroyTree(node->r_link);  // Go to the right child and delete all
        cout << "Deleting " << node->custName << "..." << endl;
        delete node; // Delete this node
    }
}

/** PUBLIC
 *  Inserts the specified array of BankAccts into the tree.
 *  Note: Sentinel `BankAcct("","N","N",0,-1)`
 *  @param an instance of BankAcct class
 */
void BankBSTree::insertAccts( BankAcct accounts[] ) {
    int idx = 0;
    while (!(accounts[idx].getCustName()   == ""  &&
             accounts[idx].getCustGender() == "N" &&
             accounts[idx].getAcctType()   == "N" &&
             accounts[idx].getBalance()    ==  0  &&
             accounts[idx].getAcctId()     == -1)) {

        insertAcct(accounts[idx]);
        cout << endl;

        idx += 1;  // Update the index
    }
}

/** PUBLIC
 *  Inserts the specified data of BankAcct type into the tree.
 *  @param an instance of BankAcct class
 */
void BankBSTree::insertAcct(BankAcct account) {

    // Search for the same holder (same name, same gender).
    Customer* customer = search(account.getCustName(), account.getCustGender());

    // Case1: If the holder already exists -> attempt to push this account into that holder.
    if (customer != NULL) {
        if ( customer->addAccount(account) ) {
            cout << account.getAcctType() << " was pushed to "
                 << account.getCustName() << endl;
        }
        return;
    }

    // Case2: If the holder is new -> create a new node and insert it into the tree.
    Customer* cusToInsert = new Customer(account);

    if(root != NULL) {  // If root exists in the tree
        insert(cusToInsert, root);
    } else {            // If root does not exist in the tree
        cout << "Setting " << account.getCustName()
             << " as a root of the tree" << endl;
        root = cusToInsert;
    }
}

/** PRIVATE
 *  Inserts a new node into the specified sub-tree.
 *  @param cusToInsert an Customer object to be inserted
 *  @param node the root node of a subtree
 */
void BankBSTree::insert(Customer* cusToInsert, Customer* node) {
    cout << left;  // Set output formatting

    // Go to the left child
    if (cusToInsert->custName < node->custName) {

        if(node->l_link != NULL) {
            insert(cusToInsert, node->l_link);
        } else {
            cout << "Inserting "
                 << setw(10) << cusToInsert->custName << " under "
                 << setw(10) << node->custName << " on the left" << endl;
            node->l_link = cusToInsert;
        }
    }
    // Go to the right child
    else if(cusToInsert->custName >= node->custName) {

        if(node->r_link != NULL) {
            insert(cusToInsert, node->r_link);
        } else {
            cout << "Inserting "
                 << setw(10) << cusToInsert->custName << " under "
                 << setw(10) << node->custName << " on the right" << endl;
            node->r_link = cusToInsert;
        }
    }
    cout << right;  // Reset output formatting
}

/** PUBLIC
 *  Prints all the nodes in the tree.
 */
void BankBSTree::printAll() const {
    printAll(root);
}

/** PRIVATE
 *  Prints all the nodes in the tree.
 *  @param node the root node of a subtree.
 */
void BankBSTree::printAll(Customer* node) const {
    // Base case: Deadend
    if (node == NULL) {
        return;
    }

    // Recursively go down the tree and check each node in the path.
    printAll(node->l_link);
    printAll(node->r_link);

    // Print customer info
    cout << setfill(' ') << left;
    cout << setw(12) << node->custName
         << setw(4)  << node->gender
         << endl;

    // Print all the accounts
    cout << setfill(' ') << right;
    vector<BankAcct> accts = node->getBankAccts();
    for (auto acct : accts) {
        cout << "    "
             << setw(4)  << acct.getAcctType()
             << fixed << setprecision(2)
             << setw(10) << acct.getBalance()
             << endl;
    }

    // Separator line
    cout << setfill('-') << setw(30) << "" << setfill(' ') << endl;
}

/** PUBLIC
 *  Public method to search for the specified key in the tree.
 *  @param custName a search key
 *  @param gender a search key
 *  @return a pointer to the Customer if found; otherwise NULL
 */
Customer* BankBSTree::search(string custName, string gender) const {
    return search(custName, gender, root);
}

/** PRIVATE
 *  Searches for the node in the specified sub-tree by custName and gender.
 *  @param custName a search key
 *  @param gender a search key
 *  @param node the root node of a subtree.
 *  @return a pointer to the Customer if found; otherwise NULL
 */
Customer* BankBSTree::search(string custName, string gender, Customer* node) const {
    cout << left << setfill('.');  // Set output formatting

    // Base case1: Deadend
    if (node == NULL) {
        cout << setw(16) << custName + " (" + gender  + ")" << "not found" << endl;
        return NULL;
    }

    // Base case2: If found, return the pointer to that node
    if( (custName == node->custName) && (gender == node->gender) ) {
        cout << setw(16) << custName + " (" + gender  + ")" << "FOUND!!!!!!" << endl;
        return node;
    }

    cout << right << setfill(' ');  // Reset output formatting

    // Recursively go down the tree and check each node in the path.
    if (custName < node->custName) {
        return search(custName, gender, node->l_link);
    } else {
        return search(custName, gender, node->r_link);
    }
}

/*================================================
  The main
=================================================*/

int main() {

    cout << "\n===Creating an array of BankAccts===\n" << endl;

    // Note: the sentinel record  - `BankAcct("","N","N",0,-1)`
    BankAcct accts[]={
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

    cout << "\n===Creating a binary tree===\n" << endl;

    BankBSTree bst;

    cout << "\n===Inserting all the accounts into the tree===\n" << endl;

    bst.insertAccts( accts );

    cout << "\n===Trying to insert a dupulicate===\n" << endl;

    bst.insertAcct( accts[0] );

    cout << "\n===Searching by name and gender===\n" << endl;

    bst.search("Julia", "f");
    bst.search("Julia", "m");

    cout << "\n===Searching by account ID===\n" << endl;

    BankAcct* temp;

    temp = BankAcct::getAcct(231);
    if (temp != NULL) temp->printAcct();

    temp = BankAcct::getAcct(45);
    if (temp != NULL) temp->printAcct();

    temp = BankAcct::getAcct(999);
    if (temp != NULL) temp->printAcct();

    temp = BankAcct::getAcct(111);
    if (temp != NULL) temp->printAcct();

    cout << "\n===Printing all the node in the tree===\n" << endl;

    bst.printAll();

    cout << "\n===Printing the list of registered accounts===\n" << endl;

    BankAcct::printAllRegisteredAccts();

    cout << "\n===End of the program===\n" << endl;

    return 0;
}

/*
Sample output

===Creating an array of BankAccts===

Searching for Account#  72...... not found
72: Available
Account created: #72 Nancy
Searching for Account#  73...... not found
73: Available
Account created: #73 Melvin
Searching for Account#  74...... not found
74: Available
Account created: #74 Verna
Searching for Account#  75...... not found
75: Available
Account created: #75 Ellen
Searching for Account#  76...... not found
76: Available
Account created: #76 Gordon
Searching for Account#  77...... not found
77: Available
Account created: #77 Benjamin
Searching for Account#  78...... not found
78: Available
Account created: #78 Hillery
Searching for Account#  79...... not found
79: Available
Account created: #79 Bradford
Searching for Account#  80...... not found
80: Available
Account created: #80 Jesse
Searching for Account#  81...... not found
81: Available
Account created: #81 Pratt
Searching for Account#  82...... not found
82: Available
Account created: #82 Peter
Searching for Account#  83...... not found
83: Available
Account created: #83 Graham
Searching for Account#  84...... not found
84: Available
Account created: #84 Eli
Searching for Account#  85...... not found
85: Available
Account created: #85 Kimberly
Searching for Account#  86...... not found
86: Available
Account created: #86 Rebecca
Searching for Account#  87...... not found
87: Available
Account created: #87 Dale
Searching for Account#  88...... not found
88: Available
Account created: #88 Andrew
Searching for Account#  89...... not found
89: Available
Account created: #89 Wallace
Searching for Account#  90...... not found
90: Available
Account created: #90 Edward
Searching for Account#  91...... not found
91: Available
Account created: #91 Amos
Searching for Account#  92...... not found
92: Available
Account created: #92 Chase
Searching for Account#  93...... not found
93: Available
Account created: #93 Verna
Searching for Account#  94...... not found
94: Available
Account created: #94 Sanjay
Searching for Account#  95...... not found
95: Available
Account created: #95 John
Searching for Account#  96...... not found
96: Available
Account created: #96 Zoe
Searching for Account#  97...... not found
97: Available
Account created: #97 Kelly
Searching for Account#  98...... not found
98: Available
Account created: #98 Alex
Searching for Account#  99...... not found
99: Available
Account created: #99 Alex
Searching for Account# 100...... not found
100: Available
Account created: #100 Alex
Searching for Account# 101...... not found
101: Available
Account created: #101 Sally
Searching for Account# 102...... not found
102: Available
Account created: #102 Jessie
Searching for Account# 103...... not found
103: Available
Account created: #103 Julia
Searching for Account# 104...... not found
104: Available
Account created: #104 Dante
Searching for Account# 105...... not found
105: Available
Account created: #105 Lewis
Searching for Account# 106...... not found
106: Available
Account created: #106 Raphael
Searching for Account# 107...... not found
107: Available
Account created: #107 Myren
Searching for Account# 108...... not found
108: Available
Account created: #108 Francis
Searching for Account# 109...... not found
109: Available
Account created: #109 Lamar
Searching for Account# 110...... not found
110: Available
Account created: #110 Quinton
Searching for Account# 111...... not found
111: Available
Account created: #111 Paul
Searching for Account#   1...... not found
1: Available
Account created: #1 James
Searching for Account#   2...... not found
2: Available
Account created: #2 John
Searching for Account#   3...... not found
3: Available
Account created: #3 Sally
Searching for Account#   4...... not found
4: Available
Account created: #4 Mary
Searching for Account#   5...... not found
5: Available
Account created: #5 Delphine
Searching for Account#   6...... not found
6: Available
Account created: #6 Robert
Searching for Account#   7...... not found
7: Available
Account created: #7 Joseph
Searching for Account#   8...... not found
8: Available
Account created: #8 Stanley
Searching for Account#   9...... not found
9: Available
Account created: #9 Marsha
Searching for Account#  10...... not found
10: Available
Account created: #10 Bernie
Searching for Account#  11...... not found
11: Available
Account created: #11 Marcus
Searching for Account#  12...... not found
12: Available
Account created: #12 Mei-Ling
Searching for Account#  13...... not found
13: Available
Account created: #13 Arturus
Searching for Account#  14...... not found
14: Available
Account created: #14 Katherine
Searching for Account#  15...... not found
15: Available
Account created: #15 Michael
Searching for Account#  16...... not found
16: Available
Account created: #16 Michelle
Searching for Account#  17...... not found
17: Available
Account created: #17 Jean-Michel
Searching for Account#  18...... not found
18: Available
Account created: #18 Dante
Searching for Account#  19...... not found
19: Available
Account created: #19 Harold
Searching for Account#  20...... not found
20: Available
Account created: #20 Betsy
Searching for Account#  21...... not found
21: Available
Account created: #21 Richard
Searching for Account#  22...... not found
22: Available
Account created: #22 Ronald
Searching for Account#  23...... not found
23: Available
Account created: #23 Wayne
Searching for Account#  24...... not found
24: Available
Account created: #24 Kevin
Searching for Account#  25...... not found
25: Available
Account created: #25 Phillip
Searching for Account#  26...... not found
26: Available
Account created: #26 Brutus
Searching for Account#  27...... not found
27: Available
Account created: #27 Betty
Searching for Account#  28...... not found
28: Available
Account created: #28 Tyrone
Searching for Account#  29...... not found
29: Available
Account created: #29 Schelly
Searching for Account#  30...... not found
30: Available
Account created: #30 Brian
Searching for Account#  31...... not found
31: Available
Account created: #31 Cameron
Searching for Account#  32...... not found
32: Available
Account created: #32 David
Searching for Account#  33...... not found
33: Available
Account created: #33 Amy
Searching for Account#  34...... not found
34: Available
Account created: #34 Jacob
Searching for Account#  35...... not found
35: Available
Account created: #35 Alex
Searching for Account#  36...... not found
36: Available
Account created: #36 Rafael
Searching for Account#  37...... not found
37: Available
Account created: #37 Reginald
Searching for Account#  38...... not found
38: Available
Account created: #38 Tamra
Searching for Account#  39...... not found
39: Available
Account created: #39 Kelly
Searching for Account#  40...... not found
40: Available
Account created: #40 Hazel
Searching for Account#  41...... not found
41: Available
Account created: #41 Zoe
Searching for Account#  42...... not found
42: Available
Account created: #42 Piper
Searching for Account#  43...... not found
43: Available
Account created: #43 Kenneth
Searching for Account#  44...... not found
44: Available
Account created: #44 Pierre
Searching for Account#  45...... not found
45: Available
Account created: #45 Carlos
Searching for Account#  46...... not found
46: Available
Account created: #46 George
Searching for Account#  47...... not found
47: Available
Account created: #47 Jorge
Searching for Account#  48...... not found
48: Available
Account created: #48 Juan
Searching for Account#  49...... not found
49: Available
Account created: #49 Lewis
Searching for Account#  50...... not found
50: Available
Account created: #50 Deborah
Searching for Account#  51...... not found
51: Available
Account created: #51 Scott
Searching for Account#  52...... not found
52: Available
Account created: #52 Adrian
Searching for Account#  53...... not found
53: Available
Account created: #53 Brooks
Searching for Account#  54...... not found
54: Available
Account created: #54 Avery
Searching for Account#  55...... not found
55: Available
Account created: #55 Hillary
Searching for Account#  56...... not found
56: Available
Account created: #56 William
Searching for Account#  57...... not found
57: Available
Account created: #57 Ezra
Searching for Account#  58...... not found
58: Available
Account created: #58 Jason
Searching for Account#  59...... not found
59: Available
Account created: #59 Sanjay
Searching for Account#  60...... not found
60: Available
Account created: #60 Matthew
Searching for Account#  61...... not found
61: Available
Account created: #61 Daniel
Searching for Account#  62...... not found
62: Available
Account created: #62 Julia
Searching for Account#  64...... not found
64: Available
Account created: #64 Xavier
Searching for Account#  65...... not found
65: Available
Account created: #65 Yannick
Searching for Account#  66...... not found
66: Available
Account created: #66 Joel
Searching for Account#  67...... not found
67: Available
Account created: #67 DeJean
Searching for Account#  68...... not found
68: Available
Account created: #68 Paul
Searching for Account#  69...... not found
69: Available
Account created: #69 Fran
Searching for Account#  70...... not found
70: Available
Account created: #70 Ingrid
Searching for Account#  71...... not found
71: Available
Account created: #71 Enid
Account created: #-1

===Creating a binary tree===

A new binary tree was created

===Inserting all the accounts into the tree===

Nancy (f).......not found
Setting Nancy as a root of the tree

Melvin (m)......not found
Inserting Melvin.... under Nancy..... on the left

Verna (f).......not found
Inserting Verna..... under Nancy..... on the right

Ellen (f).......not found
Inserting Ellen..... under Melvin.... on the left

Gordon (m)......not found
Inserting Gordon.... under Ellen..... on the right

Benjamin (m)....not found
Inserting Benjamin.. under Ellen..... on the left

Hillery (m).....not found
Inserting Hillery... under Gordon.... on the right

Bradford (m)....not found
Inserting Bradford.. under Benjamin.. on the right

Jesse (m).......not found
Inserting Jesse..... under Hillery... on the right

Pratt (m).......not found
Inserting Pratt..... under Verna..... on the left

Peter (m).......not found
Inserting Peter..... under Pratt..... on the left

Graham (m)......not found
Inserting Graham.... under Hillery... on the left

Eli (m).........not found
Inserting Eli....... under Bradford.. on the right

Kimberly (f)....not found
Inserting Kimberly.. under Jesse..... on the right

Rebecca (f).....not found
Inserting Rebecca... under Pratt..... on the right

Dale (m)........not found
Inserting Dale...... under Eli....... on the left

Andrew (m)......not found
Inserting Andrew.... under Benjamin.. on the left

Wallace (m).....not found
Inserting Wallace... under Verna..... on the right

Edward (m)......not found
Inserting Edward.... under Dale...... on the right

Amos (m)........not found
Inserting Amos...... under Andrew.... on the left

Chase (m).......not found
Inserting Chase..... under Dale...... on the left

Verna (f).......FOUND!!!!!!
S was pushed to Verna

Sanjay (m)......not found
Inserting Sanjay.... under Rebecca... on the right

John (m)........not found
Inserting John...... under Kimberly.. on the left

Zoe (f).........not found
Inserting Zoe....... under Wallace... on the right

Kelly (f).......not found
Inserting Kelly..... under John...... on the right

Alex (f)........not found
Inserting Alex...... under Amos...... on the left

Alex (f)........FOUND!!!!!!
C was pushed to Alex

Alex (m)........not found
Inserting Alex...... under Alex...... on the right

Sally (f).......not found
Inserting Sally..... under Sanjay.... on the left

Jessie (f)......not found
Inserting Jessie.... under John...... on the left

Julia (f).......not found
Inserting Julia..... under Kelly..... on the left

Dante (m).......not found
Inserting Dante..... under Edward.... on the left

Lewis (m).......not found
Inserting Lewis..... under Kimberly.. on the right

Raphael (m).....not found
Inserting Raphael... under Rebecca... on the left

Myren (m).......not found
Inserting Myren..... under Melvin.... on the right

Francis (m).....not found
Inserting Francis... under Gordon.... on the left

Lamar (m).......not found
Inserting Lamar..... under Lewis..... on the left

Quinton (m).....not found
Inserting Quinton... under Raphael... on the left

Paul (m)........not found
Inserting Paul...... under Peter..... on the left

James (m).......not found
Inserting James..... under Jesse..... on the left

John (m)........FOUND!!!!!!
S was pushed to John

Sally (f).......FOUND!!!!!!
C was pushed to Sally

Mary (f)........not found
Inserting Mary...... under Lewis..... on the right

Delphine (f)....not found
Inserting Delphine.. under Dante..... on the right

Robert (m)......not found
Inserting Robert.... under Sally..... on the left

Joseph (m)......not found
Inserting Joseph.... under Julia..... on the left

Stanley (m).....not found
Inserting Stanley... under Sanjay.... on the right

Marsha (f)......not found
Inserting Marsha.... under Mary...... on the left

Bernie (f)......not found
Inserting Bernie.... under Bradford.. on the left

Marcus (m)......not found
Inserting Marcus.... under Marsha.... on the left

Mei-Ling (f)....not found
Inserting Mei-Ling.. under Mary...... on the right

Arturus (m).....not found
Inserting Arturus... under Andrew.... on the right

Katherine (f)...not found
Inserting Katherine. under Julia..... on the right

Michael (m).....not found
Inserting Michael... under Myren..... on the left

Michelle (f)....not found
Inserting Michelle.. under Michael... on the right

Jean-Michel (m).not found
Inserting Jean-Michel under James..... on the right

Dante (m).......FOUND!!!!!!
C was pushed to Dante

Harold (m)......not found
Inserting Harold.... under Graham.... on the right

Betsy (f).......not found
Inserting Betsy..... under Bernie.... on the right

Richard (m).....not found
Inserting Richard... under Robert.... on the left

Ronald (m)......not found
Inserting Ronald.... under Robert.... on the right

Wayne (m).......not found
Inserting Wayne..... under Zoe....... on the left

Kevin (m).......not found
Inserting Kevin..... under Kelly..... on the right

Phillip (m).....not found
Inserting Phillip... under Peter..... on the right

Brutus (m)......not found
Inserting Brutus.... under Chase..... on the left

Betty (f).......not found
Inserting Betty..... under Betsy..... on the right

Tyrone (m)......not found
Inserting Tyrone.... under Stanley... on the right

Schelly (f).....not found
Inserting Schelly... under Stanley... on the left

Brian (m).......not found
Inserting Brian..... under Brutus.... on the left

Cameron (m).....not found
Inserting Cameron... under Brutus.... on the right

David (m).......not found
Inserting David..... under Delphine.. on the left

Amy (f).........not found
Inserting Amy....... under Amos...... on the right

Jacob (m).......not found
Inserting Jacob..... under James..... on the left

Alex (f)........FOUND!!!!!!
CD was pushed to Alex

Rafael (m)......not found
Inserting Rafael.... under Quinton... on the right

Reginald (m)....not found
Inserting Reginald.. under Richard... on the left

Tamra (f).......not found
Inserting Tamra..... under Tyrone.... on the left

Kelly (m).......not found
Inserting Kelly..... under Kevin..... on the left

Hazel (f).......not found
Inserting Hazel..... under Harold.... on the right

Zoe (f).........FOUND!!!!!!
C was pushed to Zoe

Piper (f).......not found
Inserting Piper..... under Phillip... on the right

Kenneth (m).....not found
Inserting Kenneth... under Kelly..... on the right

Pierre (m)......not found
Inserting Pierre.... under Piper..... on the left

Carlos (m)......not found
Inserting Carlos.... under Cameron... on the right

George (m)......not found
Inserting George.... under Francis... on the right

Jorge (m).......not found
Inserting Jorge..... under Joseph.... on the left

Juan (m)........not found
Inserting Juan...... under Joseph.... on the right

Lewis (m).......FOUND!!!!!!
C was pushed to Lewis

Deborah (f).....not found
Inserting Deborah... under David..... on the right

Scott (m).......not found
Inserting Scott..... under Schelly... on the right

Adrian (m)......not found
Inserting Adrian.... under Alex...... on the left

Brooks (m)......not found
Inserting Brooks.... under Brian..... on the right

Avery (m).......not found
Inserting Avery..... under Arturus... on the right

Hillary (f).....not found
Inserting Hillary... under Hazel..... on the right

William (m).....not found
Inserting William... under Wayne..... on the right

Ezra (m)........not found
Inserting Ezra...... under Francis... on the left

Jason (m).......not found
Inserting Jason..... under Jean-Michel on the left

Sanjay (m)......FOUND!!!!!!
C was pushed to Sanjay

Matthew (m).....not found
Inserting Matthew... under Mei-Ling.. on the left

Daniel (m)......not found
Inserting Daniel.... under Dante..... on the left

Julia (f).......FOUND!!!!!!
C was pushed to Julia

Xavier (m)......not found
Inserting Xavier.... under William... on the right

Yannick (m).....not found
Inserting Yannick... under Xavier.... on the right

Joel (m)........not found
Inserting Joel...... under Jessie.... on the right

DeJean (m)......not found
Inserting DeJean.... under Deborah... on the left

Paul (m)........FOUND!!!!!!
S was pushed to Paul

Fran (f)........not found
Inserting Fran...... under Ezra...... on the right

Ingrid (f)......not found
Inserting Ingrid.... under Jacob..... on the left

Enid (f)........not found
Inserting Enid...... under Ezra...... on the left


===Trying to insert a dupulicate===

Nancy (f).......FOUND!!!!!!
Nancy has C
Error adding an account

===Searching by name and gender===

Julia (f).......FOUND!!!!!!
Julia (m).......not found

===Searching by account ID===

Searching for Account#231....... not found
Searching for Account#45........ Found!!!!!!
  45      Carlos   m   C      0.01
Searching for Account# 999...... not found
Searching for Account# 111...... Found!!!!!!
 111        Paul   m   C    197.42

===Printing all the node in the tree===

Adrian      m
       C     22.64
------------------------------
Alex        m
       C    529.34
------------------------------
Alex        f
       S  13982.00
       C   1098.47
      CD  29931.54
------------------------------
Amy         f
       S    300.01
------------------------------
Amos        m
       C  92811.84
------------------------------
Avery       m
       S    904.69
------------------------------
Arturus     m
       C    893.00
------------------------------
Andrew      m
       C    123.17
------------------------------
Betty       f
       C   2349.34
------------------------------
Betsy       f
       S     19.05
------------------------------
Bernie      f
       S    884.44
------------------------------
Brooks      m
       C    792.00
------------------------------
Brian       m
       C      2.59
------------------------------
Carlos      m
       C      0.01
------------------------------
Cameron     m
       S      2.99
------------------------------
Brutus      m
       C     98.99
------------------------------
Chase       m
       S     12.04
------------------------------
Daniel      m
       C    400.00
------------------------------
DeJean      m
       C     23.44
------------------------------
Deborah     f
      CD   1007.93
------------------------------
David       m
       S    238.10
------------------------------
Delphine    f
       C     92.00
------------------------------
Dante       m
       S    256.70
       C   1624.00
------------------------------
Edward      m
      CD  98382.45
------------------------------
Dale        m
       C     58.94
------------------------------
Eli         m
      CD   8277.00
------------------------------
Bradford    m
       C      0.12
------------------------------
Benjamin    m
       S     23.91
------------------------------
Enid        f
       C    432.10
------------------------------
Fran        f
       S    782.90
------------------------------
Ezra        m
       C     17.00
------------------------------
George      m
       C     23.62
------------------------------
Francis     m
       S   2371.00
------------------------------
Hillary     f
       S   1000.00
------------------------------
Hazel       f
      CD    140.00
------------------------------
Harold      m
       S    266.77
------------------------------
Graham      m
       S     12.68
------------------------------
Ingrid      f
      CD   9243.92
------------------------------
Jacob       m
       S     70.00
------------------------------
Jason       m
       C     18.60
------------------------------
Jean-Michel m
       C   3416.00
------------------------------
James       m
       C      5.40
------------------------------
Joel        m
       C    398.55
------------------------------
Jessie      f
       C    478.82
------------------------------
Jorge       m
       S    463.90
------------------------------
Juan        m
      CD   5092.30
------------------------------
Joseph      m
       C     31.31
------------------------------
Katherine   f
       C   4721.00
------------------------------
Julia       f
       S      0.00
       C  87230.00
------------------------------
Kenneth     m
       C    499.00
------------------------------
Kelly       m
       S    100.00
------------------------------
Kevin       m
       S    823.00
------------------------------
Kelly       f
       S    102.00
------------------------------
John        m
       C      0.00
       S      0.00
------------------------------
Lamar       m
       C    200.12
------------------------------
Marcus      m
       C     66.87
------------------------------
Marsha      f
       S    873.73
------------------------------
Matthew     m
       S     26.00
------------------------------
Mei-Ling    f
       S     20.50
------------------------------
Mary        f
       S      1.80
------------------------------
Lewis       m
       S      1.01
       C      0.01
------------------------------
Kimberly    f
       C    100.00
------------------------------
Jesse       m
       C     41.02
------------------------------
Hillery     m
       C     20.00
------------------------------
Gordon      m
       C     66.17
------------------------------
Ellen       f
       S     23.57
------------------------------
Michelle    f
       S    175.00
------------------------------
Michael     m
      CD    245.00
------------------------------
Myren       m
       C   6727.00
------------------------------
Melvin      m
       C     78.23
------------------------------
Paul        m
       C    197.42
       S      2.01
------------------------------
Pierre      m
       C    234.00
------------------------------
Piper       f
       C   1233.10
------------------------------
Phillip     m
       C     28.00
------------------------------
Peter       m
       S  49872.40
------------------------------
Rafael      m
       C   6727.00
------------------------------
Quinton     m
       C     25.34
------------------------------
Raphael     m
       C   6720.00
------------------------------
Reginald    m
       C    200.00
------------------------------
Richard     m
       C     19.00
------------------------------
Ronald      m
       S     55.55
------------------------------
Robert      m
       S     86.00
------------------------------
Sally       f
       S      1.98
       C      0.00
------------------------------
Scott       m
       C    702.88
------------------------------
Schelly     f
       S      1.01
------------------------------
Tamra       f
       S    100.00
------------------------------
Tyrone      m
       S      1.19
------------------------------
Stanley     m
       C      7.00
------------------------------
Sanjay      m
       S     20.00
       C     19.32
------------------------------
Rebecca     f
       C   1177.71
------------------------------
Pratt       m
       c      0.00
------------------------------
Yannick     m
      CD  20100.64
------------------------------
Xavier      m
       C     10.00
------------------------------
William     m
       C     12.01
------------------------------
Wayne       m
       C    746.00
------------------------------
Zoe         f
       S     34.00
       C   2323.00
------------------------------
Wallace     m
       C     19.99
------------------------------
Verna       f
      CD   8277.00
       S   1802.00
------------------------------
Nancy       f
       C      8.20
------------------------------

===Printing the list of registered accounts===

   1       James   m   C      5.40
   2        John   m   S      0.00
   3       Sally   f   C      0.00
   4        Mary   f   S      1.80
   5    Delphine   f   C     92.00
   6      Robert   m   S     86.00
   7      Joseph   m   C     31.31
   8     Stanley   m   C      7.00
   9      Marsha   f   S    873.73
  10      Bernie   f   S    884.44
  11      Marcus   m   C     66.87
  12    Mei-Ling   f   S     20.50
  13     Arturus   m   C    893.00
  14   Katherine   f   C   4721.00
  15     Michael   m  CD    245.00
  16    Michelle   f   S    175.00
  17 Jean-Michel   m   C   3416.00
  18       Dante   m   C   1624.00
  19      Harold   m   S    266.77
  20       Betsy   f   S     19.05
  21     Richard   m   C     19.00
  22      Ronald   m   S     55.55
  23       Wayne   m   C    746.00
  24       Kevin   m   S    823.00
  25     Phillip   m   C     28.00
  26      Brutus   m   C     98.99
  27       Betty   f   C   2349.34
  28      Tyrone   m   S      1.19
  29     Schelly   f   S      1.01
  30       Brian   m   C      2.59
  31     Cameron   m   S      2.99
  32       David   m   S    238.10
  33         Amy   f   S    300.01
  34       Jacob   m   S     70.00
  35        Alex   f  CD  29931.54
  36      Rafael   m   C   6727.00
  37    Reginald   m   C    200.00
  38       Tamra   f   S    100.00
  39       Kelly   m   S    100.00
  40       Hazel   f  CD    140.00
  41         Zoe   f   C   2323.00
  42       Piper   f   C   1233.10
  43     Kenneth   m   C    499.00
  44      Pierre   m   C    234.00
  45      Carlos   m   C      0.01
  46      George   m   C     23.62
  47       Jorge   m   S    463.90
  48        Juan   m  CD   5092.30
  49       Lewis   m   C      0.01
  50     Deborah   f  CD   1007.93
  51       Scott   m   C    702.88
  52      Adrian   m   C     22.64
  53      Brooks   m   C    792.00
  54       Avery   m   S    904.69
  55     Hillary   f   S   1000.00
  56     William   m   C     12.01
  57        Ezra   m   C     17.00
  58       Jason   m   C     18.60
  59      Sanjay   m   C     19.32
  60     Matthew   m   S     26.00
  61      Daniel   m   C    400.00
  62       Julia   f   C  87230.00
  64      Xavier   m   C     10.00
  65     Yannick   m  CD  20100.64
  66        Joel   m   C    398.55
  67      DeJean   m   C     23.44
  68        Paul   m   S      2.01
  69        Fran   f   S    782.90
  70      Ingrid   f  CD   9243.92
  71        Enid   f   C    432.10
  72       Nancy   f   C      8.20
  73      Melvin   m   C     78.23
  74       Verna   f  CD   8277.00
  75       Ellen   f   S     23.57
  76      Gordon   m   C     66.17
  77    Benjamin   m   S     23.91
  78     Hillery   m   C     20.00
  79    Bradford   m   C      0.12
  80       Jesse   m   C     41.02
  81       Pratt   m   c      0.00
  82       Peter   m   S  49872.40
  83      Graham   m   S     12.68
  84         Eli   m  CD   8277.00
  85    Kimberly   f   C    100.00
  86     Rebecca   f   C   1177.71
  87        Dale   m   C     58.94
  88      Andrew   m   C    123.17
  89     Wallace   m   C     19.99
  90      Edward   m  CD  98382.45
  91        Amos   m   C  92811.84
  92       Chase   m   S     12.04
  93       Verna   f   S   1802.00
  94      Sanjay   m   S     20.00
  95        John   m   C      0.00
  96         Zoe   f   S     34.00
  97       Kelly   f   S    102.00
  98        Alex   f   S  13982.00
  99        Alex   f   C   1098.47
 100        Alex   m   C    529.34
 101       Sally   f   S      1.98
 102      Jessie   f   C    478.82
 103       Julia   f   S      0.00
 104       Dante   m   S    256.70
 105       Lewis   m   S      1.01
 106     Raphael   m   C   6720.00
 107       Myren   m   C   6727.00
 108     Francis   m   S   2371.00
 109       Lamar   m   C    200.12
 110     Quinton   m   C     25.34
 111        Paul   m   C    197.42

===End of the program===

Initializing the tree...
Deleting Adrian...
Deleting Alex...
Deleting Alex...
Deleting Amy...
Deleting Amos...
Deleting Avery...
Deleting Arturus...
Deleting Andrew...
Deleting Betty...
Deleting Betsy...
Deleting Bernie...
Deleting Brooks...
Deleting Brian...
Deleting Carlos...
Deleting Cameron...
Deleting Brutus...
Deleting Chase...
Deleting Daniel...
Deleting DeJean...
Deleting Deborah...
Deleting David...
Deleting Delphine...
Deleting Dante...
Deleting Edward...
Deleting Dale...
Deleting Eli...
Deleting Bradford...
Deleting Benjamin...
Deleting Enid...
Deleting Fran...
Deleting Ezra...
Deleting George...
Deleting Francis...
Deleting Hillary...
Deleting Hazel...
Deleting Harold...
Deleting Graham...
Deleting Ingrid...
Deleting Jacob...
Deleting Jason...
Deleting Jean-Michel...
Deleting James...
Deleting Joel...
Deleting Jessie...
Deleting Jorge...
Deleting Juan...
Deleting Joseph...
Deleting Katherine...
Deleting Julia...
Deleting Kenneth...
Deleting Kelly...
Deleting Kevin...
Deleting Kelly...
Deleting John...
Deleting Lamar...
Deleting Marcus...
Deleting Marsha...
Deleting Matthew...
Deleting Mei-Ling...
Deleting Mary...
Deleting Lewis...
Deleting Kimberly...
Deleting Jesse...
Deleting Hillery...
Deleting Gordon...
Deleting Ellen...
Deleting Michelle...
Deleting Michael...
Deleting Myren...
Deleting Melvin...
Deleting Paul...
Deleting Pierre...
Deleting Piper...
Deleting Phillip...
Deleting Peter...
Deleting Rafael...
Deleting Quinton...
Deleting Raphael...
Deleting Reginald...
Deleting Richard...
Deleting Ronald...
Deleting Robert...
Deleting Sally...
Deleting Scott...
Deleting Schelly...
Deleting Tamra...
Deleting Tyrone...
Deleting Stanley...
Deleting Sanjay...
Deleting Rebecca...
Deleting Pratt...
Deleting Yannick...
Deleting Xavier...
Deleting William...
Deleting Wayne...
Deleting Zoe...
Deleting Wallace...
Deleting Verna...
Deleting Nancy...
Deletion completed

*/
