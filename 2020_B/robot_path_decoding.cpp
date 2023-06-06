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

pair<int, int> robot(string& S)
{
	stack<tuple<int, long long, long long>> special;
	long long x = 0, y = 0;
	int m = 1e9;

	for (int i = 0; i < S.size(); ++i)
	{
		if (S[i] == 'N')
			-- y;
		else if (S[i] == 'S')
			++ y;
		else if (S[i] == 'E')
			++ x;
		else if (S[i] == 'W')
			-- x;
		else if (isdigit(S[i]))
		{
			special.push({S[i] - '0', ((x % m) + m) % m, ((y % m) + m) % m});
			x = 0;
			y = 0;
			++ i;
		}
		else if (S[i] == ')')
		{
			auto [t, xx, yy] = special.top();
			special.pop();

			x = xx += (t * (x % m)) % m;
			y = yy += (t * (y % m)) % m;
		}
	}

	return {(x + m) % m + 1, (y + m) % m + 1};
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		string S;
		cin >> S;

		cout << "Case #" << t << ": ";
		auto [x, y] = robot(S);
		cout << x << " " << y << "\n";
	}

	return 0;
}

