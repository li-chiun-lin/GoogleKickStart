# Problem

A crossword puzzle is a rectangular grid of black cells and letters A-Z.

Words in the crossword are defined as maximal vertical or horizontal segments of characters.

A palindromic crossword is one where every word is a palindrome. Let $R_{i,j}$ represent the character on the $i$-th row and $j$-th column, where $i$ and $j$ are 1-indexed. The top left corner is $R_{1,1}$.

You have been gifted a palindromic crossword puzzle with $N$ rows and $M$ columns. You finished the crossword and throw away the clues, preparing to hang it on your wall. However, you accidentally erase some of the letters! You want to recover as much of the crossword as possible, but you do not have the clues anymore. Using only the knowledge that the crossword is palindromic, restore the maximum possible number of missing characters in the given crossword.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
The first line of each test case contains two integers, $N$ and $M$, representing the number of rows and columns in the crossword, respectively.  
The next $N$ lines represent the $N$ rows of the grid. The $i$-th row consists of $M$ characters representing $R_{i,1}, R_{i,2}, …, R_{i,M}$. Each character is one of the following:

- A capital letter of the alphabet (A-Z)
- A period (.) for a missing letter (empty white cell in the example crossword)
- A hash (#) for black cell
