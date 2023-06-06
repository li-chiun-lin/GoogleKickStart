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

int dfs(int P, vector<vector<int>>& S, int i, vector<vector<int>>& dp)
{
	if (P == 0 || i < 0)
		return 0;

	if (dp[i][P])
		return dp[i][P];

	int acc = 0;
	int ret = dfs(P, S, i - 1, dp);

	for (int j = 0; j < S[i].size() && P - j - 1 >= 0; ++j)
	{
		int r = dfs(P - j - 1, S, i - 1, dp) + (acc += S[i][j]);
		ret = max(ret, r);
	}

	return dp[i][P] = ret;
}

int plates(int N, int K, int P, vector<vector<int>>& S)
{
	vector<vector<int>> dp(N, vector<int>(P + 1));

	return dfs(P, S, N - 1, dp);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, K, P;
		cin >> N >> K >> P;

		vector<vector<int>> S(N, vector<int>(K));

		for (auto& r : S)
			for (auto& c : r)
				cin >> c;

		cout << "Case #" << t << ": ";
		cout << plates(N, K, P, S) << "\n";
	}

	return 0;
}

