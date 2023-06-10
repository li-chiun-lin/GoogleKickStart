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

void print(vector<int>& v)
{
	if (v.size())
	{
		cout << v[0];

		for (int i = 1; i < v.size(); ++i)
			cout << " " << v[i];
	}

	cout << "\n";
}

vector<int> what(int N, int Q, vector<int>& A, vector<pair<int, int>>& PV)
{
	vector<int> ret(Q);
	set<int> idx_odd;

	for (int i = 0; i < N; ++i)
		if (__builtin_popcount(A[i]) % 2)
			idx_odd.insert(i);

	for (int i = 0; i < Q; ++i)
	{
		auto [p, v] = PV[i];
		int cnt = __builtin_popcount(v) % 2;

		if (cnt != idx_odd.count(p))
		{
			if (cnt)
				idx_odd.insert(p);
			else
				idx_odd.erase(p);
		}

		ret[i] = idx_odd.size() % 2 ? max(*rbegin(idx_odd), N - *begin(idx_odd) - 1) : N;
	}

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, Q;
		cin >> N >> Q;

		vector<int> A(N);
		vector<pair<int, int>> PV(Q);

		for (auto& a : A)
			cin >> a;

		for (auto& [p, v] : PV)
			cin >> p >> v;

		cout << "Case #" << t << ": ";
		auto r = what(N, Q, A, PV);
		print(r);
	}

	return 0;
}

