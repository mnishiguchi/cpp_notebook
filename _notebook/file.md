# File
- An area in a secondary storage used to hold information
- >>, get, ignore, putback, peek; <<, setfill, etc are available for file I/O
- We must declare variables, which include ifstream variables for input and ofstream variables for output
- Note: Make sure the filename has an **absolute path**. [Apple Support Communities](https://discussions.apple.com/thread/6588941?start=0&tstart=0)

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
if (!inFile.is_open() || !outFile.is_open()) {
    cout << "Error opening a file" << endl;
}
```

