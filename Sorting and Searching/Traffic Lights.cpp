#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("debug.txt", "w", stderr);
#endif

	int x, n; cin >> x >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	multiset<int> diff = {x};
	multiset<int> ele = {x, 0};
	multiset<int, greater<int>> eles = {x, 0};
	for (int x : a) {
		auto it = ele.upper_bound(x);
		auto it1 = eles.upper_bound(x);
		if (it != ele.end() && it1 != eles.end()) {
			diff.erase(diff.find(abs(*it - *it1)));
			diff.insert(abs(x - *it));
			diff.insert(abs(x - *it1));
		} else if (it == ele.end()) {
			diff.insert(abs(x - *it1));
		} else if (it1 == eles.end()) {
			diff.insert(abs(x - *it));
		}
		ele.insert(x);
		eles.insert(x);
		cout << *diff.rbegin() << " ";
	}
	return 0;
}

