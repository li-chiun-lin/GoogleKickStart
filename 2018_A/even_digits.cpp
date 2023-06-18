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

long long digits(long long N, long long b = 1e16)
{
	if (b == 0)
		return 0;

	long long d = N / b % 10;

	if (d % 2)
	{
		long long r = N % b;
		long long minus = digits(N - r - 1, b / 10) + r + 1;
		long long plus = d == 9 ? 1e16 : digits(N + (b - r), b / 10) + (b - r);
			
		return min(minus, plus);
	}
	else
	{
		return digits(N % b, b / 10);
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		long long N;
		cin >> N;

		cout << "Case #" << t << ": ";
		cout << digits(N) << "\n";
	}

	return 0;
}

