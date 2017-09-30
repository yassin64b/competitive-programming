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
		int Ng, Nm;
		cin >> Ng >> Nm;
		vector<int> g(Ng), m(Nm);
		for (int i = 0; i < Ng; ++i) {
			cin >> g[i];
		}
		for (int i = 0; i < Nm; ++i) {
			cin >> m[i];
		}
		sort(g.begin(), g.end(), greater<int>());
		sort(m.begin(), m.end(), greater<int>());
		while (!g.empty() && !m.empty()) {
			if (g.back() < m.back()) {
				g.pop_back();
			} else if (g.back() >= m.back()) {
				m.pop_back();
			}
		}
		if (g.empty() && m.empty()) {
			cout << "uncertain\n";
		} else if (g.empty()) {
			cout << "MechaGodzilla\n";
		} else {
			cout << "Godzilla\n";
		}
	}
	return 0;
}