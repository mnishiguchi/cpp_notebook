# Trees
- A tree starts with a root node
– Convenient for storing data that is hierarchical

## Decision tree
- Useful for making decisions on problems

## Binary search tree

- Left child  < parent
- Right child > parent

- Advantages:
    - Finding data can be better than sequential search
    - Inserting a node

- Drawbacks:
    - Deleting a node (E.g. deleting root or parent node)
    - Must have a unique key
    - In the worst case, no better than a linked list

## Deleting
-  a node with 0 or 1 child is simple
-  Deleting with 2 children
    +  Go to the right most grandchild of the parent's left child
    +  Move that node to take the place of the deleted node

## AVL trees
- Ensures that binary search tree can process find and other operations no worse than O(log N) like binery search
- Requirements
    + Everytime we add a node, we check the height of both left and right subtrees
    + Ensure that the height of the left subtree differs from the right by **no more than one**.
    + **Rotation** - Balance condition by rotating positions when necessary.
- Drawback
    - May have to re-order nodes upon each insert and delete and hold and update height information
    - Have to rotate nodes

## Some algorithms
- **Non-recursive binary tree traversal algorithms**

## Traveral of the tree (3 methods)
- in order   - L, node, R
- pre-order  - node, L, R
- post-order - L, R, node
