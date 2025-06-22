
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
 
vector<vector<int>> g;
vector<int> par;
vector<int> level;
int n, m;

void dfs(int node, int parent, int lvl) {
    level[node] = lvl;
    par[node] = parent;

    for(auto &child: g[node]) {
        if(parent != child) {
            dfs(child, node, lvl + 1);
        }
    }
}

void findLCA(int u, int v) {

    if(level[u] < level[v]) {
        swap(u, v);
    }

    int d = level[u] - level[v];
    while(d) {
        u = par[u];
        d--;
    }
    if(u == v) {
        cout << u << endl;
        return;
    }

    while(u != v) {
        u = par[u];
         v=par[v];
    }
    cout << u << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
  #endif

    cin >> n >> m;
    g.resize(n);
    par.resize(n,0);
    level.resize(n,0);

    for(int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
     }

    dfs(0, -1, 0); 
    findLCA(3, 2); // 0
    findLCA(3, 0); // 0

    findLCA(3, 4); // 0
    findLCA(1, 0); // 0
    findLCA(1, 2); // 0
    findLCA(1, 4); // 0
    findLCA(1, 3); // 1
}
