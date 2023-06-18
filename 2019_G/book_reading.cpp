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

long long book(int N, int M, int Q, vector<int>& P, vector<int>& R)
{
	long long cnt = 0;
	map<int, int> hist;
	vector<bool> torn(N + 1);

	for (auto r : R)
		++ hist[r];

	for (auto p : P)
		torn[p] = true;

	for (auto [r, c] : hist)
	{
		long long page = 0;

		for (int p = r; p <= N; p += r)
			if (! torn[p])
				++ page;

		cnt += page * c;
	}

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M, Q;
		cin >> N >> M >> Q;

		vector<int> P(M);
		vector<int> R(Q);

		for (auto& p : P)
			cin >> p;

		for (auto& r : R)
			cin >> r;

		cout << "Case #" << t << ": ";
		cout << book(N, M, Q, P, R) << "\n";
	}

	return 0;
}

