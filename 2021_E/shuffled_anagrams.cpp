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

string shuffle(string& S)
{
	map<char, int> hist;

	for (char c : S)
		if (++ hist[c] * 2 > S.size())
			return "IMPOSSIBLE";

	string T = S;

	for (int i = 0; i < S.size(); ++i)
		if (T[i] == S[i])
			for (int j = i + 1; j < S.size(); ++j)
				if (T[i] != T[j])
				{
					swap(T[i], T[j]);
					break;
				}

	return T;
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
		cout << shuffle(S) << "\n";
	}

	return 0;
}

