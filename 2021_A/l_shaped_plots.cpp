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

int shap(int R, int C, vector<vector<int>>& G)
{
	int cnt = 0;
	int S = max(R, C) / 2;
	int ii = 0;
	int jj = 0;

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
		{
			if (G[i][j] == 0)
				continue;

			ii = i + 1;
			jj = j + 3;

			while (0 <= ii && ii < R && 0 <= jj && jj < C && 
				G[ii][j] && G[i][jj - 2] && G[i][jj - 1] && G[i][jj])
			{
				++ cnt;
				ii += 1;
				jj += 2;
			}

			ii = i + 1;
			jj = j - 3;

			while (0 <= ii && ii < R && 0 <= jj && jj < C && 
				G[ii][j] && G[i][jj + 2] && G[i][jj + 1] && G[i][jj])
			{
				++ cnt;
				ii += 1;
				jj -= 2;
			}

			ii = i - 1;
			jj = j + 3;

			while (0 <= ii && ii < R && 0 <= jj && jj < C && 
				G[ii][j] && G[i][jj - 2] && G[i][jj - 1] && G[i][jj])
			{
				++ cnt;
				ii -= 1;
				jj += 2;
			}

			ii = i - 1;
			jj = j - 3;

			while (0 <= ii && ii < R && 0 <= jj && jj < C && 
				G[ii][j] && G[i][jj + 2] && G[i][jj + 1] && G[i][jj])
			{
				++ cnt;
				ii -= 1;
				jj -= 2;
			}

			//-------------------

			ii = i + 3;
			jj = j + 1;

			while (0 <= ii && ii < R && 0 <= jj && jj < C && 
				G[ii][j] && G[ii - 2][j] && G[ii - 1][j] && G[i][jj])
			{
				++ cnt;
				ii += 2;
				jj += 1;
			}

			ii = i - 3;
			jj = j + 1;

			while (0 <= ii && ii < R && 0 <= jj && jj < C && 
				G[ii][j] && G[ii + 2][j] && G[ii + 1][j] && G[i][jj])
			{
				++ cnt;
				ii -= 2;
				jj += 1;
			}

			ii = i + 3;
			jj = j - 1;

			while (0 <= ii && ii < R && 0 <= jj && jj < C && 
				G[ii][j] && G[ii - 2][j] && G[ii - 1][j] && G[i][jj])
			{
				++ cnt;
				ii += 2;
				jj -= 1;
			}

			ii = i - 3;
			jj = j - 1;

			while (0 <= ii && ii < R && 0 <= jj && jj < C && 
				G[ii][j] && G[ii + 2][j] && G[ii + 1][j] && G[i][jj])
			{
				++ cnt;
				ii -= 2;
				jj -= 1;
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
		int R, C;
		cin >> R >> C;

		vector<vector<int>> G(R, vector<int>(C));

		for (auto& r : G)
			for (auto& c : r)
				cin >> c;

		cout << "Case #" << t << ": ";
		cout << shap(R, C, G) << "\n";
	}

	return 0;
}

