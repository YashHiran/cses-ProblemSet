#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	n <<= 1;
	map<int, int> mm;
	while (n--) {
		int x; cin >> x;
		if (n & 1) {
			mm[x] = 1;
		} else mm[x] = -1;
	}
	int sum = 0, ans = 0;
	for (auto x : mm) {
		sum += x.second;
		ans = max(ans, sum);
	}
	cout << ans << endl;

	return 0;
}