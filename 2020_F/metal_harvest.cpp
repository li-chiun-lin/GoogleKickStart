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
int robot(int N, int K, vector<pair<int, int>>& SE)
{
	int cnt = 0;
	int ub = 0;

	for (auto& [s, e] : SE)
		ub = max(ub, e);

	vector<int> interval(ub + 1);

	for (auto& [s, e] : SE)
	{
		++ interval[s];
		-- interval[e];
	}

	for (int i = 1; i <= ub; ++i)
		interval[i] += interval[i - 1];

	int i = 0;

	while (i <= ub)
	{
		if (interval[i])
		{
			++ cnt;
			i += K;
		}
		else
			++ i;
	}

	return cnt;
}
#endif

int robot(int N, int K, vector<pair<int, int>>& SE)
{
	int cnt = 0;
	sort(begin(SE), end(SE));

	int deploy = -1;
	int end = -1;

	for (auto [s, e] : SE)
	{
		if (end < e)
		{
			end = max(end, s);
			int c = ((e - end) + (K - 1)) / K;
			end += c * K;
			cnt += c;
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
		int N, K;
		cin >> N >> K;

		vector<pair<int, int>> SE(N);

		for (auto& [s, e] : SE)
			cin >> s >> e;

		cout << "Case #" << t << ": ";
		cout << robot(N, K, SE) << "\n";
	}

	return 0;
}

