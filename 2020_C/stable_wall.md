# Problem

Apollo is playing a game involving polyominos. A polyomino is a shape made by joining together one or more squares edge to edge to form a single connected shape. The game involves combining $N$ polyominos into a single rectangular shape without any holes. Each polyomino is labeled with a unique character from $A$ to $Z$.

Apollo has finished the game and created a rectangular wall containing $R$ rows and $C$ columns. He took a picture and sent it to his friend Selene. Selene likes pictures of walls, but she likes them even more if they are stable walls. A wall is stable if it can be created by adding polyominos one at a time to the wall so that each polyomino is always supported. A polyomino is supported if each of its squares is either on the ground, or has another square below it.

Apollo would like to check if his wall is stable and if it is, prove that fact to Selene by telling her the order in which he added the polyominos.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case begins with a line containing the two integers $R$ and $C$.  
Then, $R$ lines follow, describing the wall from top to bottom. Each line contains a string of $C$ uppercase characters from $A$ to $Z$, describing that row of the wall.
