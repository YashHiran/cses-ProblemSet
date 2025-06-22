#include <bits/stdc++.h>
using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> dist(n + 1, INT_MAX);

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    int src = 1;
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        int curDist = p.first, u = p.second;

        pq.pop();

        for (auto &edge : adj[u]) {
            int v = edge.first, w = edge.second;

            if (curDist + edge.second < dist[edge.first]) {
                dist[edge.first] = curDist + edge.second;
                pq.push({dist[edge.first], edge.first});
            }
        }
    }

    // Output shortest distances
    for (int i = 1; i <= n; i++) {
        cout << "Distance to node " << i << " = ";
        if (dist[i] == INT_MAX) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}
