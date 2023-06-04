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

#if 0
long long cutting(int N, long long C, vector<pair<long long, long long>>& I)
{
	long long ub = 0;

	for (auto [l, r] : I)
		ub = max(ub, r);

	vector<long long> sweeping(ub + 1);

	for (auto [l, r] : I)
	{
		++ sweeping[l + 1];
		-- sweeping[r];
	}

	for (int i = 1; i < sweeping.size(); ++i)
		sweeping[i] += sweeping[i - 1];

	sort(rbegin(sweeping), rend(sweeping));

	long long cnt = I.size();

	for (int i = 0; i < sweeping.size() && i < C; ++i)
		cnt += sweeping[i];

	return cnt;
}
#endif

long long cutting(int N, long long C, vector<pair<long long, long long>>& I)
{
	map<long long, long long> sweeping;

	for (auto [l, r] : I)
	{
		++ sweeping[l + 1];
		-- sweeping[r];
	}

	long long pre_v = 0;
	long long pre_c = 0;
	vector<pair<long long, long long>> segment;

	for (auto [v, c] : sweeping)
	{
		segment.push_back({pre_c, v - pre_v});
		pre_c += c;
		pre_v = v;
	}

	sort(rbegin(segment), rend(segment));

	long long cnt = I.size();

	for (int i = 0; i < segment.size() && C; ++i)
	{
		long long c = min(C, segment[i].second);
		cnt += c * segment[i].first;
		C -= c;
	}

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		long long C;

		cin >> N >> C;

		vector<pair<long long, long long>> I(N);

		for (auto& [l, r] : I)
			cin >> l >> r;

		cout << "Case #" << t << ": ";
		cout << cutting(N, C, I) << "\n";
	}

	return 0;
}

