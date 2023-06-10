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

int retype(int N, int K, int S)
{
	int r1 = N + 1;
	int r2 = K - S + (N - S + 1);

	return min(r1, r2) + K - 1;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, K, S;
		cin >> N >> K >> S;

		cout << "Case #" << t << ": ";
		cout << retype(N, K, S) << "\n";
	}

	return 0;
}

