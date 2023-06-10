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

int rugby(int N, vector<pair<int, int>>& P)
{
	int ret = 0;


	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<pair<int, int>> P(N);

		for (auto& [x, y] : P)
			cin >> x >> y;

		cout << "Case #" << t << ": ";
		cout << rugby(N, P) << "\n";
	}

	return 0;
}

