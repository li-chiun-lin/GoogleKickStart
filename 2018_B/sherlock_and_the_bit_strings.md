# Problem

Sherlock and Watson are playing a game involving bit strings, i.e., strings consisting only of the digits 0 and 1. Watson has challenged Sherlock to generate a bit string $S$ of $N$ characters $S_1, S_2, ..., S_N$. The string must obey each of $K$ different constraints; each of these constraints is specified via three integers $A_i$, $B_i$, and $C_i$. The number of 1s in the substring $S_{A_i}, S_{A_i + 1}, ..., S_{B_i}$ must be equal to $C_i$.

Watson chooses the constraints in a way that guarantees that there is at least one string of the right length that obeys all of the constraints. However, since there could be multiple such strings, Watson wants Sherlock to choose the string from this set that is $P$-th in lexicographic order, with $P$ counted starting from 1.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case begins with one line containing three integers $N$, $K$, and $P$, as described above.  
Then, there are $K$ more lines; the $i$-th of these contains three integers $A_i$, $B_i$ and $C_i$, representing the parameters of the $i$-th constraint, as described above.
