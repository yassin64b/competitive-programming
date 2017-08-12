#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int cur = 0, i = 0, rest = 0;
	for (i = 0; i < n && cur < k; ++i) {
		rest += a[i];
		if (rest < 8) {
			cur += rest;
			rest = 0;
		} else {
			rest -= 8;
			cur += 8;
		}
	}
	if (cur < k) {
		i = -1;
	}
	cout << i << "\n";
	return 0;
}