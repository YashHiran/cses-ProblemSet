#include<bits/stdc++.h>
using namespace std;

int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	string s; cin >> s;
	sort(s.begin(), s.end());
	int n = s.size();

	set<string> ans;

	do {
		ans.insert(s);
	} while (next_permutation(s.begin(), s.end()));



	cout << ans.size() << "\n";
	for (auto x : ans) cout << x << "\n";

	return 0;
}
