/*
to be continued.
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

int dfs(vector<int>& S, vector<int>& E, vector<int>& L, int i, int t, vector<bool>& eaten)
{
	return 0;
}

int energy(int N, vector<int>& S, vector<int>& E, vector<int>& L)
{
	return 0;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> S(N), E(N), L(N);

		for (int i = 0; i < N; ++i)
			cin >> S[i] >> E[i] >> L[i];

		cout << "Case #" << t << ": ";
		cout << energy(N, S, E, L) << "\n";
	}

	return 0;
}

