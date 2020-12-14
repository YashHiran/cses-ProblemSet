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

	int ans; cin >> ans;
	int val = 0;

	if (ans > 0) val = ans;

	while (--n) {
		int x; cin >> x;
		val += x;
		ans = max(ans, val);
		if (val < 0) val = 0;
	}
	cout << ans;

	return 0;
}