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

	int N, M;
	cin >> N >> M;
	vector<vector<double>> dp(N + 1, vector<double>(M + 1, 0.));
	dp[N][M] = 1.;
	for (int r = 0; r < N + M - 1; ++r) {
		double p;
		cin >> p;

		for (int i = 0; i <= N; ++i) {
			//i + j == N + M - 1 - r
			int j = N + M - 1 - r - i;
			if (j > 0 && j <= M && i + 1 <= N) dp[i][j] += dp[i + 1][j] * (1. - p);
			if (j >= 0 && i > 0 && j + 1 <= M) dp[i][j] += dp[i][j + 1] * p;
		}
	}

	double win = 0., lose = 0.;
	for (int i = 1; i <= N; ++i) {
		win += dp[i][0];
	}
	for (int j = 1; j <= M; ++j) {
		lose += dp[0][j];
	}
	cout.precision(17);
	cout << fixed << win / (win + lose) << "\n";

	return 0;
}
