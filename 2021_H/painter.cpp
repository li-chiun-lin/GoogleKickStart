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

int paint(int N, string& P)
{
	int cnt = 0;
	vector<int> target(N), color(N);

	for (int i = 0; i < N; ++i)
	{
		if (P[i] == 'R')
			target[i] = 1;
		else if (P[i] == 'Y')
			target[i] = 2;
		else if (P[i] == 'B')
			target[i] = 4;
		else if (P[i] == 'O')
			target[i] = 3;
		else if (P[i] == 'P')
			target[i] = 5;
		else if (P[i] == 'G')
			target[i] = 6;
		else if (P[i] == 'A')
			target[i] = 7;
		else if (P[i] == 'U')
			;
	}

	for (int i = 0; i < N; ++i)
		for (int stroke = 1; stroke < 8; stroke <<= 1)
			if ((color[i] ^ target[i]) & stroke)
			{
				++ cnt;

				for (int j = i; j < N && ((color[j] ^ target[j]) & stroke); ++j)
					color[j] |= stroke;
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
		string P;
		cin >> N >> P;

		cout << "Case #" << t << ": ";
		cout << paint(N, P) << "\n";
	}

	return 0;
}

