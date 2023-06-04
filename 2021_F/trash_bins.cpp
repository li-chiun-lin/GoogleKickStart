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

long long trash(int N, string& S)
{
	vector<int> left(N), right(N);

	left[0] = S[0] == '1' ? 0 : N;

	for (int i = 1; i < N; ++i)
		if (S[i] == '0')
			left[i] = left[i - 1] + 1;

	right[N - 1] = S[N - 1] == '1' ? 0 : N;

	for (int i = N - 2; i >= 0; --i)
		if (S[i] == '0')
			right[i] = right[i + 1] + 1;

	long long sum = 0;

	for (int i = 0; i < N; ++i)
		sum += min(left[i], right[i]);

	return sum;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		string S;

		cin >> N >> S;

		cout << "Case #" << t << ": ";
		cout << trash(N, S) << "\n";
	}

	return 0;
}

