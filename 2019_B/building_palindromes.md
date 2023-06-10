# Problem

Anna has a row of $N$ blocks, each with exactly one letter from A to Z written on it. The blocks are numbered $1, 2, ..., N$ from left to right.

Today, she is learning about palindromes. A palindrome is a string that is the same written forwards and backwards. For example, ANNA, RACECAR, AAA and X are all palindromes, while AB, FROG and YOYO are not.

Bob wants to test how well Anna understands palindromes, and will ask her $Q$ questions. The $i$-th question is: can Anna use all of the blocks numbered from $L_i$ to $R_i$, inclusive, rearranging them if necessary, to form a palindrome? After each question, Anna puts the blocks back in their original positions.

Please help Anna by finding out how many of Bob's questions she can answer "yes" to.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case starts with a line containing the two integers $N$ and $Q$, the number of blocks and the number of questions, respectively.  
Then, another line follows, containing a string of $N$ uppercase characters (A to Z).  
Then, $Q$ lines follow. The $i$-th line contains the two integers $L_i$ to $R_i$, describing the $i$-th question.
