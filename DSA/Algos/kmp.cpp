#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
 
vector<int> Lps(string pat) {
    int n = pat.size();
    vector<int> lps(n, 0);
    int i = 0;  // length of the previous longest prefix suffix

    for(int j = 1; j < n; ++j) {
        while(i > 0 && pat[i] != pat[j]) {
            i = lps[i-1];
        }
        if(pat[i] == pat[j]) {
            i++;
        }
        lps[j] = i;
    }
    return lps;
}

vector<int> kmp(string s, string pat) {
    int sz = s.size(), psz = pat.size();
    vector<int> lps = Lps(pat);
    int j = 0;  // index for pat
    vector<int> idx;
    
    for(int i = 0; i < sz; ++i) {
        while(j > 0 && pat[j] != s[i]) {
            j = lps[j-1];
        }
        if(pat[j] == s[i]) {
            j++;
        }
        if(j == psz) {
            idx.push_back(i - psz + 1);  
            j = lps[j-1]; 
        }
    }
    return idx;
}


int main() {
    #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
  #endif

    string s, pat; cin >> s >> pat;
    vector<int> idx = kmp(s, pat);


    for(int &x: idx) {
        cout << x << " ";
    }

}
