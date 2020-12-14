#include<bits/stdc++.h>
using namespace std;

#define int long long


int32_t main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n; cin >> n;
  cout << n << " ";
  while (1) {
    if (n == 1) break;

    if (n % 2 == 1) {
      n = n * 3 + 1;
    } else {
      n /= 2;
    }
    cout << n << " ";
  }

  return 0;
}