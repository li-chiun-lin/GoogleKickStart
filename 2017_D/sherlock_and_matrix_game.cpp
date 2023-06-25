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
	for (auto x : v)
		cout << x << " ";
	cout << "\n";
}

void print(vector<vector<int>>& m)
{
	int w = 4; 

	for (auto& r : m)
	{
		for (auto c : r)
			cout << setw(w) << c;
		cout << "\n";
	}

	cout << "\n";
}

long long matrix_game(int N, int K, vector<int>& A, vector<int>& B)
{
	vector<vector<int>> M(N, vector<int>(N)), prefix(N + 1, vector<int>(N + 1));

	for (int i = 0; i < N; ++i)
		for (int j = 0, row_accu = 0; j < N; ++j)
			prefix[i + 1][j + 1] = prefix[i][j + 1] + (row_accu += M[i][j] = A[i] * B[j]);
	
	//cout << "\n";
	//print(A);
	//print(B);
	//print(M);
	//print(prefix);

	priority_queue<int, vector<int>, greater<>> pq;

	for (int a = 0; a < N; ++a)
		for (int c = a; c < N; ++c)
			for (int b = 0; b < N; ++b)
				for (int d = b; d < N; ++d)
				{
					int sum = prefix[c + 1][d + 1] - prefix[a][d + 1] - prefix[c + 1][b] + prefix[a][b];

					pq.push(sum);

					if (pq.size() > K)
						pq.pop();
				}

	
	return pq.top();
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, K;
		cin >> N >> K;

		vector<int> A(N), B(N), x(N), y(N), r(N), s(N);
		long long C, D, E1, E2, F;

		cin >> A[0] >> B[0] >> C >> D >> E1 >> E2 >> F;

		x[0] = A[0];
		y[0] = B[0];
		
		for (int i = 1; i < N; ++i)
		{
			x[i] = (C * x[i - 1] + D * y[i - 1] + E1) % F;
			y[i] = (D * x[i - 1] + C * y[i - 1] + E2) % F;
			r[i] = (C * r[i - 1] + D * s[i - 1] + E1) % 2;
			s[i] = (D * r[i - 1] + C * s[i - 1] + E2) % 2;
			//A[i] = pow(-1, r[i]) * x[i];
			//B[i] = pow(-1, s[i]) * y[i];
			A[i] = r[i] % 2 ? (-x[i]) : x[i];
			B[i] = s[i] % 2 ? (-y[i]) : y[i];
		}

		cout << "Case #" << t << ": ";
		cout << matrix_game(N, K, A, B) << "\n";
	}

	return 0;
}

