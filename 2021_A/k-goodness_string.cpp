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

int goodness(int N, int K, string& S)
{
	for (int i = 0, j = N - 1; i < j; ++i, --j)
		if (S[i] != S[j])
			-- K;
	
	return abs(K);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, K;
		string S;

		cin >> N >> K >> S;

		cout << "Case #" << t << ": ";
		cout << goodness(N, K, S) << "\n";
	}

	return 0;
}

