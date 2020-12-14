#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	vector<pair<int, int>> a;
	for (int i = 0; i < n; ++i) {
		int x, y; cin >> x >> y;
		a.push_back({x, y});
	}

	sort(a.begin(), a.end(), [](const auto & a, const auto & b) {
		return a.second < b.second;
	});

	int ans = 0;

	int i  = 0;
	while (i < n) {
		int cur = a[i++].second;
		while (i < n && a[i].first < cur) ++i;
		ans++;
	}
	cout << ans;

	return 0;
}