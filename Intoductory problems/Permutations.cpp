#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n; cin >> n;
  if (n == 2 || n == 3) {
    cout << "NO SOLUTION";
    return 0;
  }

  vector<int> o, e;

  for (int i = 1; i <= n; ++i) {
    if (i & 1) o.push_back(i);
    else e.push_back(i);
  }

  sort(o.begin(), o.end(), greater<int>());
  sort(e.begin(), e.end(), greater<int>());

  for (int x : o) cout << x << " ";
  for (int x : e) cout << x << " ";

  return 0;
}
