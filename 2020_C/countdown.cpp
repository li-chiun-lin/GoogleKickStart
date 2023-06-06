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

int countdown(int N, int K, vector<int>& A)
{
	int cnt = 0;

	for (int i = 0; i < N; ++i)
		if (A[i] == K)
		{
			for (int j = 1; i + j < N && K - j > 0; ++j)
			{
				if (A[i + j] != K - j)
				{
					i += j - 1;
					break;
				}
				
				if (A[i + j] == 1)
				{
					++ cnt;
					i += j - 1;
				}
			}
		}

	return cnt;
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
		cout << countdown(N, K, A) << "\n";
	}

	return 0;
}

