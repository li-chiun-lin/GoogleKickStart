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

long long euler(long long a, long long b, long long& x, long long& y)
{
    if (a == 0) {
        x = 0;
		y = 1;
        return b;
    }
 
    long long x1, y1;
    long long g = euler(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;
 
    return g;
}

long long inv(long long A, long long M)
{
    long long x, y;
    long long g = euler(A, M, x, y);

    return (x % M + M) % M;
}

long long comb(long long n, long long m, long long mod, vector<long long>& fac)
{
	return ((fac[n] * inv(fac[n - m], mod)) % mod * inv(fac[m], mod)) % mod;
}

long long count_the_way(int N, int M)
{
	int mod = 1e9 + 7;
	int N2 = N * 2;
	vector<long long> fac(N2 + 1);
	vector<long long> pow2(N2 + 1);
	fac[0] = 1;
	fac[1] = 1;
	pow2[0] = 1;
	pow2[1] = 2;

	for (int i = 2; i <= N2; ++i)
	{
		fac[i] = (fac[i - 1] * i) % mod;
		pow2[i] = (pow2[i - 1] << 1) % mod;
	}

	long long exclude = 0;
	int sign = 1;

	for (int m = 1; m <= M; ++m)
	{
		exclude += sign * ((comb(M, m, mod, fac) * fac[N2 - m]) % mod * pow2[m]) % mod;
		exclude = (exclude % mod + mod) % mod;
		sign *= -1;
	}

	return ((fac[N2] - exclude) % mod + mod) % mod;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M;
		cin >> N >> M;

		cout << "Case #" << t << ": ";
		cout << count_the_way(N, M) << "\n";
	}

	return 0;
}

