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

int dance_battle(int E, int N, vector<int>& S)
{
	int honor = 0;
	int ret = 0;

	sort(begin(S), end(S));

	int l = 0;
	int r = N - 1;

	while (l <= r)
	{
		if (E > S[l])
		{
			E -= S[l];
			++ honor;
			++ l;

			ret = max(ret, honor);
		}
		else if (honor)
		{
			E += S[r];
			-- honor;
			-- r;
		}
		else
			break;
	}

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int E, N;
		cin >> E >> N;

		vector<int> S(N);

		for (auto& s : S)
			cin >> s;

		cout << "Case #" << t << ": ";
		cout << dance_battle(E, N, S) << "\n";
	}

	return 0;
}

