#include <iostream>
#include <vector>

using namespace std;

constexpr int MXV = 100 * 1000;
constexpr int INF = 1000 * 1000 * 1000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int H;
	cin >> H;
	vector<int> v1(H);
	for (int i = 0; i < H; ++i) {
		cin >> v1[i];
	}
	int B;
	cin >> B;
	vector<int> v2(B);
	for (int i = 0; i < B; ++i) {
		cin >> v2[i];
	}

	vector<int> dp1(MXV + 1, INF), dp2(MXV + 1, INF);
	dp1[0] = dp2[0] = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = MXV - v1[i]; j >= 0; --j) {
			if (dp1[j] < INF) {
				dp1[j + v1[i]] = min(dp1[j + v1[i]], dp1[j] + 1);
			}
		}
	}
	for (int i = 0; i < B; ++i) {
		for (int j = MXV - v2[i]; j >= 0; --j) {
			if (dp2[j] < INF) {
				dp2[j + v2[i]] = min(dp2[j + v2[i]], dp2[j] + 1);
			}
		}
	}
	int res = INF * 2;
	for (int j = 1; j <= MXV; ++j) {
		if (dp1[j] < INF && dp2[j] < INF) {
			res = min(res, dp1[j] + dp2[j]);
		}
	}
	if (res < INF * 2) {
		cout << res << "\n";
	} else {
		cout << "impossible\n";
	}
}