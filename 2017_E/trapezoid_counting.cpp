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

long long trapezoid(int N, vector<long long>& L)
{
	long long ret = 0;
	map<long long, long long> cnt;

	sort(begin(L), end(L));

	for (auto x : L)
		++ cnt[x];
	
    // There must be a pair of sticks with equal length. Call this length C.
    // The remaining two sticks must have unequal lengths. Call the shorter of those lengths A, and the longer one B.
    // The four sticks must be able to actually connect to form an isosceles trapezoid, so we need to obey an isosceles trapezoid equivalent of the triangle inequality: B < A + 2 × C. 

	for (auto [C, count_C] : cnt)
	{
		// case 1: A is equal to C or B is equal to C.
		if (count_C >= 3)
		{
			long long left = upper_bound(begin(L), end(L), C) - begin(L);
			long long right = lower_bound(begin(L), end(L), 3 * C) - begin(L) - 1;
			long long right_C = lower_bound(begin(L), end(L), C) - begin(L) - 1;
			ret += (right - left + 1 + (right_C + 1)) * count_C * (count_C - 1) * (count_C - 2) / 6;
		}

		// case 2: A, B, and C are all different values.
		if (count_C >= 2)
		{
			for (auto A : L)
			{
				if (A == C)
					continue;

				long long left = upper_bound(begin(L), end(L), A) - begin(L);
				long long right = lower_bound(begin(L), end(L), A + 2 * C) - begin(L) - 1;

				if (left > right)
					continue;

				ret += (right - left + 1 - (A < C ? count_C : 0)) * count_C * (count_C - 1) / 2;
			}
		}
	}

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<long long> L(N);

		for (auto& x : L)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << trapezoid(N, L) << "\n";
	}

	return 0;
}

