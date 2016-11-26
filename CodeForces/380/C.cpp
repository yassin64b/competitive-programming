#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int calcTime(vector<int64_t> &g, int64_t fuel, int64_t s, int64_t k, int64_t &time)
{
	int64_t last = 0;
	time = 0;
	for (int i = 0; i < k; ++i) {
		time += (g[i] - last) * 2;
		if (g[i] - last < fuel) {
			time -= min(g[i] - last, fuel - (g[i] - last));
		} else if (g[i] - last > fuel) {
			return -1;
		}
		last = g[i];
	}

	time += (s - last) * 2;
	if (s - last < fuel) {
		time -= min(s - last, fuel - (s - last));
	} else if (s - last > fuel) {
		return -1;
	}
	return 1;
}

int main() 
{
	ios::sync_with_stdio(false);

	int64_t n, k, s, t;
	cin >> n >> k >> s >> t;
	vector<int64_t> c(n), v(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i] >> v[i];
	}
	vector<int64_t> g(k);
	for (int i = 0; i < k; ++i) {
		cin >> g[i];
	}
	sort(g.begin(), g.end());

	int64_t low = 1, high = 4000000000LL;
	while (low <= high) {
		int64_t fuel = (low + high) / 2, time = 0;
		int64_t isOk = calcTime(g, fuel, s, k, time);
		
		if (isOk == 1 && time <= t) {
			if (calcTime(g, fuel-1, s, k, time) == 1) {
				high = fuel - 1;
			} else {
				low = fuel;
				break;
			}
		} else {
			low = fuel + 1;
		}

		//cout << low << " " << high << endl;
	}

	int64_t min = 10e9;
	for (int i = 0; i < n; ++i) {
		if (v[i] >= low && c[i] <= min) {
			min = c[i];
		}
	}
	cout << (min == (int64_t)10e9 ? -1 : min) << endl;

    return 0;
}