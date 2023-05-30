# Problem

Given a grid of $R$ rows and $C$ columns each cell in the grid is either $0$ or $1$.

A segment is a nonempty sequence of consecutive cells such that all cells are in the same row or the same column. We define the length of a segment as number of cells in the sequence.

A segment is called "good" if all the cells in the segment contain only $1$'s.

An "L-shape" is defined as an unordered pair of segments, which has all the following properties:

- Each of the segments must be a "good" segment.
- The two segments must be perpendicular to each other.
- The segments must share one cell that is an endpoint of both segments.
- Segments must have length at least 2.
- The length of the longer segment is twice the length of the shorter segment.

We need to count the number of L-shapes in the grid.

## Input

The first line of the input contains the number of test cases, $T$. $T$ test cases follow.  
The first line of each testcase contains two integers $R$ and $C$.  
Then, $R$ lines follow, each line with $C$ integers representing the cells of the grid.
