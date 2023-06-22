# Problem

Hannah is working on a new language which consists only of first $L$ lowercase letters of the English alphabet. She is obsessed with palindromes, which are words that read the same forward and backward, e.g. __hannah__ and __civic__. She has written down all of the words in her language of length at most $N$, that are also palindromes.

Now, she is interested in finding the length of the word that is lexicographically $K$-th smallest among all the words she has written. A word composed of ordered letters $a_1, a_2, ..., a_p$ is lexicographically smaller than word $b_1, b_2, ..., b_q$ if $a_i < b_i$, where $i$ is the first index where characters differ in the two words. Also, a prefix of a word is considered lexicographically smaller than the word itself. For example, the following words are arranged in lexicographically increasing order: __a, aa, aba, cabac, d__.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case consists of one line containing three integers $L$, $N$, and $K$, as described above.
