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

string challenge(string& N)
{
	char digit = 0;

	for (char c : N)
		digit = (digit + (c - '0')) % 9;

	string M = "";
	digit = ((9 - digit) % 9) + '0';

	int i = 0;

	while (i < N.size())
	{
		if (N[i] > digit)
			break;

		++ i;
	}

	if (i == 0 && digit == '0')
		i = 1;
	
	return N.substr(0, i) + digit + N.substr(i);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		string N;
		cin >> N;

		cout << "Case #" << t << ": ";
		cout << challenge(N) << "\n";
	}

	return 0;
}

