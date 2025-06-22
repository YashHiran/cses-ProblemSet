#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
 

int pow(int num, int exp, int mod = 1e9 + 7) {
   int ans = 1;
   while(exp) {
      if(exp & 1) {
         ans *= num;
         ans %= mod;
         exp--;
      } else {
         num *= num;
         num %= mod;
         exp /= 2;
      }
   }
   return ans;
}

int main() {
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

    // a^m-2 congruent to a-1 mod m

    // so a inverse under modulo m = a^m-2

    cout << pow(4, 5, 7) << endl;
}