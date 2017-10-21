#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int N, M, L, S;
		cin >> N >> M >> L >> S;
		vector<int> init(S);
		for (int i = 0; i < S; ++i) { 
			cin >> init[i];
			--init[i];
		}
		vector<vector<pair<int, int>>> g(N);
		for (int i = 0; i < M; ++i) {
			int u, v, e;
			cin >> u >> v >> e;
			g[u - 1].emplace_back(v - 1, e + L);
			g[v - 1].emplace_back(u - 1, e + L);
		}

		priority_queue<pair<int, int>> pq;
		vector<int> taken(N, 0);
		for (int i = 0; i < S; ++i) {
			taken[init[i]] = 1;
			for (const auto& p : g[init[i]]) {
				if (!taken[p.first])
					pq.emplace(-p.second, p.first);
			}
		}
		long long cost = 0;
		while (!pq.empty()) {
			int u = pq.top().second, c = -pq.top().first;
			pq.pop();
			if (!taken[u]) {
				cost += c;
				taken[u] = 1;
				for (const auto& p : g[u]) {
					if (!taken[p.first])
						pq.emplace(-p.second, p.first);
				}
			}
		}
		cout << cost << "\n";
	}
}