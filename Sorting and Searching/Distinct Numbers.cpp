#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	set<int> ms;

	while (n--) {
		int c; cin >> c;
		ms.insert(c);
	}

	cout << ms.size();

	return 0;
}
