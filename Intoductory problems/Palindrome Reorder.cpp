#include<bits/stdc++.h>
using namespace std;

int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	string s; cin >> s;

	int f[26] = {};

	for (int i = 0; i < s.size(); ++i) {
		f[s[i] - 'A']++;
	}

	int cnt = 0;
	char odd;
	bool flag = 0;
	for (int i = 0; i < 26; ++i) {
		if (f[i] & 1) {
			cnt++;
			flag = 1;
			odd = char('A' + i);
		}
		f[i] /= 2;
	}

	if (cnt > 1) {
		cout << "NO SOLUTION";
		return 0;
	}

	string ans;

	for (int i = 0; i < 26; ++i) {
		int cnt = f[i];
		while (cnt--) {
			ans += char('A' + i);
		}
	}


	string rev = ans;
	reverse(rev.begin(), rev.end());

	string res = ans;
	if (flag) res += odd;
	res += rev;
	cout << res;



	return 0;
}
