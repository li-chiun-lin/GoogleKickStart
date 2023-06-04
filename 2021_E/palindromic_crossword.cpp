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

void print(vector<string>& vec)
{
	for (auto& s : vec)
		cout << s << "\n";
}

void print(vector<vector<vector<pair<int, int>>>>& adj)
{
	for (int i = 0; i < adj.size(); ++i)
		for (int j = 0; j < adj[i].size(); ++j)
		{
			cout << "[" << i << "," << j << "] ";
			for (auto& [s, t] : adj[i][j])
				cout << "(" << s << "," << t << ") ";
			cout << "\n";
		}
}

int crossword(int N, int M, vector<string>& R)
{
	vector<vector<vector<pair<int, int>>>> adj(N, 
		vector<vector<pair<int, int>>>(M));

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			if (R[i][j] == '#')
				continue;

			int k = j;

			while (k + 1 < M && R[i][k + 1] != '#')
				++ k;

			for (int jj = j, kk = k; jj < kk; ++jj, --kk)
			{
				adj[i][jj].push_back({i, kk});
				adj[i][kk].push_back({i, jj});
			}

			j = k;
		}

	for (int j = 0; j < M; ++j)
		for (int i = 0; i < N; ++i)
		{
			if (R[i][j] == '#')
				continue;

			int k = i;

			while (k + 1 < N && R[k + 1][j] != '#')
				++ k;

			for (int ii = i, kk = k; ii < kk; ++ii, --kk)
			{
				adj[ii][j].push_back({kk, j});
				adj[kk][j].push_back({ii, j});
			}

			i = k;
		}

	queue<pair<int, int>> que;
	int cnt = 0;
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (R[i][j] != '#' && R[i][j] != '.')
				que.push({i, j});

	while (que.size())
	{
		auto [i, j] = que.front();
		que.pop();

		for (auto [s, t] : adj[i][j])
			if (R[s][t] == '.')
			{
				++ cnt;
				R[s][t] = R[i][j];
				que.push({s, t});
			}
	}

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M;
		cin >> N >> M;

		vector<string> R(N);

		for (auto& r : R)
			cin >> r;

		cout << "Case #" << t << ": ";
		cout << crossword(N, M, R) << "\n";
		print(R);
	}

	return 0;
}

