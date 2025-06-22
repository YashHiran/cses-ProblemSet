#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<vector<int>> g;
vector<int> vis;
vector<int> cycle;
int cycleStartNode;

bool dfs(int node, int par) {

   vis[node] = true;
   cycle.push_back(node);
   for(int child: g[node]) {
      if(child == par) continue;

      if(!vis[child]) {
         if(dfs(child, node)) return true;
      } else {
         if(par != child) {
            cycleStartNode = child;
            return true;
         }
      }
   }
   cycle.pop_back();
   return false;
} 

int main() {
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

   int n; cin >> n;
   int m; cin >> m;

   g.resize(n + 1);
   vis.resize(n + 1, 0);

   while(m--) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
   }
   if(!dfs(0, -1)) {
      cout << "No cycle\n";
   }
   else {
      vector<int> c(1, cycleStartNode);
      for(int i = cycle.size() - 1; i >= 0; --i) {
         c.push_back(cycle[i]);
         if(cycle[i] == cycleStartNode) {
            break;
         }
      }

      reverse(c.begin(), c.end());

      for(auto &x: c) {
         cout << x << " ";
      }
      cout << endl;
   }
  
}



// 5 5
// 0 1
// 1 2
// 2 3
// 3 4
// 4 1




