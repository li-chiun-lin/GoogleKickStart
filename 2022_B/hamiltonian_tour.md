# Problem

Hamilton is a Canadian city near Toronto, and a nice place to take a walking tour.

In this problem, Hamilton is represented by a grid of unit cells with $2R$ rows and $2C$ columns, where each cell is either empty (represented by *) or contains a building (represented by #). The cell on the $i$-th row and $j$-th column is represented by $A_{i,j}$ where $1≤i≤2R$ and $1≤j≤2C$. It is not possible to enter cells containing buildings and you can only move to an adjacent cell that shares a side with the current cell (not just a corner). The grid is such that if it is divided evenly into $2×2$ blocks of unit cells, then in each of those blocks, either all four cells are empty, or all four cells are occupied by a building. Let us represent the block formed by $A_{2i−1,2j−1},A_{2i−1,2j},A_{2i,2j−1}$, and $A_{2i,2j}$ cells as $B_{i,j}$ where $1≤i≤R$ and $1≤j≤C$.

Grace is a tourist in Hamilton and wants to visit all the empty cells in Hamilton. Grace is currently in cell $A_{1,1}$. Visiting the same cell twice could be boring for her. Hence, Grace wants to visit each of the empty cells exactly once and finally end in cell $A_{1,1}$. Can you help Grace by providing a string (consisting of directional moves {N, E, S, W} representing the unit moves to the north, east, south, or west respectively) which Grace can follow to visit every empty cell once and end again in $A_{1,1}$.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
The first line of each test case contains two integers $R$ and $C$.  
The next $R$ lines of each test case contains $C$ characters each.
The $j$-th character on the $i$-th of these lines represents the block $B_{i,j}$ formed by the following four cells: $A_{2i−1,2j−1},A_{2i−1,2j},A_{2i,2j−1}$, and $A_{2i,2j}$.  
If $B_{i,j}$= #, all four of the cells in $B_{i,j}$ are occupied by a building.  
Otherwise, if $B_{i,j}$= *, all four of the cells in $B_{i,j}$ are empty.
