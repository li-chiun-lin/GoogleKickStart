# Problem

You are given two integers, the number of vertices $N$ and area $A$. You need to construct a simple polygon of $N$ vertices such that the area of the polygon is exactly $A/2$, and all the vertices have non-negative integer coordinates with value up to $10^9$.

A simple polygon is one that:

- Defines a closed area.
- Does not have self-intersections, even at a single point.
- No two consecutive edges form a straight angle.

## Input

The first line of the input gives the number of test cases, $T$. $T$ lines follow.  
The first line of each test case contains two integers, $N$ denoting the number of vertices and $A$, denoting double the required area of the polygon.
