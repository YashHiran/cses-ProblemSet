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

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int n, l, r; cin >> n >> l >> r;
    vi a(n  + 1); FO(i, 1, n + 1) cin >> a[i];
    int b = r;
    vi pre(n + 1); pre[1] = a[1];

    FO(i, 2, n + 1) {
        pre[i] = pre[i - 1] + a[i];
    }
    set<pll> ms;
    ll ans = LLONG_MIN;
    FO(i, 1, n + 1) {
        if (i >= l) ms.insert({pre[i - l], i - l});
        if (sz(ms)) ans = max(ans, pre[i] - ms.begin()->F);
        if (i >= b) ms.erase({pre[i - b], i - b});
    }
    cout << ans << endl;
    return 0;
}