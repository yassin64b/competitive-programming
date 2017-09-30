#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int n;
		cin >> n;
		unordered_map<string, int> m;
		for (int i = 0; i < n; ++i) {
			string name, cat;
			cin >> name >> cat;
			++m[cat];
		}
		long long res = 1;
		for (const auto& p : m) {
			res *= p.second + 1;
		}
		cout << res - 1 << "\n";
	}
	return 0;
}