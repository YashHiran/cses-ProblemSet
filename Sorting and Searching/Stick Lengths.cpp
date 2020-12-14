#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long n; cin >> n;
	long ans = 0;
	vector<long> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	long val = a[n / 2];

	for (auto x : a) {
		ans += abs(x - val);
	}
	cout << ans;




	return 0;
}