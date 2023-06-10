/*
ts3 TLE
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

long long combination(int W, int N, vector<int>& X)
{
	long long ret = LLONG_MAX;
	set<int> s(begin(X), end(X));

	for (auto w : s)
	{
		long long cnt = 0;

		for (auto x : X)
			cnt += min(abs(x - w), N - abs(x - w));

		ret = min(ret, cnt);
	}

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int W, N;
		cin >> W >> N;

		vector<int> X(W);

		for (auto& x : X)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << combination(W, N, X) << "\n";
	}

	return 0;
}

