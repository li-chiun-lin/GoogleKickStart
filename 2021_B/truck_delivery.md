# Problem

Charles is a truck driver in the city of Googleland. Googleland is built in form of a tree with N nodes where each node represents a city and each edge represents a road between two cities. The cities are numbered 1 to N. The capital of Googleland is city 1. Each day Charles picks up a load of weight W in city C and wants to deliver it to city 1 using the simple path (which is unique) between the cities. Each road i has a toll which charges amount Ai if the weight of the load is greater than or equal to a load-limit Li.

Charles works for Q days, where for each day Charles will be given the starting city C and weight of the load W. For each day find the greatest common divisor of all the toll charges that Charles pays for that day. If Charles did not have to pay in any of the tolls the answer is 0.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
The first line of each test case contains the two integers $N$ and $Q$.  
The next $N−1$ lines describe the roads. $i$-th of these lines contains the four space separated integers $X$, $Y$, $L_i$ and $A_i$, indicating a road between cities $X$ and $Y$ with load-limit $L_i$ and toll charge $A_i$.  
The next $Q$ lines describe the queries. $j$-th of these lines contains the two space separated integers $C_j$ and $W_j$ representing the starting city and weight of the load on $j$-th day.
