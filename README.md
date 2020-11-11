# Breadth-First search algorithm

## Outline
The aim of the project was to program a graph search algorithm to find a solution both optimal and complete (whenever possible).
This algorithm itself is not particularly efficient due to it's radial approach to searching. For small applications it works fine.

## Structure overview

The code is designed to display the optimal route for the given problem.
The map is a (5x6) grid with the start location at (0,0) and the goal at (4,5).
```
    0 	1 	2 	3 	4 	5
0 	0 	1 	0 	0 	0 	0
1 	0 	1 	0 	0 	0 	0
2 	0 	1 	0 	0 	0 	0
3 	0 	1 	0 	0 	0 	0
4 	0 	0 	0 	1 	1 	0

```
The program displays both the expansions made by the BF search algorithm in order in addition to the optimal route.

```
BFS expansions in order:
0   -1  13  17  -1  -1
1   -1  10  14  18  -1
2   -1  8   11  15  19
3   -1  7   9   12  16
4   5   6   -1  -1  20
```

```
Optimal route:
v   -   -   -   -   -
v   -   -   -   -   -
v   -   -   -   -   -
v   -   >   >   >   v
>   >   ^   -   -   *
```
