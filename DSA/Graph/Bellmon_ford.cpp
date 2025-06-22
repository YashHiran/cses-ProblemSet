#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int n; 
    vector<pair<int, pair<int, int>>> edges; // (u, (v, w)) format for edges

    Graph(int n) {
        this->n = n;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({u, {v, w}});
    }

    void bellmanFord(int src) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Relax edges up to (n-1) times
        for (int i = 0; i < n - 1; i++) {
            for (auto &edge : edges) {
                int u = edge.first;
                int v = edge.second.first;
                int w = edge.second.second;
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative-weight cycles
        for (auto &edge : edges) {
            int u = edge.first;
            int v = edge.second.first;
            int w = edge.second.second;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                cout << "Negative weight cycle detected!" << endl;
                return;
            }
        }

        // Output distances
        for (int i = 0; i < n; i++) {
            cout << "Distance to node " << i << " = ";
            if (dist[i] == INT_MAX) cout << "INF" << endl;
            else cout << dist[i] << endl;
        }
    }
};

int main() {
    #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    Graph g(n);

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int src;
    cin >> src;

    g.bellmanFord(src);
}
