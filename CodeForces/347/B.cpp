#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	vector<int> v;
	char c;
	cin >> c;
	assert(c == '?');
	v.push_back(1);
	int sum = 1;
	while (cin >> c) {
		if (c == '+') {
			v.push_back(1);
			++sum;
		} else if (c == '-') {
			v.push_back(-1);
			--sum;
		} else {
			assert(c == '=');
			break;
		}
		cin >> c;
		assert(c == '?');
	}
	int n;
	cin >> n;
	for (int i = 0; i < (int)v.size(); ++i) {
		if (v[i] > 0) {
			if (sum < n) {
				v[i] = min(n, n - (sum - 1));
				sum += min(n, n - (sum - 1)) - 1;
			}
		} else if (v[i] < 0) {
			if (sum > n) {
				v[i] = -min(n, (sum + 1) - n);
				sum -= min(n, (sum + 1) - n) - 1;
			}
		} else {
			assert(false);
		}
	}
	if (sum == n) {
		cout << "Possible\n";
		cout << v[0];
		for (int i = 1; i < (int)v.size(); ++i) {
			cout << " " << (v[i] > 0 ? '+' : '-') << " " << abs(v[i]); 
		}
		cout << " = " << n << "\n";
	} else {
		cout << "Impossible\n";
	}
}