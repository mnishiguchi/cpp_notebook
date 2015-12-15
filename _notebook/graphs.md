# Graphs
- Textbook(6th ed.) Chapter 20
- https://web.stanford.edu/class/cs97si/06-basic-graph-algorithms.pdf
- A set of vertices and edges.

**Undirected graph**
- No restriction on directions. Can move two ways.
```
1 --------- 2
```

**Directed graph**

```
1 --------> 2
```

**Directed weighted graph**

```
    30km
1 --------> 2
```

**Multiple paths**

- Deadlock may occur.
```
1 --> 8---> 2 ---> 5
      |     ^     /
      |     |    /
      V     |  L
6 --> 3 <-- 4 ---> 7
```

==

## Minimum spanning tree
- Unique path connecting all the nodes connected at minimum cost.
- Often used for directed weighted graph.

==

## Graph Representation
- Two commonly used methods: adjacency matrices and adjacency lists.

### Adjacency matrix
- Often wastes memory space.

```
0  0  1  0  0  1  1  0  
1  0  0  0  1  0  0  0  
0  0  1  0  1  0  1  0  
0  0  1  0  0  1  1  0  
1  0  0  0  1  0  0  0  
0  0  1  0  1  0  1  0  
0  0  1  0  0  1  1  0  
```

### Adjacency list
- Usually spend less memory than the adjacency matrix.

```
[0] -> node -> node -> node -> ...
[1] -> node -> node -> ...
[2] -> NULL
[3] -> node -> ...
```

==

## Depth First Traversal
- Visit all the verteces
- similar to the preorder traversal of a binary tree

1. Start from the lowest index.
2. Find the lowest connected node, move to it and as far as possible.
3. Move to the next lowest and repeat.
