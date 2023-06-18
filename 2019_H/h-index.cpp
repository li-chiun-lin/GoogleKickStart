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

void print(vector<int>& v)
{
	if (v.size())
	{
		cout << v[0];

		for (int i = 1; i < v.size(); ++i)
			cout << " " << v[i];
	}

	cout << "\n";
}

#if 0
vector<int> index(int N, vector<int>& A)
{
	vector<int> ret(N);
	int h = 0;
	priority_queue<int, vector<int>, greater<>> pq;

	for (int i = 0; i < N; ++i)
	{
		if (A[i] > h)
		{
			pq.push(A[i]);

			while (pq.size() && pq.top() <= h)
				pq.pop();

			if (pq.size() >= h + 1)
				++ h;
		}

		ret[i] = h;
	}

	return ret;
}
#endif

void update(int i, int v, vector<int>& vec)
{
	for (++i; i < vec.size(); i += i & -i)
		vec[i] += v;
}

int query(int i, vector<int>& vec)
{
	int ret = 0;

	for (++i; i; i -= i & -i)
		ret += vec[i];

	return ret;
}

vector<int> index(int N, vector<int>& A)
{
	vector<int> ret(N);
	int ub = *max_element(begin(A), end(A));
	vector<int> vec(ub + 2);
	int h = 1;

	for (int i = 0; i < N; ++i)
	{
		update(A[i], 1, vec);

		if (i + 1 - query(h, vec) > h)
			++ h;

		ret[i] = h;
	}

	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;

		vector<int> A(N);

		for (auto& a : A)
			cin >> a;

		cout << "Case #" << t << ": ";
		auto r = index(N, A);
		print(r);
	}

	return 0;
}

