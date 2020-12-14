#include<bits/stdc++.h>
using namespace std;

const int n = 8;
int ans = 0;

vector<vector<int>> vis, res;
bool isSafe(int row, int col) {
	if (res[row][col]) return false;
	for (int i = 0; i < n; ++i) {
		if (vis[row][i]) return false;
		if (vis[i][col]) return false;
	}
	for (int i = row, j = col; i < n && j < n; ++i, ++j) {
		if (vis[i][j]) return false;
	}

	for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
		if (vis[i][j]) return false;
	}


	for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
		if (vis[i][j]) return false;
	}

	for (int i = row, j = col; i <  n && j >= 0; ++i, --j) {
		if (vis[i][j]) return false;
	}
	return true;
}
void Nqueens(int row) {
	if (row >= n) {
		ans++;
		return;
	}
	for (int col = 0; col < n; ++col) {
		if (isSafe(row, col)) {
			vis[row][col] = 1;
			Nqueens(row + 1);
			vis[row][col] = 0;
		}
	}
	// return false;
}
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	freopen("debug.txt", "w", stderr);
// #endif

	vis.resize(n, vector<int>(n, 0));
	res.resize(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char x; cin >> x;
			if (x == '.') vis[i][j] = 0;
			else res[i][j] = 1;
		}
	}
	// for (auto x : vis) {
	// 	for (int x : x) {
	// 		cout << x << " ";
	// 	}
	// 	cout << endl;
	// }
	Nqueens(0);
	cout << ans;
	return 0;
}
