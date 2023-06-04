# Problem

You are given an integer $K$ and a string $S$ of length $N$, consisting of lowercase letters from the first $K$ letters of the English alphabet. Find the number of palindrome strings of length $N$ which are lexicographically smaller than $S$ and consist of lowercase letters from the first $K$ letters of the English alphabet.

A string composed of ordered letters $a_1,a_2,…,a_n$ is lexicographically smaller than another string of the same length $b_1,b_2,…,b_n$ if $a_i<b_i$, where $i$ is the first index where characters differ in the two strings. For example, the following strings are arranged in lexicographically increasing order: $aaa$, $aab$, $aba$, $cab$.

A palindrome is a string that is the same written forwards and backwards. For example, $anna$, $racecar$, $aaa$ and $x$ are all palindromes, while $ab$, $frog$ and $yoyo$ are not.

As the number of such strings can be very large, print the answer modulo $10^9+7$.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow. Each test case consists of two lines.  
The first line contains two integers $N$ and $K$.  
The second line contains a string $S$ of length $N$, consisting of lowercase letters.
