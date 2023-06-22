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

bool valid(long long x)
{
	while (x)
	{
		if (x % 10 == 9)
			return false;

		x /= 10;
	}

	return true;
}

long long count(long long x)
{
	long long xx = x - (x % 10);
	long long xxx = xx;

	long long C = 0;
	long long b = 1;

	while (xx)
	{
		C += (xx % 10) * b;
		xx /= 10;
		b *= 9;
	}

	C = C / 9 * 8;

	for (long long i = xxx; i <= x; ++i)
		if (i % 9 && valid(i))
			++ C;

	return C;
} 

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		long long F, L;
		cin >> F >> L;

		cout << "Case #" << t << ": ";
		cout << (count(L) - count(F) + 1) << "\n";
	}

	return 0;
}

