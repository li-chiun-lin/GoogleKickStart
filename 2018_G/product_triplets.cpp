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
int triplet(int N, vector<int>& A)
{
	int cnt = 0;
	sort(begin(A), end(A));
	int Z = 0;

	for (int i = 0; i < N; ++i)
	{
		if (A[i] == 0)
		{
			++ Z;
			continue;
		}

		for (int j = i + 2; j < N; ++j)
			if (A[j] % A[i] == 0)
				for (int k = i + 1; k < j; ++k)
					if (A[k] == A[j] / A[i])
						++ cnt;
	}

	int oo = Z * (Z - 1) / 2 * (N - Z);
	int ooo = Z * (Z - 1) * (Z - 2) / 6;

	return cnt + oo + ooo;
}
#endif

#if 0
int triplet(int N, vector<long long>& A)
{
	int ans = 0;
	sort(rbegin(A), rend(A));
	int Z = 0;

	while (A.size() && A.back() == 0)
	{
		++ Z;
		A.pop_back();
	}

	reverse(begin(A), end(A));

	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = i + 1; j < A.size(); ++j)
		{
			long long target = A[i] * A[j];
			auto lb = lower_bound(begin(A) + j + 1, end(A), target);
			auto ub = upper_bound(begin(A) + j + 1, end(A), target);

			if (lb == end(A) || *lb > target)
				continue;
			else
				ans += ub - lb;
		}
	}

	int oo = Z * (Z - 1) / 2 * (N - Z);
	int ooo = Z * (Z - 1) * (Z - 2) / 6;

	return ans + oo + ooo;
}
#endif

long long triplet(int N, vector<long long>& A)
{
	long long ans = 0;
	sort(rbegin(A), rend(A));
	long long Z = 0;

	while (A.size() && A.back() == 0)
	{
		++ Z;
		A.pop_back();
	}

	unordered_map<long long, long long> occurences;

	for (int y = 0; y < A.size(); ++y)
	{
		for (int x = y + 1; x < A.size(); ++x)
			ans += occurences[A[x] * A[y]];

		++ occurences[A[y]];
	}

	long long oo = Z * (Z - 1) / 2 * (N - Z);
	long long ooo = Z * (Z - 1) * (Z - 2) / 6;

	return ans + oo + ooo;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<long long> A(N);

		for (auto& a : A)
			cin >> a;

		cout << "Case #" << t << ": ";
		cout << triplet(N, A) << "\n";
	}

	return 0;
}

