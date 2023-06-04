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

void print(vector<int>& vec)
{
	for (auto x : vec)
		cout << x << " ";
	cout << "\n";
}



int banana(int N, int K, vector<int>& B)
{
	vector<int> prefix(N + 1);

	for (int i = 0; i < N; ++i)
		prefix[i + 1] = prefix[i] + B[i];

#if 0
	cout << "\n";
	print(B);
	print(prefix);
#endif

	int ret = INT_MAX;

	// case 1: 1 section only
	for (int l = 0; l < N; ++l)
		for (int r = l + 1; r <= N; ++r)
		{
			int d = prefix[r] - prefix[l];

			if (d > K)
				break;

			if (d == K)
			{
				ret = min(ret, r - l);
				break;
			}
		}

	// case 2: 2 sections
	for (int l1 = 0; l1 < N; ++l1)
		for (int r1 = l1 + 1; r1 <= N; ++r1)
		{
			int d1 = prefix[r1] - prefix[l1];
			if (d1 >= K)
				break;

			for (int l2 = r1 + 1; l2 < N; ++l2)
				for (int r2 = l2 + 1; r2 <= N; ++r2)
				{
					int d2 = prefix[r2] - prefix[l2];

					if (d1 + d2 > K)
						break;

					if (d1 + d2 == K)
					{
						ret = min(ret, (r1 - l1) + r2 - l2);
						break;
					}
				}
		}


	return ret == INT_MAX ? -1 : ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, K;
		cin >> N >> K;

		vector<int> B(N);

		for (auto& x : B)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << banana(N, K, B) << "\n";
	}

	return 0;
}

