#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<vector<int>> g;
vector<int> vis, in, low;
int timer;

void dfs(int node, int par) {
	vis[node] = 1;
	in[node] = low[node] = timer++;
	for(int child: g[node]) {
		if(child == par) continue;

		if(vis[child]) {
			low[node] = min(low[node], in[child]);
		} else {
			dfs(child, node);

			if(low[child] > in[node]) {
				cout << node <<  "->" << child << endl;
			}

			low[node] = min(low[node], low[child]);

		}
	}
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
	in.resize(n + 1, 0);
	low.resize(n + 1, 0);

	while(m--) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			dfs(i, -1);
		}
	}
}
