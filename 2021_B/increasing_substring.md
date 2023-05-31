# Problem

Your friend John just came back from vacation, and he would like to share with you a new property that he learned about strings.

John learned that a string $C$ of length $L$ consisting of uppercase English characters is strictly increasing if, for every pair of indices $i$ and $j$ such that $1≤i<j≤L$ (1-based), the character at position $i$ is smaller than the character at position $j$.

For example, the strings ABC and ADF are strictly increasing, however the strings ACC and FDA are not.

Now that he taught you this new exciting property, John decided to challenge you: given a string $S$ of length $N$, you have to find out, for every position $1≤i≤N$, what is the length of the longest strictly increasing substring that ends at position $i$.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case consists of two lines.  
The first line contains an integer $N$, representing the length of the string.  
The second line contains a string $S$ of length $N$, consisting of uppercase English characters.
