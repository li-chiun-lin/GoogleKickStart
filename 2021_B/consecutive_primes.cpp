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

long long secret(long long Z)
{
	long long zz = sqrt(Z);
	vector<bool> sieve(Z, true);
	vector<long long> prime;


	for (long long i = 2; i < Z; ++i)
		if (sieve[i])
		{
			prime.push_back(i);

			if (prime.size() >= 2 && prime[prime.size() - 2] * prime[prime.size() - 1] > Z)
				break;

			for (long long j = i * i; j < sieve.size(); j += i)
				sieve[j] = false;
		}

	//cout << p1 << " " << p2 << "\n";

	
	return prime[prime.size() - 3] * prime[prime.size() - 2];
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		long long Z;
		cin >> Z;

		cout << "Case #" << t << ": ";
		cout << secret(Z) << "\n";
	}

	return 0;
}

