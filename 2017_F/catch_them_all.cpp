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

void print(vector<vector<int>>& dst)
{
	for (auto& r : dst)
	{
		for (auto c : r)
		{
			cout << setw(2);

			if (c == INT_MAX)
				cout << "-";
			else
				cout << c;
		}
		cout << "\n";
	}
	cout << "\n";
}

void print(vector<vector<double>>& v)
{
	for (auto& r : v)
	{
		for (auto c : r)
			cout << c << " ";
		cout << "\n";
	}

	cout << "\n";
}

void square(vector<vector<double>>& A)
{
	int n = A.size();
	int m = A[0].size();

	if (n != m)
	{
		cerr << "square size error\n";
		return ;
	}

	vector<vector<double>> buf(n, vector<double>(n));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				buf[i][j] += A[i][k] * A[k][j];

#if 0
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			A[i][j] = buf[i][j];
#endif
	A = buf;
}



void multiply(vector<vector<double>>& A, vector<vector<double>>& F)
{
	int n1 = A.size();
	int m1 = A[0].size();
	int n2 = F.size();
	int m2 = F[0].size();

	if (m1 != n2)
	{
		cerr << "multiply size error\n";
		return ;
	}

	vector<vector<double>> buf(n1, vector<double>(m2));

	for (int i = 0; i < n1; ++i)
		for (int j = 0; j < m2; ++j)
			for (int k = 0; k < m1; ++k)
				buf[i][j] += A[i][k] * F[k][j];

	F = buf;
}

void power(vector<vector<double>>& A, int K)
{
	int n = A.size();
	int m = A[0].size();

	if (n != m)
	{
		cerr << "power size error\n";
		return ;
	}

	vector<vector<double>> I(n, vector<double>(n));

	for (int i = 0; i < n; ++i)
		I[i][i] = 1;

	while (K)
	{
		if (K & 1)
			multiply(A, I);
			
		square(A);
		K >>= 1;
	}
	
	A = I;
}

double catch_them_all(int N, int M, int P, vector<tuple<int, int, int>>& R)
{
	vector<vector<int>> dst(N + 1, vector<int>(N + 1, INT_MAX));
	vector<vector<pair<int, int>>> adj(N + 1);
	vector<int> S(N + 1);

	for (auto [u, v, d] : R)
	{
		adj[u].push_back({v, d});
		adj[v].push_back({u, d});
	}

	for (int i = 1; i <= N; ++i)
	{
		queue<int> que;
		que.push(i);
		dst[i][i] = 0;

		while (que.size())
		{
			auto u = que.front();
			que.pop();

			for (auto [v, d] : adj[u])
				if (dst[i][v] > dst[i][u] + d)
				{
					dst[i][v] = dst[i][u] + d;
					que.push(v);
				}
		}

		S[i] = accumulate(begin(dst[i]) + 1, end(dst[i]), 0);
	}

	vector<vector<double>> A(N + 1, vector<double>(N + 1, 1.0 / (N - 1)));
	vector<vector<double>> F(N + 1, vector<double>(1));

	F[N][0] = 1;

	for (int i = 0; i < N; ++i)
	{
		A[i][i] = 0;
		A[i][N] = (double)S[i + 1] / (N - 1);
	}

	for (int j = 0; j < N; ++j)
		A[N][j] = 0;

	A[N][N] = 1;

	power(A, P);
	multiply(A, F);

	return F[0][0];

#if 0
	vector<vector<double>> dp(P + 1, vector<double>(N + 1));

	for (int K = 1; K <= P; ++K)
	{
		for (int L = 1; L <= N; ++L)
		{
			for (int i = 1; i <= N; ++i)
			{
				if (i == L)
					continue;

				dp[K][L] += dp[K - 1][i] + dst[L][i];
			}

			dp[K][L] /= (N - 1);
		}
	}

	return dp[P][1];
#endif
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M, P;
		cin >> N >> M >> P;

		vector<tuple<int, int, int>> R(M);

		for (auto& [u, v, d] : R)
			cin >> u >> v >> d;

		cout << "Case #" << t << ": ";
		cout << fixed << setprecision(6) << catch_them_all(N, M, P, R) << "\n";
	}

	return 0;
}

