#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  long n; cin >> n;
  const int mod = 1e9 + 7;

  long ans = 1;

  while (n--) {
    ans *= 2;
    ans %= mod;
  }

  cout << ans;

  return 0;
}