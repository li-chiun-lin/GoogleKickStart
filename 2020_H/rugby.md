# Problem

On a far away planet, rugby is played in the two dimensional Cartesian coordinate system without bounds. The players can occupy integer grid points only and they can move to the neighboring grid points in any of the four cardinal directions. Specifically, if a player is currently at the point $(X, Y)$, then they can move to either of the points $(X+1, Y), (X-1, Y), (X, Y+1),$ or $(X, Y-1)$ in a single step.

After the game, $N$ players are scattered throughout the coordinate system such that any grid point is empty or occupied by one or more players. They want to gather for a picture and form a perfect horizontal line of $N$ grid points, one player per point, all occupied points next to each other. Formally, the players have to move so as to occupy the grid points $(X, Y), (X+1, Y), (X+2, Y), ..., (X+N-1, Y)$ for some coordinates $X$ and $Y$. What is the minimum total number of steps the players should make to form a perfect line if they are free to choose the position of the line in the coordinate system and the ordering of players is not important?

## Input

The first line of the input gives the number of test cases $T$. $T$ test cases follow.  
The first line of each test case gives the number of players $N$.  
The subsequent $N$ lines give the initial coordinates of the players. The $i$-th of these lines contains two integers $X_i$ and $Y_i$, which describe the initial position of $i$-th player $(1 ≤ i ≤ N)$.
