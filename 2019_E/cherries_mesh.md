# Problem

Your friend is recently done with cooking class and now he wants to boast in front of his school friends by making a nice dessert. He has come up with an amazing dessert called Cherries Mesh. To make the dish, he has already collected cherries numbered $1$ to $N$. He has also decided to connect each distinct and unordered pair of cherries with a sweet strand, made of sugar. Sweet strands are either red or black, depending on the sugar content in them. Each black strand contains one units of sugar, and each red strand contains two units of sugar.

But it turns out that the dessert is now too sweet, and these days his school friends are dieting and they usually like dishes with less sugar. He is really confused now and comes to your rescue. Can you help him find out which all sweet strands he should remove such that each pair of cherries is connected directly or indirectly via a sugar strand, and the dish has the minimum possible sugar content?

## Input

The first line of input gives the number of test cases, $T$.  
Each test case begins with a line containing two integers $N$ and $M$, the number of cherries and the number of black sweet strands, respectively.  
Then $M$ lines follow, each describing a pair of cherries connected to a black strand. The $i$-th line contains cherries numbered $C_i$ and $D_i$, it indicates that $C_i$ and $D_i$ cherry are connected with a black strand of sugar.  

Note: Any other pair of cherries not present in the input means that they are connected by a red strand.
