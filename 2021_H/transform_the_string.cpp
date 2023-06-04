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

int transform(string& S, string& F)
{
	int cnt = 0;
	vector<bool> is_favorite(26);

	for (char c : F)
		is_favorite[c - 'a'] = true;

	for (char c : S)
	{
		c -= 'a';

		int l = 0;

		while (! is_favorite[(c - l + 26) % 26] && ! is_favorite[(c + l) % 26])
			++ l;

		cnt += l;
	}

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		string S, F;
		cin >> S >> F;

		cout << "Case #" << t << ": ";
		cout << transform(S, F) << "\n";
	}

	return 0;
}

