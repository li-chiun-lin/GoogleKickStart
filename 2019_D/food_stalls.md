# Problem

Everybody loves street food, especially the local residents of Bitetown! For this reason, you have decided to build exactly K food stalls and one warehouse on the main street of Bitetown.

The main street is a long horizontal line that is 109 metres long. There are N spots that you are allowed to build stalls or a warehouse on. You may not build anywhere else on the street. The i-th spot is Xi meters from the left end of the street.

You can build at most one stall or warehouse at the i-th spot (but not both), which costs Ci dollars. Additionally, if the warehouse is in the j-th spot, then building a stall in the i-th spot costs an extra |Xj - Xi| dollars.

Please find the minimum cost to build exactly K food stalls and one warehouse.

## Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a line containing two integers K and N, the number of stalls you must build and the number of spots on the street, respectively.

The second line contains N integers Xi; the i-th of these is the distance of the i-th spot from the left end of the street, in meters.

The third line contains N integers Ci; the i-th of these is the cost of building a stall or warehouse at the i-th spot.
