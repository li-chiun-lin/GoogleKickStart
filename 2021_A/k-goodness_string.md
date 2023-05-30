# Problem

Charles defines the goodness score of a string as the number of indices $i$ such that $S_i≠S_{N−i+1}$ where $1≤i≤N/2$ (1-indexed). For example, the string CABABC has a goodness score of 2 since $S_2≠S_5$ and $S_3≠S_4$.

Charles gave Ada a string $S$ of length $N$, consisting of uppercase letters and asked her to convert it into a string with a goodness score of $K$. In one operation, Ada can change any character in the string to any uppercase letter. Could you help Ada find the minimum number of operations required to transform the given string into a string with goodness score equal to $K$?

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
The first line of each test case contains two integers $N$ and $K$.  
The second line of each test case contains a string $S$ of length $N$, consisting of uppercase letters.
