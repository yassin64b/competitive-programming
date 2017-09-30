#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int Ncs, Ne;
		cin >> Ncs >> Ne;
		vector<int> cs(Ncs), e(Ne);
		double avgcs = 0., avge = 0.;
		for (int i = 0; i < Ncs; ++i) {
			cin >> cs[i];
			avgcs += cs[i];
		}
		for (int i = 0; i < Ne; ++i) {
			cin >> e[i];
			avge += e[i];
		}
		avgcs /= Ncs;
		avge /= Ne;
		int res = 0;
		for (int i = 0; i < Ncs; ++i) {
			if (cs[i] < avgcs && cs[i] > avge) {
				++res;
			}
		}
		cout << res << "\n";
	}
	return 0;
}