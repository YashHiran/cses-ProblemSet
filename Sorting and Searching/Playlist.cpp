#include<bits/stdc++.h>
#define int  long long
#define ll  long long
#define pb push_back
#define vi vector<ll>

#define sz(x) ((int) (x).size())
#define pll pair<long long,long long>
#define F first
#define S second
#define T int tt; cin>>tt; while(tt--)
#define fastio ios_base::sync_with_stdio(false);

#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define display(x) for(auto i : x) cerr << i << " "; cerr << '\n';
#define input(x) for(auto &xx : x) cin >> xx;
#define FO(i,startLoop,n) for (int i = startLoop; i < n; i++)

#define mod 1000000007
#define Y cout<<"YES"<<endl;
#define N cout<<"NO"<<endl;
using namespace std;

int32_t main()
{
	fastio
	cin.tie(NULL); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	vi a(n); input(a)
	map<int, int> mm;

	int l = 0, r = 0;
	int ans = 0;
	while (r < n) {
		while (mm[a[r]] > 0) {
			if (l < n)
				mm[a[l++]]--;
		}
		if (r < n)
			mm[a[r++]]++;
		ans = max(ans, r - l);
	}
	cout << ans;
	return 0;
}