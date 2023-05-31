# Problem

Ada has bought a secret present for her friend John. In order to open the present, Ada wants John to crack a secret code. She decides to give him a hint to make things simple for him. She tells him that the secret code is a number that can be formed by taking the product of two consecutive prime numbers, such that it is the largest number that is smaller than or equal to $Z$. Given the value of $Z$, help John to determine the secret code.

Formally, let the order of prime numbers $2,3,5,7,11,...$ be denoted by $p_1,p_2,p_3,p_4,p_5, ..$. and so on. Consider $R_i$ to be the product of two consecutive primes $p_i$ and $p_{i+1}$. The secret code is the largest $R_j$ such that $R_j≤Z$.

## Input

The first line of the input gives the number of test cases, $T$. $T$ lines follow.  
Each line contains a single integer $Z$, representing the number provided by Ada as part of the hint.
