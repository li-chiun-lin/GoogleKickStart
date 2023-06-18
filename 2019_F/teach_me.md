# Problem

Here at Google we love teaching new skills to each other! There are $N$ employees at Google, numbered from $1$ to $N$. There are a total of $S$ different skills, numbered from $1$ to $S$. Each employee knows up to 5 different skills.

The $i$-th employee can mentor the $j$-th employee if there is a skill that the $i$-th employee knows that the $j$-th employee does not know. How many ordered pairs $(i, j)$ are there where the $i$-th employee can mentor the $j$-th employee?

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
The first line of each test case gives the two integers $N$ and $S$, which are the number of employees and the number of skills respectively.  
The next $N$ lines describe the skills that each employee knows. The $i$-th of these lines begins with an integer $C_i$ which is the number of skills the $i$-th employee knows.  
Then, $C_i$ integers follow on the same line. The $j$-th of these integers is $A_{ij}$ indicating that the $i$-th employee knows the skill $A_{ij}$.
