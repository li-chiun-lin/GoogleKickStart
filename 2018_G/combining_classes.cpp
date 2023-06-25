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

void print(map<long long, long long>& m)
{
	for (auto [k, v] : m)
		cout << k << ":" << v << " ";
	cout << "\n";
}

void print(vector<pair<long long, long long>>& m)
{
	for (auto [k, v] : m)
		cout << k << ":" << v << " ";
	cout << "\n";
}

#if 0
long long combin(int N, int Q, vector<long long>& L, vector<long long>& R, vector<long long>& K)
{
	long long ans = 0;
	map<long long, long long> sweeping;
	long long total_student = 0;

	for (int i = 0; i < N; ++i)
	{
		++ sweeping[L[i]];
		-- sweeping[R[i] + 1];
		total_student += R[i] - L[i] + 1;
	}

	sweeping[0] = 0;
	long long accu = 0;

	for (auto& [k, v] : sweeping)
		accu = v += accu;

	for (int i = 0; i < Q; ++i)
	{
		long long prev_k = 0;
		long long prev_v = 0;
		long long acc = 0;
		long long target = total_student - K[i];

		if (target < 0)
			continue;

		for (auto [k, v] : sweeping)
		{
			long long inc = (k - prev_k) * prev_v;

			if (acc + inc < target || prev_v == 0)
			{
				acc += inc;
				prev_k = k;
				prev_v = v;
			}
			else
			{
				long long score = prev_k + (target - acc) / prev_v;
				ans += score * (i + 1);
				break;
			}
		}
	}

	return ans;
}
#endif

#if 0
long long combin(int N, int Q, vector<long long>& L, vector<long long>& R, vector<long long>& K)
{
	long long ans = 0;
	map<long long, long long> sweeping;
	long long total_student = 0;

	for (int i = 0; i < N; ++i)
	{
		++ sweeping[L[i]];
		-- sweeping[R[i] + 1];
		total_student += R[i] - L[i] + 1;
	}

	sweeping[0] = 0;
	long long accu = 0;

	for (auto& [k, v] : sweeping)
		accu = v += accu;

	map<long long, long long> sweeping_acc;

	accu = 0;
	long long prev_k = 0;
	long long prev_v = 0;
	for (auto& [k, v] : sweeping)
	{
		sweeping_acc[k] = accu += prev_v * (k - prev_k);
		prev_k = k;
		prev_v = v;
	}
	
	#if 0
	cout << "\n";
	cout << "total " << total_student << "\n";
	cout << accu << "\n";
	print(sweeping);
	print(sweeping_acc);
	#endif

	for (int i = 0; i < Q; ++i)
	{
		long long prev_k = 0;
		long long prev_v = 0;
		long long target = total_student - K[i];

		if (target < 0)
			continue;

		for (auto [k, v] : sweeping_acc)
		{
			if (v < target || sweeping[prev_k] == 0)
			{
				prev_k = k;
				prev_v = v;
			}
			else
			{
				long long score = prev_k + (target - prev_v) / sweeping[prev_k];
				ans += score * (i + 1);

				//cout << i << " " << K[i] << " > " << score << "\n";
				break;
			}
		}
	}

	return ans;
}
#endif

long long combin(int N, int Q, vector<long long>& L, vector<long long>& R, vector<long long>& K)
{
	long long ans = 0;
	map<long long, long long> sweeping;
	long long total_student = 0;

	for (int i = 0; i < N; ++i)
	{
		++ sweeping[L[i]];
		if (-- sweeping[R[i] + 1] == 0)
			sweeping.erase(R[i] + 1);
		total_student += R[i] - L[i] + 1;
	}

	long long accu = 0;

	for (auto& [k, v] : sweeping)
		accu = v += accu;

	vector<tuple<long long, long long, long long>> prefix;

	accu = 0;
	long long prev_k = 0;
	long long prev_v = 0;
	for (auto& [k, v] : sweeping)
	{
		accu += prev_v * (k - prev_k);
		prefix.push_back({accu, k, v});
		prev_k = k;
		prev_v = v;
	}

	for (int i = 0; i < Q; ++i)
	{
		long long target = total_student - K[i] + 1;

		if (target <= 0)
			continue;

		auto ub = upper_bound(begin(prefix), end(prefix), make_tuple(target, 0LL, 0LL));
		auto [acc, base, step] = *prev(ub);
		long long score = base + (target - acc - 1) / step;
		ans += score * (i + 1);
	}

	return ans;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, Q;
		cin >> N >> Q;

		vector<long long> X(N), Y(N), Z(Q), L(N), R(N), K(Q);
		long long A1, A2, A3;
		long long B1, B2, B3;
		long long C1, C2, C3;
		long long M1, M2, M3;

		cin >> X[0] >> X[1] >> A1 >> B1 >> C1 >> M1;
		cin >> Y[0] >> Y[1] >> A2 >> B2 >> C2 >> M2;
		cin >> Z[0] >> Z[1] >> A3 >> B3 >> C3 >> M3;

		L[0] = min(X[0], Y[0]) + 1;
		R[0] = max(X[0], Y[0]) + 1;
		K[0] = Z[0] + 1;

		L[1] = min(X[1], Y[1]) + 1;
		R[1] = max(X[1], Y[1]) + 1;
		K[1] = Z[1] + 1;
 			
		for (int i = 2; i < N; ++i)
		{
			X[i] = (A1 * X[i - 1] + B1 * X[i - 2] + C1) % M1;
			Y[i] = (A2 * Y[i - 1] + B2 * Y[i - 2] + C2) % M2;
			L[i] = min(X[i], Y[i]) + 1;
			R[i] = max(X[i], Y[i]) + 1;
		}

		for (int i = 2; i < Q; ++i)
		{
			Z[i] = (A3 * Z[i - 1] + B3 * Z[i - 2] + C3) % M3;
			K[i] = Z[i] + 1;
		}

		cout << "Case #" << t << ": ";
		cout << combin(N, Q, L, R, K) << "\n";
	}

	return 0;
}

