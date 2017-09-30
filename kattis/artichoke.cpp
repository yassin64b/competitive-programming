#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int p, a, b, c, d, n;
	cin >> p >> a >> b >> c >> d >> n;
	vector<double> price(n + 1);
	for (int k = 1; k <= n; ++k) {
		price[k] = p * (sin(a * k + b) + cos(c * k + d) + 2);
	}
	double mx = price[1], res = 0.;
	for (int k = 1; k <= n; ++k) {
		mx = max(mx, price[k]);
		res = max(res, mx - price[k]);
	}
	cout.precision(17);
	cout << fixed << res << "\n";
	return 0;
}