/*

*/

#define _USE_MATH_DEFINES

#include <algorithm>
#include <bit>
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



double board_game(int N, vector<int>& A, vector<int>& B)
{
	

	return 0;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> A(N * 3), B(N * 3);

		for (auto& a : A)
			cin >> a;

		for (auto& b : B)
			cin >> b;

		cout << "Case #" << t << ": ";
		cout << fixed << setprecision(12) << board_game(N, A, B) << "\n";
	}

	return 0;
}

