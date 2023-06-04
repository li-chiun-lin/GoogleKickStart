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

bool feed(int N, int D, int C, int M, string& S)
{
	for (int i = 0; i < N; ++i)
	{
		if (S[i] == 'D')
		{
			if (D == 0)
				return false;

			-- D;
			C += M;
		}
		else
		{
			if (C == 0)
			{
				for (int j = i + 1; j < N; ++j)
					if (S[j] == 'D')
						return false;

				return true;
			}

			-- C;
		}
	}

	return true;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, D, C, M;
		string S;
		cin >> N >> D >> C >> M >> S;

		cout << "Case #" << t << ": ";
		cout << (feed(N, D, C, M, S) ? "YES" : "NO") << "\n";
	}

	return 0;
}

