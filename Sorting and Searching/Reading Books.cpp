#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	vector<int> a(n);
	int maxx = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		ans += a[i];
		maxx = max(a[i], maxx);
	}

	cout << max(ans, 2 * maxx);



	return 0;
}
