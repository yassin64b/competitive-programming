#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int t = 0; t < n; ++t) {
		int k, w;
		cin >> k >> w;
		vector<string> words(w);
		for (int i = 0; i < w; ++i) {
			cin >> words[i];
		}
		int res = k;
		for (int i = 1; i < w; ++i) {
			int add = k;
			for (int j = 0; j < k; ++j) {
				bool poss = true;
				for (int a = 0; poss && a + j < k; ++a) {
					if (words[i - 1][j + a] != words[i][a]) {
						poss = false;
					}
				}
				if (poss) {
					add = j;
					break;
				}
			}
			res += add;
		}
		cout << res << "\n";
	}
}