#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

struct item {
	int t, d, p, id;
};

int main() {
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<item> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].t >> v[i].d >> v[i].p;
		v[i].id = i + 1;
	}
	sort(v.begin(), v.end(), [](const item& lhs, const item& rhs) {
		return lhs.d < rhs.d;
	});

	//dp[i][j] = max val when saving items 0..i until time j
	vector<vector<int>> dp(n + 1, vector<int>(2000 + 1, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= 2000; ++j) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (j + v[i].t < v[i].d) {
				dp[i + 1][j + v[i].t] = max(dp[i + 1][j + v[i].t], dp[i][j] + v[i].p);
			}
		}
	}
	int res = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= 2000; ++j) {
			res = max(res, dp[i][j]);
		}
	}
	cout << res << "\n";
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= 2000; ++j) {
			if (dp[i][j] == res) {
				vector<int> el;
				while (i > 0) {
					if (dp[i - 1][j] == dp[i][j]) {
						--i;
					} else {
						el.push_back(v[i - 1].id);
						--i;
						j -= v[i].t;
					}
				}
				reverse(el.begin(), el.end());
				cout << el.size() << "\n";
				for (int x : el) {
					cout << x << " ";
				}
				cout << "\n";
				return 0;
			}
		}
	}

	return 0;
}