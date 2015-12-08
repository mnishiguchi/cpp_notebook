#include <iostream>
using namespace std;

/**
 * @param list
 * @param newList  The reversal of list
 * @param size
 */
void reverse(const int list[], int newList[], int size) {

    for (int i = 0, j = size - 1;  // Initialze.
            i < size;              // Test.
            i++, j--)              // Update.
    {
        newList[j] = list[i];
    }
}

/**
 * @param list
 * @param size
 */
void printArray(const int list[], int size) {

    for (int i = 0; i < size; i++) {

        cout << list[i] << " ";

    }
}

int main() {

    const int SIZE = 6;
    int list[] = { 1, 2, 3, 4, 5, 6 };
    int newList[SIZE];

    reverse(list, newList, SIZE);

    cout << "The original array: ";
    printArray(list, SIZE);
    cout << endl;

    cout << "The reversed array: ";
    printArray(newList, SIZE);
    cout << endl;

    return 0;
}
