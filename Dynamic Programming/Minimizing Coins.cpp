#include<bits/stdc++.h>
using namespace std;
#define int long long

const int32_t mod = (1e9 + 7);

int32_t main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n; cin >> n;
  int amount; cin >> amount;
  vector<int> a(n + 1);

  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<int> dp(amount + 1, INT_MAX);

  dp[0] = 0;
  for (int i = 0; i < amount + 1; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i - a[j] >= 0)
        dp[i] = min(dp[i], dp[i - a[j]] + 1);
    }
  }

  cout << (dp[amount] == INT_MAX ? -1 : dp[amount]);


  return 0;
}
