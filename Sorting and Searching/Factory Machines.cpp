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

const ll maxN = long(1e18);

vi a;
ll n, t;

bool ok(ll timer) {
	ll prod = 0;
	for (auto x : a) {
		prod += (timer / x);
	}
	return prod >= t;
}
int main()
{
	fastio
	cin.tie(NULL); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	cin >> n >> t;
	a.resize(n);
	input(a);
	ll ans = 0;

	ll l = 0, r = maxN;

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
