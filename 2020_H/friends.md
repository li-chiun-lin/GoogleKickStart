# Problem

There are $N$ people in the world numbered $1$ to $N$. The $i$-th person has a distinct name $S_i$ that is a string of uppercase English letters.

Two people are friends if and only if there is some letter that appears at least once in each of their names. Any such letter does not need to be at the same position in both names. After all, friendship requires having something in common!

A friendship chain of length $n$ between person $A$ and person $B$ is a sequence of people $X_1, X_2, ..., X_n$ such that $X_1 = A, X_n = B$, and $X_i$ and $X_{i+1}$ are friends, for $i=1$ to $n-1$. Note that any two people can have zero or more friendship chains between them.

For each of the given $Q$ pairs of people, can you find the length of the shortest friendship chain between them? If there is no friendship chain between a pair, output $-1$.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
The first line of each test case contains the two integers $N$ and $Q$.  
The second line contains $N$ strings, which are people's names. The $i$-th string (starting from $1$) is $S_i$.  
Then, $Q$ lines follow, describing the queries. The $i$-th of these lines contains the two integers $X_i$ and $Y_i$, which are the indexes (counting starting from $1$) of a pair of people in the list of names.
