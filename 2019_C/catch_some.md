# Problem

Bundle is an animal researcher and needs to go observe $K$ dogs. She lives on a horizontal street marked at metre increments with consecutive numbers 0, 1, 2, 3 and so on. She begins in her home, which is at position 0. There are also $N$ dogs on the street. The $i$-th dog is $P_i$ metres to the right of her home on the street (multiple dogs can share the same position).

Dogs come in different colors, which are denoted by positive integers. The $i$-th animal is of color $A_i$.

If Bundle is at her home, she can change the current color of her shirt. This is important since the dogs are very shy! Bundle can only observe a dog if she is at the same position as that dog, and is wearing a shirt of the same color as the dog.

It takes Bundle one second to move one metre to the left or right on the street. It takes her no time to change shirts or observe a dog.

What is the least amount of time it will take Bundle to observe $K$ dogs? Note that she does not have to return home after observing $K$ dogs.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each testcase begins with a line containing the two integers $N$ and $K$, the number of dogs on the number line and the number of dogs Bundle needs to observe, respectively.  
The second line contains $N$ integers, the $i$-th of which is $P_i$, the position of the $i$-th dog.  
The third line contains $N$ integers, the $i$-th of which is $A_i$, the color of the $i$-th dog.
