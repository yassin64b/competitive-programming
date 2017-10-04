#include <iostream>
#include <vector>

using namespace std;

constexpr int PROCT = 1000;
constexpr int MAXT = 100000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> t(n);
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}
	long long lo = 0, hi = n, ans = hi;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		vector<long long> free(MAXT + 1 + PROCT, 0);
		free[0] = mid * k;
		int j = 0;
		for (int i = 0; i <= MAXT && j < n; ++i) {
			if (t[j] == i) {
				while (j < n && t[j] == i) {
					if (free[i] == 0) {
						break;
					}
					free[i] -= 1;
					free[i + PROCT] += 1;
					++j;
				}
				free[i + 1] += free[i];	
			} else {
				free[i + 1] += free[i];
			}
		}
		if (j == n) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << ans << "\n";
}