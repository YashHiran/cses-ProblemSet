#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n; cin >> n;
  int ans = 0;
  int i = 5;
  while (n / i >= 1) {
    ans += n / i;
    i *= 5;
  }

  cout << ans;

  return 0;
}