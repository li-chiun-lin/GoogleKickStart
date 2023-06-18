# Problem

Supervin is a librarian handling an ancient book with $N$ pages, numbered from $1$ to $N$. Since the book is too old, unfortunately $M$ pages are torn out: page number $P_1, P_2, ..., P_M$.

Today, there are $Q$ lazy readers who are interested in reading the ancient book. Since they are lazy, each reader will not necessarily read all the pages. Instead, the $i$-th reader will only read the pages that are numbered multiples of $R_i$ and not torn out. Supervin would like to know the sum of the number of pages read by each reader.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case begins with a line containing the three integers $N$, $M$, and $Q$, the number of pages in the book, the number of torn out pages in the book, and the number of readers, respectively.  
The second line contains $M$ integers, the $i$-th of which is $P_i$.  
The third line contains $Q$ integers, the $i$-th of which is $R_i$.
