# Bank account 

- Create a collection of bank accounts and process them several ways.

## The BankAccount class
- a node on a linked list.
- must include:
    - the name of the account holder
    - the account type, and
    - the account balance
- For the purpose of this exercise, all members of BankAccount may be declared as public.
- will obviously need to add any other members needed to process the BankAccount as a linked list node.

## Three types of accounts
    - Checking (C)
    - Saving (S)
    - Certificate of Deposit (CD)

## Array of BankAccount pointers
- a five-element array of BankAccount pointers.
- each pointer points to a linked list of BankAccount objects (Divided into alhabetical groups)
- Each stack must never hold more than MAX_STACK_ITEMS items.

## Reading data from a file
- Data will be read from a file.
- Create a dynamic instance of BankAccount as the current object.
- If there's less than MAX_STACK_ITEMS on that stack, then push the BankAccount onto that stack.
- If there's no room, you must pop off the top item and place it into a "side collection" of your choice and then push the current object onto that stack.

## Side collection
- has the ability to hold any number of BankAccounts that may have been popped from the stack.
- either a linked list or a dynamic array
- show the name and balance of each BankAccount held in this collection at the end of the program (After closing the files).

## Utility functions
### find(String name) function
- find an account by the name in the list.
- outputs the balance and account type for an account that matches a name passed as a parameter.
- If the name is not found, ensure this is reported as output.
- the logic should search the proper stack for the name James.
- If the name is not found on the stack, output, “Name not found”, otherwise, output the account type and balance for that BankAccount.
- Do NOT search the side collection.

## Dynamically delete lists
- Finally, you will properly remove all of the dynamically created BankAccounts from memory.
- main lists and side collection

## Distributing the stacks among the five elements

- BankAccount objects must be pushed onto one of the five stacks.
- The appropriate stack is dependent on the name of the bank account holder.  
    + Element index 0: A-D
    + Element index 1: E-G
    + Element index 2: H-M
    + Element index 3: N-S
    + Element index 4: T-Z

```cpp
class BankAccount {
public:
    string accountName;
    string accountType;
    double balance;

};

int getStackIndexFor(string name) {
>     if (name[0] >= 'A' && name[0] <= 'D') {
>       return 0;
>     } else if (...) {
>       return 1;
>     }
}
```
