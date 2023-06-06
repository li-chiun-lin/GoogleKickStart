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

string stable_wall(int R, int C, vector<string>& P)
{
	vector<vector<bool>> visited(R, vector<bool>(C));
	set<char> count;
	map<char, set<char>> support;
	map<char, int> degree;
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
					if (support[P[i][j]].count(P[s][t]) == 0)
					{
						support[P[i][j]].insert(P[s][t]);
						++ degree[P[s][t]];
					}
				}
			}
		}

	string ret = "";
	queue<char> que;

	for (char c : count)
		if (degree[c] == 0)
			que.push(c);

	while (que.size())
	{
		auto u = que.front();
		que.pop();

		ret.push_back(u);

		for (auto v : support[u])
			if (-- degree[v] == 0)
				que.push(v);
	}

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

		if (r.empty())
			cout << -1 << "\n";
		else
			cout << r << "\n";
	}

	return 0;
}

