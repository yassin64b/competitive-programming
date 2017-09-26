#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int a, b, f, k;
	cin >> a >> b >> f >> k;
	int pos = 0, tank = b, res = 0;
	for (int i = 0; i < k; ++i) {
		if (pos == 0) {
			tank -= f;
			if (tank < 0) {
				cout << -1 << "\n";
				return 0;
			}
			if (i < k - 1 && tank < 2 * (a - f) || i == k - 1 && tank < a - f) {
				tank = b;
				++res;
			}
			tank -= (a - f);
			if (tank < 0) {
				cout << -1 << "\n";
				return 0;
			}
			pos = a;
		} else {
			tank -= (a - f);
			if (tank < 0) {
				cout << -1 << "\n";
				return 0;
			}
			if (i < k - 1 && tank < 2 * f || i == k - 1 && tank < f) {
				tank = b;
				++res;
			}
			tank -= f;
			if (tank < 0) {
				cout << -1 << "\n";
				return 0;
			}
			pos = 0;
		}
	}
	cout << res << "\n";

	return 0;
}