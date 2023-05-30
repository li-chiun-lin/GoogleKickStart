# Problem

Ada has $N$ ants labelled from $1$ to $N$. She decides to test John's concentration skills. She takes a stick $L$ cm long, and drops the ants on it.

The positions on the stick at which the ants are dropped are represented by an integer array $P$, where ant $i$ is dropped at the position $P_i$ (that is, $P_i$ cm away from the left end) on the stick. Each ant travels either to the left or right with a constant speed of $1$ cm per second. The initial directions of the ants is represented by an array $D$, where the direction of ant $i$ is $D_i$: $0$ if left, and $1$ if right. When two ants meet, they bounce off each other and reverse their directions. The ants fall off the stick when they reach either end of it.

Ada challenges John to find the exact order in which the ants fall off the stick. John needs your help!

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
The first line of each test case contains two integers, $N$ and $L$: the number of ants, and the length of the stick, respectively.  
The next $N$ lines describe the positions and directions of the ants.  
The $i$-th line contains two integers, $P_i$ and $D_i$: the position and direction of ant $i$, respectively.
