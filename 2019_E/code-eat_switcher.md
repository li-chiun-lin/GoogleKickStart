# Problem

Umon is a foodie coder. Do you know what two activities that he loves the most? Of course, coding and eating! He always spends the whole day doing only those two activities. However, he thinks that some times of the day are better spent coding, and others are better spent eating.

To illustrate this problem, Umon divides his day into $S$ time slots. During the $i$-th time slot, if Umon codes 100% of the time, he will achieve $C_i$ units of coding. On the other hand, if he eats 100% of the time, he will achieve $E_i$ units of eating. But of course, Umon can also use only a fraction of the time for coding, and the remaining for eating. Formally, he will choose a real number $f$ $(0 ≤ f ≤ 1)$, code for $f$ of the time, and use the remaining $(1 - f)$ time to eat. This way, he will achieve $f × C_i$ units of coding and $(1 - f) × E_i$ units of eating. The total amount of coding Umon achieves for the day is simply the sum of all units of coding he achieved in each of the time slots. The total amount of eating is calculated in a similar way.

Umon needs to plan his schedule for the next $D$ days. On the $i$-th day, he needs to achieve at least a total amount of $A_i$ units of coding and $B_i$ units of eating. For each day, determine whether there is a way for Umon to achieve his target.

## Input

The first line of input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case begins with a line containing two integers $D$ and $S$, the number of days and the number of time slots in a day, respectively.  
Then $S$ lines follow, each describing a time slot. The $i$-th line contains two integers $C_i$ and $E_i$, the amount of coding units achieved if Umon codes for 100% of the time slot, and the amount of eating units achieved if he eats for 100% of the time slot, respectively.  
Then $D$ lines follow, each describing a day. The $i$-th line contains two integers $A_i$ and $B_i$, the minimal total amount of coding and eating that needs to be achieved on that day.
