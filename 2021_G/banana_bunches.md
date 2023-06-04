# Problem

Barbara goes to Alan's banana farm, where the $N$ banana trees are organized in one long line represented by an array $B$. The tree at position $i$ has $B_i$ banana bunches. Each tree has the same cost. Once Barbara buys a tree, she gets all the banana bunches on that tree.

Alan has a special rule: because he does not want too many gaps in his line, he allows Barbara to buy at most $2$ contiguous sections of his banana tree line.

Barbara wants to buy some number of trees such that the total number of banana bunches on these purchased trees equals the capacity $K$ of her basket. She wants to do this while spending as little money as possible. How many trees should she buy?

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case begins with a line containing two integers integer $N$, the number of trees on Alan's farm, and $K$, the capacity of Barbara's basket.  
The next line contains $N$ non-negative integers $B_1,B_2,…,B_N$ representing array $B$, where the $i$-th integer represents the number of banana bunches on the $i$-th tree on Alan's farm.
