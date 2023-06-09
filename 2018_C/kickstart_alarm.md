# Problem

Shil has a very hard time waking up in the morning each day, so he decides to buy a powerful alarm clock to Kickstart his day. This Alarm is called a Kickstart Alarm. It comes pre-configured with $K$ powerful wakeup calls. Before going to bed, the user programs the clock with a Parameter Array consisting of the values $A_1, A_2, ..., A_N$. In the morning, the clock will ring $K$ times, with the $i$-th wakeup call having power $POWER_i$.

To calculate $POWER_i$, the alarm generates all the contiguous subarrays of the Parameter Array and calculates the summation of the $i$-th exponential-power of all contiguous subarrays. The $i$-th exponential-power of subarray $A_j, A_{j+1}, ..., A_k$ is defined as $A_j × 1^i + A_{j+1} × 2^i + A_{j+2} × 3^i + ... + A_k × (k-j+1)^i$. So $POWER_i$ is just the summation of the $i$-th exponential-power of all the contiguous subarrays of the Parameter Array.

For example, if $i = 2$, and $A = [1, 4, 2]$, then the $i$-th exponential-power of $A$ would be calculated as follows:

- 2-nd exponential-power of $[1] = 1 × 1^2 = 1$
- 2-nd exponential-power of $[4] = 4 × 1^2 = 4$
- 2-nd exponential-power of $[2] = 2 × 1^2 = 2$
- 2-nd exponential-power of $[1, 4] = 1 × 1^2 + 4 × 2^2 = 17$
- 2-nd exponential-power of $[4, 2] = 4 × 1^2 + 2 × 2^2 = 12$
- 2-nd exponential-power of $[1, 4, 2] = 1 × 1^2 + 4 × 2^2 + 2 × 3^2 = 35$

so the total is $71$.

Tonight, Shil is using his Kickstart Alarm for the first time. Therefore, he is quite worried about the sound the alarm might make in the morning. It may wake up the neighbors, or, worse yet, it may wake up the whole planet! However, calculating the power of each wakeup call is quite difficult for him. Given $K$ and the Parameter Array $A_1, A_2, ..., A_N$, can you help him by calculating the summation of power of each wakeup call: $POWER_1 + POWER_2 + ... + POWER_K$?

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case consists of one line with nine integers $N, K, x_1, y_1, C, D, E_1, E_2$ and $F$.  
$N$ is the length of array $A$, $K$ is the number of wakeup calls. Rest of the values are parameters that you should use to generate the elements of the array $A$, as follows.

Use the recurrences below to generate $x_i$ and $y_i$ for $i = 2$ to $N$:

- $x_i = (C × x_{i-1} + D × y_{i-1} + E_1) \mod F$.
- $y_i = (D × x_{i-1} + C × y_{i-1} + E_2) \mod F$.

We define $A_i = (x_i + y_i) \mod F$, for all $i = 1$ to $N$.
