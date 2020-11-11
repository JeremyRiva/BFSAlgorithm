# Path planning with graph search algorithms

## Outline
The __breadth-first search__ is compared to the __A* search__ algorithm. In this scenario the breadth-first search algorithm is not as efficient due to it's uninformed radial approach of searching. 
On the other hand the A* search is more efficient as it is informed, in other words it is aware of where the goal is located, hence finding the shortest route.

## Structure overview
The map is a (5x6) grid with the start location at (0,0) and the goal at (4,5). The obstacles are represented by a '1' in the grid below.

```
0   1   0   0   0   0
0   1   0   0   0   0
0   1   0   0   0   0
0   1   0   0   0   0
0   0   0   1   1   0
```

### Breadth-First search algorithm
The program displays the expansions made by the BF search algorithm in order. In this example the algorithm took 20 expansions to reach the goal. The areas not expanded are represented by '-1'.

```
BFS expansions in order:
0   -1  13  17  -1  -1
1   -1  10  14  18  -1
2   -1   8  11  15  19
3   -1   7   9  12  16
4    5   6  -1  -1  20
```

### A* search algorithm
For this model the Manhattan Heuristic vector was used, which was calcualted as follows:   
`x = x_goal - x_cellposition`   
`y = y_goal - y_cellposition`   
`Manhattan distance d = |x| + |y|`   

In comparison the expansion made by the A* search shows only 11 expansions to reach the goal (the shortest path).

```
A* search expansions in order:
0   -1  -1  -1  -1  -1
1   -1  -1  -1  -1  -1
2   -1  -1  -1  -1  -1
3   -1   7   8   9  10
4    5   6  -1  -1  11
```

## Results
Both algorithms displayed the optimal route for the given problem. The goal in this case is represented by a '*'.

```
Optimal route:
v   -   -   -   -   -
v   -   -   -   -   -
v   -   -   -   -   -
v   -   >   >   >   v
>   >   ^   -   -   *
```
