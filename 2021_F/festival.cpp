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

void print(vector<int>& vec)
{
	for (auto x : vec)
		cout << x << " ";
	cout << "\n";
}

long long festival(int D, int N, int K, vector<vector<int>>& A)
{
	map<int, vector<vector<int>>> sweeping;

	for (auto& a : A)
	{
		sweeping[a[1]].resize(2);
		sweeping[a[1]][0].push_back(a[0]);
		sweeping[a[2] + 1].resize(2);
		sweeping[a[2] + 1][1].push_back(a[0]);
	}

	long long ret = 0;
	//long long sum = 0;
	
	map<int, int> running;

	for (auto& [d, vec] : sweeping)
	{
		for (auto r : vec[1])
		{
			-- running[r];
		}

		for (auto a : vec[0])
		{
			++ running[a];
		}

		if (vec[0].size())
		{
			long long sum = 0;

			int i = 0;
			for (auto it = rbegin(running); it != rend(running) && i < K; ++it)
			{
				int d = min(K - i, it->second);
				sum += d * it->first;
				i += d;
			}

			ret = max(ret, sum);
		}
	}


	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int D, N, K;
		cin >> D >> N >> K;

		vector<vector<int>> A(N, vector<int>(3));

		for (auto& a : A)
			cin >> a[0] >> a[1] >> a[2];

		cout << "Case #" << t << ": ";
		cout << festival(D, N, K, A) << "\n";
	}

	return 0;
}

