# Problem

Bahu is playing a board game with Bala. Each player has $3 \times N$ army cards with various strength values. There are 3 battlefields in the game. Each player must distribute their cards among the battlefields, face down, such that each battlefield gets exactly $N$ of their cards.

When the game begins, all cards will be revealed. For each battlefield, each player sums up the strength values of their $N$ cards in that battlefield, and then the players compare those totals. If one player has a higher total, that player wins that battlefield. If the totals are the same, Bala wins that battlefield; this is his special advantage.

The overall winner of the game is the player who wins the most battlefields. (Since there are 3 battlefields, it is guaranteed that there will not be an overall tie.)

Bala thinks that his advantage is enough to make him win, so he just randomly shuffles his cards and puts the first $N$ on the first battlefield, the next $N$ on the second battlefield, and the last $N$ on the third battlefield.

Even though Bahu is at a disadvantage, he is still going to try to win! Find the probability that he will win if he distributes his cards optimally. Note that all Bala's cards are faced down so Bahu must choose the distribution of his cards before seeing the distribution of Bala's cards.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow; each consists of three lines.  
The first line contains an integer $N$, as described above.  
The second line contains $3 \times N$ integers $A_0, A_1, ... , A_{3 \times N-1}$, representing the strength values of Bahu's cards.  
The third line consists of $3 \times N$ integers $B_0, B_1, ... , B_{3 \times N-1}$, representing the strength values of Bala's cards.
