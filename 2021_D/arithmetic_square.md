# Problem

You are given a $3×3$ grid of integers. Let $G_{i,j}$ denote the integer in the $i$-th row and $j$-th column of the grid, where $i$ and $j$ are 0-indexed. The integer in the middle of the grid, $G_{1,1}$, is missing. Find the maximum number of rows, columns, and diagonals of this square, that form sequences which are arithmetic progressions. You can replace the missing number with any integer.

An arithmetic progression (also known as arithmetic sequence) is a sequence of numbers such that the difference between consecutive terms is constant. In mathematical terms, this can be represented as $a_n=a_{n−1}+d$, where $d$ is the common difference. In this problem, a sequence can be the 3 numbers in either a row, column or diagonal. We are looking to replace the missing value by an integer that maximizes the number of arithmetic progressions that can be found in the resulting set of sequences.

Two sequences are considered different if they are from different rows, columns, or diagonals. For example, the sequence $\{2,4,6\}$ across the middle row and $\{2,4,6\}$ across the top row will be counted as two sequences but the sequences $\{2,4,6\}$ and $\{6,4,2\}$ across the same row, column, or diagonal will be counted as one sequence.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow. Each test case consists of 3 lines.  
The first line of each test case contains 3 integers, $G_{0,0}, G_{0,1},$ and $G_{0,2}$.  
The second line of each test case contains 2 integers, $G_{1,0}$ and $G_{1,2}$.  
The last line of each test case contains 3 integers, $G_{2,0}, G_{2,1},$ and $G_{2,2}$.
