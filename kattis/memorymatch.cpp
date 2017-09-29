#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	unordered_map<string, set<int>> m;
	for (int i = 0; i < K; ++i) {
		int C1, C2;
		string S1, S2;
		cin >> C1 >> C2 >> S1 >> S2;
		if (S1 == S2) {
			m.erase(S1);
			N -= 2;
		} else {
			m[S1].insert(C1);
			m[S2].insert(C2);
		}
	}
	int res = 0;
	int singlepairs = 0;
	for (const auto& p : m) {
		if (p.second.size() == 2U) {
			++res;
			N -= 2;
		} else if (p.second.size() == 1U) {
			++singlepairs;
		}
	}
	if (singlepairs * 2 == N) {
		res += singlepairs;
	} else if (singlepairs == 0 && N == 2) {
		++res;
	}
	cout << res << "\n";
	return 0;
}