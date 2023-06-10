# Problem

Mike has a square matrix with $N$ rows and $N$ columns. Cell $(i,j)$ denotes the cell present at row $i$ and column $j$. Cell $(1,1)$ denotes the top left corner of the matrix. Each cell has some amount of coins associated with it and Mike can collect them only if he visits that cell. $C_{i,j}$ represents the number of coins in cell with row $i$ and column $j$. From a cell $(i,j)$, Mike can decide to go to cell $(i+1,j+1)$ or cell $(i-1,j-1)$, as long as the cell lies within the boundaries of the matrix and has not been visited yet. He can choose to start the journey from any cell and choose to stop at any point. Mike wants to maximize the number of coins he can collect. Please help him determine the maximum number of coins he can collect.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case begins with a line containing the integer $N$.  
The next $N$ lines contain $N$ integers each. The $j$-th integer in the $i$-th line represents the number of coins $C_{i,j}$ in cell $(i,j)$.
