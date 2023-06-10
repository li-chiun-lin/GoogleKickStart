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

vector<int> atm(int N, int X, vector<int>& A)
{
	vector<int> ret(N);
	vector<pair<int, int>> AA(N);

	for (int i = 0; i < N; ++i)
		AA[i] = {(A[i] + (X - 1)) / X, i};

	sort(begin(AA), end(AA));

	for (int i = 0; i < N; ++i)
		ret[i] = AA[i].second + 1;

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, X;
		cin >> N >> X;

		vector<int> A(N);

		for (auto& a : A)
			cin >> a;

		cout << "Case #" << t << ": ";
		auto r = atm(N, X, A);
		print(r);
	}

	return 0;
}

