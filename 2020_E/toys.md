# Problem

Little Axel has $N$ toys numbered from $1$ to $N$. Each toy has two properties:

- $E_i$—enjoyment, which is the number of minutes Axel can play with toy number $i$ without getting bored with it;
- $R_i$—remembrance, which is the number of minutes it takes Axel to forget toy number $i$ after having played with it.

The toys are arranged in a circle, from $1$ to $N$ clockwise. Axel plays with them one by one.

When Axel reaches toy $i$ which he has not played with yet, or which he has already forgotten about, he plays with it for $E_i$ minutes and then immediately moves to the next one (clockwise).

If he reaches a toy that he has not forgotten yet (if less than $R_i$ minutes have passed since the last time he finished playing with it), he will stop and cry.

We can define the time Axel spent playing as the sum of $E_i$ of every toy Axel played with before stopping. If Axel played with a toy several times, it should be counted that many times.

Given the description of the toys, remove the smallest possible number of them in order to make Axel play either an indefinitely long time, or (if that is not possible) as long as possible before he stops.

Note:

- Axel has never played with these toys before;
- he cannot be left without toys;
- he always starts with the toy that has the smallest number;
- after finishing playing with the toy that has the largest number, he will move to the toy that has the smallest number.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case begins with a line containing the integer $N$.  
Next $N$ lines contain 2 integers each: $E_i$ and $R_i$. The $i$-th line is describing the toy number $i$.
