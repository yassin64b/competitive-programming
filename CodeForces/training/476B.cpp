#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;

	vector<uint32_t> x(m);
	for (int i = 0; i < m; ++i) {
		cin >> x[i];
	}
	uint32_t fedor;
	cin >> fedor;

	int ans = 0;
	for (int i = 0; i < m; ++i) {
		int res = 0;
		uint32_t diff = fedor ^ x[i];
		for (int j = 0; j < 32; ++j) {
			res += ((diff >> j) & 0b1);
		}
		if (res <= k) {
			++ans;
		}
	}

	cout << ans << endl;

	return 0;
}