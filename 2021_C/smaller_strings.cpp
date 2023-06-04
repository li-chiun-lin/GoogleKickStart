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

int smaller_strings(int N, int K, string& S)
{
	int mod = 1e9 + 7;
	long long ret = 1;

	if (S.size() == 1 && K == 1 && S[0] == 'a')
		return 0;

	for (int l = 0, r = N - 1; l < r; ++l, --r)
	{
		
	}

	return 0;
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
		cout << smaller_strings(N, K, S) << "\n";
	}

	return 0;
}

