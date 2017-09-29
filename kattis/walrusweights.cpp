#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long int64;

constexpr int MAXW = 3000;

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> w(N);
	for (int i = 0; i < N; ++i) {
		cin >> w[i];
	}
	vector<int> dp(MAXW + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = MAXW; j >= w[i]; --j) {
			if (dp[j - w[i]]) {
				dp[j] = 1;
			}
		}
	}
	int resw = 0;
	for (int i = 0; i <= MAXW; ++i) {
		if (dp[i] && abs(i - 1000) <= abs(resw - 1000)) {
			resw = i;
		}
	}
	cout << resw << "\n";
}