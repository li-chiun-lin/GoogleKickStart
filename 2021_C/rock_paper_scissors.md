# Problem

You and your friend like to play Rock Paper Scissors. Each day you play exactly $60$ rounds and at the end of each day, you tally up the score from these $60$ rounds.

During each round, without any knowledge of the other person's choice, you each make your choice. Then, you both reveal the choice you made and determine your score. Rock wins over Scissors, Scissors wins over Paper, and Paper wins over Rock. Let $R$ represent Rock, $P$ represent Paper, and $S$ represent Scissors. Every day you both agree on values $W$ and $E$. If your choice wins, you get $W$ points. If you and your friend both pick the same choice, you get $E$ points. If your choice loses, you get nothing.

By accident, you see your friend's strategy written in an open notebook on a desk one day. Your friend keeps track of how many times you have chosen $R$, $P$, and $S$ so far during one day. Let $A_i$ be your choice of $R$, $P$, or $S$ on round $i$, while $B_i$ is your friend's choice on the same round. Let $r_i$ be the number of times $A_j= R$ for $1≤j≤(i−1)$. Similarly, let $p_i$ and $s_i$ be the total number of times you have chosen $P$ and $S$, respectively, prior to round $i$.

On round $1$ of each day, $i=1$ and $r_1=s_1=p_1=0$, and your friend plays randomly due to the lack of information (i.e. your friend chooses each option with probability $1/3$). On every subsequent round, your friend decides $B_i$ by choosing $R$ with probability $Pr[R]=s_i/(i−1)$, $P$ with probability $Pr[P]=r_i/(i−1)$, and $S$ with probability $Pr[S]=p_i/(i−1)$. This strategy is adaptive and tough to beat!

You are going on vacation for the next $T$ days. You must leave your assistant with instructions on what choice to pick each round each day. Let integer $X$ be the average reward you are aiming for in this game after $T$ days. Given $W$ and $E$ (different values for different days), provide your instructions as a string of $60$ characters, ordered from round $1$ to round $60$. Each character represents your choice for the corresponding round. Your goal is to choose your set of instructions so that the average expected value of the reward across all the days of your gameplay is at least $X$. Note that you can choose different instructions for different values of $W$ and $E$.

## Input

The first line of the input gives the number of days, $T$.  
The second line contains an integer $X$, your targeted average reward after these $T$ days.  
Then the description of $T$ days follows.  
Each day is described as two integers $W$ and $E$. $W$ is how much you get if your choice wins for each round that day. $E$ is how much you get for each round when your choice is the same as your friend's choice.

All the tests (except the sample test below) are generated as follows. We choose $50$ different values $G$ between $5$ and $95$ (with uniform distribution). Then for each of these values, there will be $4$ days, with $W$ equal to $10×G$ and $E$ equal to $W,\frac{W}{2},\frac{W}{10},$ and $0$. Do not assume anything about the order of these days.
