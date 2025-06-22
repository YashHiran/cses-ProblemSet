#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
 
vector<int> primeFactors(int n) {
   vector<int> factors;

   for(int i = 2; i <= sqrt(n); ++i) {
      if(n % i == 0) {
         while(n % i == 0) {
            factors.push_back(i);
            n /= i;
         }
      }
   }
   if(n > 1) {
      factors.push_back(n);
   }

   return factors;
}

int main() {
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

    auto factors = primeFactors(100);
    for(int &x: factors) cout << x << " ";
}  

// O(sqrt(n))
// space: O(log n) -> i.e max prime factors for a number.