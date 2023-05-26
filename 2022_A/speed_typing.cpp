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

int speed(string& I, string& P)
{
	int i = 0;
	int j = 0;

	while (i < I.size() && j < P.size())
	{
		if (I[i] == P[j])
			++ i;
		
		++ j;
	}

	return i == I.size() ? P.size() - i : -1;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		string I, P;

		cin >> I >> P;

		int r = speed(I, P);

		cout << "Case #" << t << ": ";
		if (r == -1)
			cout << "IMPOSSIBLE\n";
		else
			cout << r << "\n";
	}

	return 0;
}

