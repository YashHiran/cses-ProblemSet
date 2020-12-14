#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n; cin >> n;
	ll sum = n * (n + 1) / 2;

	ll tot = 0;
	n--;
	while (n--) {
		int x; cin >> x; tot += x;
	}

	cout << sum - tot;

	return 0;
}