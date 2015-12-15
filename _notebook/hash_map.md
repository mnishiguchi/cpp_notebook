# Map, associativee array

- https://en.wikipedia.org/wiki/Key-value_database
- Can get close to O(1), as opposed to binary search being O(log N)

## Hash function
- [A hash function is any function that can be used to map data of arbitrary size to data of fixed size.](https://en.wikipedia.org/wiki/Hash_function)
- Pass the key as an argument and get returned an index.
- Key ==> [Hash function] ==> Index

==

## Rules
- Ensure that the array size is large enough
- Memory is freely available
- Hashing algorithm should yied a good distribution
- Should utilize all of our arry elements to minimiae collisions
- The hash algorithm should be fast
- The hash algorithm should map input to the same hash value (consistency)

==

## Collision
- Can affect our O(1) performance
- Different keys get the same index.
- Good hash functions minimize collisions.

==

## Rehashing (3 alternatives)
- Rehash when half-full
- Rehash when we collide our first element
- Rehash to a load factor (how many elems in relation to the array size)
    + this is commonly used
    + 75% is an optimal load factor
    + a higher one will reduce rehashes
    + a lower one would reduce collisions

==

## HashMap vs TreeMap in Java

- [Difference between Space utilization and Load factor in hashtable](http://stackoverflow.com/questions/17228376/difference-between-space-utilization-and-load-factor-in-hashtable)

==
