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

int anagram(int L, string& A, string& B)
{
	int cnt = 0;
	vector<set<vector<int>>> ss(L);
	
	for (auto& a : A)
		a -= 'A';

	for (auto& b : B)
		b -= 'A';

	for (int i = 0; i < L; ++i)
	{
		vector<int> hist(26);

		for (int j = i; j < L; ++j)
		{
			++ hist[B[j]];
			ss[j - i].insert(hist);
		}
	}

	for (int i = 0; i < L; ++i)
	{
		vector<int> hist(26);

		for (int j = i; j < L; ++j)
		{
			++ hist[A[j]];
			cnt += ss[j - i].count(hist);
		}
	}

	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int L;
		string A, B;

		cin >> L >> A >> B;

		cout << "Case #" << t << ": ";
		cout << anagram(L, A, B) << "\n";
	}

	return 0;
}

