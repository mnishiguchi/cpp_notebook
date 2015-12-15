/**
 * Chapter 8 Programming exerciese
 * _06_grading_true_false_test
 *
 * Grade a True/False test.
 *
 */
#include <iostream>
#include <string>
using namespace std;

// Configuration.
const string ANSWER = "TFFTFFTTTT";
const int NUM_QUESTIONS = 10;

// Function prototypes.
int gradeTrueFalseTest();
char getGradeChar(double);


int main() {

    // Prompt the user for the student ID.
    string studentId = "?";
    cout << "Enter student ID: ";
    cin  >> studentId;
    cout << endl;

    // Prompt the user for the student's answers'.
    int correctCount = gradeTrueFalseTest();

    // Get the grade char.
    char gradeChar   = getGradeChar( 100.0 * correctCount / NUM_QUESTIONS );

    cout << "---------------------------------" << endl;
    cout << "ID:    " << studentId << endl;
    cout << "Grade: " << gradeChar << endl;

    return 0;
}


//------------------------------------------------------------------------------ //
//------------------------------------------------------------------------------ //


/**
 * Prompt the user to enter the student ID and the student's answers.
 * e.g., ABC54301 TFFTFFTTTT
 * e.g., ABC54301 TF FTFTT T
 * @return How many the student get right?
 */
int gradeTrueFalseTest() {

    char studentAnswers[ NUM_QUESTIONS ];
    int correctCount = 0;

    // Prompt the user for the student's answers.
    cout << "Enter student's " << NUM_QUESTIONS << " answers (e.g., TF FTFTT T): ";
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        cin  >> studentAnswers[ i ];

        // Count the correct answers.
        if ( toupper(studentAnswers[ i ]) == 'T' ) {
            correctCount += 1;
            cout << correctCount;
        } else {
            cout << ".";
        }
    }

    cout << endl;  // Move to next line.

    return correctCount;

}


/**
 * @param  percentage
 * @return grade scale: 90%–100%, A; 80%–89.99%, B; 70%–79.99%, C; 60%–69.99%, D; and 0%–59.99%, F.
 */
char getGradeChar(double percentage) {
    char gradeChar;

    // Reject invalid input.
    if (percentage > 100 || percentage < 0) {
        gradeChar = '?';
        return gradeChar;
    }

    // Evaluate the percentage.
    if (percentage >= 90) {
        gradeChar = 'A';
    } else if (percentage >= 80) {
        gradeChar = 'B';
    } else if (percentage >= 70) {
        gradeChar = 'C';
    } else if (percentage >= 60) {
        gradeChar = 'D';
    } else {
        gradeChar = 'F';
    }

    // Return the char.
    return gradeChar;
}
