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

long long candies(long long N, long long O, long long D, vector<long long>& S)
{
	long long ret = LLONG_MIN;
	multiset<long long> ss;
	vector<long long> prefix(N + 1);

	for (int i = 0; i < N; ++i)
		prefix[i + 1] += prefix[i] + S[i];

	int r = 0;

	for (int l = 0; l < N; ++l)
	{
		r = max(r, l);

		while (r < N)
		{
			if (S[r] % 2 == 0)
				ss.insert(prefix[r + 1]);
			else if (O)
			{
				ss.insert(prefix[r + 1]);
				-- O;
			}
			else
				break;

			++ r;
		}

		auto it = ss.upper_bound(D + prefix[l]);

		if (it != begin(ss))
		{
			-- it;
			ret = max(*it - prefix[l], ret);
		}

		if (l < r)
		{
			if (S[l] % 2)
				++ O;
			
			ss.erase(ss.find(prefix[l + 1]));
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
		long long N, O, D;
		cin >> N >> O >> D;

		vector<long long> S(N);
		long long A, B, C, M, L;

		cin >> S[0] >> S[1] >> A >> B >> C >> M >> L;

		for (int i = 2; i < N; ++i)
			S[i] = (A * S[i - 1] + B * S[i - 2] + C) % M;

		for (int i = 0; i < N; ++i)
			S[i] += L;
		
		cout << "Case #" << t << ": ";
		long long ret = candies(N, O, D, S);

		if (ret == LLONG_MIN)
			cout << "IMPOSSIBLE\n";
		else
			cout << ret << "\n";
	}

	return 0;
}

