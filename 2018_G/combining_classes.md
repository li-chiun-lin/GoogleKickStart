# Problem

Supervin is teaching $N$ classes, which are numbered from $1$ to $N$. After giving his most recent exam, he noticed that in each of his classes, the test scores of his students form a sequence of consecutive integers. Therefore, Supervin can summarize the scores for the $i$-th class as two integers $L_i$ and $R_i$. This means that the $i$-th class has $R_i - L_i + 1$ students, and for each $x$ $(L_i ≤ x ≤ R_i)$, there is exactly one student with score $x$.

Supervin would like to combine the scores from the students from all of his classes and sort the scores in non-increasing order. He has $Q$ questions (numbered from $1$ to $Q$) about this list; for the $i$-th question, he wants to know what the $K_i$-th highest score is. (If $K_i$ is greater than the number of students, then the answer for the $i$-th question is $0$.)

Can you help Supervin answer all of his questions? Since there may be many answers, instead of outputting all of them, output proof that you have answered them: the sum of $(S_i × i)$ for all $1 ≤ i ≤ Q$, where $S_i$ is the answer to the $i$-th question.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow. Each test case contains four lines.  
The first line contains two integers $N$ and $Q$ as described above.  
The next three lines each contain six integers in the following format, respectively:

$X_1\ X_2\ A_1\ B_1\ C_1\ M_1$  
$Y_1\ Y_2\ A_2\ B_2\ C_2\ M_2$  
$Z_1\ Z_2\ A_3\ B_3\ C_3\ M_3$

These values are used to generate $L_i$, $R_i$, and $K_i$ as follows:

We define:

$X_i = (A_1 × X_{i - 1} + B_1 × X_{i - 2} + C_1) \mod M_1$, for $i = 3$ to $N$.  
$Y_i = (A_2 × Y_{i - 1} + B_2 × Y_{i - 2} + C_2) \mod M_2$, for $i = 3$ to $N$.  
$Z_i = (A_3 × Z_{i - 1} + B_3 × Z_{i - 2} + C_3) \mod M_3$, for $i = 3$ to $Q$.

We also define:

$L_i = \min(X_i, Y_i) + 1$, for $i = 1$ to $N$.  
$R_i = \max(X_i, Y_i) + 1$, for $i = 1$ to $N$.  
$K_i = Z_i + 1$, for $i = 1$ to $Q$.
