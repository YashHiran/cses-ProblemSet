#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif

    ll n, tar; cin >> n >> tar;
    vector<ll> a(n), ans;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto arr = a;

    sort(arr.begin(), arr.end());



    for (ll i  = 0; i < n - 2; ++i) {
        if (arr[i] > tar) break;
        ll l = i + 1,  r = n - 1;
        while (l < r) {
            ll val = arr[i] + arr[l] + arr[r];
            if (val == tar) {
                ans.push_back(arr[i]);
                ans.push_back(arr[l]);
                ans.push_back(arr[r]);
                goto out;
            } else if (val < tar) {
                l++;
            } else {
                r--;
            }
        }
    }

    if (!ans.size()) {
        cout << "IMPOSSIBLE";
        return 0;
    }

out :
    cerr << ans[0] << " " << ans[1] << " " << ans[2];
    ll ans1 = -1, ans2 = -1, ans3 = -1;

    for (int i = 0; i < n; ++i) {
        if (a[i] == ans[0] && i  != ans2 && i != ans3 && ans1 == -1) {
            ans1 = i;
        }
        if (a[i] == ans[1] && i != ans1 && i != ans3 && ans2 == -1) {
            ans2 = i;
        }
        if (a[i] == ans[2] && i != ans1 && i != ans2) {
            ans3 = i;
        }
    }

    cout << ++ans1 << " " << ++ans2 << " " << ++ans3;
    return 0;
}