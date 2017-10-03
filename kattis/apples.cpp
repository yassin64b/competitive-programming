#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int R, C;
	cin >> R >> C;
	vector<string> g(R);
	for (int i = 0; i < R; ++i) {
		cin >> g[i];
	}
	for (int j = 0; j < C; ++j) {
		int num = 0;
		for (int i = 0; i < R; ++i) {
			if (g[i][j] == 'a') {
				++num;
				g[i][j] = '.';
			} else if (g[i][j] == '#') {
				for (int k = i - num; k < i; ++k) {
					g[k][j] = 'a';
				}
				num = 0;
			}
		}
		for (int k = R - num; k < R; ++k) {
			g[k][j] = 'a';
		}
	}
	for (int i = 0; i < R; ++i) {
		cout << g[i] << "\n";
	}
}