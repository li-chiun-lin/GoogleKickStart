/*

*/

#define _USE_MATH_DEFINES

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool is_palindrome(long long x)
{
	long long y = 0;
	long long xx = x;

	while (x)
	{
		y = y * 10 + (x % 10);
		x /= 10;
	}
	
	return y == xx;
}

int count(long long A)
{
	int cnt = 0;
	long long p = 1;

	while(p * p < A)
	{
		if (A % p == 0)
		{
			if (is_palindrome(p))
				++ cnt;

			if (is_palindrome(A / p))
				++ cnt;
		}

		++ p;
	}

	if (p * p == A)
	{
		if (is_palindrome(p))
			++ cnt;
	}

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		long long A;
		cin >> A;

		cout << "Case #" << t << ": ";
		cout << count(A) << "\n";
	}

	return 0;
}

