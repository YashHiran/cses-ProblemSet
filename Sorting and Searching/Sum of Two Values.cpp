#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, target; cin >> n >> target;

	// value, index
	map<int, int> mm;
	bool f = 0;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		int req = target - x;
		if (mm.find(req) != mm.end()) {
			cout << mm[req] << " " << (i + 1);
			return 0;
		}
		mm[x] = i + 1;
	}
	cout << "IMPOSSIBLE";


	return 0;
}