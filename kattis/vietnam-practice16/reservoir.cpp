#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int N;
		cin >> N;
		vector<long long> L(N), H(N);
		for (int i = 0; i < N; ++i) {
			cin >> L[i];
		}
		for (int i = 0; i < N; ++i) {
			cin >> H[i];
		}
		vector<long long> sum_walls(N);
		sum_walls[0] = H[0];
		for (int i = 1; i < N; ++i) 
			sum_walls[i] = sum_walls[i - 1] + H[i];
		vector<long long> dp(N + 1);
		dp[0] = 0;
		stack<int> lastbigger;
		for (int i = 0; i < N; ++i) {
			while (!lastbigger.empty() && H[lastbigger.top()] < H[i])
				lastbigger.pop();
			if (!lastbigger.empty()) {
				int ind = lastbigger.top();
				dp[i + 1] = dp[ind + 1] + (L[i] - L[ind]) * H[i] - (sum_walls[i] - sum_walls[ind]);
			} else {
				dp[i + 1] = (L[i] + 1) * H[i] - sum_walls[i];
			}
			lastbigger.push(i);
		}
		for (int i = 1; i <= N; ++i) ++dp[i];

		int Q;
		cin >> Q;
		for (int i = 0; i < Q; ++i) {
			long long K;
			cin >> K;
			cout << --upper_bound(dp.begin(), dp.end(), K) - dp.begin() << "\n";
		}
	}
}