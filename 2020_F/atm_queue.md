# Problem

There are $N$ people numbered from $1$ to $N$, standing in a queue to withdraw money from an ATM. The queue is formed in ascending order of their number. The person numbered $i$ wants to withdraw amount $A_i$. The maximum amount a person can withdraw at a time is $X$. If they need more money than $X$, they need to go stand at the end of the queue and wait for their turn in line. A person leaves the queue once they have withdrawn the required amount.

You need to find the order in which all the people leave the queue.

## Input

The first line of the input gives the number of test cases $T$. $T$ test cases follow.  
The first line of each test case gives two space separated integers: the number of people standing in the queue, $N$ and the maximum amount $X$ that can be withdrawn in one turn.  
The next line contains $N$ space separated integers $A_i$.
