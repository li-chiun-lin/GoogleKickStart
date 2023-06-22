# Problem

In order to advance in his quest to defeat the villainous Graphendorf, our hero Edge has to overcome a challenge in a shrine. The shrine is two-dimensional in the xy-plane, and there are $N$ towers (of varying heights) erected along the x-axis of the plane. Each tower can be represented by a vertical line segment in a 2D plane. For tower $i$, the base of the tower is at $(p_i, 0)$, and the top of the tower is at $(p_i, h_i)$. There are also $K$ balloons floating in the plane. Each balloon can be represented by a single point in the 2D plane, with balloon $i$ at position $(x_i, y_i)$. Edge has to collect as many balloons as possible in this challenge.

Fortunately, Edge has a trusty paraglider which he found in a different room of this shrine. He may choose to climb any tower and glide down from any position on the tower towards either the positive or negative direction of the x-axis. When he glides, he descends in a straight path that makes a 45 degrees angle relative to the tower. Edge can collect any balloons in his way when he glides down from the tower. He can repeat this process of climbing up a tower and jumping off any number of times. If he touches a tower during his descent, then he is considered to be on the tower at the point and climbing. You may assume Edge to be a single point in the xy-plane.

Using a pair of goggles made from ancient technology, Edge was able to figure out the height and position of each tower and balloon. With this information, can you help Edge deduce the maximum number of balloons that he can collect in this shrine?

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow. Each test case contains five lines.  
The first line contains the integers $N$ and $K$ as described above.  
Each of the next four lines describe a recurrence used to generate the positions and heights of the towers and the $x$ and $y$ coordinates of the balloons. The four lines will each contain six integers in the following format:

$p_1\ p_2\ A_1\ B_1\ C_1\ M_1$  
$h_1\ h_2\ A_2\ B_2\ C_2\ M_2$  
$x_1\ x_2\ A_3\ B_3\ C_3\ M_3$  
$y_1\ y_2\ A_4\ B_4\ C_4\ M_4$

To generate the values for $p_i$ (from $3$ to $N$), $h_i$ (from $3$ to $N$), $x_i$ (from $3$ to $K$) and $y_i$ (from $3$ to $K$), we use the following recurrences:

$p_i = (A_1 × p_{i - 1} + B_1 × p_{i - 2} + C_1) \mod M_1 + 1$, for $i = 3$ to $N$.  
$h_i = (A_2 × h_{i - 1} + B_2 × h_{i - 2} + C_2) \mod M_2 + 1$, for $i = 3$ to $N$.  
$x_i = (A_3 × x_{i - 1} + B_3 × x_{i - 2} + C_3) \mod M_3 + 1$, for $i = 3$ to $K$.  
$y_i = (A_4 × y_{i - 1} + B_4 × y_{i - 2} + C_4) \mod M_4 + 1$, for $i = 3$ to $K$.

It is guaranteed that no two towers share the same position. However, it is possible for a tower to overlap with a balloon. In this case, we assume that the balloon can be collected. Note that two or more balloons might share a point; in that case, Edge can collect all of those balloons at once by passing through that point.
