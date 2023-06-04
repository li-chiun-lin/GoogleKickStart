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

int arithmetic(vector<vector<int>>& G)
{
	int base_case = 0;

	for (int i = 0; i < 3; i += 2)
		if (G[i][2] - G[i][1] == G[i][1] - G[i][0])
			++ base_case;

	for (int j = 0; j < 3; j += 2)
		if (G[2][j] - G[1][j] == G[1][j] - G[0][j])
			++ base_case;

	map<int, int> cnt;

	if (((G[1][2] - G[1][0])) % 2 == 0)
		++ cnt[G[1][0] + (G[1][2] - G[1][0]) / 2];

	if (((G[2][1] - G[0][1])) % 2 == 0)
		++ cnt[G[0][1] + (G[2][1] - G[0][1]) / 2];

	if ((G[2][2] - G[0][0]) % 2 == 0)
		++ cnt[G[0][0] + (G[2][2] - G[0][0]) / 2];

	if ((G[2][0] - G[0][2]) % 2 == 0)
		++ cnt[G[0][2] + (G[2][0] - G[0][2]) / 2];

	int max_c = 0;

	for (auto [x, c] : cnt)
		if (max_c < c)
			max_c = c;
	
	return max_c + base_case;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		vector<vector<int>> G(3, vector<int>(3));

		for (auto& c : G[0])
			cin >> c;

		cin >> G[1][0] >> G[1][2];

		for (auto& c : G[2])
			cin >> c;

		cout << "Case #" << t << ": ";
		cout << arithmetic(G) << "\n";
	}

	return 0;
}

