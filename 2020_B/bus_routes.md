# Problem

Bucket is planning to make a very long journey across the countryside by bus. Her journey consists of $N$ bus routes, numbered from $1$ to $N$ in the order she must take them. The buses themselves are very fast, but do not run often. The $i$-th bus route only runs every $X_i$ days.

More specifically, she can only take the $i$-th bus on day $X_i$, $2X_i$, $3X_i$ and so on. Since the buses are very fast, she can take multiple buses on the same day.

Bucket must finish her journey by day $D$, but she would like to start the journey as late as possible. What is the latest day she could take the first bus, and still finish her journey by day $D$?

It is guaranteed that it is possible for Bucket to finish her journey by day $D$.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case begins with a line containing the two integers $N$ and $D$.  
Then, another line follows containing $N$ integers, the $i$-th one is $X_i$.
