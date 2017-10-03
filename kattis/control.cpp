#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int MX = 500000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<vector<int>> rec(N);
	vector<int> inrec(MX + 1, -1);
	int res = 0;
	for (int i = 0; i < N; ++i) {
		int M;
		cin >> M;
		rec[i].resize(M);
		for (int j = 0; j < M; ++j) {
			cin >> rec[i][j];
		}
		unordered_map<int, int> m;
		for (int j = 0; j < M; ++j) {
			if (inrec[rec[i][j]] != -1) {
				++m[inrec[rec[i][j]]];
			}
		}
		bool poss = true;
		for (const auto& p : m) {
			if (p.second != (int)rec[p.first].size()) {
				poss = false;
			}
		}
		if (poss) {
			for (int j = 0; j < M; ++j) {
				inrec[rec[i][j]] = i;
			}
			++res;
		}
	}
	cout << res << "\n";
}