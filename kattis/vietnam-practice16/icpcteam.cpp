#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int N;
		cin >> N;
		vector<int> P(3 * N);
		for (int i = 0; i < 3 * N; ++i) {
			cin >> P[i];
		}
		sort(P.begin(), P.end());
		int res = 0;
		for (int i = 0; i < N; ++i) {
			P.pop_back();
			res += P.back();
			P.pop_back();
		}
		cout << res << "\n";
	}
}