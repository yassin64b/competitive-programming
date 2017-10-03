#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	while ((cin >> N >> M) && (N || M)) {
		unordered_set<int> first;
		for (int i = 0; i < N; ++i) {
			int x;
			cin >> x;
			first.insert(x);
		}
		int res = 0;
		for (int i = 0; i < M; ++i) {
			int x;
			cin >> x;
			if (first.find(x) != first.end()) {
				++res;
			}
		}
		cout << res << "\n";
	}
}