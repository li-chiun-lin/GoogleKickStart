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

long long d2(pair<int, int>& a, pair<int, int>& b)
{
	return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int square_cnt(int R, int C)
{
	int m = 1e9 + 7;
	long long cnt = 0;

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
		{

		}
	
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

		cout << "Case #" << t << ": ";
		cout << square_cnt(R, C) << "\n";
	}

	return 0;
}

