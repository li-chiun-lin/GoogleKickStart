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

int palindromes(int N, int Q, string& S, vector<pair<int, int>>& LR)
{
	int cnt = 0;
	vector<vector<int>> hist(N + 1, vector<int>(26));

	for (int i = 0; i < N; ++i)
	{
		hist[i + 1] = hist[i];
		++ hist[i + 1][S[i] - 'A'];
	}

	for (auto [l, r] : LR)
	{
		vector<int> h = hist[r];

		int odd = 0;
		for (int j = 0; j < 26 && odd < 2; ++j)
			odd += (hist[r][j] - hist[l - 1][j]) % 2;

		if (odd < 2)
			++ cnt;
	}

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, Q;
		string S;
		cin >> N >> Q >> S;

		vector<pair<int, int>> LR(Q);

		for (auto& [l, r] : LR)
			cin >> l >> r;
		
		cout << "Case #" << t << ": ";
		cout << palindromes(N, Q, S, LR) << "\n";
	}

	return 0;
}

