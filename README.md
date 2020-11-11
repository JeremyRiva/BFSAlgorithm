# Breadth-First search algorithm

## Outline
The aim of the project is to program a graph search algorithm to find a route both optimal and complete using the breadth-first search.
The breadth-first search algorithm itself is not particularly efficient due to it's radial approach to searching. Nonetheless, for small applications it works well.

## Structure overview

The map is a (5x6) grid with the start location at (0,0) and the goal at (4,5). The obstacles are represented by a '1' in the grid below.

```
0   1   0   0   0   0
0   1   0   0   0   0
0   1   0   0   0   0
0   1   0   0   0   0
0   0   0   1   1   0
```

The program displays the expansions made by the BF search algorithm in order. In this example the algorithm took 20 expansions to reach the goal. The areas not expanded are represented by '-1'.

```
BFS expansions in order:
0   -1  13  17  -1  -1
1   -1  10  14  18  -1
2   -1  8   11  15  19
3   -1  7   9   12  16
4   5   6   -1  -1  20
```

And is also designed to display the optimal route for the given problem. The goal in this case is represented by a '*'.

```
Optimal route:
v   -   -   -   -   -
v   -   -   -   -   -
v   -   -   -   -   -
v   -   >   >   >   v
>   >   ^   -   -   *
```
