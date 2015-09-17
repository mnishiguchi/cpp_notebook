# linked list

## linked list vs vector

### Vector
- Stores items in contiguous memory locations.
- Supports quick access to i'th element via v.at(i)
- but may be slow for inserts or deletes on large lists due to necessary shifting of elements

### Linked list
- Stores each item anywhere in memory, with each item pointing to the next item in the list
- Supports fast inserts or deletes
- but access to i'th element may be slow as the list must be traversed from the first item to the i'th item
- uses more memory due to storing a link for each item

## The basic operations on linked lists

1. Initialize the list.
2. Determine whether the list is empty.
3. Print the list.
4. Find the length of the list.
5. Destroy the list.
6. Retrieve the info contained in the first node.
7. Retrieve the info contained in the last node.
8. Search the list for a given item.
9. Insert an item in the list.
10. Delete an item from the list.
11. Make a copy of the linked list.

## two types of linked lists

In general, there are two types of linked lists
— sorted lists, whose elements are arranged according to some criteria
- unsorted lists, whose elements are in no particular order

### ordered linked list

- The elements are arranges according to some comparison criteria, usually less than or equal to
- will be in ascending order
- after inserting an element into or removing an element from an ordered list, the resulting list will be ordered

### unordered linked list
- we can insert a new item at either the end or the beginning
- we can build such a list in either a forward manner or a backward manner





