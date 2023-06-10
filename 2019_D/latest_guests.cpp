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

void print(vector<int>& v)
{
	if (v.size())
	{
		cout << v[0];

		for (int i = 1; i < v.size(); ++i)
			cout << " " << v[i];
	}

	cout << "\n";
}

vector<int> guest(int N, int G, int M, vector<pair<int, char>>& H)
{
	vector<int> ret(G);
	vector<map<int, vector<int>>> record(N);
	int q = M / N;
	int r = M % N;
	int loop_time = q * N;
	int loop_time1 = (q - 1) * N;

	for (int i = 0; i < G; ++i)
	{
		int h = H[i].first - 1;
		char c = H[i].second;

		if (c == 'C')
		{
			for (int j = 0; j <= r; ++j)
				record[(h + j) % N][loop_time + j].push_back(i);

			if (q)
			{
				for (int j = r + 1; j < N; ++j)
					record[(h + j) % N][loop_time1 + j].push_back(i);
			}
		}
		else
		{
			for (int j = 0; j <= r; ++j)
				record[(h - j + N) % N][loop_time + j].push_back(i);

			if (q)
			{
				for (int j = r + 1; j < N; ++j)
					record[(h - j + N) % N][loop_time1 + j].push_back(i);
			}
		}
	}

	for (int j = 0; j < N; ++j)
		if (record[j].size())
			for (auto i : rbegin(record[j])->second)
				++ ret[i];

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, G, M;
		cin >> N >> G >> M;

		vector<pair<int, char>> H(G);

		for (auto &[h, c] : H)
			cin >> h >> c;

		cout << "Case #" << t << ": ";
		auto r = guest(N, G, M, H);
		print(r);
	}

	return 0;
}

