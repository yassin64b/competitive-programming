#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt[6] = {0};
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		++cnt[v[i] - 1];
	}
	for (int i = 5; i >= 0; --i) {
		if (cnt[i] == 1) {
			cout << find(v.begin(), v.end(), i + 1) - v.begin() + 1 << "\n";
			return 0;
		}
	}
	cout << "none\n";
	return 0;
}