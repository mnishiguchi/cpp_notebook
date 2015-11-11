/*****************************************************************************

   CSCI-241C-01 Data structures
   bank_account_tree.cpp

   This program demonstrates a binary search tree of hypothetical bank accounts.

    == Validations ==
    - A person with same name and gender is a single person.
    - A single person can NOT have multiple accounts of the same type.
    - The account number must be unique.

   Name: Masatoshi Nishiguchi (N00263071)
   Date: 11/10/2015

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

    // Accessors
    string getCustName() const { return customer->custName; }
    string getCustGender() const { return customer->gender; }
    string getAcctType() const { return acctType; }
    double getBalance() const { return balance; }
    int getAcctId() const { return acctId; }

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
    void destroyTree(Customer* leaf);
    void insert(Customer* cusToInsert, Customer *leaf);
    void printAll(Customer *leaf) const;
    Customer* search(string custName, string gender, Customer* leaf) const;
    Customer* search(int acctId, Customer* leaf) const;
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
    return acctDictionary.find(acctId)->second;
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
 *  deletes that leaf, and then works its way back up.
 *  @param leaf the root node of a subtree
 */
void BankBSTree::destroyTree(Customer* leaf) {
    if(leaf != NULL) {  // Base case: Stop recursion when leaf is NULL
        destroyTree(leaf->l_link);  // Go to the left child and delete all
        destroyTree(leaf->r_link);  // Go to the right child and delete all
        cout << "Deleting " << leaf->custName << "..." << endl;
        delete leaf; // Delete this leaf
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
 *  Inserts a new leaf into the specified sub-tree.
 *  @param cusToInsert an Customer object to be inserted
 *  @param leaf the root node of a subtree
 */
void BankBSTree::insert(Customer* cusToInsert, Customer* leaf) {
    cout << left;  // Set output formatting

    // Go to the left child
    if (cusToInsert->custName < leaf->custName) {

        if(leaf->l_link != NULL) {
            insert(cusToInsert, leaf->l_link);
        } else {
            cout << "Inserting "
                 << setw(10) << cusToInsert->custName << " under "
                 << setw(10) << leaf->custName << " on the left" << endl;
            leaf->l_link = cusToInsert;
        }
    }
    // Go to the right child
    else if(cusToInsert->custName >= leaf->custName) {

        if(leaf->r_link != NULL) {
            insert(cusToInsert, leaf->r_link);
        } else {
            cout << "Inserting "
                 << setw(10) << cusToInsert->custName << " under "
                 << setw(10) << leaf->custName << " on the right" << endl;
            leaf->r_link = cusToInsert;
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
 *  @param leaf the root node of a subtree.
 */
void BankBSTree::printAll(Customer* leaf) const {
    // Base case: Deadend
    if (leaf == NULL) {
        return;
    }

    // Recursively go down the tree and check each node in the path.
    printAll(leaf->l_link);
    printAll(leaf->r_link);

    // TODO
    // Print customer info
    cout << setfill(' ') << right;

    cout << setw(12) << leaf->custName
         << setw(4)  << leaf->gender
         << endl;
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
 *  @param leaf the root node of a subtree.
 *  @return a pointer to the Customer if found; otherwise NULL
 */
Customer* BankBSTree::search(string custName, string gender, Customer* leaf) const {
    cout << left << setfill('.');  // Set output formatting

    // Base case1: Deadend
    if (leaf == NULL) {
        cout << setw(16) << custName + " (" + gender  + ")" << "not found" << endl;
        return NULL;
    }

    // Base case2: If found, return the pointer to that leaf
    if( (custName == leaf->custName) && (gender == leaf->gender) ) {
        cout << setw(16) << custName + " (" + gender  + ")" << "FOUND!!!!!!" << endl;
        return leaf;
    }

    cout << right << setfill(' ');  // Reset output formatting

    // Recursively go down the tree and check each node in the path.
    if (custName < leaf->custName) {
        return search(custName, gender, leaf->l_link);
    } else {
        return search(custName, gender, leaf->r_link);
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

    BankAcct* temp = BankAcct::getAcct(45);
    cout << temp->getCustName() << endl;

    cout << "\n===Printing all the node in the tree===\n" << endl;

    bst.printAll();

    cout << "\n===Printing the list of registered accounts===\n" << endl;

    BankAcct::printAllRegisteredAccts();

    cout << "\n===End of the program===\n" << endl;

    return 0;
}
