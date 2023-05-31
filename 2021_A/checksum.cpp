/*
to be continued.
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


int checksum(int N, vector<vector<int>>& A, vector<vector<int>>& B, vector<int>& R, vector<int>& C)
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

		vector<vector<int>> A(N, vector<int>(N)), B(N, vector<int>(N));
		vector<int> R(N), C(N);

		for (auto& r : A)
			for (auto& c : r)
				cin >> c;

		for (auto& r : B)
			for (auto& c : r)
				cin >> c;

		for (auto& c : R)
			cin >> c;

		for (auto& c : C)
			cin >> c;

		cout << "Case #" << t << ": ";
		cout << checksum(N, A, B, R, C) << "\n";
	}

	return 0;
}

