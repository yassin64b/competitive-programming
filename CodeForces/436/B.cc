#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	int res = 0;
	for (int i = 0; i < n; ) {
		int j = i;
		while (j < n && s[j] >= 'a' && s[j] <= 'z') {
			++j;
		}
		int occ[26] = {0};
		for (int k = i; k < j; ++k) {
			occ[s[k] - 'a'] = 1;
		}
		i = j + 1;
		res = max(res, accumulate(occ, occ + 26, 0));
	}
	cout << res << "\n";
	return 0;
}