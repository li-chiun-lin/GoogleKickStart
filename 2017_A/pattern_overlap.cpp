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

bool dfs(string& s1, string&s2, int i, int j)
{

	return false;
}

bool match(string& s1, string& s2)
{
	return dfs(s1, s2, 0, 0);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		string s1, s2;
		cin >> s1 >> s2;

		cout << "Case #" << t << ": ";
		cout << (match(s1, s2) ? "TRUE" : "FALSE") << "\n";
	}

	return 0;
}

