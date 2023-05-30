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

string new_passsword(string& Old)
{
	bool upper = false;
	bool lower = false;
	bool digit = false;
	bool special = false;

	for (char c : Old)
	{
		if (isdigit(c))
			digit = true;
		else if (isupper(c))
			upper = true;
		else if (islower(c))
			lower = true;
		else if (c == '#' || c == '@' || c == '*' || c == '&')
			special = true;
	}

	if (! upper)
		Old.push_back('A');

	if (! lower)
		Old.push_back('a');

	if (! digit)
		Old.push_back('0');

	if (! special)
		Old.push_back('#');

	while (Old.size() < 7)
		Old.push_back('a');

	return Old;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		string Old;

		cin >> N >> Old;

		cout << "Case #" << t << ": ";
		cout << new_passsword(Old) << "\n";
	}

	return 0;
}

