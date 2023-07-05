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

int dfs(int N, vector<int>& dp)
{
	if (N == 0)
		return 0;

	if (N == 1)
		return 1;

	if (dp[N] != INT_MAX)
		return dp[N];

	int ret = INT_MAX;

	for (int i = 1; i * i <= N; ++i)
	{
		int area = i * i;
		int acc = area;
		int cnt = 1;

		while (acc <= N)
		{
			auto r = dfs(N - acc, dp) + cnt;
			ret = min(ret, r);
			acc += area;
			++ cnt;
		}
	}

	return dp[N] = ret;
}

int cake(int N)
{
	vector<int> dp(N + 1, INT_MAX);
	dp[0] = 0;
	dp[1] = 1;

	//return dfs(N, dp);

	for (int n = 2; n <= N; ++n)
		for (int a = 1; a * a <= n; ++a)
		{
			int area = a * a;
			
			for (int cnt = 1; area * cnt <= n; ++ cnt)
				dp[n] = min(dp[n], dfs(n - area * cnt, dp) + cnt);
		}

	return dp[N];
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		cout << "Case #" << t << ": ";
		cout << cake(N) << "\n";
	}

	return 0;
}

