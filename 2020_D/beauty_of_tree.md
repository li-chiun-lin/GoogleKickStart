# Problem

Amadea and Bilva are decorating a rooted tree containing $N$ nodes, labelled from $1$ to $N$. Node $1$ is the root of the tree, and all other nodes have a node with a numerically smaller label as their parent.

Amadea and Bilva's decorate the tree as follows:

- Amadea picks a node of the tree uniformly at random and paints it. Then, she travels up the tree painting every $A$-th node until she reaches the root.
- Bilva picks a node of the tree uniformly at random and paints it. Then, she travels up the tree painting every $B$-th node until she reaches the root.

The beauty of the tree is equal to the number of nodes painted at least once by either Amadea or Bilva. Note that even if they both paint a node, it only counts once.

What is the expected beauty of the tree?

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case begins with a line containing the three integers $N$, $A$ and $B$.  
The second line contains $N-1$ integers. The $i$-th integer is the parent of node $i+1$.
