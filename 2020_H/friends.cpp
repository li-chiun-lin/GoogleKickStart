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
	if (v.size())
	{
		cout << v[0];

		for (int i = 1; i < v.size(); ++i)
			cout << " " << v[i];
	}

	cout << "\n";
}

void print(vector<vector<int>>& v)
{
	for (auto& r : v)
		print(r);

	cout << "\n";
}

void print(vector<set<int>>& v)
{
	for (auto& r : v)
	{
		for (auto c : r)
			cout << c << " ";
		cout << "\n";
	}

	cout << "\n";
}

#if 0
vector<int> friends(int N, int Q, vector<string>& S, vector<pair<int, int>>& XY)
{
	vector<int> ret(Q);

	vector<set<int>> grp(26);
	vector<set<int>> adj(N);

	for (int i = 0; i < N; ++i)
		for (auto c : set<char>(begin(S[i]), end(S[i])))
		{
			for (auto j : grp[c - 'A'])
			{
				adj[j].insert(i);
				adj[i].insert(j);
			}

			grp[c - 'A'].insert(i);
		}

	vector<vector<int>> dst(N, vector<int>(N, INT_MAX));

	for (int i = 0; i < Q; ++i)
	{
		auto [s, t] = XY[i];
		-- s;
		-- t;

		if (dst[s][t] != INT_MAX)
		{
			ret[i] = dst[s][t];
			continue;
		}

		if (dst[t][s] != INT_MAX)
		{
			ret[i] = dst[t][s];
			continue;
		}

		dst[s][s] = 0;
		queue<int> que;
		que.push(s);

		while (que.size())
		{
			auto u = que.front();
			que.pop();

			for (auto v : adj[u])
			{
				if (dst[s][v] > dst[s][u] + 1)
				{
					dst[s][v] = dst[s][u] + 1;
					que.push(v);
				}
			}
		}

		for (auto& d : dst[s])
			if (d == INT_MAX)
				d = -1;
			else
				++ d;

		ret[i] = dst[s][t];
	}
	
	return ret;
}
#endif

vector<int> friends(int N, int Q, vector<string>& S, vector<pair<int, int>>& XY)
{
	vector<int> ret(Q);

	vector<vector<bool>> adj_char(26, vector<bool>(26));
	vector<vector<int>> dst(26, vector<int>(26, INT_MAX));

	for (int i = 0; i < N; ++i)
	{
		set<char> ss(begin(S[i]), end(S[i]));

		for (auto c : ss)
			for (auto d : ss)
			{
				adj_char[c - 'A'][d - 'A'] = true;
				adj_char[d - 'A'][c - 'A'] = true;
			}
	}

	for (int i = 0; i < 26; ++i)
	{
		dst[i][i] = 1;
		queue<int> que;
		que.push(i);

		while (que.size())
		{
			auto u = que.front();
			que.pop();

			for (int v = 0; v < 26; ++v)
				if (adj_char[u][v] && dst[i][v] > dst[i][u] + 1)
				{
					dst[i][v] = dst[i][u] + 1;
					que.push(v);
				}
		}

		for (int& d : dst[i])
			if (d == INT_MAX)
				d = -1;
			else
				++d ;

	}

	for (int i = 0; i < Q; ++i)
	{
		int s = XY[i].first - 1;
		int t = XY[i].second - 1;

		int r = INT_MAX;

		for (char c : S[s])
			for (char d : S[t])
				r = min(r, dst[c - 'A'][d - 'A']);

		ret[i] = r == INT_MAX ? -1 : r;
	}

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, Q;
		cin >> N >> Q;

		vector<string> S(N);
		vector<pair<int, int>> XY(Q);

		for (auto& s : S)
			cin >> s;

		for (auto& [x, y] : XY)
			cin >> x >> y;

		cout << "Case #" << t << ": ";
		auto r = friends(N, Q, S, XY);
		print(r);
	}

	return 0;
}

