# Problem

Mr. Raven is stuck in a cave represented by a matrix of $N$ rows and $M$ columns, where rows are numbered from $1$ to $N$ from top to bottom, and columns are numbered from $1$ to $M$ from left to right. The cell at the $i$-th row and the $j$-th column is denoted by $(i, j)$. Mr. Raven is currently at the cell $(S_R, S_C)$, and the exit of the cave is located at the cell $(T_R, T_C)$.

Some cells of the cave may contain obstacles. Mr. Raven cannot step into a cell that has an obstacle.
Other cells may contain traps. The first time that Mr. Raven enters a cell with a trap, he must spend a number of energy points equal to the strength of the trap. If he has fewer energy points than needed, he cannot enter the cell.
Moreover, some other cells may contain potions. The first time that Mr. Raven enters a cell with a potion, he gains energy points equal to the strength of the potion.

Mr. Raven initially has $E$ energy points. He can move between cells that share an edge (not just a corner). On the exit cell, Mr. Raven can choose not to exit the cave and continue to explore the cave if he wants to. Can you help him find the maximum number of energy points he can have when he exits the cave, if it is possible to do so?

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case consists of one line with seven integers $N, M, E, S_R, S_C, T_R$ and $T_C$ as described above.  
The $i$-th of the next $N$ lines describes the $i$-th row of the cave.  
Each line consists of $M$ integers $V_{ij}; the $j$-th of these represents the cell in the $j$-th column of the $i$-th row. Each $V_{ij}$ can be one of the following

- $0$: represents an empty cell.
- $-100000$: represents a cell with an obstacle.
- an integer between $-99999$ and $-1$ (both inclusive): represents a trap with strength $-V_{ij}$.
- an integer between $1$ and $99999$ (both inclusive): represents a potion with strength $V_{ij}$.
