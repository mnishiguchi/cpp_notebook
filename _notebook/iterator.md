# Iterator
- http://www.cplusplus.com/reference/iterator/

- In general, an iterator points to the elements of a container (sequence or associative).
- The two most common operations on iterators
    + `++` (the increment operator)
    + `*` (the dereferencing operator)

## Types of Iterators (five types)
- Input iterators
- Output iterators
- Forward iterators
- Bidirectional iterators
- Random access iterators

```cpp
deque<Airplane*> myQueue;
myQueue.push_back( obj_1 );
myQueue.push_back( obj_2 );

deque<Airplane*>::iterator it;

for ( int i = 0; i < it != myQueue; it++ ) {

    cout << "Value: " << (**it).name << endl;

}
```

```cpp
    // Create an iterator of vector<FunThing*> type.
    vector<FunThing*>::iterator iterator;

    // An temp variable to make the code easier to understand.
    FunThing* currentElement;

    // Iterate over the vector using that iterator.
    cout << "v_boardGames contains:\n";
    for ( iterator  = v_boardGames.begin() ;
          iterator != v_boardGames.end()   ;
          iterator++ ) {

        // Retrieve the current element.
        // - The iterator is a pointer pointing to the current element.
        // - That element is a FunThing pointer.
        currentElement = *iterator;

        // Output the info.
        currentElement->ouputToStream( cout );
    }
```

```cpp
    collection.sort( compareFunThingPointers );

    // Create a reverse-iterator of list<FunThing*> type.
    list<FunThing*>::reverse_iterator iterator;

    // An temp variable to make the code easier to understand.
    FunThing* currentElement;

    // Iterate over the list using that iterator.
    int count = 0;
    for ( iterator  = collection.rbegin() ;
          iterator != collection.rend() && count < howMany ;
          iterator++, count++ ) {

        // Retrieve the current element.
        // - The iterator is a pointer pointing to the current element.
        // - That element is a FunThing pointer.
        currentElement = *iterator;

        // Push the element to the highestThings list.
        highestThings.push_back( currentElement );
    }
```
