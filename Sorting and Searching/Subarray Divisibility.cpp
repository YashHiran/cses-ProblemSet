#include<bits/stdc++.h>
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

int main()
{
    fastio
    cin.tie(NULL); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif

    ll n; cin >> n;
    vi a(n); input(a);

    ll pre = 0, ans = 0;
    map<ll, ll> mm;
    mm[0] = 1;
    for (ll x : a) {
        pre += x;
        pre %= n;
        if (pre < 0) pre += n;
        ans += mm[pre];
        mm[pre]++;
    }
    cout << ans;


    return 0;
}
