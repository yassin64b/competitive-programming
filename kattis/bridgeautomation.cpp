#include <iostream>
#include <vector>
#include <algorithm>

constexpr int INF = 1000 * 1000 * 1000;
constexpr int MXT = 30 * 60;

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	std::cin >> N;
	std::vector<int> T(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> T[i];
	}

	std::vector<int> dp(N + 1, INF);
	dp[0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < i; ++j) {
			int duration = std::max(T[i - 1] + 20 - (T[j] + MXT), 20 * (i - j));
			dp[i] = std::min(dp[i], dp[j] + duration + 120);
		}
	}
	std::cout << dp[N] << "\n";

	return 0;
}