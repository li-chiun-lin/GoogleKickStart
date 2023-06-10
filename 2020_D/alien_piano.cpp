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

int alien(int K, vector<int>& A)
{
	int cnt = 0;
	int ub = 0;
	int lb = 0;

	for (int i = 1; i < K; ++i)
	{
		if (A[i] > A[i - 1])
		{
			++ ub;
			lb = 0;
		}
		else if (A[i] < A[i - 1])
		{ 
			++ lb;
			ub = 0;
		}
		else
		{

		}

		if (ub > 3 || lb > 3)
		{
			++ cnt;
			ub = 0;
			lb = 0;
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
		int K;
		cin >> K;

		vector<int> A(K);

		for (auto& x : A)
			cin >> x;

		cout << "Case #" << t << ": ";
		cout << alien(K, A) << "\n";
	}

	return 0;
}

