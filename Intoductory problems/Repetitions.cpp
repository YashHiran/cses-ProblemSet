#include<bits/stdc++.h>
using namespace std;

#define int long long


int32_t main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  string s; cin >> s;
  int cnt = 1;
  int ans = 0;

  int n = s.size();


  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i - 1]) {
      cnt++;
    }
    else {
      ans = max(ans, cnt);
      cnt = 1;
    }
  }
  ans = max(ans, cnt);
  cout << ans;

  return 0;
}
