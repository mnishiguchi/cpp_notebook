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
