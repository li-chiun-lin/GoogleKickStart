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

void print(vector<int>& v)
{
	for (auto x : v)
		cout << x << " ";
	cout << "\n";
}

int kick_start(string& S)
{
	int cnt = 0;
	vector<int> s, e;

	int i = 0;
	
	while (i < S.size())
	{
		if (S[i] == 'S')
		{
			if (i + 4 < S.size() &&
				S[i + 1] == 'T' &&
				S[i + 2] == 'A' &&
				S[i + 3] == 'R' &&
				S[i + 4] == 'T')
			{
				e.push_back(i);
				i += 4;
			}
		}
		else if (S[i] == 'K')
		{
			if (i + 3 < S.size() &&
				S[i + 1] == 'I' &&
				S[i + 2] == 'C' &&
				S[i + 3] == 'K')
			{
				s.push_back(i);
				// we still have to consider the next "KICK" might overlap with the last 'K'
				i += 2;
			}
		}
		
		++ i;
	}

	int j = 0;

	for (int i = 0; i < s.size(); ++i)
	{
		while (j < e.size() && e[j] < s[i])
			++ j;

		cnt += e.size() - j;
	}

	return cnt;
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
		cout << kick_start(S) << "\n";
	}

	return 0;
}

