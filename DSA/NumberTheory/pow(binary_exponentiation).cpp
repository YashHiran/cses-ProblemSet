#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
 
int pow(int num, int exp) {

   int ans = 1;

   while(exp) {
      if(exp & 1) {
         ans *= num;
         exp--;
      } else {
         num *= num;
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

    cout << pow(2, 5) << endl;
    cout << pow(3,7);
}


// log(exp)
