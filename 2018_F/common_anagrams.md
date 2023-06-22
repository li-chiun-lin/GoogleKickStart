# Problem

Ayla has two strings $A$ and $B$, each of length $L$, and each of which is made of uppercase English alphabet letters. She would like to know how many different substrings of $A$ appear as anagrammatic substrings of $B$. More formally, she wants the number of different ordered tuples $(i, j)$, with $0 ≤ i ≤ j < L$, such that the $i$-th through $j$-th characters of $A$ (inclusive) are the same multiset of characters as at least one contiguous substring of length $(j - i + 1)$ in $B$.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case starts with one line, containing $L$: the length of the string.  
The next two lines contain one string of $L$ characters each: these are strings $A$ and $B$, in that order.
