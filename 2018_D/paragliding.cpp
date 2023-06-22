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

void print(vector<pair<long long, long long>>& v)
{
	for (auto [x, y] : v)
		cout << setw(3) << x;
	cout << "\n";

	for (auto [x, y] : v)
		cout << setw(3) << y;
	cout << "\n";
}

long long paragliding(int N, int K, vector<long long>& p, vector<long long>& h, vector<long long>& x, vector<long long>& y)
{
	long long cnt = 0;
	vector<pair<long long, long long>> tower(N), relevant_tower;
	vector<int> collect(K);

	for (int i = 0; i < N; ++i)
		tower[i] = {p[i], h[i]};

	sort(begin(tower), end(tower));

	for (auto [pi, hi] : tower)
	{
		while (relevant_tower.size())
		{
			auto [pj, hj] = relevant_tower.back();

			if (hj > hi - abs(pi - pj))
				break;
				
			relevant_tower.pop_back();
		}

		if (relevant_tower.empty())
			relevant_tower.push_back({pi, hi});
		else
		{
			auto [pj, hj] = relevant_tower.back();

			if (hi > hj - abs(pi - pj))
				relevant_tower.push_back({pi, hi});
		}
	}

	int M = relevant_tower.size();

	for (int j = 0; j < K; ++j)
	{
#if 0
		for (auto [pi, hi] : relevant_tower)
		{
			if (y[j] <= hi - abs(x[j] - pi))
			{
				++ cnt;
				break;
			}
		}
#endif

		auto it = lower_bound(begin(relevant_tower), end(relevant_tower), make_pair(x[j], y[j])) - begin(relevant_tower);

		if (it < M)
		{
			auto [pi, hi] = relevant_tower[it];
			if (y[j] <= hi - abs(x[j] - pi))
			{
				++ cnt;
				continue;
			}
		}
		
		if (it > 0)
		{
			auto [pi, hi] = relevant_tower[it - 1];
			if (y[j] <= hi - abs(x[j] - pi))
				++ cnt;
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
		int N, K;
		cin >> N >> K;

		vector<long long> A(4), B(4), C(4), M(4), p(N), h(N), x(K), y(K);

		cin >> p[0] >> p[1] >> A[0] >> B[0] >> C[0] >> M[0];
		cin >> h[0] >> h[1] >> A[1] >> B[1] >> C[1] >> M[1];
		cin >> x[0] >> x[1] >> A[2] >> B[2] >> C[2] >> M[2];
		cin >> y[0] >> y[1] >> A[3] >> B[3] >> C[3] >> M[3];

		for (int i = 2; i < N; ++i)
		{
			p[i] = (A[0] * p[i - 1] + B[0] * p[i - 2] + C[0]) % M[0] + 1;
			h[i] = (A[1] * h[i - 1] + B[1] * h[i - 2] + C[1]) % M[1] + 1;
		}

		for (int i = 2; i < K; ++i)
		{
			x[i] = (A[2] * x[i - 1] + B[2] * x[i - 2] + C[2]) % M[2] + 1;
			y[i] = (A[3] * y[i - 1] + B[3] * y[i - 2] + C[3]) % M[3] + 1;
		}

		cout << "Case #" << t << ": ";
		cout << paragliding(N, K, p, h, x, y) << "\n";
	}

	return 0;
}

