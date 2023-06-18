# Problem

The laws of the universe can be represented by an array of $N$ non-negative integers. The $i$-th of these integers is $A_i$.

The universe is good if there is a non-negative integer $k$ such that the following equation is satisfied: $(A_1 \oplus k) + (A_2 \oplus k) + ... (A_N \oplus k) ≤ M$, where $\oplus$ denotes the bitwise exclusive or.

What is the largest value of $k$ for which the universe is good?

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case begins with a line containing the two integers $N$ and $M$, the number of integers in $A$ and the limit on the equation, respectively.  
The second line contains $N$ integers, the $i$-th of which is $A_i$, the $i$-th integer in the array.
