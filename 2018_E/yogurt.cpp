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

#if 0
long long yogurt(int N, int K, vector<int>& A)
{
	map<int, int> expire;

	for (auto a : A)
		++ expire[a];

	long long max_consuming = 0;
	long long actuall_consume = 0;

	for (auto [d, c] : expire)
	{
		max_consuming = (long long)d * K - actuall_consume;
		actuall_consume += min((long long)c, max_consuming);
	}

	return actuall_consume;
}
#endif

int yogurt(int N, int K, vector<int>& A)
{
	sort(begin(A), end(A));

	int i = 0;
	int expired = 0;

	// for each day, 
	for (int d = 0, i = 0; d < N && i < N; ++d)
	{
		// remove those already expired.
		while (i < N && A[i] <= d)
		{
			++ expired;
			++ i;
		}

		// consume at most K yogurts.
		for (int k = 0; k < K && i < N; ++k)
			++ i;
	}

	return N - expired;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, K;
		cin >> N >> K;

		vector<int> A(N);

		for (auto& a : A)
			cin >> a;

		cout << "Case #" << t << ": ";
		cout << yogurt(N, K, A) << "\n";
	}

	return 0;
}

