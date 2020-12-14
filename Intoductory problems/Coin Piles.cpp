#include<bits/stdc++.h>
using namespace std;

int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int tt; cin >> tt;
	while (tt--) {
		int f, s; cin >> f >> s;

		if (2 * min(f, s) < max(f, s)) {
			cout << "NO\n";
			continue;
		}
		if (1) {
			f %= 3;
			s %= 3;
		}
		if (abs(f - s) >= 2) {
			cout << "NO" << "\n";
		} else {
			if (f + s == 0 || f + s == 3) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}
