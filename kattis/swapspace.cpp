#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
		int add1 = lhs.second - lhs.first, add2 = rhs.second - rhs.first;
		if (add1 > 0 && add2 <= 0) {
			return true;
		} else if (add2 > 0 && add1 <= 0) {
			return false;
		} else if (add1 > 0 && add2 > 0) {
			return lhs.first < rhs.first;
		} else {
			return lhs.second > rhs.second;
		}
	});
	/*for (int i = 0; i < N; ++i) {
		cout << v[i].first << " " << v[i].second << "\n";
	}*/
	long long res = 0;
	long long free = 0;
	for (int i = 0; i < N; ++i) {
		if (free >= v[i].first) {
			free -= v[i].first;
			free += v[i].second;
		} else {
			res += v[i].first - free;
			free = v[i].second;
		}
	}
	cout << res << "\n";
}