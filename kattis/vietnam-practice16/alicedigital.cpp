#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int n, m, sum1 = 0, sum2 = 0, res = 0;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			sum2 += a;
			if (a == m) {
				sum1 = sum2;
				sum2 = 0;
			} else if (a < m) {
				sum1 = sum2 = 0;
			}
			if (sum1) {
				res = max(res, sum1 + sum2);
			}
		}
		cout << res << "\n";
	}
}