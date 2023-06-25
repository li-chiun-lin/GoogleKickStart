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
int OB = -100000;

int find(vector<int>& g, int x)
{
	if (g[x] != x)
		g[x] = find(g, g[x]);

	return g[x];
}

void join(vector<int>& g, int x, int y)
{
	int gx = find(g, x);
	int gy = find(g, y);

	if (gx > gy)
	{
		g[gx] = gy;
	}
	else if (gx < gy)
	{
		g[gy] = gx;
	}
}

void print(vector<vector<int>>& v)
{
	for (auto& r : v)
	{
		for (auto c : r)
			cout << setw(8) << c;
		cout << "\n";
	}
	cout << "\n";
}

void print_shortest_dst(vector<vector<int>>& d)
{
	for (int i = 0; i < d.size(); ++i)
		for (int j = 0; j < d[i].size(); ++j)
			if (d[i][j] != INT_MAX)
				cout << i << " <-> " << j << " = " << d[i][j] << "\n";
	cout << "\n";
}

void print(vector<vector<int>>& V, vector<int>& g)
{
	for (int i = 0; i < V.size(); ++i)
	{
		for (int j = 0; j < V[i].size(); ++j)
		{
			cout << setw(4);

			if (V[i][j] == OB)
			{
				cout << "*";
			}
			else if (V[i][j] < 0)
			{
				cout << -find(g, i * V[i].size() + j);
			}
			else
			{
				cout << find(g, i * V[i].size() + j);
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

void print(vector<int>& g, int M)
{
	for (int i = 0; i < g.size(); ++i)
	{
		cout << setw(3) << g[i];

		if (i % M == M - 1)
			cout << "\n";
	}
	cout << "\n";
}

void print(map<int, set<pair<int, int>>>& adj)
{
	for (auto& [g, ss] : adj)
	{
		cout << g << " : ";
		for (auto [i, j] : ss)
			cout << i << "," << j << " ";
		cout << "\n";
	}

	cout << "\n";
}

void print(vector<int>& sum)
{
	cout << "local sum : ";

	for (int i = 0; i < sum.size(); ++i)
		if (sum[i])
			cout << i << ":" << sum[i] << " ";
	cout << "\n";
}

void print_grp_dst(vector<vector<pair<int, int>>>& adj)
{
	for (int i = 0; i < adj.size(); ++i)
	{
		if (adj[i].size())
		{
			cout << i << " : ";
			for (auto [w, j] : adj[i])
				cout << j << ":" << w << " ";
			cout << "\n";
		}
	}

	cout << "\n";
}

void dfs(int u, int e, int target, vector<bool>& visited, vector<vector<pair<int, int>>>& adj, vector<int>& sum, int& ret)
{
	cout << "entering " << u << " with " << e << "\n";

	if (visited[target])
		ret = max(ret, e);
	
	for (auto [w, v] : adj[u])
	{
		if (visited[v] || e + w < 0)
			continue;

		visited[v] = true;
		cout << "from " << u << " to " << v << "\n";
		dfs(v, e + w + sum[v], target, visited, adj, sum, ret);
		visited[v] = false;
	}
}

int cave(int N, int M, int E, int SR, int SC, int TR, int TC, vector<vector<int>>& V)
{
	vector<int> g(N * M);
	iota(begin(g), end(g), 0);
	int d[] = {1, 0, -1, 0, 1};
	vector<int> grp_sum(N * M);
	vector<vector<int>> dst_connected_by_traps(N, vector<int>(M, OB));
	map<int, set<pair<int, int>>> directly_connected_trap;
	vector<vector<int>> shortest_dst_between_groups(N * M, vector<int>(N * M, INT_MAX));
	vector<vector<pair<int, int>>> grp_adj(N * M);
	vector<int> grp_dst(N * M, OB);
	vector<bool> grp_visited(N * M);
	vector<pair<int, int>> trap;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			int idx = i * M + j;

			if (V[i][j] == OB)
			{
			}
			else if (V[i][j] < 0)
			{
				trap.push_back({i, j});
			}
			else
			{
				for (int k = 0; k < 4; ++k)
				{
					int ii = i + d[k];
					int jj = j + d[k + 1];

					if (0 <= ii && ii < N && 0 <= jj && jj < M)
					{
						if (V[ii][jj] == OB)
							;
						else if (V[ii][jj] >= 0)
							join(g, idx, ii * M + jj);
						else
						{
							directly_connected_trap[find(g, idx)].insert({ii, jj});
						}
					}
				}
			}
		}

	sort(begin(trap), end(trap), 
		[&](pair<int, int>& a, pair<int, int>& b)
		{
			return V[a.first][a.second] > V[b.first][b.second];
		});

	for (auto& [gx, trap] : directly_connected_trap)
	{
		queue<pair<int, int>> que;

		for (auto t : trap)
		{
			que.push(t);
			dst_connected_by_traps[t.first][t.second] = V[t.first][t.second];
		}

		while (que.size())
		{
			auto [i, j] = que.front();
			que.pop();

			for (int k = 0; k < 4; ++k)
			{
				int ii = i + d[k];
				int jj = j + d[k + 1];

				if (0 <= ii && ii < N && 0 <= jj && jj < M)
				{
					if (V[ii][jj] == OB)
						;
					else if (V[ii][jj] >= 0)
					{
						int gy = find(g, ii * M + jj);

						if (gx != gy)
						{
							shortest_dst_between_groups[gx][gy] = min(shortest_dst_between_groups[gx][gy], dst_connected_by_traps[i][j]);
						}
					}
					else
					{
						if (dst_connected_by_traps[ii][jj] < dst_connected_by_traps[i][j] + V[ii][jj])
						{
							dst_connected_by_traps[ii][jj] = dst_connected_by_traps[i][j] + V[ii][jj];
							que.push({ii, jj});
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < N * M; ++i)
		for (int j = 0; j < N * M; ++j)
			if (shortest_dst_between_groups[i][j] != INT_MAX)
			{
				grp_adj[i].push_back({shortest_dst_between_groups[i][j], j});
				grp_adj[j].push_back({shortest_dst_between_groups[i][j], i});
			}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			int idx = i * M + j;

			if (V[i][j] == OB)
			{
			}
			else if (V[i][j] < 0)
			{

			}
			else
			{
				grp_sum[find(g, idx)] += V[i][j];
			}
		}

	int gs = find(g, (SR - 1) * M + (SC - 1));
	int gt = find(g, (TR - 1) * M + (TC - 1));
	long long ub = 1LL << trap.size();
	int ret = -1;

	// TODO: go throuth every possible combination of traps
	for (long long trap_set = 0; trap_set < ub; ++ trap_set)
	{

	}


	


	cout << "\n";
	cout << "the cave\n";
	print(V);
	cout << "the groups\n";
	print(V, g);
	//print(g, M);
	cout << "the directly connected traps for each group\n";
	print(directly_connected_trap);
	cout << "the shortest distance between group\n";
	print_shortest_dst(shortest_dst_between_groups);
	cout << "the adjacent info for each group\n";
	print_grp_dst(grp_adj);
	cout << "the shortest path connected by traps\n";
	print(dst_connected_by_traps);
	print(grp_sum);
	cout << "from group " << gs << " to " << gt << "\n";
	cout << "there are " << trap.size() << " traps\n";





	
	
	
	

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M, E, SR, SC, TR, TC;
		cin >> N >> M >> E >> SR >> SC >> TR >> TC;

		vector<vector<int>> V(N, vector<int>(M));

		for (auto& r : V)
			for (auto& c : r)
				cin >> c;

		cout << "Case #" << t << ": ";
		cout << cave(N, M, E, SR, SC, TR, TC, V) << "\n";
	}

	return 0;
}

