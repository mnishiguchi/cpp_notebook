# STANDARD TEMPLATE LIBRARY (STL)
- http://www.cplusplus.com/reference/
- three components
    + Containers 
    + Iterators
    + Algorithms
- Containers and iterators are class templates. 

==

## Container Types
- used to manage objects of a given type.
- classified into three categories
    + Sequence containers (also called sequential containers)
        * `vector`, `deque`, `list`
        * Every object in a sequence container has a specific position. 
        
    + Associative containers
        * `Sets`, `Multisets`, `Maps`, `Multimaps`
        * Elements in an associative container are **automatically sorted according to some ordering criteria**. 
        * The default ordering criterion: the relational operator < (less than).
        * Users also have the option of specifying their own ordering criterion.
        * Because elements in an associative container are sorted automatically, when a new element is inserted into the container, it is inserted at the proper place.
        * Implemented as a **binary search tree**; thus, every element in the container has a parent node (except the root node) and, at most, two children. For each element, the key in the parent node is larger than the key in the left child and smaller than the key in the right child.

    + Container adapters
        * TODO

### THE FUNCTIONS begin AND end
- **Every container has the member functions begin and end**. 
- **`begin()`**: returns the position of the first element in the container.
- **`end()`**: returns the position of one past the last element in the 

### Sequence container: vector
- stores and manages its objects in a **dynamic array**. 
- A random access data structure; the elements of a vector can be accessed randomly.
- Item insertion in the middle or beginning of an array is time consuming, especially if the array is large. However, inserting an item at the end is quite fast.

### Sequence Container: deque
- Stands for double-ended queue. 
- Implemented as **dynamic arrays** in such a way that the elements **can be inserted at both ends**; thus, a deque can **expand in either direction**. 
- Elements can also be inserted in the middle. 
- Inserting elements in the beginning or at the end is fast; inserting elements in the middle, however, is time consuming because the elements in the queue need to be shifted.

### Sequence Container: list
- Describes the sequence container list.
- Implemented as **doubly linked lists**; thus, every element in a list points to both its immediate predecessor and its immediate successor (except the first and last elements).
- **Not a random access data structure**; therefore, to access an element in the list, we **must traverse the list**.

==

## Linked lists

### <list>

==

## Associative Containers

### <set> and <multiset>
- Automatically sort their elements according to some sort criteria. 
- The default sorting criterion is the relational operator < (less than); that is, the elements are arranged in ascending order.
- The user can also specify other sorting criteria.
- For user-defined data types, such as classes, the relational operators must be overloaded properly.
- difference between set and multiset:
    + multiset allows duplicates
    + set does NOT allow duplicates

### <map> and <multimap>


==

## Others

### <bitset>
### <forward_list>
### <map>
### <queue>
### <stack>
### <unordered_map>
### <unordered_set>

==


