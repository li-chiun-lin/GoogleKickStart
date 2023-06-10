# Problem

A combination lock has $W$ wheels, each of which has the integer values $1$ through $N$ on it, in ascending order.

At any moment, each wheel shows a specific value on it. $X_i$ is the initial value shown on the $i$-th wheel.

You can use a single move to change a wheel from showing the value $X$ to showing either $X+1$ or $X-1$, wrapping around between $1$ and $N$.

Given all wheels' initial values, what is the minimum number of moves to get all wheels to show the same value?

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
The first line of each test case contains the two integers $W$ and $N$.  
The second line contains $W$ integers. The $i$-th integer is $X_i$.
