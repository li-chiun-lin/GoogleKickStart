# Problem

There are $N$ events, numbered $1$ through $N$. The probability of occurrence of each event depends upon the occurrence of exactly one other event called the parent event, except event $1$, which is an independent event. In other words, for each event from $2$ to $N$, 3 values are given: $P_i$ denoting the parent event of event $i$, $A_i$ denoting the probability of occurrence of event $i$ if its parent event occurs, and $B_i$ denoting the probability of occurrence of event $i$ if its parent event does not occur. For event $1$, its probability of occurrence $K$ is given. There are $Q$ queries that we want to answer. Each query consists of 2 distinct events, $u_j$ and $v_j$, and you need to find the probability that both events $u_j$ and $v_j$ have occurred.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
The first line of each test case contains two integers $N$ and $Q$ denoting the number of events and number of queries, respectively.  
$N$ lines follow. The $i$-th line describes event $i$.  
The first line contains a single integer $K$ denoting the probability of occurrence of event $1$ multiplied by $10^6$.  
Each of the next $N−1$ lines consists of three integers $P_i$, $A_i$ and $B_i$ denoting the parent event of event $i$, the probability of occurrence of event $i$ if its parent event occurs multiplied by $10^6$, and the probability of occurrence of event $i$ if its parent event does not occur multiplied by $10^6$, respectively.  
Then, $Q$ lines follow, describing the queries. Each of these lines contains two distinct integers $u_j$ and $v_j$. For each query, find the probability that both events $u_j$ and $v_j$ occurred.
