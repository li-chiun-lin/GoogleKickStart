# Problem

John and Ada are sitting on the grass above a small hill. It is midnight and the sky is full of stars. The sky looks like a 2D plane from so far away and the stars look like points on that plane. Ada loves blue stars and suddenly she notices one, while all the other stars in the sky are white. She loves the blue star so much that she wants to trap it. And she asks John for help.

Ada will tell John the position of the blue star and he has to trap it. To trap it, John has to draw a polygon in the sky with his buster sword, so that the blue star is strictly inside the polygon (not on the border of the polygon) and the polygon has the smallest possible perimeter. The vertices of the polygon must be the white stars.

Even though John is super awesome, he needs your help. Given the positions of the white stars and the blue star, you need to find out whether John can trap the blue star and if he can, also find the minimum length of the perimeter of the polygon he will use.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
For each test case, the first line contains an integer $N$, it denotes the number of white stars in the sky.  
The next $N$ lines will each contain two integers, $X_i$ and $Y_i$. The $i$-th pair of integers denotes the $x$ and $y$ coordinates of the $i$-th star in the sky.  
After these $N$ lines, there will be one last line, which will contain two integers, $X_s$ and $Y_s$, which denote the $x$ and $y$ coordinates of the blue star.
