
#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int n; cin >> n;
	vector<int> a(n);

	int sum = 0;

	for (int i = 0 ; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	int ans = LLONG_MAX;
	for (int i = 0; i < (1 << n); ++i) {
		int tot = 0, t2 = 0;
		for (int j = 0; j < n; ++j) {
			if (1 << j & i) {
				tot += a[j];
			} else {
				t2 += a[j];
			}
		}
		if (tot != sum)
			ans = min(ans, abs(tot - t2));
	}
	cout << ans;





	return 0;
}
