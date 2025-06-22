#include <bits/stdc++.h>
#include<algorithm>

#define ll long long 
using namespace std;
 

vector<int> robinKarp(string haystack, string needle) {
        // to find the big prime number: http://www.bigprimes.net/archive/prime/100001/
        unsigned ll q = 373591679;
        
        vector<int> indexes;
        ll m = needle.size();
        ll n = haystack.size();
        if (m == 0 || n == 0 || m > n) {
            return indexes;
        }

        ll d = 3;
        ll t = haystack[0];
        ll p = needle[0];
        ll h = 1;

        for(int i = 1; i < m; i++) {
            h = (h*d)%q;
            p = (p*d + needle[i])%q;
            t =  (t*d + haystack[i])%q;
        }

        for(int i = 0; i <= n-m; i++) {
            if(p == t) {
                int j = 0;
                for(; j < m && needle[j] == haystack[i+j]; j++);
                if(j == m) {
                    indexes.push_back(i);
                }
            }

            if(i < n-m)
                t = ((t-haystack[i]*h)*d + haystack[i+m])%q;
        }

        return indexes;
    }



int main() {
    #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
  #endif

     auto vec = robinKarp("abcabcababccbab", "ab");
     for(auto &x: vec) cout << x << " "; 

}
