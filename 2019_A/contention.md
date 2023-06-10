# Problem

You are selling tickets for the front row of seats at a movie theater. The front row has $N$ seats, numbered $1$ to $N$ from left to right. You have been out of the office the last week, and upon your return, $Q$ bookings for seats have piled up! The $i$-th booking requests all the seats from $L_i$ to $R_i$ inclusive. You now have the boring job of entering each booking into the system, one at a time.

Since some of the bookings may overlap, the system might not be able to fulfill each booking entirely. When you enter a booking into the system, it will assign every seat requested by the booking that hasn't already been assigned to a booking entered into the system earlier.

What is the largest integer $k$ where there exists an order that you can enter the bookings into the system, such that each booking is assigned at least $k$ seats?

## Input

The first line of the input gives the number of test cases, $T$. $T$ test cases follow.  
Each test case starts with a line containing two integers $N$ and $Q$, the number of seats and the number of bookings, respectively.  
Then, there are $Q$ more lines, the $i$-th of which contains the two integers $L_i$ and $R_i$, indicating that the $i$-th booking would like to book all the seats from $L_i$ to $R_i$, inclusive.
