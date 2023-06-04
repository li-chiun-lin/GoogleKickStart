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

void print(vector<pair<int, int>>& vec)
{
	for (auto [k, v] : vec)
		cout << k << ":" << v << " ";
	cout << "\n";
}

void print_ant(vector<int>& A, vector<int>& P, vector<int>& D)
{
	for (auto a : A)
		cout << setw(3) << (a + 1);
	cout << "\n";

	for (auto a : A)
		cout << setw(3) << P[a];
	cout << "\n";

	for (auto a : A)
		cout << setw(3) << (D[a] ? ">" : "<");
	cout << "\n";
	cout << "\n";
}

void print_ant(vector<int>& A, vector<int>& P, vector<int>& D, vector<int>& accu)
{
	for (auto a : A)
		cout << setw(3) << (a + 1);
	cout << "\n";

	for (auto a : A)
		cout << setw(3) << P[a];
	cout << "\n";

	for (auto a : A)
		cout << setw(3) << (D[a] ? ">" : "<");
	cout << "\n";

	for (auto a : accu)
		cout << setw(3) << a;
	cout << "\n";

	cout << "\n";
}

vector<int> ants(int N, int L, vector<int>& P, vector<int>& D)
{
	vector<int> ret;
	vector<int> ant(N);
	vector<pair<int, int>> order;

	iota(begin(ant), end(ant), 0);

	sort(begin(ant), end(ant), 
		[&] (auto a, auto b)
		{
			return P[a] < P[b];
		});

#if 1
	cout << "------------------------------------\n";
	//print(P);
	//print(D);
	//print(ant);
	print_ant(ant, P, D);
#endif

	int l = 0;
	int r = N - 1;
	vector<int> dif(N + 1);
	vector<int> accu(N);

	for (int i = 0; i < N - 1; ++i)
		dif[i + 1] = P[ant[i + 1]] - P[ant[i]];

	print(dif);

	while (l < r)
	{
		if (D[ant[l]] == 0)
		{
			cout << "ant " << (ant[l] + 1) << " go to left\n";
			order.push_back({P[ant[l]] + accu[l], ant[l]});
			dif[l + 1] = 0;
			++ l;
		}
		else if (D[ant[r]] == 1)
		{
			cout << "ant " << (ant[r] + 1) << " go to right\n";
			order.push_back({L - P[ant[r]] + accu[r], ant[r]});
			dif[r] = 0;
			-- r;
		}
		else
		{
			
			for (int i = l; i <= r; ++i)
				accu[i] += dif[i] + dif[i + 1];

			D[ant[l]] = 0;
			D[ant[r]] = 1;

			cout << "case 3\n";
			print_ant(ant, P, D, accu);
		}

		
	}

	if (l == r)
	{
		if (D[ant[l]] == 0)
		{
			order.push_back({P[ant[l]] + accu[l], ant[l]});
		}
		else
		{
			order.push_back({L - P[ant[r]] + accu[r], ant[r]});
		}
	}

	

	sort(begin(order), end(order));

	//print(order);

	for (auto [p, i] : order)
		ret.push_back(i + 1);


	

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

