/*
TLE
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

#if 0
int teach(int N, int S, vector<vector<int>>& A)
{
	int cnt = 0;
	vector<vector<int>> know(S + 1, vector<int>(N));
	vector<int> count(S + 1);

	for (int i = 0; i < N; ++i)
		for (auto s : A[i])
		{
			know[s][i] = 1;
			++ count[s];
		}

	set<pair<int, int>> teach;
	vector<int> id(N);
	iota(begin(id), end(id), 0);


	for (int j = 1; j <= S; ++j)
	{
		sort(begin(id), end(id), 
			[&] (auto a, auto b)
			{
				return know[j][a] > know[j][b];
			});

		for (int x = 0; x < count[j]; ++x)
			for (int y = count[j]; y < N; ++y)
				teach.insert({id[x], id[y]});
	}

	return teach.size();
}
#endif

int teach(int N, int S, vector<vector<int>>& A)
{
	vector<set<int>> member(N);

	for (int i = 0; i < N; ++i)
		member[i] = set<int>(begin(A[i]), end(A[i]));

	int cnt = 0;

	for (int i = 0; i < N; ++i)
		for (int j = i + 1; j < N; ++j)
		{
			for (auto x : member[i])
				if (member[j].count(x) == 0)
				{
					++ cnt;
					break;
				}

			for (auto x : member[j])
				if (member[i].count(x) == 0)
				{
					++ cnt;
					break;
				}
		}
	
	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, S;
		cin >> N >> S;

		vector<vector<int>> A(N);

		for (auto& a : A)
		{
			int C;
			cin >> C;

			a.resize(C);

			for (auto& c : a)
				cin >> c;
		}

		cout << "Case #" << t << ": ";
		cout << teach(N, S, A) << "\n";
	}

	return 0;
}

