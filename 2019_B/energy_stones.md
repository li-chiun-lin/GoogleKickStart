# Problem

Duda the rock monster lives in the enchanted forest and has collected $N$ energy stones for lunch. Since he has a small mouth, he eats energy stones one at a time. Some stones are tougher than others! The $i$-th stone takes him $S_i$ seconds to eat.

Duda eats energy stones to get energy. Different stones give him different amounts of energy. Furthermore, the stones lose energy over time. The $i$-th stone initially contains $E_i$ units of energy and will lose $L_i$ units of energy each second. When Duda starts to eat a stone, he will receive all the energy the stone contains immediately (no matter how much time it takes to actually finish eating the stone). The stone's energy stops decreasing once it hits zero.

What is the largest amount of energy Duda could receive from eating his stones?

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case starts with a line containing the integer $N$, the number of energy stones Duda has.  
Then, there are $N$ more lines, the $i$-th of which contains the three integers $S_i$, $E_i$ and $L_i$, as described above.
