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

void print(vector<int>& vec)
{
	for (auto x : vec)
		cout << x << " ";
	cout << "\n";
}

void print(vector<string>& P)
{
	for (auto& s : P)
		cout << s << "\n";
	cout << "\n";
}

void check(vector<string>& P, string& seq)
{
	vector<string> Q = P;

	for (auto& s : Q)
		for (char& c : s)
			c = ' ';

	for (auto x : seq)
	{
		for (int i = 0; i < P.size(); ++i)
			for (int j = 0; j < P[i].size(); ++j)
				if (P[i][j] == x)
					Q[i][j] = x;

		print(Q);
	}
}

string stable_wall(int R, int C, vector<string>& P)
{
	for (auto& p : P)
		for (auto& c : p)
			c -= 'A';

	vector<vector<bool>> visited(R, vector<bool>(C));
	unordered_set<char> count;
	vector<vector<bool>> support(26, vector<bool>(26));
	vector<int> degree(26);

	int d[] = {0, 1, 0, -1, 0};

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
		{
			if (visited[i][j])
				continue;

			visited[i][j] = true;
			count.insert(P[i][j]);
			queue<pair<int, int>> que;

			que.push({i, j});

			while (que.size())
			{
				auto [s, t] = que.front();
				que.pop();

				for (int k = 0; k < 3; ++k)
				{
					int ss = s + d[k];
					int tt = t + d[k + 1];

					if (0 <= ss && ss < R && 0 <= tt && tt < C && 
						! visited[ss][tt] && P[ss][tt] == P[i][j])
					{
						visited[ss][tt] = true;
						que.push({ss, tt});
					}
				}

				-- s;

				if (0 <= s && s < R && P[s][t] != P[i][j])
				{
					if (! support[P[i][j]][P[s][t]])
					{
						support[P[i][j]][P[s][t]] = true;
						++ degree[P[s][t]];
					}
				}
			}
		}

	string ret = "";
	queue<int> que;

	for (char c : count)
		if (degree[c] == 0)
			que.push(c);

	while (que.size())
	{
		auto u = que.front();
		que.pop();

		ret.push_back(u + 'A');

		for (int v = 0; v < 26; ++v)
			if (support[u][v] && -- degree[v] == 0)
					que.push(v);
	}

	for (auto& p : P)
		for (auto& c : p)
			c += 'A';

	return ret.size() == count.size() ? ret : "";
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int R, C;
		cin >> R >> C;

		vector<string> P(R);

		for (auto& p : P)
			cin >> p;

		cout << "Case #" << t << ": ";

		auto r = stable_wall(R, C, P);

		//cout << "\n";
		//check(P, r);

		if (r.empty())
			cout << -1 << "\n";
		else
			cout << r << "\n";
	}

	return 0;
}

