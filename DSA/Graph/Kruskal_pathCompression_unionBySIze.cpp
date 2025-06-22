#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
 
vector<int> par;
vector<int> rank1;

class Graph {
public:
    int from;
    int to;
    int w;

    Graph(int from, int to, int w) {
        this->from = from;
        this->to = to;
        this->w = w;
    }
};

int find(int node) {
    if(par[node] == -1) return node;
    return par[node] = find(par[node]);
}

void union1(int u, int v) {
    if(find(u) == find(v)) return;

    if(rank1[u] > rank1[v]) {
        par[v] = u;
        rank1[u] += rank1[v];
    } else {
         par[u] = v;
         rank1[v] += rank1[u];
    }
}

int main() {
    #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
  #endif

    int n, m; cin >> n >> m;
    vector<Graph> g;
    par.resize(n + 1, -1);
    rank1.resize(n + 1, 1);


    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        Graph graph =  Graph(u, v, w);
        g.push_back(graph);
    }

    sort(g.begin(), g.end(), [&](Graph &a, Graph &b){
       return  a.w < b.w;
    });

    int ans = 0;

    for(Graph &node: g) {
        int a = find(node.from);
        int b = find(node.to);
        if(a == b) continue;

        union1(a, b);
        ans += node.w;
    }

    cout << ans;
     
}

// class UnionFind {
//     vector<int> par;
//     vector<int> size;
// public:
//     UnionFind(int n) {
//         par.resize(n);
//         for(int i = 0; i < n; ++i) {
//             par[i] = i;
//         }
//         size.resize(n, 1);
//     }

//     int find(int node) {
//         if(par[node] == node) return node;
//         return par[node] = find(par[node]);
//     }

//     void unionBySize(int u, int v) {
//         int pu = find(u);
//         int pv = find(v);
//         if(pu == pv) return;

//         if(size[pu] > size[pv]) {
//             par[pv] = pu;
//             size[pu] += size[pv];
//         } else {
//             par[pu] = pv;
//             size[pv] += size[pu];
//         }
//     }
// };