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

int mural(int N, string& W)
{
	int glo = 0;
	int n = (N + 1) / 2;
	int loc = accumulate(begin(W), begin(W) + (n - 1), 0) - (n - 1) * '0';

	for (int i = n - 1; i < N; ++i)
	{
		loc += W[i] - '0'; 
		glo = max(glo, loc);
		loc -= W[i - (n - 1)] - '0';
	}

	return glo;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		string W;
		cin >> N >> W;

		cout << "Case #" << t << ": ";
		cout << mural(N, W) << "\n";
	}

	return 0;
}

