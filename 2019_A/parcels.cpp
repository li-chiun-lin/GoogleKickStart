/*
to be continued.
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

int parcels(int R, int C, vector<string>& G)
{
	vector<vector<int>> dst(R, vector<int>(C, INT_MAX));
	int d[] = {1, 0, -1, 0, 1};
	queue<pair<int, int>> que;
	int ret = 0;

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			if (G[i][j] == '1')
			{
				dst[i][j] = 0;
				que.push({i, j});
			}

	while (que.size())
	{
		auto [i, j] = que.front();
		que.pop();

		for (int k = 0; k < 4; ++k)
		{
			int ii = i + d[k];
			int jj = j + d[k + 1];

			if (0 <= ii && ii < R && 0 <= jj && jj < C && G[ii][jj] == '0' && dst[ii][jj] > dst[i][j] + 1)
			{
				dst[ii][jj] = dst[i][j] + 1;
				que.push({ii, jj});
			}
		}
	}

	// TODO

	return ret ;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int R, C;
		cin >> R >> C;

		vector<string> G(R);

		for (auto& g : G)
			cin >> g;

		cout << "Case #" << t << ": ";
		cout << parcels(R, C, G) << "\n";
	}

	return 0;
}

