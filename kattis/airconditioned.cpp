#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct range {
	int L, U;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<range> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i].L >> v[i].U;
	}
	sort(v.begin(), v.end(), [](const range& lhs, const range& rhs) {
		return lhs.U < rhs.U;
	});

	int res = 0, last = -1;
	for (int i = 0; i < N; ++i) {
		if (v[i].L <= last && v[i].U >= last) {

		} else {	
			++res;
			last = v[i].U;
		}
	}
	cout << res << "\n";
}