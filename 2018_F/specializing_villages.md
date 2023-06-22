# Problem

The countryside of Kickstartia consists of $V$ villages, connected by $E$ bidirectional roads. Because the citizens appreciate diversity in their road construction, no two roads have the same length. Each road connects exactly two villages, and no two roads connect the same two villages.

The new king, eager to show off his progressiveness, would like to create a plan in which each village will specialize in producing exactly one food: either fruit or vegetables. If a village produces fruit, then they will find a shortest path (perhaps using multiple roads) to some village that produces vegetables. Similarly, if a village produces vegetables, then they will find a shortest path to some village that produces fruit.

To keep things running smoothly, the king would like to minimize the average of the distances that each village needs to travel to get the food that it does not produce.

There could be many plans that minimize this average distance, so the king would like you to tell him how many there are. Two plans are different if there is a village that produces fruit in one plan, but vegetables in the other. The king guarantees that it is possible to find a plan which allows each village to get both fruit and vegetables.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case starts with one line, containing two integers $V$ and $E$: the number of villages, and the number of roads, respectively. The villages are labeled from $1$ to $V$.  
$E$ lines follow; the $i$-th of these lines contains three integers $A_i$, $B_i$ and $L_i$, indicating that the $i$-th road connects village $A_i$ to village $B_i$ and has length $L_i$.
