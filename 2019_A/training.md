# Problem

As the football coach at your local school, you have been tasked with picking a team of exactly $P$ students to represent your school. There are $N$ students for you to pick from. The $i$-th student has a skill rating $S_i$, which is a positive integer indicating how skilled they are.

You have decided that a team is fair if it has exactly $P$ students on it and they all have the same skill rating. That way, everyone plays as a team. Initially, it might not be possible to pick a fair team, so you will give some of the students one-on-one coaching. It takes one hour of coaching to increase the skill rating of any student by $1$.

The competition season is starting very soon (in fact, the first match has already started!), so you'd like to find the minimum number of hours of coaching you need to give before you are able to pick a fair team.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case starts with a line containing the two integers $N$ and $P$, the number of students and the number of students you need to pick, respectively.  
Then, another line follows containing $N$ integers $S_i$; the $i$-th of these is the skill of the $i$-th student.
