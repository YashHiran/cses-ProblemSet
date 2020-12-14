#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int n; cin >> n;

	int sum = n * (n + 1) / 2;


	if (sum & 1) {
		cout << "NO" << endl;
		return 0;
	}

	int target = sum / 2;
	vector<int> one, two;
	while (n > 0) {
		if (target - n >= 0) {
			one.push_back(n);
			target -= n;
		} else {
			two.push_back(n);
		}
		n--;
	}
	cout << "YES" << endl;
	cout << one.size() << "\n";
	for (int x : one) cout << x << " ";
	cout << endl;

	cout << two.size() << endl;
	for (int x : two) cout << x << " ";

	return 0;
}