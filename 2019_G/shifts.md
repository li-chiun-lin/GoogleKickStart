# Problem

Aninda and Boon-Nam are security guards at a small art museum. Their job consists of $N$ shifts. During each shift, at least one of the two guards must work.

The two guards have different preferences for each shift. For the $i$-th shift, Aninda will gain $A_i$ happiness points if he works, while Boon-Nam will gain $B_i$ happiness points if she works.

The two guards will be happy if both of them receive at least $H$ happiness points. How many different assignments of shifts are there where the guards will be happy?

Two assignments are considered different if there is a shift where Aninda works in one assignment but not in the other, or there is a shift where Boon-Nam works in one assignment but not in the other.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case begins with a line containing the two integers $N$ and $H$, the number of shifts and the minimum happiness points required, respectively.  
The second line contains $N$ integers. The $i$-th of these integers is $A_i$, the amount of happiness points Aninda gets if he works during the $i$-th shift.  
The third line contains $N$ integers. The $i$-th of these integers is $B_i$, the amount of happiness points Boon-Nam gets if she works during the $i$-th shift.
