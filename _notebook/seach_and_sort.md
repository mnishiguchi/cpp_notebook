# Searching and sorting
- http://www.sorting-algorithms.com/

==

## Complexity
- O(1)   - always constant
- O(n)   - linear
- O(n^2) - exponential

==

## Binery seach
- More efficient on a large number of items
- The items must be sorted in order to use a binery search

==

## What do we need before doing sort?
- keys
- sort order (ASC/DESC)

==

## Why need sorting?
- Makes data human-friendly

==

## Big-O analysis

- g(n) = 1
The growth rate is constant, so it does not depend on n, the size of the problem.
- g(n) = log2n
The growth rate is a function of log2n. Because a logarithm function grows slowly, the growth rate of the function f is also slow.
- g(n) = n
The growth rate is linear. The growth rate of f is directly proportional to the size of the problem.
- g(n) = nlog2n
The growth rate is faster than the linear algorithm.
- g(n) = n2
The growth rate of such functions increases rapidly with the size of the problem. The growth rate is quadrupled when the problem size is doubled.
- g(n) = 2n
The growth rate is exponential. The growth rate is squared when the problem size is doubled.

- constant

### Bubble sort
O(n^2)

==

## Function pointer
- Pass a function into another fuction
- sort(func_ptr)
    + sortByTitle()
    + sortByMinAge(v_game_1, v_game_2)
