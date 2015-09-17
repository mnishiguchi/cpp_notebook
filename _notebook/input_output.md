# input and output

## std::cin vs std::cin.getline

|   |   |   |
|---|---|---|
|std::cin         |getting first word| |
|std::cin.getline |getting line      |[doc](http://www.cplusplus.com/reference/string/string/getline/)|

## istreamVar.clear();

- Restores the input stream to a working state
- Still need to clear the rest of the garbage from the input stream by using the function ignore

```cpp
    cout << "Enter the number of rows and columns: ";
    cin >> numRows >> numColumns;
    
    cin.clear();            // Restore input stream
    cin.ignore(100, '\n');  // Clear the buffer
```

## << flush

- The << flush forces cout to flush any characters in its buffer to the screen before doing each task, otherwise the characters may be held in the buffer until after a later task completes. 

