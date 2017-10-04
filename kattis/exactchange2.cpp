#include <iostream>
#include <vector>

using namespace std;

constexpr int MXV = 100 * 10000;
constexpr int INF = 1000 * 1000 * 1000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int val, N;
		cin >> val >> N;
		vector<int> coins(N), dp(MXV + 1, INF);
		int realmxv = 0;
		for (int i = 0; i < N; ++i) {
			cin >> coins[i];
			realmxv += coins[i];
		}
		dp[0] = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = realmxv - coins[i]; j >= 0; --j) {
				dp[j + coins[i]] = min(dp[j + coins[i]], dp[j] + 1);
			}
		}
		for (int j = val; j <= realmxv; ++j) {
			if (dp[j] < INF) {
				cout << j << " " << dp[j] << "\n";
				break;
			}
		}
	}
}