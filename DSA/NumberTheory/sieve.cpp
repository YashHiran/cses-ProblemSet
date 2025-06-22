#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int maxN = 101;
vector<bool> isPrime;

void sieve() {
   for(int i = 2; i <= sqrt(maxN); ++i) {
      if(!isPrime[i]) continue;
      for(int j = i * i; j < maxN; j += i) {
         isPrime[j] = false;
      }
   }
}

int main() {
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

    isPrime.resize(101, 1);
    isPrime[0] = isPrime[1] = false;
    sieve();
    for(int i = 0; i < maxN; ++i) {
      if(isPrime[i]) cout << i << " ";
    }

}

// O(maxN⋅loglogmaxN)
