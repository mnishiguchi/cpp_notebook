# Graphs
- Textbook(6th ed.) Chapter 20
- https://web.stanford.edu/class/cs97si/06-basic-graph-algorithms.pdf
- A set of vertices and edges.

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
1 --------> 2 ---> 5
      |     ^     /
      |     |    /
      V     |  L
6 --> 3 <-- 4 ---> 7
```

## Minimum spanning tree
- Unique path one vertex to another that is the shortest.

==

## Graph Representation
- Two commonly used methods: adjacency matrices and adjacency lists.

### Adjacency matrix
- Often wastes memory space.
- 
```
0 0 1 0 0 1 1 0 
1 0 0 0 1 0 0 0 
0 0 1 0 1 0 1 0 
0 0 1 0 0 1 1 0 
1 0 0 0 1 0 0 0 
0 0 1 0 1 0 1 0 
0 0 1 0 0 1 1 0 
```

### Adjacency list
- Usually spend less memory than the adjacency matrix.

```
[0] -> node -> node -> node -> ...
[1] -> node -> node -> ...
[2] -> NULL
[3] -> node -> ...
```




