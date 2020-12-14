#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, tar; cin >> n >> tar;
	vector<int> a(n);
	map<int, int> mm;
	for (int &X : a) cin >> X;

	mm[0] = 1;
	int pre = 0;
	int ans = 0;

	for (int x : a) {
		pre += x;
		ans += mm[pre - tar];
		mm[pre]++;
	}
	cout << ans;

	return 0;
}