# Problem

Arsh recently found an old rectangular circuit board that he would like to recycle. The circuit board has $R$ rows and $C$ columns of squares.

Each square of the circuit board has a thickness, measured in millimetres. The square in the $r$-th row and $c$-th column has thickness $V_{r,c}$. A circuit board is good if in each row, the difference between the thickest square and the least thick square is no greater than $K$.

Since the original circuit board might not be good, Arsh would like to find a good subcircuit board. A subcircuit board can be obtained by choosing an axis-aligned subrectangle from the original board and taking the squares in that subrectangle. Arsh would like your help in finding the number of squares in the largest good subrectangle of his original board.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow. Each test case begins with one line containing three integers $R, C$ and $K$, the number of rows, the number of columns, and the maximum difference in thickness allowed in each row.  
Then, there are $R$ more lines containing $C$ integers each. The $c$-th integer on the $r$-th line is $V_{r, c}$, the thickness of the square in the $r$-th row and $c$-th column.
