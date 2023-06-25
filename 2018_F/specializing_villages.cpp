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

long long village(int V, int E, vector<vector<int>>& R)
{
	vector<vector<pair<int, int>>> adj(V);

	for (auto& r : R)
	{
		adj[r[0] - 1].push_back({r[2], r[1] - 1});
		adj[r[1] - 1].push_back({r[2], r[0] - 1});
	}

	vector<int> l(V), d(V), f(V), type(V, -1);

	for (int v = 0; v < V; ++v)
	{
		l[v] = v;
		auto it = min_element(begin(adj[v]), end(adj[v]));
		d[v] = it->first;
		f[v] = it->second;
	}

	sort(begin(l), end(l), 
		[&](int a, int b)
		{
			return d[a] < d[b];
		});

	int N = 0;

	for (int v : l)
	{
		if (type[f[v]] == -1)
		{
			++ N;
			type[v] = 0;
		}
		else
		{
			type[v] = 1 - type[f[v]];

			if (d[v] && d[f[v]] == 0)
				++ N;
		}
	}

	return pow(2, N);
}

#if 0
int village(int V, int E, vector<vector<int>>& R)
{
	vector<vector<pair<int, int>>> adj(V);

	for (auto& r : R)
	{
		adj[r[0] - 1].push_back({r[1] - 1, r[2]});
		adj[r[1] - 1].push_back({r[0] - 1, r[2]});
	}

	vector<vector<int>> dst(V, vector<int>(V, INT_MAX));
	queue<int> que;

	for (int x = 0; x < V; ++x)
	{
		dst[x][x] = 0;
		que.push(x);

		while (que.size())
		{
			auto u = que.front();
			que.pop();

			for (auto [v, l] : adj[u])
			{
				if (dst[x][v] > dst[x][u] + l)
				{
					dst[x][v] = dst[x][u] + l;
					que.push(v);
				}
			}
		}
	}

	int ub = 1 << V;
	map<int, vector<int>> avg;

	for (int producing_type = 0; producing_type < ub; ++producing_type)
	{
		vector<int> type(V);
		int i = 0;
		int p = producing_type;

		while (p)
		{
			type[i ++] = p & 1;
			p >>= 1;
		}

		int len = 0;

		for (int x = 0; x < V; ++x)
		{
			int shr = INT_MAX;

			for (int y = 0; y < V; ++y)
			{
				if (y == x || type[y] == type[x])
					continue;

				shr = min(shr, dst[x][y]);
			}

			// not a valid plan.
			if (shr == INT_MAX)
			{
				len = -1;
				break;
			}

			len += shr;
		}

		// not a valid plan.
		if (len == -1)
			continue;

		avg[len].push_back(producing_type);
	}

	return begin(avg)->second.size();
}
#endif

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int V, E;
		cin >> V >> E;

		vector<vector<int>> R(E, vector<int>(3));

		for (auto& r : R)
			cin >> r[0] >> r[1] >> r[2];

		cout << "Case #" << t << ": ";
		cout << village(V, E, R) << "\n";
	}

	return 0;
}

