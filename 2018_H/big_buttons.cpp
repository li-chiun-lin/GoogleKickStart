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

struct trie
{
	bool eow;
	struct trie* next[2];
};

void insert(trie* obj, string& s)
{
	for (char c : s)
	{
		int i = c == 'B' ? 0 : 1;

		if (! obj->next[i])
			obj->next[i] = new trie();
		
		obj = obj->next[i];
	}

	obj->eow = true;
}

long long count(trie* obj, int N)
{
	if (! obj)
		return 0;
	
	if (obj->eow)
		return pow(2, N);
	else
		return count(obj->next[0], N - 1) + count(obj->next[1], N - 1);
}

long long big_buttons(int N, int P, vector<string>& S)
{
	trie* obj = new trie();

	for (auto& s : S)
		insert(obj, s);

	return pow(2, N) - count(obj, N);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, P;
		cin >> N >> P;

		vector<string> S(P);

		for (auto& s : S)
			cin >> s;

		cout << "Case #" << t << ": ";
		cout << big_buttons(N, P, S) << "\n";
	}

	return 0;
}

