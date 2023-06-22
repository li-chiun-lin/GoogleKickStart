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

void print(vector<int>& v)
{
	// skip redundant v[0]
	for (int i = 1; i < v.size(); ++i)
		cout << v[i] << " ";

	cout << "\n";
}

int extra_edge(int N, vector<pair<int, int>>& V)
{
	set<int> spanning_tree;

	for (int i = 0; i < N; ++i)
	{
		auto [x, y] = V[i];

		if (spanning_tree.count(x) && spanning_tree.count(y))
			return i;

		spanning_tree.insert(x);
		spanning_tree.insert(y);
	}
	
	cerr << "no extra edge\n";
	return -1;
}

bool dfs(int p, int u, int t, vector<vector<int>>& adj, vector<int>& path)
{
	if (u == t)
		return true;

	for (int v : adj[u])
	{
		if (v == p)
			continue;

		path.push_back(v);

		if (dfs(u, v, t, adj, path))
			return true;

		path.pop_back();
	}

	return false;
}

vector<int> planet_distance(int N, vector<pair<int, int>>& V)
{
	int e = extra_edge(N, V);
	vector<vector<int>> adj(N + 1);

	for (int i = 0; i < N; ++i)
	{
		// exclude the extra edge, 
		// we got a tree.
		if (i == e)
			continue;

		auto [x, y] = V[i];
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	vector<int> dst(N + 1, INT_MAX);
	vector<int> path;

	auto [s, t] = V[e];
	path.push_back(s);

	// find the path from s to e.
	if (dfs(-1, s, t, adj, path) == false)
	{
		cerr << "can not find path from " << s << " to " << t << "\n";
		return dst;
	}

	// set the destance to 0
	for (auto x : path)
		dst[x] = 0;

	// calculate the distance for other nodes.
	while (path.size())
	{
		auto u = path.back();
		path.pop_back();

		for (int v : adj[u])
		{
			if (dst[v] > dst[u] + 1)
			{
				dst[v] = dst[u] + 1;
				path.push_back(v);
			}
		}
	}

	return dst;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<pair<int, int>> V(N);

		for (auto& [x, y] : V)
			cin >> x >> y;

		cout << "Case #" << t << ": ";
		auto r = planet_distance(N, V);
		print(r);
	}

	return 0;
}

