# Problem

You are given a prime number $P$.

Let's define $V(x)$ as the degree of $P$ in the prime factorization of $x$. To be clearer, if $V(x)=y$ then $x$ is divisible by $P^y$, but not divisible by $P^{y+1}$. Also we define $V(0)=0$.

For example, when $P=3$, and $x=45$, since $45=5⋅3^2$, therefore $V(45)=2$.

You are also given an array $A$ with $N$ elements. You need to process $Q$ queries of 2 types on this array:

- type 1 query: $1$ $pos$ $val$ - assign a value $val$ to the element at $pos$, i.e. $A_{pos}:=val$
- type 2 query: $2$ $S$ $L$ $R$ - print $∑_{i=L}^R V(A_i^S−(A_i \mod P)^S)$.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
The first line of each test case contains 3 space separated positive integers $N$, $$Q and $P$ - the number of elements in the array, the number of queries and a prime number.  
The next line contains $N$ positive integers $A_1,A_2,…,A_N$ representing elements of array $A$.  
Each of the next $Q$ lines describes a query, and contains either

- 3 space separated positive integers: $1$ $pos$ $val$
- or 4 space separated positive integers: $2$ $S$ $L$ $R$
