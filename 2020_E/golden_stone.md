# Problem

Leopold's friend Kate likes stones, so he decided to give her a golden stone as a gift. There are $S$ types of stones numbered from $1$ to $S$, $1$ being the golden stone. Some types of stones are available free of charge in various parts of the city. The city consists of $N$ junctions numbered from $1$ to $N$ and $M$ two-way streets between pairs of distinct junctions. At each junction, zero or more types of stones are available in unlimited supply.

Unfortunately, the golden stone is not available anywhere. Luckily, Leopold is a bit of a magician and knows how to combine a group of stones and turn them into another stone. For example, one of his recipes could produce a golden stone out of one silver stone and two marble stones. He could collect those stones in some of the junctions if they are available, or he could use some of his many other recipes to produce any of those stones. Formally, Leopold has $R$ recipes, where a recipe is in the form $(a_1, a_2, ..., a_k) \rightarrow b$ for some $k ≥ 1$. If Leopold has gathered $k$ stones of types $a_1, a_2, ...,$ and $a_k$ at a certain junction, he can choose to apply the recipe and turn these stones into one stone of type $b$.

Leopold likes puzzles much more than physical activity, therefore, he does not want to carry stones around the city unnecessarily. Carrying a stone along a street costs him one unit of energy. Leopold can carry no more than one stone at a time, however, he can drop off a stone at any junction and pick it up later at any time.

What is the minimum amount of energy Leopold must spend to produce one golden stone? Leopold is very scared of large numbers. If the answer is greater than or equal to $10^{12}$, print $-1$ instead.

## Input

The first line of the input gives the number of test cases $T$. $T$ test cases follow.  
The first line of each test case consists of four integers $N, M, S,$ and $R$ giving the number of junctions, streets, stone types, and recipes, respectively.  
The following $M$ lines describe the map of the city. The $i$-th of these lines contains two distinct integers $U_i$ and $V_i$ denoting the pair of junctions connected by the $i$-th street.

The subsequent $N$ lines describe the types of stones available in each junction. The $i$-th of these lines starts with the number of stone types $C_i$ available in $i$-th junction followed by Ci distinct integers in the range $[2, S]$ enumerating the stone types. The golden stone is always numbered $1$ and is not available.

The last $R$ lines of each test case describe Leopold's magic recipes. The $i$-th of these lines starts with the number of ingredient stones $K_i$ required for the $i$-th recipe followed by $K_i$ not necessarily distinct integers in the range $[2, S]$ enumerating the types of necessary ingredients.  
The $i$-th line ends with an integer in the range $[1, S]$, which is the type of the resulting stone after applying the $i$-th recipe.

For example 3 6 5 6 3 denotes a recipe that requires two stones of type 6, one stone of type 5, and produces a stone of type 3.

It is guaranteed that it is possible to produce a golden stone in each of the test cases.
