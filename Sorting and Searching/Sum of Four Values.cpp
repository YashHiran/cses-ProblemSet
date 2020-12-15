#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll n, tar; cin >> n >> tar;
    vector<ll> arr(n);
    for (ll i = 0; i < n; ++i)
        cin >> arr[i];

    vector<pair<ll, pair<ll, ll>>> a;

    for (ll i = 0; i < n - 1; ++i)
        for (ll j = i + 1; j < n; ++j)
            a.push_back({arr[i] + arr[j], {i + 1, j + 1}});

    sort(a.begin(), a.end());

    ll l = 0, r = a.size() - 1;


    while (l <= r) {
        ll val = a[l].first + a[r].first;
        if (val == tar) {
            set<ll> s;
            s.insert(a[l].second.first);
            s.insert(a[l].second.second);
            s.insert(a[r].second.first);
            s.insert(a[r].second.second);
            if (s.size() < 4) {
                ++l;
            } else {
                for (ll x : s) {
                    cout << x << " ";
                }
                return 0;
            }
        } else if (val < tar) {
            l++;
        } else {
            r--;
        }
    }


    cout << "IMPOSSIBLE";



    return 0;
}