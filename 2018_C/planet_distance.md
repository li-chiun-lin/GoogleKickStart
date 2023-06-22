# Problem

There are $N$ planets in the universe, and Google's Space division has installed $N$ vacuum tubes through which you can travel from one planet to another. The tubes are bidirectional; travelers may use a tube between two planets to travel from either of those planets to the other. Each vacuum tube connects two planets and no two vacuum tubes connect the same pair of planets. These tubes connect the planets such that it is possible to travel from any planet to any other planet using one or more of them. Some of these tubes are connected such that there exists exactly one cycle in the universe. Google has hidden gifts in all the planets that are part of this cycle. Now, Google wants to know how far away each of the planets in the universe is from the gifts.

Your task is to find the minimum distance (in terms of the number of vacuum tubes) between each planet and a planet that is part of the cycle. Planets that are part of the cycle are assumed to be at distance $0$.

## Input

The first line contains an integer $T$, the number of test cases. $T$ test cases follow.  
The first line of each test case contains an integer $N$, the number of planets and vacuum tubes. The planets are numbered from $1$ to $N$.  
$N$ lines follow, the $i$-th of these lines contains two integers $x_i$ and $y_i$, indicating that the $i$-th vacuum tube connects planet $x_i$ and planet $y_i$.
