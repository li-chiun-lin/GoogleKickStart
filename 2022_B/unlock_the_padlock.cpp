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

long long dfs(int N, int D, vector<int>& V, int l, int r, int v, vector<vector<map<int, long long>>>& dp)
{
	if (l > r)
		return 0;

	if (v == V[l])
		return dfs(N, D, V, l + 1, r, v, dp);

	if (v == V[r])
		return dfs(N, D, V, l, r - 1, v, dp);

	if (dp[l][r].find(v) != end(dp[l][r]))
		return dp[l][r][v];

	int left_abs = abs(v - V[l]);
	int left_dst = min(left_abs, D - left_abs);
	int right_abs = abs(v - V[r]);
	int right_dst = min(right_abs, D - right_abs);

	auto ret1 = dfs(N, D, V, l + 1, r, V[l], dp) + left_dst;
	auto ret2 = dfs(N, D, V, l, r - 1, V[r], dp) + right_dst;

	return dp[l][r][v] = min(ret1, ret2);
}

long long unlock(int N, int D, vector<int>& V)
{
	vector<vector<map<int, long long>>> dp(N, 
		vector<map<int, long long>>(N));

	return dfs(N, D, V, 0, N - 1, 0, dp);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, D;
		cin >> N >> D;

		vector<int> V(N);

		for (auto& v : V)
			cin >> v;

		cout << "Case #" << t << ": ";
		cout << unlock(N, D, V) << "\n";
	}

	return 0;
}

