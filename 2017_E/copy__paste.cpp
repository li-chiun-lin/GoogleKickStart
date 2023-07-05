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

#define D 0

int dfs(string& S, int i, int copy_i, int copy_len, vector<vector<vector<int>>>& dp)
{
	#if D
	cout << "entering " << i << "\n";
	#endif
	int n = S.size();

	if (i == n)
		return 0;

	if (i == n - 1)
		return 1;

	if (dp[i][copy_i][copy_len] != -1)
		return dp[i][copy_i][copy_len];

	int ret = INT_MAX;

	// Add any single lowercase letter to the end of your string.
	#if D
	cout << "add any single letter\n";
	#endif
	auto r1 = dfs(S, i + 1, copy_i, copy_len, dp) + 1;
	ret = min(ret, r1);

	// Add the entire contents of the clipboard to the end of your string.
	#if D
	cout << "check add copy\n";
	#endif
	if (copy_len > 1 && i + copy_len <= n)
	{
		bool match = true;

		for (int j = 0; j < copy_len && match; ++j)
			match = S[i + j] == S[copy_i + j];

		if (match)
		{
			#if D
			cout << "add copy " << copy_i << " -> " << copy_len << "\n";
			#endif
			auto r2 = dfs(S, i + copy_len, copy_i, copy_len, dp) + 1;
			ret = min(ret, r2);
		}
	}
	
	// Copy any substring of your string to the clipboard.
	#if D
	cout << "check copy " << S << "\n";
	#endif
	for (int new_copy_i = 0; new_copy_i + 1 < i; ++ new_copy_i)
	{
		if (S[i] != S[new_copy_i])
			continue;

		for (int j = 1; new_copy_i + j < i && i + j < n && S[i + j] == S[new_copy_i + j]; ++ j)
		{
			#if D
			cout << i << " copy and immediately paste " << new_copy_i << " " << j << "\n";
			#endif
			auto r3 = dfs(S, i + j + 1, new_copy_i, j + 1, dp) + 2;
			ret = min(ret, r3);
		}
	}

	#if D
	cout << "return from " << i << "\n";
	#endif
	return dp[i][copy_i][copy_len] = ret;
}

int copy_paste(string& S)
{
	int n = S.size();
	vector<vector<vector<int>>> dp(n, 
		vector<vector<int>>(n, 
		vector<int>(n, -1)));

	#if D
	cout << "\n";
	#endif

	return dfs(S, 0, 0, 0, dp);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		string S;
		cin >> S;

		cout << "Case #" << t << ": ";
		cout << copy_paste(S) << "\n";
	}

	return 0;
}

