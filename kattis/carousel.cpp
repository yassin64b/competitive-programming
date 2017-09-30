#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr double eps = 1e-8;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	while (cin >> n >> m && (n || m)) {
		int a, b;
		double best = 1e9;
		for (int i = 0; i < n; ++i) {
			int ta, tb;
			cin >> ta >> tb;
			if (ta <= m && (double)tb / ta < best) {
				best = (double)tb / ta;
				a = ta;
				b = tb;
			} else if (ta <= m && (double)tb / ta == best && ta > a) {
				best = (double)tb / ta;
				a = ta;
				b = tb;
			}
		}
		if (best == 1e9) {
			cout << "No suitable tickets offered\n";
		} else {
			cout << "Buy " << a << " tickets for $" << b << "\n";
		}
	}

	return 0;
}
