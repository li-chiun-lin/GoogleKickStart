# Problem

Kibur has made a new puzzle for you to solve! The puzzle consists of an $N$ by $N$ grid of squares. Each square is either black or white. The goal of the puzzle is to make all the squares black in as few moves as possible.

In a single move, you may choose any diagonal of squares and flip the color of every square on that diagonal (black becomes white and white becomes black). For example, the $10$ possible diagonals for a $3$ by $3$ grid are shown below.

```text
/..      ./.      ../      ...      ...
...      /..      ./.      ../      ...
...      ...      /..      ./.      ../


...      ...      \..      .\.      ..\
...      \..      .\.      ..\      ...
\..      .\.      ..\      ...      ...
```

Given the initial configuration of the board, what is the fewest moves needed to make all the squares black? You are guaranteed that it is possible to make all the squares black.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case begins with a line containing the integer $N$, the size of the grid.  
Then, $N$ lines follow, each containing $N$ characters that describe the initial configuration of the grid. The $c$-th character on the $r$-th line is the character . (ASCII number 46) if the square in the $r$-th row and $c$-th column is initially white. Otherwise, it is # (ASCII number 35), indicating that it is black.
