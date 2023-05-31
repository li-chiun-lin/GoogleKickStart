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

long long bfs(int R, int C, vector<vector<int>>& G, int x, int y)
{
	long long cnt = 0;
	int d[] = {0, 1, 0, -1, 0};

	queue<pair<int, int>> que;
	que.push({x, y});

	while (que.size())
	{
		auto [i, j] = que.front();
		que.pop();

		for (int k = 0; k < 4; ++k)
		{
			int ii = i + d[k];
			int jj = j + d[k + 1];

			if (0 <= ii && ii < R && 0 <= jj && jj < C && G[ii][jj] < G[i][j] - 1)
			{
				int d = G[i][j] - 1 - G[ii][jj];
				cnt += d;
				G[ii][jj] += d;
				que.push({ii, jj});
			}
		}
	}

	return cnt;
}

long long house(int R, int C, vector<vector<int>>& G)
{
	long long cnt = 0;

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			cnt += bfs(R, C, G, i, j);

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int R, C;
		cin >> R >> C;

		vector<vector<int>> G(R, vector<int>(C));

		for (auto& r : G)
			for (auto& c : r)
				cin >> c;

		cout << "Case #" << t << ": ";
		cout << house(R, C, G) << "\n";
	}

	return 0;
}

