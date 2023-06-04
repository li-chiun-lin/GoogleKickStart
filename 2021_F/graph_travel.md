# Problem

Ada lives in a magic country $A$, and she is studying at Magic University. Today, Ada wants to collect magic points in a special space.

The space has $N$ rooms ($0,1,…,N−1)$. There are $M$ corridors connecting the rooms. A corridor $j$ connects room $X_j$ and room $Y_j$, meaning you can travel between the two rooms.

The $i$-th room contains $A_i$ magic points and is protected by a magic shield with properties $L_i$ and $R_i$. To enter the $i$-th room, first you need to get to any room adjacent to the $i$-th room (i.e. connected to it by a corridor) through rooms with already broken shields. Then you have to break the shield to this room, but you can break the shield if and only if you have between $L_i$ and $R_i$ magic points, inclusive. After you break the shield, you will enter the room and automatically collect the $A_i$ magic points assigned to this room. The room will not generate new magic points. The room will also not generate a new shield after it is broken, so you can freely go back to every room with already broken shields regardless of the amount of points you have.

Ada starts with $0$ magic points and her goal is to find a way to collect exactly $K$ magic points. She can start in any room, and end in any room. The room she chooses to start in will automatically have its magic shield broken, and she will automatically collect all the magic points from this room.

After inspecting the map of the rooms and corridors, Ada thinks the task is very easy, so she wants to challenge herself with a more difficult task. She wants to know how many unique ways there are to reach the goal. Two ways are different if their unique paths are different. The unique path is the order of rooms in which she broke the shields, e.g.: if you visit the rooms in the order $(1,3,2,1,3,5,3,6)$, the unique path is $(1,3,2,5,6)$.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
For each test case, the first line contains three integers $N$, $M$, and $K$: the number of rooms, the numbers of corridors, and the numbers of magic points we want to collect, respectively.  
The next $N$ lines contain three integers $L_i$, $R_i$, and $A_i$: The magic shield properties $L_i$ and $R_i$ of room $i$, and the number of magic points $A_i$, respectively.  
The next $M$ lines contain two integers $X_j$ and $Y_j$: the rooms that are connected by corridor $j$.
