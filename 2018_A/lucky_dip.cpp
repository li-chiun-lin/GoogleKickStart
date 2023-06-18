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

void print(map<int, double>& m)
{
	for (auto [k, v] : m)
		cout << k << " : " << v << "\n";
	cout << "\n";
}

double lucky(int N, int K, vector<int>& V)
{
	double sum = accumulate(begin(V), end(V), 0LL);
	vector<double> E(K + 1);
	E[0] = sum / N;

	for (int i = 1; i <= K; ++i)
		for (double v : V)
			E[i] += max(v, E[i - 1]) / N;

	return E[K];
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, K;
		cin >> N >> K;

		vector<int> V(N);

		for (auto& v : V)
			cin >> v;

		cout << "Case #" << t << ": ";
		cout << fixed << setprecision(7) << lucky(N, K, V) << "\n";
	}

	return 0;
}

