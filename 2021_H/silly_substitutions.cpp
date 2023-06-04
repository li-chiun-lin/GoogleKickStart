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

char next(char a)
{
	return ((a - '0' + 1) % 10) + '0'; 
}

bool valid(char a, char b)
{
	return next(a) == b;
}

string silly(int N, string& S)
{
	string T = "";

	

	return S;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		string S;
		cin >> N >> S;

		cout << "Case #" << t << ": ";
		cout << silly(N, S) << "\n";
	}

	return 0;
}

