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

void print(map<int, int>& m)
{
	for (auto [k, v] : m)
		cout << k << ":" << v << "\n";
	cout << "\n";
}

void print(vector<int>& v)
{
	for (auto x : v)
		cout << setw(3) << x;
	cout << "\n";
}

void dfs(int u, int f, vector<vector<int>>& adj_diff, vector<vector<int>>& adj_same, vector<int>& flip, map<int, int>& cnt)
{
	flip[u] = f;
	++ cnt[f];

	for (int v : adj_same[u])
		if (flip[v] == 0)
			dfs(v, f, adj_diff, adj_same, flip, cnt);

	f *= -1;
	for (int v : adj_diff[u])
		if (flip[v] == 0)
			dfs(v, f, adj_diff, adj_same, flip, cnt);
}

int diagonal(int N, vector<string>& G)
{
	map<int, int> dia_id, per_id;
	int NN = 2 * N - 1;

	for (int i = 0; i < NN; ++i)
	{
		per_id[i] = i;
		dia_id[-N + 1 + i] = i + NN;
	}

	vector<vector<int>> adj_diff(NN * 2), adj_same(NN * 2);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			int u = dia_id[i - j];
			int v = per_id[i + j];

			if (G[i][j] == '.')
			{
				adj_diff[u].push_back(v);
				adj_diff[v].push_back(u);
			}
			else
			{
				adj_same[u].push_back(v);
				adj_same[v].push_back(u);
			}
		}

	vector<int> flip(NN * 2);
	int ret = 0;

	for (int i = 0; i < flip.size(); ++i)
		if (flip[i] == 0)
		{
			map<int, int> cnt;
			dfs(i, 1, adj_diff, adj_same, flip, cnt);

			ret += min(cnt[-1], cnt[1]);
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

		vector<string> G(N);

		for (auto& g : G)
			cin >> g;

		cout << "Case #" << t << ": ";
		cout << diagonal(N, G) << "\n";
	}

	return 0;
}

