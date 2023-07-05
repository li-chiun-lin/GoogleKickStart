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

bool dfs_B(int N, vector<int>& A, int l, int pivot, int r);
bool dfs_C(int N, vector<int>& A, int l, int pivot, int r);

bool dfs_B(int N, vector<int>& A, int l, int pivot, int r)
{
	// left side elements: l + 1
	// right side elements : N - r
	// the pivot element : 1
	// if there is less than one element, we are done.
	if (l + 1 + N - r + 1 <= 1)
		return true;

	// check if we can put all the elements, except the pivot, into B
	for (int i = 0; i <= l; ++i)
		if (A[i] > A[pivot])
			return false;

	for (int i = r; i < N; ++i)
		if (A[i] > A[pivot])
			return false;

	if (l + 1 >= N - r)
		return dfs_B(N, A, l - 1, l, r) || dfs_C(N, A, l - 1, l, r);
	else
		return dfs_B(N, A, l, r, r + 1) || dfs_C(N, A, l, r, r + 1);
}

bool dfs_C(int N, vector<int>& A, int l, int pivot, int r)
{
	if (l + 1 + N - r + 1 <= 1)
		return true;

	// check if we can put all the elements, except the pivot, into C
	for (int i = 0; i <= l; ++i)
		if (A[i] <= A[pivot])
			return false;

	for (int i = r; i < N; ++i)
		if (A[i] <= A[pivot])
			return false;

	if (l + 1 >= N - r)
		return dfs_B(N, A, l - 1, l, r) || dfs_C(N, A, l - 1, l, r);
	else
		return dfs_B(N, A, l, r, r + 1) || dfs_C(N, A, l, r, r + 1);
}

bool kicksort(int N, vector<int>& A)
{
	int p = (N - 1) / 2;

	return dfs_B(N, A, p - 1, p, p + 1) || dfs_C(N, A, p - 1, p, p + 1);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> A(N);

		for (auto& a : A)
			cin >> a;

		cout << "Case #" << t << ": ";
		cout << (kicksort(N, A) ? "YES" : "NO") << "\n";
	}

	return 0;
}

