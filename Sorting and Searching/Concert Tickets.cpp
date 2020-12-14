#include<bits/stdc++.h>
using namespace std;

int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	for (int &x : a) cin >> x;
	for (int &x : b) cin >> x;

	multiset<int, greater<int>> ms(a.begin(), a.end());



	for (int i = 0; i < m; ++i) {
		auto it = ms.lower_bound(b[i]);
		if (it == ms.end()) {
			cout << -1  << "\n";
		} else {
			cout << *it  << "\n";
			ms.erase(it);
		}
	}


	return 0;
}