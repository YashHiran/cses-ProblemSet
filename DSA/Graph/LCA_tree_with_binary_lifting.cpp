
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
 
int maxN = 10;
vector<vector<int>> g;
vector<vector<int>> LCA;
vector<int> level;
int n, m;

void dfs(int node, int parent, int lvl) {
    level[node] = lvl;
    LCA[node][0] = parent;

    for(auto &child: g[node]) {
        if(parent != child) {
            dfs(child, node, lvl + 1);
        }
    }
}

void buildSparseTable() {
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j < maxN; ++j) {
            int val = LCA[i][j-1];
            if(val != -1)
            LCA[i][j] = LCA[val][j-1];
        }
    }
}

void findLCA(int u, int v) {

    if(level[u] < level[v]) {
        swap(u, v);
    }

    int d = level[u] - level[v];
    while(d) {
        int i = log2(d);
        u = LCA[u][i];
        d-= 1 << i;
    }
    if(u == v) {
        cout << u << endl;
        return;
    }

    for(int i = maxN; i >= 0; --i) {
        if(LCA[u][i] != -1 && LCA[u][i] != LCA[v][i]) {
            u = LCA[u][i];
            v = LCA[v][i];
        }
    }
    cout << LCA[u][0] << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
  #endif

    cin >> n >> m;
    g.resize(n);
    LCA.resize(n,vector<int>(maxN + 1, -1));
    level.resize(n,0);

    for(int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
     }

    dfs(0, -1, 0); 
    buildSparseTable();

    findLCA(3, 2); // 0
    findLCA(3, 0); // 0

    findLCA(3, 4); // 0
    findLCA(1, 0); // 0
    findLCA(1, 2); // 1
    findLCA(1, 4); // 0
    findLCA(1, 3); // 1
}
