# Problem

Supervin loves to eat candies. Today, his favorite candy shop is offering $N$ candies, which are arranged in a line. The $i$-th candy in the line (counting starting from $1$) has a sweetness level $S_i$. Note that the sweetness level of a candy might be negative, which means the candy tastes bitter.

Supervin likes to eat sweet candies. However, candies with a combined sweetness level of more than $D$ would be too much sweetness even for him. Supervin also realises that a candy with an odd sweetness level is "odd", and he does not want to eat more than $O$ odd candies. In other words, an odd candy is a candy with a sweetness level that is not evenly divisible by $2$. Additionally, since Supervin is in a rush, he can only eat a single contiguous subset of candies.

Therefore, he wants to eat a contiguous non-empty subset of candies in which there are at most $O$ odd candies and the total sweetness level is maximized, but not more than $D$. Help Supervin to determine the maximum total sweetness level he can get, or return $IMPOSSIBLE$ if there is no contiguous subset satisfying these constraints.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow. Each test case contains two lines.  
The first line contains three integers $N$, $O$, and $D$, as described above.  
The second line contains seven integers $X_1, X_2, A, B, C, M, L$; these values are used to generate the values $S_i$, as follows:

We define:

- $X_i = (A × X_{i - 1} + B × X_{i - 2} + C) \mod M$, for $i = 3$ to $N$.
- $S_i = X_i + L$, for $i = 1$ to $N$.
