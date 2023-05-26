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

long long area(long long R, int A, int B)
{
	long long area = R * R;

	while (R)
	{
		R *= A;
		area += R * R;
		R /= B;
		area += R * R;
	}

	return area;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int R, A, B;
		cin >> R >> A >> B;

		cout << "Case #" << t << ": ";
		cout << fixed << (M_PI * area(R, A, B)) << "\n";
	}

	return 0;
}

