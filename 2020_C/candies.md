# Problem

Carl has an array of $N$ candies. The $i$-th element of the array (indexed starting from 1) is $A_i$ representing sweetness value of the $i$-th candy. He would like to perform a series of $Q$ operations. There are two types of operation:

- Update the sweetness value of a candy in the array.
- Query the sweetness score of a subarray.

The sweetness score of a subarray from index $l$ to $r$ is: $A_l × 1 - A_{l+1} × 2 + A_{l+2} × 3 - A_{l+3} × 4 + A_{l+4} × 5 ...$

More formally, the sweetness score is the sum of $(-1)^{i-l}A_i × (i - l + 1)$, for all $i$ from $l$ to $r$ inclusive.

For example, the sweetness score of:

- $[3, 1, 6] is 3 × 1 - 1 × 2 + 6 × 3 = 19$
- $[40, 30, 20, 10] is 40 × 1 - 30 × 2 + 20 × 3 - 10 × 4 = 0$
- $[2, 100] is 2 × 1 - 100 × 2 = -198$

Carl is interested in finding out the total sum of sweetness scores of all queries. If there is no query operation, the sum is considered to be $0$. Can you help Carl find the sum?

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case begins with a line containing $N$ and $Q$.  
The second line contains $N$ integers describing the array. The $i$-th integer is $A_i$. The $j$-th of the following $Q$ lines describe the $j$-th operation.  
Each line begins with a single character describing the type of operation ($U$ for update, $Q$ for query).

- For an update operation, two integers $X_j$ and $V_j$ follow, indicating that the $X_j$-th element of the array is changed to $V_j$.
- For a query operation, two integers $L_j$ and $R_j$ follow, querying the sweetness score of the subarray from the $L_j$-th element to the $R_j$-th element (inclusive).
