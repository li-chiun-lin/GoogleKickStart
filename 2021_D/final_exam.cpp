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

void print(vector<long long>& vec)
{
	if (vec.size())
	{
		cout << vec[0];

		for (int i = 1; i < vec.size(); ++i)
			cout << " " << vec[i];
	}

	cout << "\n";
}

vector<long long> final_exam(long long N, long long M, vector<pair<long long, long long>>& AB, vector<long long>& S)
{
	vector<long long> ret(M);
	map<long long, long long> seg;

	for (auto [a, b] : AB)
		seg[a] = b - a + 1;

	for (int i = 0; i < M; ++i)
	{
		auto it = seg.upper_bound(S[i]);
		long long next_a = LLONG_MAX, next_b = LLONG_MAX;
		long long prev_a = LLONG_MIN, prev_b = LLONG_MIN;

		if (it != end(seg))
		{
			next_a = it->first;
			next_b = next_a + it->second - 1;
		}

		if (it != begin(seg))
		{
			-- it;
			prev_a = it->first;
			prev_b = prev_a + it->second - 1;
		}

		if (prev_a <= S[i] && S[i] <= prev_b)
		{
			ret[i] = S[i];

			if (prev_a == S[i])
			{
				seg.erase(prev_a);
				if (prev_b - prev_a)
					seg[prev_a + 1] = prev_b - prev_a;
			}
			else if (S[i] == prev_b)
			{
				if (-- seg[prev_a] == 0)
					seg.erase(prev_a);
			}
			else
			{
				if (S[i] - prev_a)
					seg[prev_a] = S[i] - prev_a;

				if (prev_b - (S[i] + 1) + 1)
					seg[S[i] + 1] = prev_b - (S[i] + 1) + 1;
			}
		}
		else if (prev_b != LLONG_MIN && S[i] - prev_b <= next_a - S[i])
		{
			ret[i] = prev_b;
			if (-- seg[prev_a] == 0)
				seg.erase(prev_a);
		}
		else
		{
			ret[i] = next_a;
			seg.erase(next_a);
			if (next_b - next_a)
				seg[next_a + 1] = next_b - next_a;
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
		long long N, M;
		cin >> N >> M;

		vector<pair<long long, long long>> AB(N);

		for (auto& [a, b] : AB)
			cin >> a >> b;

		vector<long long> S(M);

		for (auto& s : S)
			cin >> s;

		cout << "Case #" << t << ": ";
		auto ret = final_exam(N, M, AB, S);
		print(ret);
	}

	return 0;
}

