# Problem

Li has planned a bike tour through the mountains of Switzerland. His tour consists of $N$ checkpoints, numbered from $1$ to $N$ in the order he will visit them. The $i$-th checkpoint has a height of $H_i$.

A checkpoint is a peak if:

- It is not the 1st checkpoint or the $N$-th checkpoint, and
- The height of the checkpoint is strictly greater than the checkpoint immediately before it and the checkpoint immediately after it.

Please help Li find out the number of peaks.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case begins with a line containing the integer $N$.  
The second line contains $N$ integers. The $i$-th integer is $H_i$.
