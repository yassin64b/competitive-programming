#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void dfs(int u, int& t, const vector<vector<int>>& g,
			vector<int>& tin, vector<int>& tout) {
	tin[u] = ++t;
	for (int v : g[u]) {
		dfs(v, t, g, tin, tout);
	}
	tout[u] = ++t;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<vector<int>> g(N);
	vector<int> roots;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		if (x) {
			g[x - 1].push_back(i);
		} else {
			roots.push_back(i);
		}
	}

	vector<int> tin(N), tout(N);
	int t = 0;
	for (int r : roots) {
		dfs(r, t, g, tin, tout);
	}

	int Q;
	cin >> Q;
	for (int q = 0; q < Q; ++q) {
		int M;
		cin >> M;
		vector<int> v(M);
		for (int i = 0; i < M; ++i) {
			cin >> v[i];
			--v[i];
		}
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < M; ++j) {
				if (v[i] != -1 && v[j] != -1) {
					if (tin[v[i]] < tin[v[j]] && tout[v[i]] > tout[v[j]]) {
						v[j] = -1; //v[j] is in subtree of v[i] --> delete
					}
				}
			}
		}
		int res = 0;
		for (int i = 0; i < M; ++i) {
			if (v[i] != -1) {
				assert((tout[v[i]] - tin[v[i]] - 1) % 2 == 0);
				res += 1 + (tout[v[i]] - tin[v[i]] - 1) / 2;
			}
		}
		cout << res << "\n";
	}
}