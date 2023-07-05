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

int power(long long A, int x, int P)
{
	long long r = 1;

	while (x)
	{
		if (x & 1)
			r = (r * A) % P;
		A = (A * A) % P;
		x >>= 1;
	}

	return r;
}

int huge(int A, int N, int P)
{
	for (int i = 1; i <= N; ++i)
		A = power(A, i, P);

	return A;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int A, N, P;
		cin >> A >> N >> P;

		cout << "Case #" << t << ": ";
		cout << huge(A, N, P) << "\n";
	}

	return 0;
}

