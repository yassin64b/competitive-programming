#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <map>

using namespace std;

using int64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int64> s(n), g(n);
	for (int i = 0; i < n; ++i)
		cin >> s[i] >> g[i];
	vector<int64> res1(n), res2(n);
	res1[0] = s[0] + g[0];
	for (int i = 1; i < n; ++i)
		res1[i] = min(res1[i - 1] + 1, s[i] + g[i]);
	res2[n - 1] = s[n - 1] + g[n - 1];
	for (int i = n - 2; i >= 0; --i) 
		res2[i] = min(res2[i + 1] + 1, s[i] + g[i]);
	vector<int64> res(n);
	for (int i = 0; i < n; ++i)
		res[i] = min(res1[i], res2[i]);
	int64 ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!(s[i] <= res[i] && res[i] <= s[i] + g[i])) {
			cout << -1 << "\n";
			return 0;
		}
		ans += res[i] - s[i];
	}
	cout << ans << "\n";
	for (int i = 0; i < n; ++i) 
		cout << res[i] << " ";
	cout << "\n";
}