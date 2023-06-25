# Problem

Today, Sherlock and Watson attended a lecture in which they were introduced to matrices. Sherlock is one of those programmers who is not really interested in linear algebra, but he did come up with a problem involving matrices for Watson to solve.

Sherlock has given Watson two one-dimensional arrays $A$ and $B$; both have length $N$. He has asked Watson to form a matrix with $N$ rows and $N$ columns, in which the $j$-th element in the $i$-th row is the product of the $i$-th element of $A$ and the $j$-th element of $B$.

Let $(x, y)$ denote the cell of the matrix in the $x$-th row (numbered starting from $0$, starting from the top row) and the $y$-th column (numbered starting from $0$, starting from the left column). Then a submatrix is defined by bottom-left and top-right cells $(a, b)$ and $(c, d)$ respectively, with $a ≥ c$ and $d ≥ b$, and the submatrix consists of all cells $(i, j)$ such that $c ≤ i ≤ a$ and $b ≤ j ≤ d$. The sum of a submatrix is defined as sum of all of the cells of the submatrix.

To challenge Watson, Sherlock has given him an integer $K$ and asked him to output the $K$-th largest sum among all submatrices in Watson's matrix, with $K$ counting starting from $1$ for the largest sum. (It is possible that different values of $K$ may correspond to the same sum; that is, there may be multiple submatrices with the same sum.) Can you help Watson?

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case consists of one line with nine integers $N, K, A_1, B_1, C, D, E_1, E_2$ and $F$. $N$ is the length of arrays $A$ and $B$; $K$ is the rank of the submatrix sum Watson has to output, $A_1$ and $B_1$ are the first elements of arrays $A$ and $B$, respectively; and the other five values are parameters that you should use to generate the elements of the arrays, as follows:

First define $x_1 = A_1, y_1 = B_1, r_1 = 0, s_1 = 0$. Then, use the recurrences below to generate $x_i$ and $y_i$ for $i = 2$ to $N$:

$x_i = ( C \times x_{i-1} + D \times y_{i-1} + E_1 ) \mod F$.  
$y_i = ( D \times x_{i-1} + C \times y_{i-1} + E_2 ) \mod F$.

Further, generate $r_i$ and $s_i$ for $i = 2$ to $N$ using following recurrences:

$r_i = ( C \times r_{i-1} + D \times s_{i-1} + E_1 ) \mod 2$.  
$s_i = ( D \times r_{i-1} + C \times s_{i-1} + E_2 ) \mod 2$.

We define $A_i = (-1)^{r_i} \times x_i$ and $B_i = (-1)^{s_i} \times y_i$, for all $i = 2$ to $N$.
