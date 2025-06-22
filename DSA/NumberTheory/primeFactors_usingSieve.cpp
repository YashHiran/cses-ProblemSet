#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
 
int maxN = 101;
vector<int> primes;

void sieve() {

   for(int i = 2; i <= sqrt(maxN); ++i) {
      if(primes[i] != -1) continue;
      for(int j = i; j < maxN; j += i) {
         if(primes[j] == -1) primes[j] = i;
      }
   }
}

vector<int> primeFactors(int n) {
   vector<int> factors;

   while(primes[n] != -1) {
      factors.push_back(primes[n]);
      n /= primes[n];
   }

   return factors;
}

int main() {
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

    primes.resize(maxN, -1);
    sieve();

    auto v = primeFactors(100);
    for(auto &x: v) cout << x << " ";

}



// O(log n) for prime factors calculation after preprocessing. 