# Problem

You are given a list of valid arithmetic expressions using non-negative integers, parentheses $()$, plus $+$, multiply $*$, and an extra operator $\#$. The expressions are fully parenthesized and in infix notation.

A fully parenthesized expression is an expression where every operator and its operands are wrapped in a single parenthesis. For example, the expression $x+y$ becomes $(x+y)$ when fully parenthesized, and $x+y+z$ becomes $((x+y)+z)$. However, $0$ is still $0$ when fully parenthesized, because it consists of a single number and no operators. $((x+y))$ is not considered fully parenthesized because it has redundant parentheses.

The operators $+$ and $*$ denote addition and multiplication, and $\#$ can be any total function.

You want to group the expressions into equivalence classes, where expressions are in the same equivalence class if and only if they are guaranteed to result in the same numeric value, regardless of which function $\#$ represents.

You can assume that $\#$ represents the same function across all expressions in a given test case. That might mean that $\#$ represents some known function like addition or subtraction, but not both in different parts of the same test case.

For example, consider the following expressions:

$F_1=((1\#(1+1))+((2\#3)*2))$  
$F_2=(((2\#3)+(1\#2))+(2\#3))$  
$F_3=((2*(2\#3))+(1\#2)).$

Let $A = 1\#2$, and let $B = 2\#3$. Then we can say $F_1=F_2=F_3$, regardless of the function $\#$ represents because the expressions can be rewritten as:

$F_1=((1\#2)+((2\#3)*2))=(A+(B*2))=(A+2B)$  
$F_2=(((2\#3)+(2\#3))+(1\#2))=((B+B)+A)=(A+2B)$  
$F_3=((2*(2\#3))+(1\#2))=((2*B)+A)=(A+2B).$

However, consider the expressions $F_4=((0\#0)+(0\#0))$ and $F_5=(0\#0)$. If $\#$ represents addition, then $F_4=F_5$. However, if $\#$ is $f(x,y)=C$, such that $C$ is a non-zero integer, then $F_4≠F_5$ since $2C≠C$. Therefore $F_4$ and $F_5$ are not in the same equivalence class.

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case begins with a line containing the integer $N$.  
$N$ lines follow. $i$-th line contains one expression, $E_i$.
