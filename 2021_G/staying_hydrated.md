# Problem

With online classes in full swing, it is important for Grace to take breaks and keep herself hydrated at all times. She has decided to place a water bottle in her room in the most convenient place. This means that the position of this water bottle should be close to all the places in the room where she generally hangs out like the study desk, bed and coffee table among other places.

The room is represented in the form of a coordinate plane. The number of steps Grace needs to go from Point $A$ to Point $B$ is equal to the Manhattan distance between the 2 points. This means, Grace can only walk parallel to the axes of the coordinate plane and with each step, she can move one unit in either of the four directions.

Can you help her find a position in the room to keep the bottle, such that the sum of steps from the bottle to all her favourite furniture pieces will be minimum?

## Notes

- All the furniture (like study desk, bed, or coffee table) can be represented as rectangles of non-zero area in the plane with edges parallel to the axes.  
- It is possible for furniture pieces to overlap, as she likes to work on her bed-table too.
- Assume that Grace can simply pass through the furniture while walking and does not need to go around them.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
The first line of each test case contains an integer $K$ which represents the number of objects in Grace's room.  
$K$ lines follow, each of them describing one object. The $i$-th line contains four integers, $x_{i,1}, y_{i,1}, x_{i,2}, y_{i,2}$, where $(x_{i,1}, y_{i,1})$ represents coordinates of the bottom left corner and $(x_{i,2}, y_{i,2})$ represents coordinates of the top right corner of the $i$-th rectangular object.
