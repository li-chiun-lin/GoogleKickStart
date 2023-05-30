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

vector<int> range(long long N, int X, int Y)
{
	vector<int> ret;
	long long sum = N * (N + 1) / 2;

	if (sum % (X + Y))
		return ret;

	long long aX = (sum / (X + Y)) * X;

	while (aX && N)
	{
		if (aX >= N)
		{
			ret.push_back(N);
			aX -= N;
			-- N;
		}
		else
		{
			N = aX;
		}
	}

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, X, Y;
		cin >> N >> X >> Y;

		auto r = range(N, X, Y);

		cout << "Case #" << t << ": ";
		if (r.empty())
			cout << "IMPOSSIBLE\n";
		else
		{
			cout << "POSSIBLE\n";
			cout << r.size() << "\n";

			for (auto x : r)
				cout << x << " ";
			cout << "\n";
		}
	}

	return 0;
}

