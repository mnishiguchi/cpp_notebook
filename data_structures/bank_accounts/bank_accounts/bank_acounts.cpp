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
