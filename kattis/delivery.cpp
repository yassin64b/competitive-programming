#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

int solve(vector<pair<int, int>>& xt, const int K) {
	int res = 0;
	while (1) {
		int load = K, start = 0;
		for (int i = (int)xt.size() - 1; i >= 0; --i) {
			if (xt[i].second) {
				if (!start) {
					assert(load == K);
					int num = xt[i].second / K;
					xt[i].second -= num * K;
					res += num * 2 * xt[i].first;
				}
				if (xt[i].second) {
					int tmp = max(0, xt[i].second - load);
					load -= xt[i].second - tmp;
					xt[i].second = tmp;
					start = max(start, xt[i].first);
				}
			}
		}
		if (load < K) {
			res += 2 * start;
		} else {
			break;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> pxt, nxt;
	for (int i = 0; i < N; ++i) {
		int x, t;
		cin >> x >> t;
		if (x < 0) {
			nxt.emplace_back(-x, t);
		} else {
			pxt.emplace_back(x, t);
		}
	}
	sort(pxt.begin(), pxt.end());
	sort(nxt.begin(), nxt.end());
	cout << solve(pxt, K) + solve(nxt, K) << "\n";
}