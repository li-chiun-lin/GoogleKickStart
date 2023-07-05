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

int dfs(int N, int Ts, int Tf, vector<tuple<int, int, int>>& B, int i, int t, vector<vector<int>>& dp)
{
	if (t > Tf)
		return -1;

	if (i == B.size())
		return 0;

	if (dp[i][t] != -2)
		return dp[i][t];

	auto [s, f, d] = B[i];
	int q1 = (max(t - s, 0) + f - 1) / f;
	int q2 = (max(t + Ts - s, 0) + f - 1) / f;

	int r1 = dfs(N, Ts, Tf, B, i + 1, s + f * q1 + d, dp);
	int r2 = dfs(N, Ts, Tf, B, i + 1, s + f * q2 + d, dp);
	int ret = -1;

	if (r1 == -1 && r2 == -1)
		ret = -1;
	else if (r1 == -1)
		ret = r2 + 1;
	else if (r2 == -1)
		ret = r1;
	else
		ret= max(r1, r2 + 1);

	return dp[i][t] = ret;
}

int sightseeing(int N, int Ts, int Tf, vector<tuple<int, int, int>>& B)
{
	vector<vector<int>> dp(N, vector<int>(Tf + 1, -2));

	return dfs(N, Ts, Tf, B, 0, 0, dp);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, Ts, Tf;
		cin >> N >> Ts >> Tf;

		vector<tuple<int, int, int>> B(N - 1);

		for (auto& [s, f, d] : B)
			cin >> s >> f >> d;

		auto r = sightseeing(N, Ts, Tf, B);

		cout << "Case #" << t << ": ";

		if (r == -1)
			cout << "IMPOSSIBLE\n";
		else
			cout << r << "\n";
	}

	return 0;
}

