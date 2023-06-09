# Problem

Bob is an outstanding Googler. He loves efficiency, so he does everything well and quickly. Today, Bob has discovered that the trash can near his desk has disappeared! Sadly, this means that he has to use another nearby trash can instead. Since getting out of his seat to use the trash can would lower his productivity, Bob has decided to throw his trash into that trash can!

But there are many obstacles in the Google office. For example, it is rude if the thrown trash hits somebody, or the wall, or anything else. Bob hopes to throw the trash without touching any existing obstacles.

To simplify this problem, we will only consider the vertical plane that includes Bob and the trash can. Bob is at point $(0, 0)$; the trash can is at point $(P, 0)$. Moreover, there are $N$ obstacles in the office; each of them is a single point, and the $i$-th one has coordinates $(X_i, Y_i)$. The ceiling of the office is a line with the expression $y=H$ in the plane. Since Bob is in one of the new high-tech floating offices, we do not consider the office floor in this problem; you do not need to worry about collisions with it. Bob will throw a piece of trash that is a circle with radius $R$. The center of the piece of trash starts off at $(0, 0)$. When the piece of trash is thrown, the center of the piece of trash must follow the path of a parabola with the expression $f(x)=ax(x-P)$, where $0 ≤ x ≤ P$, and $a$ can be any real number less than or equal to $0$. The piece of trash is only considered thrown away when its center reaches the trash can's point, and it is not enough for some part of the piece of trash to just touch that point.

Bob is wondering: what is the largest piece of trash he can throw without hitting the ceiling or any obstacles? That is, we must find the maximum value of $R$ for which there is at least one value $a$ that satisfies the following: for any $0 ≤ x ≤ P$, the Euclidean distance between $(x, f(x))$ and $(x, H)$ is greater than $R$, and for each $i$, the Euclidean distance between the point $(x, f(x))$ and $(X_i, Y_i)$ is greater than or equal to $R$.

## Input

The input starts with one line containing one integer $T$, the number of test cases. $T$ test cases follow.  
The first line of each test case contains three integers $N$, $P$, and $H$: the number of obstacles, the x-coordinate of the trash can, and the height of the ceiling.  
Then, there are $N$ more lines; the $i$-th of those lines represents the $i$-th obstacle, and has two integers $X_i$ and $Y_i$, representing that obstacle's coordinates.
