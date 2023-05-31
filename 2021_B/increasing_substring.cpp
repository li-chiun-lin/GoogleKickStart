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

vector<int> increasing(int N, string& S)
{
	vector<int> ret(N, 1);

	for (int i = 1; i < N; ++i)
		if (S[i - 1] < S[i])
			ret[i] = ret[i - 1] + 1;

	return ret;
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
		auto ret = increasing(N, S);
		print(ret);
	}

	return 0;
}

