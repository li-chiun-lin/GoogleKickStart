# Problem

Imagine you have a padlock, which is a combination lock consisting of $N$ dials, set initially to a random combination. The dials of the padlock are of size $D$, which means that they can have values between $0$ and $D−1$, inclusive, and can be rotated upwards or downwards. They are also ordered from left to right, with the leftmost and rightmost dials at positions $1$ and $N$, respectively. The padlock can be unlocked by setting the values of all its dials to $0$.

You can perform zero or more operations of this kind:

- Pick any range $[l,r]$ such that 1≤l≤r≤N and rotate all the dials in $[l,r]$ together, upwards or downwards. Rotating up increases the value of each dial in the range $[l,r]$ by $1$, and rotating down decreases its value by $1$. Note that a dial with value $D−1$ becomes $0$ when increased (rotated up) and a dial with value $0$ becomes $D−1$ when decreased (rotated down).

The series of operations must satisfy the following condition:

- The range $[l_{i−1},r_{i−1}]$ chosen in the $(i−1)$-th operation needs to be completely contained within the range $[l_i,r_i]$ chosen in the $i$-th operation; that is, $l_i≤l_{i−1}≤r_{i−1}≤r_i$. The initial range ($[l_1,r_1]$) can be chosen arbitrarily.

Example of a valid sequence of operations to unlock a padlock with initial combination $[1,1,2,2,3,3]$:

1. Rotate range $[5,6]$ downwards.
1. Rotate range $[3,6]$ downwards.
1. Rotate range $[1,6]$ downwards.

The following are some operations that cannot be performed:

1. Rotating range $[1,4]$ after $[6,9]$, because $[6,9]$ is not completely contained in $[1,4]$ (does not satisfy $r_{i−1}≤r_i$ where $r_{i−1}=9$ and $r_i=4$).
1. Rotating range $[3,6]$ after $[2,7]$.

The goal for you is to output the minimum number of valid operations needed to make all dials in the padlock set to $0$.

## Input

The first line of the input contains the number of test cases, $T$. $T$ test cases follow.  
Each test case consists of two lines.  
The first line of each test case contains two integers $N$ and $D$, representing the number of dials in the padlock and the size of the dials, respectively.  
The second line of each test case contains $N$ integers $V_1,V_2,…,V_N$, where the $i$-th integer represents the value of the $i$-th dial in the initial combination of the padlock.
