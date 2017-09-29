#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using uint64 = unsigned long long;

constexpr int MAXONE = 50, MAXTWO = 25;

int main() {
	vector<vector<uint64>> dp(MAXONE + 1, vector<uint64>(MAXTWO + 1, 0));
	for (int i = 0; i <= MAXONE; ++i) {
		dp[i][0] = 1;
	}
	for (int j = 0; j <= MAXTWO; ++j) {
		dp[0][j] = 1;
	}
	for (int i = 1; i <= MAXONE; ++i) {
		for (int j = 1; j <= MAXTWO; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	
	int P;
	cin >> P;
	for (int t = 0; t < P; ++t) {
		int K, S;
		cin >> K >> S;
		uint64 res = 0;
		for (int twostep = 0; twostep <= S; twostep += 2) {
			int onestep = S - 2 * twostep;
			if (onestep >= 0 && onestep % 2 == 0 && onestep <= twostep) {
				uint64 tmp = dp.at(onestep / 2).at(twostep / 2);
				res += tmp * tmp;
			}
		}
		cout << K << " " << res << "\n";
	}
	return 0;
}