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

int peak(int N, vector<int>& H)
{
	int cnt = 0;

	for (int i = 1; i < N - 1; ++i)
		if (H[i - 1] < H[i] && H[i] > H[i + 1])
			++ cnt;

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> H(N);

		for (auto& h : H)
			cin >> h;

		cout << "Case #" << t << ": ";
		cout << peak(N, H) << "\n";
	}

	return 0;
}

