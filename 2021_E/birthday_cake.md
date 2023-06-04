# Problem

You are given a grid of $R$ ows and $C$ columns that corresponds to a birthday cake. The rows are numbered from $1$ to $R$ starting from the top. The columns are numbered from $1$ to $C$ starting from the left. Each cell in the grid is a square of size $1×1$. You noticed that the most delicious part of the cake forms a single filled rectangle; that means all the cells inside this single rectangle will be delicious as well, but all the cells outside this rectangle are not delicious. You have a knife that is long enough to make straight-line cuts of length up to $K$.

We want to make a series of cuts to extract each of the delicious cells separately, so that we can put candles on them, and enjoy the birthday party. To extract each of the delicious cells separately, they must be disconnected from any other cell. A cell is disconnected if no other cell is connected to it in any of the 4 directions (up, down, left, right).

A cut is a directed line segment which is valid if the following conditions are met:

- The cut runs along one of the horizontal or vertical lines between the rows and columns of the grid.
- The length of the cut must not exceed $K$.
- The starting and ending points of the cut must be grid points (i.e. a corner of a cell). In addition, the starting point must be already exposed, meaning that it lies on one of the 4 sides of the grid or on one of the previous cuts.
- The cut must not pass through any other exposed points. It may touch an exposed point, but if it does, it must end right there.

We need to find the minimum number of cuts needed to extract all the delicious cells.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case starts with a line containing three integers, $R$, $C$ and $K$.  
The next line contains four integers, $r_1, c_1, r_2, c_2$, representing the top-left and bottom-right cell of the delicious rectangle respectively.
