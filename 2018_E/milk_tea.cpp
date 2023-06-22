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

void dfs(int i, string& same_type, vector<string>& preference, vector<string>& forbidden, long long& ret)
{
	if (i < 0)
	{
		for (auto& f : forbidden)
			if (f == same_type)
				return ;

		long long complain = 0;

		for (string& p : preference)
			for (int j = 0; j < p.size(); ++j)
				if (same_type[j] != p[j])
					++ complain;

		ret = min(ret, complain);
	}
	else
	{
		same_type[i] = '0';
		dfs(i - 1, same_type, preference, forbidden, ret);
		same_type[i] = '1';
		dfs(i - 1, same_type, preference, forbidden, ret);
	}
}

#if 0
long long milk_tea(int N, int M, int P, vector<string>& preference, vector<string>& forbidden)
{
	long long cnt = LLONG_MAX;
	string same_type(P, '0');

	dfs(P - 1, same_type, preference, forbidden, cnt);

	return cnt;
}
#endif

void dfs(int i, vector<int>& idx, vector<int>& cost_of_flip, string& same_type, vector<string>& forbidden, int cost, int& min_cost)
{
	if (i < 0)
	{
		for (auto& f : forbidden)
			if (f == same_type)
				return ;

		min_cost = min(min_cost, cost);
	}
	else
	{
		// don't change
		dfs(i - 1, idx, cost_of_flip, same_type, forbidden, cost, min_cost);

		if (cost > min_cost)
			return ;

		// change
		same_type[idx[i]] = 1 - (same_type[idx[i]] - '0') + '0';
		dfs(i - 1, idx, cost_of_flip, same_type, forbidden, cost + cost_of_flip[idx[i]], min_cost);
		same_type[idx[i]] = 1 - (same_type[idx[i]] - '0') + '0';
	}
}

long long milk_tea(int N, int M, int P, vector<string>& preference, vector<string>& forbidden)
{
	long long cnt = 0;
	vector<int> cost_of_flip(P);
	string same_type(P, '0');

	for (int j = 0; j < P; ++j)
	{
		int complain_if_set_bit_to_1 = 0;

		for (auto& p : preference)
			if (p[j] == '0')
				++ complain_if_set_bit_to_1;

		if (complain_if_set_bit_to_1 * 2 > N)
		{
			same_type[j] = '0';
			cnt += N - complain_if_set_bit_to_1;
			cost_of_flip[j] = -N + 2 * complain_if_set_bit_to_1;
		}
		else
		{
			same_type[j] = '1';
			cnt += complain_if_set_bit_to_1;
			cost_of_flip[j] = N - 2 * complain_if_set_bit_to_1;
		}
	}

	vector<int> idx(P);
	iota(begin(idx), end(idx), 0);
	sort(begin(idx), end(idx), 
		[&](int a, int b)
		{
			return cost_of_flip[a] < cost_of_flip[b];
		});


	// the best we can have without the constrain of forbidden
	//cout << "the ideal type " << same_type << " " << cnt << "\n";

	for (auto& f : forbidden)
		if (f == same_type)
		{
			int min_cost = INT_MAX;
			dfs(P - 1, idx, cost_of_flip, same_type, forbidden, 0, min_cost);

			if (min_cost != INT_MAX)
				return cnt + min_cost;

			cout << "not found\n";
		}

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M, P;
		cin >> N >> M >> P;

		vector<string> preference(N), forbidden(M);

		for (auto& s : preference)
			cin >> s;

		for (auto& s : forbidden)
			cin >> s;

		cout << "Case #" << t << ": ";
		cout << milk_tea(N, M, P, preference, forbidden) << "\n";
	}

	return 0;
}

