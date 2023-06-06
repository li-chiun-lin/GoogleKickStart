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

int allocation(int N, int B, vector<int>& A)
{
	int cnt = 0;

	sort(begin(A), end(A));

	for (auto a : A)
	{
		if (a <= B)
		{
			B -= a;
			++ cnt;
		}
		else
			break;
	}

	return cnt;

}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, B;
		cin >> N >> B;

		vector<int> A(N);

		for (auto& a : A)
			cin >> a;

		cout << "Case #" << t << ": ";
		cout << allocation(N, B, A) << "\n";
	}

	return 0;
}

