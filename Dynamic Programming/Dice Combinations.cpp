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
  int dp[n + 1] = {1};

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= 6; ++j)
      if (i - j >= 0)
        dp[i] = (dp[i  - j] + dp[i]) % mod;
  cout << dp[n];

  return 0;
}