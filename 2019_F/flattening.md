# Problem

Blotch has built a wall. The wall is made up of $N$ sections, numbered from $1$ to $N$ from left to right. Since he had built the wall in a hurry, not all the sections are of the same height. The $i$-th section of wall is $A_i$ metres tall.

Blotch would like to fix his wall by rebuilding some of the sections. Blotch can set the height of each section he rebuilds to any height he chooses.

Blotch will be happy if the number of indices $i$ $(1 ≤ i < N)$ where $A_i ≠ A_{i+1}$ is not more than $K$.

What is the fewest sections of the wall Blotch needs to rebuild so that he will be happy?

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case begins with a line containing the two integers $N$ and $K$, the number of sections of wall and the maximum number of changes in height between adjacent sections, respectively.  
The second line contains $N$ integers. The $i$-th integer is $A_i$, the height of the $i$-th section of wall.
