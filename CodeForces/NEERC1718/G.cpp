#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>
#include <set>
#include <utility>

using namespace std;

int n, m, s;
vector<set<pair<int, int>>> g;
vector<pair<int, int>> undir;
set<pair<int, int>> res;

void dfs(int u, vector<int>& vis, const bool flag) {
	vis[u] = 1;
	for (const auto& p : g[u]) {
		int v = p.first;
		if (!vis[v]) {
			if (p.second) {
				if (flag) {
					res.emplace(u, v);
					//cout << "make " << u+1 << " " << v+1 << endl;
					dfs(v, vis, flag);
				} else {
					res.emplace(v, u);
					//cout << "make " << v+1 << " " << u+1 << endl;
				}
			} else {
				dfs(v, vis, flag);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> s;
	--s;
	g.resize(n);
	for (int i = 0; i < m; ++i)  {
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 1) {
			g[u - 1].emplace(v - 1, 0);
		} else if (t == 2) {
			g[u - 1].emplace(v - 1, 1);
			g[v - 1].emplace(u - 1, 1);
			undir.emplace_back(u - 1, v - 1);
		}
	}
	vector<int> vis(n, 0);
	dfs(s, vis, true);
	int sum = accumulate(vis.begin(), vis.end(), 0);
	cout << sum << "\n";
 	for (int i = 0; i < (int)undir.size(); ++i) {
 		if (res.find(undir[i]) != res.end()) {
			assert(res.find({undir[i].second, undir[i].first}) == res.end());
 			cout << '+';
 		} else {
 			cout << '-';
 		}
 	}
 	cout << "\n";

	res.clear();
	vis.assign(n, 0);
	dfs(s, vis, false);
	sum = accumulate(vis.begin(), vis.end(), 0);
	cout << sum << "\n";
	for (int i = 0; i < (int)undir.size(); ++i) {
 		if (res.find(undir[i]) != res.end()) {
 			assert(res.find({undir[i].second, undir[i].first}) == res.end());
 			cout << '+';
 		} else {
 			cout << '-';
 		}
 	}
 	cout << "\n";
}