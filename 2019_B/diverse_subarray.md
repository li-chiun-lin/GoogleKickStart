# Problem

Vanity has $N$ trinkets on her shelf, numbered $1, 2, ..., N$ from left to right. Trinkets come in different types, which are denoted by positive integers. The $i$-th trinket on her shelf is of type $A_i$.

She is going to see her family overseas today and would like to bring as many trinkets as she can. However, since she is in a hurry, Vanity must take a consecutive interval of trinkets. Formally, Vanity selects two indices, $l$ and $r$, and takes all of the trinkets numbered $l, l+1, ..., r-1, r$. Also, due to tax rules, airport security will throw away all trinkets of a type if Vanity has more than $S$ of that type in the chosen interval.

For example, suppose that $S = 2$, and Vanity brings six trinkets: one of type $0$, two of type $1$, and three of type $2$. She will be allowed to keep the trinket of type $0$ and both trinkets of type $1$, but she will lose all of the trinkets of type $2$!

Vanity needs to choose $l$ and $r$ such that she can take the maximum number of trinkets for her family. What is the maximum number of trinkets she can bring?

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
The first line of each test case contains the two integers $N$ and $S$, the number of trinkets, and the maximum number of trinkets allowed of a single type, respectively.  
The second line contains $N$ integers. The $i$-th integer gives $A_i$, the type of the $i$-th trinket.
