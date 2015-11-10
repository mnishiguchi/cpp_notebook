/*****************************************************************************

   CSCI-241C-01 Data structures
   bank_account_tree.cpp

   Name: Masatoshi Nishiguchi (N00263071)
   Date: 11/10/2015

 *****************************************************************************/

/*

Analysis

1) What key would you use and why? (5 pts)

# Key to be used
- I would create the AcctHolder class and use that class's name (string type) as a key.
The AcctHolder class holds as members name, gender and list of pointers to
his/her account(s).

# Reason
- Because that way, we can access multiple account that the same account holder has
in constant time once the account holder has been found in the tree.
- The user of the program is very likely to inspect different accounts that
the same account holder has once the user has accessed one account.

2) Assume that you expect to get many requests for your BankAcct instances where only the name and account type is known.  Does your answer somehow change?  How so?  (5 pts)

3) Assume your key is the account number.
What problems will you potentially face when retrieving the data from your BST
(again, assume the data has been loaded in the order shown.)?
What could you do to fix the problem(s), if any?

Hint: you should pay attention to the actual values of the account numbers in the array.  (10 pts)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

// class declaration
class BankAcct;
class AcctHolder;
class BankAcctBankAcctBinaryTree;

/**
 * Class that represents an account holder.
 * - A single person (same name and gender) may have multiple accounts.
 * - A single person can NOT have multiple accounts of the same type.
 *     - E.g., Joel who is male cannot have two account types of CD.
 *     - E.g., Sally who is female may have a checking and a savings account.
 * - The account number is unique - No two account will ever share the same account number.
 */

/*
== Required validations ==

# A single person (same name and gender)
boolean BankAcctBankAcctBinaryTree::isSamePerson(AcctHolder* acctHolder);

# A single person can NOT have multiple accounts of the same type.
boolean AcctHolder::existsAcctType(string acctType);

# The account number is unique
boolean BankAcct::isTakenAcctId(int acctId);

*/

/*================================================
  Class declaration
=================================================*/

/**
 * Class that represents an bank account.
 */
class AcctHolder {
public:
    AcctHolder(BankAcct account);
    AcctHolder(string holderName, string gender, BankAcct account);

    bool addAccount(BankAcct account);
    bool existsAcctType(string acctType);

    string holderName;
    string gender;
    vector<BankAcct> accounts;

    AcctHolder* left;
    AcctHolder* right;
};

/**
 * Class that represents an bank account.
 */
class BankAcct {
public:
    BankAcct(string name, string gender, string acctType, double balance, int acctId);

    // Instance variables
    AcctHolder* acctHolder;
    string acctType;
    double balance;
    int acctId;

    // Keep track of the availabilities of account IDs
    static map<int, bool> acctIdAvailabilities;
    static bool isTakenAcctId(int acctId);
    static void printIdAvailabilities();
};

/*================================================
  Implementation of class AcctHolder
=================================================*/

/**
 * Constructor of the AcctHolder class
 */
AcctHolder::AcctHolder(BankAcct account) {
    this->holderName = account.acctHolder->holderName;
    this->gender     = account.acctHolder->gender;
    this->accounts.push_back(account);

    AcctHolder* left  = NULL;
    AcctHolder* right = NULL;
}

/**
 * Constructor of the AcctHolder class
 */
AcctHolder::AcctHolder(string holderName, string gender, BankAcct account) {
    this->holderName = holderName;
    this->gender     = gender;
    this->accounts.push_back(account);

    AcctHolder* left  = NULL;
    AcctHolder* right = NULL;
}

/**
 * @param account
 * @return true if the adding is successful; else false
 */
bool AcctHolder::addAccount(BankAcct account) {
  if (!existsAcctType(account.acctType)) {
    accounts.push_back(account);
    return true;  // Success
  }
  return false;   // Fail
}

/**
 * @param acctType
 * @return true if this AcctHolder instance already has the specified account type
 */
bool AcctHolder::existsAcctType(string acctType) {
    int len = (int)accounts.size();
    for (int i = 0; i < len; i++) {
        if (accounts.at(i).acctType == acctType) {
            cout << holderName << " already has "  << acctType << endl;
            return true;
        }
    }
    return false;
}

/*================================================
  Implementation of class BankAcct
=================================================*/

// Initialize the static map to keep track of all the used IDs
map<int, bool> BankAcct::acctIdAvailabilities;

