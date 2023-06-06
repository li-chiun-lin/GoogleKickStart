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

long long bus(int N, long long D, vector<long long>& X)
{
	long long d = D;

	for (int i = N - 1; i >= 0; --i)
		d = d / X[i] * X[i];

	return d;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		long long D;
		cin >> N >> D;

		vector<long long> X(N);

		for (auto& x : X)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << bus(N, D, X) << "\n";
	}

	return 0;
}

