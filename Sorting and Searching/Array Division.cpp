#include<bits/stdc++.h>
#define ll  unsigned long long
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


ll n, k;
vi a;


bool ok(ll sum) {
	ll cnt = 0;
	ll j = 0;
	while (j < n) {
		if (a[j] > sum) return false;
		ll val = 0;
		while (j < n && a[j] + val <= sum) {
			val += a[j++];
		}
		cnt++;
	}
	return cnt <= k;
}

int main()
{
	fastio
	cin.tie(NULL); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("debug.txt", "w", stderr);
#endif
	cin >> n >> k;
	a.resize(n);
	input(a);

	ll l = 0ll, r = accumulate(a.begin(), a.end(), 0LL);
	ll ans = 0;
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		if (ok(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans;


	return 0;
}