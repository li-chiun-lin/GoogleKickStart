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

int catch_some(int N, int K, vector<int>& P, vector<int>& A)
{
	int ret = 0;
	map<int, int> farthest;

	

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, K;
		cin >> N >> K;

		vector<int> P(N), A(N);

		for (auto& p : P)
			cin >> p;

		for (auto& a : A)
			cin >> a;

		cout << "Case #" << t << ": ";
		cout << catch_some(N, K, P, A) << "\n";
	}

	return 0;
}

