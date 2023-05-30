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

void print(vector<int>& vec)
{
	if (vec.size())
	{
		cout << vec[0];

		for (int i = 1; i < vec.size(); ++i)
			cout << " " << vec[i];
	}

	cout << "\n";
}

vector<int> ants(int N, int L, vector<int>& P, vector<int>& D)
{
	vector<int> ret;

	

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, L;
		cin >> N >> L;

		vector<int> P(N), D(N);

		for (int i = 0; i < N; ++i)
			cin >> P[i] >> D[i];

		cout << "Case #" << t << ": ";

		auto ret = ants(N, L, P, D);
		print(ret);
	}

	return 0;
}

