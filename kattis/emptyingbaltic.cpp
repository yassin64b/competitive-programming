#include <iostream>
#include <vector>
#include <tuple>
#include <cassert>
#include <queue>

using namespace std;

int h, w;

bool valid(int x, int y) {
	return x >= 0 && x < h && y >= 0 && y < w;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> h >> w;
	vector<vector<int>> g(h, vector<int>(w));
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> g[i][j];
			g[i][j] = (g[i][j] > 0) ? 0 : -g[i][j];
		}
	}
	int x, y;
	cin >> x >> y;
	--x; --y;

	vector<vector<int>> vis(h, vector<int>(w, 0));
	long long res = 0;
	priority_queue<tuple<int, int, int>> pq;
	pq.emplace(g[x][y], x, y);
	vis[x][y] = 1;
	while (!pq.empty()) {
		int x, y, w;
		tie(w, x, y) = pq.top();
		res += w;
		pq.pop();
		for (int i = -1; i <= 1; ++i) {
			for (int j = -1; j <= 1; ++j) {
				int nx = x + i, ny = y + j;
				if (valid(nx, ny) && g[nx][ny] && !vis[nx][ny]) {
					vis[nx][ny] = 1;
					int nw = min(w, g[nx][ny]);
					pq.emplace(nw, nx, ny);
				}
			}
		}
	}

	cout << res << "\n";
}