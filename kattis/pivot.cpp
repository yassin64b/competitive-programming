#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	vector<int> mnr(n);
	mnr[n - 1] = v[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		mnr[i] = min(mnr[i + 1], v[i]);
	}
	int mxl = v[0], res = 0;
	for (int i = 0; i < n; ++i) {
		mxl = max(mxl, v[i]);
		if (v[i] >= mxl && (i == n - 1 || v[i] < mnr[i + 1])) {
			++res;
		}
	}
	cout << res << "\n";

	return 0;
}
