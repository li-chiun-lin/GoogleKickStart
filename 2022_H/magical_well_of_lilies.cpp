/*

*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int magical(int L)
{
    vector<int> dp(L + 1, INT_MAX);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= L; ++ i)
    {
        dp[i] = min(dp[i], dp[i - 1] + 1);

        for (int j = 1; j * i <= L; ++j)
            dp[j * i] = min(dp[j * i], dp[i] + 4 + 2 * (j - 1));
    }

    return dp[L];
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
        int L;
        cin >> L;

		cout << "Case #" << t << ": ";
		cout << magical(L) << "\n";
	}

	return 0;
}

