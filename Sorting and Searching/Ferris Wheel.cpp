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

	int n, w; cin >> n >> w;
	vector<int> a(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int ans = 0;

	sort(a.begin(), a.end());

	int l = 0, r = n - 1;

	while (l <= r) {
		int val = a[r--];
		if (l <= r && a[l] + val <= w) {
			val += a[l++];
		}
		ans++;
	}
	cout << ans;

	return 0;
}