/**
 * Constructor of the BankAcct class
 * @param Name of account holder
 * @param gender(m or f)
 * @param account type (C=checking, S=savings, CD=certificate of deposit)
 * @param account balance, account number
 */
BankAcct::BankAcct(string name, string gender, string acctType,
                   double balance, int acctId) {
    this->acctHolder = new AcctHolder(name, gender, *this);
    this->acctType   = acctType;
    this->balance    = balance;
    this->acctId     = acctId;

    // Keep track of the used ids
    acctIdAvailabilities[ acctId ] = true;

    // Report the user about the accout that has been created
    cout << "Account created: #" << acctId << " " << name << endl;
}

/**
 * A static function to check the availability of the specified account ID
 * @param acctId
 * @return true if the specified ID is available; false otherwise
 */
bool BankAcct::isTakenAcctId(int acctId) {
    bool isTaken =  acctIdAvailabilities.find(acctId)->second;
    cout << acctId << ((isTaken) ? ": Taken" : ": Available") << endl;
    return isTaken;
}

/**
 * A static function to print all the currently issued IDs
 */
void BankAcct::printIdAvailabilities() {
    for (auto it : acctIdAvailabilities) {
        cout << it.first << " " << it.second << endl;
    }
}

/*================================================
  Implementation of class BankAcctBinaryTree
=================================================*/

// TODO - BankAcctBinaryTree

/**
 *  Encapsulates the workings of the tree into a single area.
 */
class BankAcctBinaryTree {
public:
    BankAcctBinaryTree();
    //~BankAcctBinaryTree();

    // Public methods
    void insertAcct(BankAcct account);

private:
    void insert(AcctHolder* toBeInserted, AcctHolder *leaf);
    AcctHolder* root;
};

/**
 *  Constructor
 */
BankAcctBinaryTree::BankAcctBinaryTree() {
    root = NULL;
    cout << "A new binary tree was created" << endl;
}


//-----------------------------------------
//  BankAcctBinaryTree's private methods
//-----------------------------------------

/** PRIVATE
 *  Inserts a new leaf into the specified sub-tree.
 *  @param toBeInserted an AcctHolder object to be inserted
 *  @param leaf the root node of a subtree
 */
void BankAcctBinaryTree::insert(AcctHolder* toBeInserted, AcctHolder* leaf) {
    // Go to the left child
    if (toBeInserted->holderName < leaf->holderName) {

        if(leaf->left != NULL) {
            insert(toBeInserted, leaf->left);

        } else {
            cout << "Inserting " << left
                 << setw(10) << toBeInserted->holderName << " under "
                 << setw(10) << leaf->holderName << " on the left" << endl;
            leaf->left = toBeInserted;
        }
    }
    // Go to the right child
    else if(toBeInserted->holderName >= leaf->holderName) {

        if(leaf->right != NULL) {
            insert(toBeInserted, leaf->right);

        } else {
            cout << "Inserting " << left
                 << setw(10) << toBeInserted->holderName << " under "
                 << setw(10) << leaf->holderName << " on the right" << endl;
            leaf->right = toBeInserted;
        }
    }
}

//-----------------------------------------
//  BankAcctBinaryTree's public methods
//-----------------------------------------

/** PUBLIC
 * Inserts the specified data of BankAcct type into the tree.
 * @param an instance of BankAcct class
 * Note: The root is hidden.
 */
void BankAcctBinaryTree::insertAcct(BankAcct account) {

    // 1. Search for the same holder (same name, same gender).
    // TODO

    // 2A. If the holder already exists -> push this account into it.
    // TODO

    // If the holder is new -> create a new node and insert it into the tree.
    AcctHolder* toBeInserted = new AcctHolder(account);

    if(root != NULL) {  // If root exists in the tree
        insert(toBeInserted, root);
    } else {            // If root does not exist in the tree
        cout << "Setting " << account.acctHolder->holderName << " as a root of the tree" << endl;
        root = toBeInserted;
    }
}

/*================================================
  The main
=================================================*/

int main() {

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

    BankAcct::printIdAvailabilities();

    BankAcct::isTakenAcctId(67);
    BankAcct::isTakenAcctId(55);
    BankAcct::isTakenAcctId(112);

    BankAcctBinaryTree bst;

    for (int i = 0; i < 50; i++) {
        bst.insertAcct( accts[i] );
    }

    return 0;
}
