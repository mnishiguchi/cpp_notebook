/**
 * Chapter 8 Programming exercise
 * _07_five_election_candidates
 *
 *
 * Prompts the user to enter:
 *  - the last nameList of five candidates in a local election and
 *  - the number of votes received by each candidate.
 *
 * Outputs:
 *  - each candidate’s name,
 *  - the number of votes received, and
 *  - the percentage of the total votes received by the candidate
 *  - the winner of the election
 */


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// Global constants.
const int NUM_CANDIDATES = 5;


// Function prototypes.
void promptCandidateNames(string*);
void promptVotesRecieved(string*, int*);
int getTotalVotes(int*);
int getWinnerIndex(int*);
void printTableHeader();
void printTableRow(string, int, double);
void printTableBody(string*, int*);
void printWinner(string*, int*);


/**
 * @return
 */
int main() {

    // The data stores for user's input.
    string nameList[ NUM_CANDIDATES ];
    int voteList[ NUM_CANDIDATES ];

    promptCandidateNames(nameList);
    promptVotesRecieved(nameList, voteList);
    printTableHeader();
    printTableBody(nameList, voteList);
    printWinner(nameList, voteList);

    return 0;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * Prompt the user to enter the last nameList of five candidates in a local election,
 * and store those nameList in the specified string array.
 * @param nameList  a string array in which we store the user's input.
 */
void promptCandidateNames(string* nameList) {

    // The prompt message.
    cout << "Enter the last nameList of five candidates:" << endl;

    for ( int i = 0; i < NUM_CANDIDATES; i++ ) {

        cout << ">>>";
        cin >> nameList[ i ];

    }

    cout << endl;  // Insert a blank line.
}


/**
 * Prompt the user to enter the number of votes received by each candidate
 * and store those values in the specified int array.
 * @param nameList  a string array in which the candidates' nameList are stored.
 * @param voteList  an int array in which we store the user's input.
 */
void promptVotesRecieved(string* nameList, int* voteList) {

    bool isAccepted;

    // The prompt message.
    cout << "Enter the number of votes received by each candidate:" << endl;

    // For each candidate...
    for ( int i = 0; i < NUM_CANDIDATES; i++ ) {

        isAccepted = false;
        while ( !isAccepted ) {

            // Get vote accepted.
            cout << "[" << nameList[ i ] << "]>>>";
            cin >> voteList[ i ];

            // Ensure that the input was valid.
            if ( cin.fail() || voteList[ i ] < 0 ) {
                cout << "Invalid input: Must be an interger [0..inf)" << endl;
                cin.clear();            // Restore input stream.
                cin.ignore(100, '\n');  // Clear the buffer.

            } else {
                isAccepted = true;  // Exit the loop.
            }
        } // end while
    } // end for

    cout << endl;  // Insert a blank line.
}


/**
 * @param voteList an int array that contains each candidate's votes received.
 * @return sum of all the votes.
 */
int getTotalVotes(int* voteList) {

    int sum = 0.0;
    for ( int i = 0; i < NUM_CANDIDATES; i++ ) {

        sum += voteList[ i ];

    }

    return sum;
}


/**
 * @param voteList an int array that contains each candidate's votes received.
 * @return The array index of the winner.
 */
int getWinnerIndex(int* voteList) {

    int winnerIdx = 0;

    for ( int i = 0; i < NUM_CANDIDATES; i++ ) {

        if ( voteList[ i ] > voteList[ winnerIdx ] ) {

            winnerIdx = i;
        }

    }

    return winnerIdx;
}


/**
 * Prints the table header.
 */
void printTableHeader() {

    cout << "Candidate   Votes Received  % of Total Votes" << endl;
}


/**
 * Prints the table row with information.
 * @param candidate
 * @param votesReceived
 * @param percentageOfTotalVotes
 */
void printTableRow(string candidate, int votesReceived, double percentageOfTotalVotes) {

    cout << left  << setw(12) << candidate;
    cout << right << setw(8) << votesReceived;

    if (percentageOfTotalVotes >= 0) {
        cout << fixed << showpoint << setprecision(2);
        cout << right << setw(16) << percentageOfTotalVotes;
    }

    cout << endl;  // Move to next line.
}


/**
 * Prints the table body.
 * @param nameList  A string array.
 * @param voteList  A int array.
 */
void printTableBody(string* nameList, int* voteList) {

    double percentageOfTotalVotes = 0.0;

    // Get the total votes.
    int totalVotes = getTotalVotes(voteList);

    // Print table rows witn information.
    for ( int i = 0; i < NUM_CANDIDATES; i++ ) {
        // NOTE: I place 100.0 at the beginning so that we can prevent.
        // integers from trancate values in the computation.
        percentageOfTotalVotes = 100.0 * voteList[ i ] / totalVotes;
        printTableRow(nameList[ i ], voteList[ i ], percentageOfTotalVotes);
    }
    cout << endl;  // Insert a blank line.

    // Print the total.
    printTableRow("Total", totalVotes, -1);
    cout << endl;  // Insert a blank line.
}


/**
 * Prints the winner of the election.
 * @param nameList  A string array.
 * @param voteList  A int array.
 */
void printWinner(string* nameList, int* voteList) {

    int winner = getWinnerIndex(voteList);
    cout << "The Winner of the Election is " << nameList[ winner ] << "." << endl;
    cout << endl;  // Insert a blank line.
}


/* OUTPUT

Enter the last nameList of five candidates:
>>>Johnson
>>>Miller
>>>Duffy
>>>Robinson
>>>Ashtony

Enter the number of votes received by each candidate:
[Johnson]>>>5000
[Miller]>>>4000
[Duffy]>>>6000
[Robinson]>>>2500
[Ashtony]>>>1800

Candidate   Votes Received  % of Total Votes
Johnson         5000           25.91
Miller          4000           20.73
Duffy           6000           31.09
Robinson        2500           12.95
Ashtony         1800            9.33

Total          19300

The Winner of the Election is Duffy.

Program ended with exit code: 0
 */
