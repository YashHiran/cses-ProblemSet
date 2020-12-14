#include<bits/stdc++.h>
using namespace std;

#define int long long
int32_t main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n; cin >> n;
  vector<int> a(n);
  for (int &X : a) cin >> X;
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i - 1]) {
      ans += a[i - 1] - a[i];
      a[i] = a[i - 1];
    }

  }

  cout << ans;

  return 0;
}