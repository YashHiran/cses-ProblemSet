#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
 
int gcd(int a, int b) {
   if(a == 0) return b;
   return gcd(b, a % b);
}

int main() {
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

    cout << gcd(12, 8);
}