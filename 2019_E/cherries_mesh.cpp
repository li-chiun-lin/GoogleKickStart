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

#if 0
int cherries(int N, int M, vector<pair<int, int>>& B)
{
	int cnt = 0;

	vector<vector<int>> strand(N + 1, vector<int>(N + 1, 2));

	for (auto [c, d] : B)
	{
		strand[c][d] = 1;
		strand[d][c] = 1;
	}
	
	vector<bool> connected(N + 1);
	priority_queue<
		pair<int, int>, 
		vector<pair<int, int>>, 
		greater<>> pq;

	pq.push({0, 1});

	while (pq.size())
	{
		auto [w, u] = pq.top();
		pq.pop();

		if (connected[u])
			continue;

		connected[u] = true;
		cnt += w;

		for (int v = 1; v <= N; ++v)
		{
			if (connected[v])
				continue;

			pq.push({strand[u][v], v});
		}
	}

	return cnt;
}
#endif

int cherries(int N, int M, vector<pair<int, int>>& B)
{
	int cnt = 0;

	vector<vector<int>> strand(N + 1);

	for (auto [c, d] : B)
	{
		strand[c].push_back(d);
		strand[d].push_back(c);
	}
	
	vector<bool> connected(N + 1);
	queue<int> pq;

	for (int i = 1; i <= N; ++i)
	{
		if (connected[i])
			continue;

		connected[i] = true;
		pq.push(i);
		int c = 0;

		while (pq.size())
		{
			auto u = pq.front();
			pq.pop();

			++ c;

			for (int v : strand[u])
			{
				if (connected[v])
					continue;

				connected[v] = true;
				pq.push(v);
			}
		}

		if (c)
			cnt += c - 1;
	}

	return cnt + (N - 1 - cnt) * 2;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M;
		cin >> N >> M;

		vector<pair<int, int>> B(M);

		for (auto& [c, d] : B)
			cin >> c >> d;

		cout << "Case #" << t << ": ";
		cout << cherries(N, M, B) << "\n";
	}

	return 0;
}

