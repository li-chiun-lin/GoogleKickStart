# Problem

The countryside of Kickstartia consists of $V$ villages (labelled from $1$ to $V$), connected by $V-1$ bidirectional roads (labelled from $1$ to $V-1$). The $i$-th road connects village $X_i$ to village $Y_i$. Each road connects exactly two villages, and no two roads connect the same two villages. Furthermore, there is exactly one sequence of roads that connects any two villages in Kickstartia.

Some villages are more beautiful than others. The $i$-th village has a beauty value of $B_i$. Note that it is possible for a village to have a negative beauty value!

You are going to build lighthouses in some of the villages. A village is illuminated if there is a lighthouse built in it, or there is a lighthouse built in a village that is directly connected to it by a road.

You may build as many or as few (even zero) lighthouses as you like. What is the maximum possible sum of beauty values of illuminated villages you can obtain?

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case begins with a line containing the integer $V$, the number of villages.  
The second line contains $V$ integers. The $i$-th of these is $B_i$, the beauty value of the $i$-th village.  
Then, $V-1$ lines follow. The $i$-th line gives $X_i$ and $Y_i$, indicating the $i$-th road connects village $X_i$ to village $Y_i$.
