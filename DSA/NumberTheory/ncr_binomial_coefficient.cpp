#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

// Function to calculate nCr
long long nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;

    // nCr = n! / (r! * (n - r)!)
    long long res = 1;

    // Use a more efficient multiplicative formula
    // nCr = n * (n-1) * ... * (n-r+1) / r!
    for (int i = 1; i <= r; ++i) {
        res *= n - r + i;
        res /= i;
    }

    return res;
}


int main() {
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

   // nCr = n! / (r! * (n-r)!)
    // when ans is large and p(prime_modulo) is greater than N 
    // directly get n! and multi with inverse module of both of it divisors.

    // below code when p <= N

    cout << "nCr = " << nCr(4, 2) << endl;

}