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

long long maximum(int N, vector<vector<int>>& C)
{
	vector<long long> sum(N * 2 + 1);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			sum[i - j + N] += C[i][j];

	long long ret = 0;

	for (auto s : sum)
		ret = max(ret, s);

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

		vector<vector<int>> C(N, vector<int>(N));

		for (auto& r : C)
			for (auto& c : r)
				cin >> c;

		cout << "Case #" << t << ": ";
		cout << maximum(N, C) << "\n";
	}

	return 0;
}

