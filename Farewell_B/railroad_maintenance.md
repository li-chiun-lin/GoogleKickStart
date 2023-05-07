# Problem

You are in charge of the maintenance of a railroad network. The network consists of $N$ stations and $L$ train lines. Each train line serves a fixed list of stations bidirectionally (trains turn around in the first and last stations of the list). Transfers from one line to another in a station are possible, which means a trip in the network from station $a$ to station $b$ is possible if there is a list of train lines such that the first one serves station $a$, the last one serves station $b$, and for any consecutive pair of train lines in the list there is at least one station that they both serve.

The easiest way to do maintenance is to shut down entire lines, one at a time. However, some train lines may be essential. A train line is essential if removing it would make at least one trip between a pair of stations not possible.

Given the list of existing train lines, calculate how many of them are essential.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case starts with a line containing two integers $N$ and $L$: the number of stations and train lines in the network. Then, $L$ groups of 2 lines follow.  
The first line of the $i$-th group contains a single integer $K_i$ the number of stations served by the $i$-th train line.  
The second line of the $i$-th group contains $K_i$ integers $S_{i,1},S_{i,2},…,S_{i,K_i}$ representing the stations served by the $i$-th train line.
