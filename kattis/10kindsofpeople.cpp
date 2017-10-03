#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;

bool valid(int r, int c) {
	return (r >= 0 && r < n && c >= 0 && c < m);
}

void dfs(int r, int c, const vector<string>& g, vector<vector<int>>& comp) {
	for (int i = 0; i < 4; ++i) {
		int x = r + dx[i], y = c + dy[i];
		if (valid(x, y) && !comp[x][y] && g[r][c] == g[x][y]) {
			comp[x][y] = comp[r][c];
			dfs(x, y, g, comp);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	vector<string> grid(n);
	for (int i = 0; i < n; ++i) {
		cin >> grid[i];
		for (int j = 0; j < m; ++j) {
			grid[i][j] -= '0';
		}
	}
	int compid = 0;
	vector<vector<int>> comp(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!comp[i][j]) {
				comp[i][j] = ++compid;
				dfs(i, j, grid, comp);
			}
		}
	}
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		--r1; --c1; --r2; --c2;
		if (comp[r1][c1] == comp[r2][c2]) {
			if (grid[r1][c1]) {
				cout << "decimal\n";
			} else {
				cout << "binary\n";
			}
		} else {
			cout << "neither\n";
		}
	}
}