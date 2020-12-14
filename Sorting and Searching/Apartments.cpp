#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	freopen("debug.txt", "w", stderr);
// #endif
	ios_base :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	multiset<int> a;
	vector<int> b(m);
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		a.insert(x);
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	int ans = 0;

	for (int x : b) {
		auto it = a.lower_bound(x - k);
		if (it != a.end() && *it <= x + k) {
			ans++;
			a.erase(it);
		}
	}
	cout << ans << endl;
	return 0;
}
