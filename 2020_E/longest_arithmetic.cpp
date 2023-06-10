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

int arithmetic(int N, vector<int>& A)
{
	int p = A[1] - A[0];
	int l = 2;
	int ret = 2;

	for (int i = 2; i < N; ++i)
	{
		int q = A[i] - A[i - 1];

		if (p != q)
		{
			ret = max(ret, l);
			p = q;
			l = 2;
		}
		else
			++ l;
	}

	return max(ret, l);
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
		cout << arithmetic(N, A) << "\n";
	}

	return 0;
}

