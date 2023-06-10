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

int training(int N, int P, vector<int>& S)
{
	sort(begin(S), end(S));

	int sum = 0;

	for (int i = 0; i < P; ++i)
		sum += S[i];

	int cnt = S[P - 1] * P - sum;

	for (int i = P; i < N; ++i)
		cnt = min(cnt, S[i] * P - (sum += S[i] - S[i - P]));

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, P;
		cin >> N >> P;

		vector<int> S(N);

		for (auto& s : S)
			cin >> s;

		cout << "Case #" << t << ": ";
		cout << training(N, P, S) << "\n";
	}

	return 0;
}

