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

long long equation(int N, long long M, vector<long long>& A)
{
	long long k = 0;
	int ub = 53;
	long long sum = accumulate(begin(A), end(A), 0LL);

	for (long long b = 1LL << ub; b; b >>= 1)
	{
		long long s1 = 0;
		long long s0 = 0;

		for (long long a : A)
		{
			s1 += (a & b) ^ b;
			s0 += (a & b);
		}

		if (s1 <= s0)
		{
			sum = sum - s0 + s1;
			k |= b;
		}
	}

	if (sum > M)
		return -1;

	for (long long b = 1LL << ub; b; b >>= 1)
	{
		if (k & b)
			continue;

		long long s1 = 0;
		long long s0 = 0;

		for (long long a : A)
		{
			s1 += (a & b) ^ b;
			s0 += (a & b);
		}

		if (sum - s0 + s1 <= M)
		{
			sum = sum - s0 + s1;
			k |= b;
		}
	}

	return sum > M ? -1 : k;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		long long M;
		cin >> N >> M;

		vector<long long> A(N);

		for (auto& a : A)
			cin >> a;

		cout << "Case #" << t << ": ";
		cout << equation(N, M, A) << "\n";
	}

	return 0;
}

