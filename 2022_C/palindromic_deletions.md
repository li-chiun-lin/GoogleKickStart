# Problem

Games with words and strings are very popular lately. Now Edsger tries to create a similar new game of his own. Here is what he came up with so far.

Edsger's new game is called Palindromic Deletions. As a player of this game, you are given a string of length $N$. Then you will perform the following process $N$ times:

1. Pick an index in the current string uniformly at random.
1. Delete the character at that index. You will then end up with a new string with one fewer character.
1. If the new string is a palindrome, you eat a piece of candy in celebration.

Now Edsger wonders: given a starting string, what is the expected number of candies you will eat during the game?

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow. Each test case consists of two lines.  
The first line of each test case contains an integer $N$, representing the length of the string.  
The second line of each test case contains a string $S$ of length $N$, consisting of lowercase English characters.
