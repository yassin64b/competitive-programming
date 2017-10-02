#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <cassert>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int c;
	cin >> c;
	for (int t = 0; t < c; ++t) {
		int l, m;
		cin >> l >> m;
		l *= 100;
		vector<int> left, right;
		for (int i = 0; i < m; ++i) {
			int len;
			string side;
			cin >> len >> side;
			if (side == "left") {
				left.push_back(len);
			} else {
				right.push_back(len);
			}
		}
		int numit = 0, lastleft = 1;
		for (int i = 0, j = 0; i < (int)left.size() || j < (int)right.size(); ) {
			int load = 0;
			while (i < (int)left.size() && load + left[i] <= l) {
				load += left[i++];
			}
			lastleft = (load > 0);
			load = 0;
			while (j < (int)right.size() && load + right[j] <= l) {
				load += right[j++];
			}
			lastleft = (load == 0);
			++numit;
		}
		cout << numit * 2 - lastleft << "\n";
	}

	return 0;
}
