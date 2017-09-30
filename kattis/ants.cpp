#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int l, n;
		cin >> l >> n;
		int mn = 0, mx = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			mn = max(mn, min(l - x, x));
			mx = max(mx, max(l - x, x));
		}
		cout << mn << " " << mx << "\n";
	}

	return 0;
}
