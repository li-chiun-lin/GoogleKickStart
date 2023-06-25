# Problem

Given $N$ integers $A_1, A_2, ..., A_N$, count the number of triplets $(x, y, z)$ (with $1 ≤ x < y < z ≤ N$) such that at least one of the following is true:

- $A_x = A_y × A_z$, and/or
- $A_y = A_x × A_z$, and/or
- $A_z = A_x × A_y$

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each begins with one line containing an integer $N$: the number of integers in array A.  
The second line consists of $N$ integers $A_i$; the $i$-th of these is the value of the $i$-th integer, as described above.
