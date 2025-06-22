#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<vector<int>> g;
vector<int> vis, in, low;
stack<int> st; 
vector<int> curSccVisited; 
int timer;
int scc;

void dfs(int node) {
	// cout << node << " ";
	vis[node] = 1;
	in[node] = low[node] = timer++;
	curSccVisited[node] = true;
	st.push(node);

	for(int child: g[node]) {

		if(vis[child] && curSccVisited[child]) {
			low[node] = min(low[node], in[child]);
		} else if(!vis[child]) {
			dfs(child);

			if(curSccVisited[child]){
				low[node] = min(low[node], low[child]);
			}

		}
	}

	if(in[node] == low[node]) {
		scc++;
		cout << scc << ": ";
		int currNode;
		while(true) {
			currNode = st.top(); st.pop();
			cout << currNode << " ";
			curSccVisited[currNode] = false;
			if(currNode == node) break;
		}
		cout << endl;
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
	curSccVisited.resize(n + 1, 0);

	while(m--) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		// g[v].push_back(u);
	}

	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			dfs(i);
		}
	}
	// cout << scc; 
}
