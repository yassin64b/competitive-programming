#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

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
		bool flag = true;
		int64_t fuel = (low + high) / 2;
		int64_t last = 0, time = 0;
		//cout << fuel << ": " << endl;
		for (int i = 0; flag && i < k; ++i) {
			time += (g[i] - last) * 2;
			if (g[i] - last < fuel) {
				time -= min(g[i] - last, fuel - (g[i] - last));
			} else if (g[i] - last > fuel) {
				low = fuel + 1;
				flag = false;
			}
			//cout << time << " ";
			last = g[i];
		}
		if (!flag) {
			//cout << endl << endl;
			continue;
		}
		time += (s - last) * 2;
		if (s - last < fuel) {
			time -= min(s - last, fuel - (s - last));
		} else if (s - last > fuel) {
			low = fuel + 1;
			continue;
		}
		//cout << time << endl << endl;
		if (time <= t) {
			fuel = fuel - 1;
			bool possible = true;
			int64_t last = 0, time = 0;
			for (int i = 0; possible && i < k; ++i) {
				time += (g[i] - last) * 2;
				if (g[i] - last < fuel) {
					time -= min(g[i] - last, fuel - (g[i] - last));
				} else if (g[i] - last > fuel) {
					low = fuel + 1;
					possible = false;
				}
				last = g[i];
			}
			if (!possible) {
				//if (t == 1000000000) cout << "Hi1" << endl;
				break;
			}
			time += (s - last) * 2;
			if (s - last < fuel) {
				time -= min(s - last, fuel - (s - last));
			} else if (s - last > fuel) {
				low = fuel + 1;
				//if (t == 1000000000) cout << "Hi2" << endl;
				break;
			}
			high = fuel;
		} else {
			low = fuel + 1;
		}
	}
	//if (t == 1000000000) {
	//	cout << low << endl;
	//}
	//cout << low << endl;
	int64_t min = 10e9;
	for (int i = 0; i < n; ++i) {
		if (v[i] >= low && c[i] <= min) {
			min = c[i];
		}
	}
	cout << (min == (int64_t)10e9 ? -1 : min) << endl;

    return 0;
}