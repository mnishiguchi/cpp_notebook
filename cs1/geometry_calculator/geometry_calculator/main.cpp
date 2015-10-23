/**
 * APCT-233C-01
 * Geometry Calculator
 *
 * Masatoshi Nishiguchi
 * 10/22/2015
 */

/* ANALYSIS
 
 Calculaing area of a shape
 
 1. Circle
 A = PI * radius^2
 
 e.g. If radius is 6,
 A = 3.14 * 6^2 = 113
 
 2. Rectangle
 A = side1 * side2
 
 e.g. If side1 is 5 and side2 is 6,
 A = 5 * 6 = 30
 
 3. Triangle
 A = base * height / 2
 
 e.g. If base is 10 and height is 12,
 A = 10 * 12 / 2 = 60
 */


/* ACTUAL OUTPUT
 
 Geometry Calculator
 1. Calculate the Area of a Circle
 2. Calculate the Area of a Rectangle
 3. Calculate the Area of a Triangle
 4. Quit
 
 Enter your choice (1-4): -3
 
 Invalid input
 
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
 Would you like to continue? (y / n): y
 
 Geometry Calculator
 1. Calculate the Area of a Circle
 2. Calculate the Area of a Rectangle
 3. Calculate the Area of a Triangle
 4. Quit
 
 Enter your choice (1-4): 7
 
 Invalid input
 
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
 Would you like to continue? (y / n):
 */


#include <iostream>
using namespace std;

// Functions
bool validateInput(double num);
void calcAreaCircle();
void calcAreaRectangle();
void calcAreaTriangle();

/**
 * Main function of this program.
 */
int main() {
    
    int shapeCode;
    char choiceChar;
    
    while (true) {
        
        // Explanation
        cout << "Geometry Calculator" << endl;
        cout << "1. Calculate the Area of a Circle" << endl;
        cout << "2. Calculate the Area of a Rectangle" << endl;
        cout << "3. Calculate the Area of a Triangle" << endl;
        cout << "4. Quit" << endl;
        cout << endl;
        
        // Prompt user to enter his/her choice
        cout << "Enter your choice (1-4): ";
        cin >> shapeCode;
        cout << endl;
        
        // Conditional
        switch (shapeCode) {
            case 1:
                calcAreaCircle();
                break;
            case 2:
                calcAreaRectangle();
                break;
            case 3:
                calcAreaTriangle();
                break;
            case 4:
                cout << "Good bye!" << endl;
                return 0;
            default:
                cout << "Invalid input" << endl;
        }
        
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
        
        // Ask user if he/she wants to do another computation.
        
        choiceChar = '?';
        cout << "Would you like to continue? (y / n): ";
        cin >> choiceChar;
        cout << endl;
        
        if (choiceChar == 'y' || choiceChar == 'Y') {
            continue;
        } else {
            break;
        }
    }
    cout << "Good bye!" << endl;
    return 0;
}

/**
 * Returns true if the number is valid.
 */
bool validateInput(double num) {
    if (num <= 0) {
        cout << "Please enter a positive number." << endl;
        return false;
    }
    return true;
}

/**
 * A = PI * radius^2
 */
void calcAreaCircle() {
    
    cout << "Computing the area of a circle" << endl;
    
    const double PI = 3.14159;
    double area, radius;
    
    // Input and validation
    do {
        cout << "Enter radius: ";
        cin >> radius;
    } while ( !validateInput(radius) );
    cout << endl;
    
    // Computation
    area = PI * radius * radius;
    
    // Output
    cout << area << endl;
}

/**
 * A = side1 * side2
 */
void calcAreaRectangle() {
    
    cout << "Computing the area of a rectangle" << endl;
    
    double area, side1, side2;
    
    // Input and validation
    do {
        cout << "Enter length: ";
        cin >> side1;
    } while ( !validateInput(side1) );
    
    do {
        cout << "Enter width:  ";
        cin >> side2;
    } while ( !validateInput(side2) );
    cout << endl;
    
    // Computation
    area = side1 * side2;
    
    // Output
    cout << area << endl;
}

/**
 * A = base * height / 2
 */
void calcAreaTriangle() {
    
    cout << "Computing the area of a triangle" << endl;
    
    double area, base, height;
    
    // Input and validation
    do {
        cout << "Enter base:   ";
        cin >> base;
    } while ( !validateInput(base) );
    
    do {
        cout << "Enter height: ";
        cin >> height;
    } while ( !validateInput(height) );
    cout << endl;
    
    // Computation
    area = base * height / 2;
    
    // Output
    cout << area << endl;
}
