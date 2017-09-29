#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long int64;

constexpr int MOD = 1000 * 1000 * 1000 + 7;

int main() {
	ios::sync_with_stdio(false);
	int N, T, A, B, C, t0;
	cin >> N >> T >> A >> B >> C >> t0;
	vector<int> t(N);
	t[0] = t0;
	for (int i = 1; i < N; ++i) {
		t[i] = (((int64)A * t[i - 1] + B) % C) + 1;
	}
	sort(t.begin(), t.end());
	int penalty = 0, num = 0, time = 0;
	for (int i = 0; i < N; ++i) {
		if (time + t[i] <= T) {
			time += t[i];
			penalty += time;
			penalty %= MOD;
			++num;
		} else {
			break;
		}
	}
	cout << num << " " << penalty << "\n";
}