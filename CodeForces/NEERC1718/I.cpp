#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>
#include <random>
#include <utility>

using namespace std;

constexpr int INF = 2 * 1000 * 1000 * 1000;

int brute(int i, const int n, const int k, const vector<int>& v) {
	if (i == n) 
		return 0;
	int res = 1000 * 1000 * 1000 * 2;
	for (int j = i + k; j <= n; ++j) {
		res = min(res, max(v[j - 1] - v[i], brute(j, n, k, v)));
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) 
		cin >> v[i];

    //random_device rd;
    //default_random_engine dre(rd());
    //uniform_int_distribution<int> uid(1,1000);
    //for (int i = 0; i < n; ++i) {
    //	v[i] = uid(dre);
    //}
	sort(v.begin(), v.end());
	
	int low = 0, high = 1000 * 1000 * 1000, ans = high;
	while (low <= high) {
		int mid = (low + high) / 2;

		vector<pair<int, int>> dp(n + 1, {INF, 0});
		dp[0] = {0, 0};
		dp[k] = {v[k - 1] - v[0], v[k - 1] - v[0]};
		for (int i = k; i < n; ++i) {
			dp[i + 1] = {max(dp[i].first, dp[i].second + v[i] - v[i - 1]), dp[i].second + v[i] - v[i - 1]};
			
			int add = v[i] - v[i - k + 1];
			if (dp[i + 1].first <= mid) {
				if (max(dp[i + 1 - k].first, add) <= mid) {
					if (dp[i + 1].second > add) {
						dp[i + 1].first = max(dp[i + 1 - k].first, add);
						dp[i + 1].second = add;
					}
				}
			} else {
				dp[i + 1].first = max(dp[i + 1 - k].first, add);
				dp[i + 1].second = add;
			}
		}

		if (dp[n].first <= mid) {
			high = mid - 1;
			ans = mid;
		} else {
			low = mid + 1;
		}
	}


	cout << ans << "\n";

	//cout << brute(0, n, k, v) << "\n";
}