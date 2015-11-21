/**
 * _17_print_grade.cpp
 *
 * Created by Masatoshi Nishiguchi on 11/20/15.
 */

#include <iostream>
#include <string>

using namespace std;

/*
OUTPUT

Enter course score: 89

Your course score : 89
Your grade        : B.
 */


// Function prototypes.
int getScore();
string calculateGrade(int score);


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * Main funcion of this program.
 */
int main() {

    int score = getScore();

    cout << "Your course score : " << score << endl;
    cout << "Your grade        : " << calculateGrade( score ) << endl;

    return 0;
}


// ----------------------------------------------------------------------------- //
// ----------------------------------------------------------------------------- //


/**
 * Prompts the user to enter a course score.
 * @return The score that the user enters.
 */
int getScore() {

    int score;

    cout << "Enter course score: ";
    cin >> score;
    cout << endl;

    return score;

}


/**
 * @param score  A score that is of integer type.
 * @return A string that represents the grade corresponding to the score.
 */
string calculateGrade(int score) {

    string grade;

    if (score >= 90) {
        grade = "A.";

    } else if (score >= 80) {
        grade = "B.";

    } else if (score >= 70) {
        grade = "C.";

    } else if (score >= 60) {
        grade = "D.";

    } else {
        grade = "F.";
    }

    return grade;
}
