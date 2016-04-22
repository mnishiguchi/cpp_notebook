# File
- An area in a secondary storage used to hold information
- >>, get, ignore, putback, peek; <<, setfill, etc are available for file I/O
- We must declare variables, which include ifstream variables for input and ofstream variables for output
- Note: Make sure the filename has an **absolute path**. [Apple Support Communities](https://discussions.apple.com/thread/6588941?start=0&tstart=0)

[](http://stackoverflow.com/a/4324667/3837223)

## fstream
- used for file I/O
- contains the definitions of two data types:
    + ifstream - input file stream
    + ofstream - output file stream
- [calc_average_scores](https://github.com/mnishiguchi/cpp_practice_code/blob/master/cs1/chap3_programming_exercises/calc_average_scores/calc_average_scores/main.cpp)

## The five-step process
1. Include the header file fstream in the program
```cpp
#include <fstream>
```

2. Declare file stream variables
```cpp
ifstream inFile;
outstream outFile;
```

3. Associate the file stream variables with the input/output sources
```cpp
inFile.open("prog.dat");    // Open the input file
outFile.open("prog.out"); // Open the output file
```

4. Use the file stream variables with >>, << or other input/output functions
```cpp
inFile >> payRate;
outFile << "The paycheck is: $" << pay << endl;
```

5. Close the files 
```cpp
inFile.close(); 
outFile.close();
```

## Checking if a file was successfully opened

```cpp
if ( ! inFile.is_open() || ! outFile.is_open() ) {
    cout << "Error opening a file" << endl;
}
```

==

```cpp
int main() {

    ifstream reader;

    // Temporary data containers for each line.
    char acctName[101], acctType[11];
    double acctBal;
    BankAccount* newAccount;

    // Create a bank
    Bank* bank = new Bank;

    // Open the appropriate file
    reader.open( "/Users/masa/data_cpp_exercises/bank_data.txt" );

    // Loop will terminate once there is no more data to read from file
    while( ! reader.eof() ) {

        // Reads the name of the account holder into acctName
        reader.getline( acctName, 100, ',' );

        // Reads the account type of the account into acctType
        reader.getline( acctType, 10, ',' );

        // Reads the balance into acctBal
        reader >> acctBal;

        reader.ignore();

        //************************************************

        // Data validation (rejecting data with an empty string)
        if ( acctName[0] == '\0' || acctType[0] == '\0' ) {
           cout << "Ignored data with empty name or empty type." << endl;
           continue;
        }

        // Create a new account with this data set and add to the bank.
        newAccount = new BankAccount( acctName, acctType, acctBal );
        bank->addAccount( newAccount );

        drawLine();

        // Clear the variables.
        acctName[0] = '\0';
        acctType[0] = '\0';
        acctBal     = NULL;

        //************************************************
    }
    reader.close();  // Close the file
```

==

## [Comparing character arrays and string literals in C++](http://stackoverflow.com/a/1639437/3837223)
- `std::strcmp` returns 0 if strings are equal.

==

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
...

    ifstream thingsFile;

    // Five fields: [tType, tName, funLevel, numPlayers, dangerous]
    string fields[ 5 ];

    //
    thingsFile.open( "/Users/masa/Desktop/cpp_notebook/data_files/funthingfile.txt" );

    // if (thingsFile.good()) { cout << "GOOD" << endl; }
    // else                   { cout << "BAD" << endl; }

    // Temp var to hold an instance.
    FunThing* funThing;

    // A collection to hold all the data that was read from a file.
    vector<FunThing*> collection;

    // Read each row.
    // istream& getline (char* s, streamsize n, char delim );
    // http://www.cplusplus.com/reference/istream/istream/getline/
    // http://stackoverflow.com/a/19936571/3837223
    string row;
    while ( getline( thingsFile, row ) ) {

        int columnIndex = 0;  // Initialize columnIndex.

        // Read each field delimited by ',' from the row.
        istringstream rowStream( row );
        string field;
        while ( getline( rowStream, field, ',' ) ) {

            fields[ columnIndex ] = field; // Store value for each field.
            columnIndex += 1;              // Update columnIndex.
        }

        // Create a new FunThing instance.
        funThing = createAppropriateFunThing( fields, 5 );

        // Ignore this item and continue if the instantiation fails.
        if ( funThing == NULL ) { continue; }

        // Push this item to collection.
        collection.push_back( funThing );

        // // Clear all the temp variables.
        // for ( int i = 0; i < 5; i++ ) { fields[ i ] = ""; }
        // funThing = NULL;

        // // DEBUG: Print all the fields in this row.
        // for ( int i = 0; i < 5; i++ ) {
        //     cout << "Field " << i << ": " << fields[i] << endl;
        // }

    } // end while
```
