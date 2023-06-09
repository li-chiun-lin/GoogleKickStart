# Problem

Consider an infinite complete binary tree where the root node is $1/1$ and left and right childs of node $p/q$ are $p/(p+q)$ and $(p+q)/q$, respectively. This tree looks like:

```text
         1/1
    ______|______
    |           |
   1/2         2/1
 ___|___     ___|___
 |     |     |     |
1/3   3/2   2/3   3/1
...
```

It is known that every positive rational number appears exactly once in this tree. A level-order traversal of the tree results in the following array:

$1/1, 1/2, 2/1, 1/3, 3/2, 2/3, 3/1, \dots$

Please solve the following two questions:

- Find the $n$-th element of the array, where $n$ starts from $1$.
- Given $p/q$, find its position in the array.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow. Each test case consists of one line. The line contains a problem id ($1$ or $2$) and one or two additional integers:

1. If the problem id is $1$, then only one integer $n$ is given, and you are expected to find the $n$-th element of the array.
1. If the problem id is $2$, then two integers $p$ and $q$ are given, and you are expected to find the position of $p/q$ in the array.
