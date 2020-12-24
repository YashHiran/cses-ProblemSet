#include<bits/stdc++.h>
using namespace std;

#define int long long
const int32_t mod = 1e9 + 7;

int n, amt;
vector<int> a, dp;
int ans;
int fun(int cur_amt) {
	if (cur_amt > amt) return 0;
	if (cur_amt == amt) return  1;

	if (dp[cur_amt] != -1) return dp[cur_amt];

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += fun(cur_amt + a[i]);
		ans %= mod;
	}
	return dp[cur_amt] = ans;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> amt;
	a.resize(n);
	dp.resize(amt + 1, -1);
	for (int &x : a) cin >> x;
	cout << fun(0);
	return 0;
}