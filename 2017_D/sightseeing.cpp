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

void dfs(int N, int Ts, int Tf, vector<tuple<int, int, int>>& B, int i, int t, int seen, int& ret)
{
	//cout << i << " " << t << "\n";

	if (t > Tf)
		return ;

	if (i == N - 1)
	{
		ret = max(ret, seen);
		return ;
	}

	auto [s, f, d] = B[i];

	// dont
	int bus_round1 = (max(t - s, 0) + (f - 1)) / f;
	dfs(N, Ts, Tf, B, i + 1, s + bus_round1 * f + d, seen, ret);

	// take
	int bus_round2 = (max(t + Ts - s, 0) + (f - 1)) / f;
	dfs(N, Ts, Tf, B, i + 1, s + bus_round2 * f + d, seen + 1, ret);

}

int sightseeing(int N, int Ts, int Tf, vector<tuple<int, int, int>>& B)
{
	int ret = -1;
	dfs(N, Ts, Tf, B, 0, 0, 0, ret);

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, Ts, Tf;
		cin >> N >> Ts >> Tf;

		vector<tuple<int, int, int>> B(N - 1);

		for (auto& [s, f, d] : B)
			cin >> s >> f >> d;

		auto r = sightseeing(N, Ts, Tf, B);

		cout << "Case #" << t << ": ";

		if (r == -1)
			cout << "IMPOSSIBLE\n";
		else
			cout << r << "\n";
	}

	return 0;
}

